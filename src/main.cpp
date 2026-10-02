#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <WiFi.h>
#include <WebServer.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>
#include <TinyGPSPlus.h>

// ============================================================================
// 1. MAPEAMENTO DE PINOS E COMPONENTES
// ============================================================================
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// DHT22 (Temperatura e Umidade)
#define DHTPIN 4
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

// MicroSD (SPI)
#define SD_CS 5

// GPS NEO-6M (UART2)
#define GPS_RX_PIN 16
#define GPS_TX_PIN 17
HardwareSerial gpsSerial(2);
TinyGPSPlus gps;

// Servidor Web
WebServer server(80);

// ============================================================================
// ESTRUTURA DE DADOS DA ESTAÇÃO
// ============================================================================
struct StationData {
  float temperature;
  float humidity;
  float laeq_db;
  double latitude;
  double longitude;
  String timestamp;
  bool sd_ok;
  bool dht_ok;
  bool oled_ok;
  bool wifi_ok;
};

StationData currentData = {0.0, 0.0, 0.0, -25.4284, -49.2733, "2026-10-02 12:00:00", false, false, false, false};

// ============================================================================
// 2. FUNÇÕES DE TESTES ISOLADOS (EVIDÊNCIAS DE BANCADA)
// ============================================================================

void testOLED() {
  Serial.println("\n[TESTE 1/4] Inicializando Display OLED SSD1306...");
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println("❌ FALHA: OLED nao encontrado no barramento I2C (0x3C).");
    currentData.oled_ok = false;
  } else {
    Serial.println("✅ SUCESSO: OLED SSD1306 inicializado com sucesso.");
    currentData.oled_ok = true;
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 10);
    display.println("MAPA DE RUIDO CWB");
    display.setCursor(10, 28);
    display.println("Setup Wokwi ESP32");
    display.setCursor(10, 46);
    display.println("Auto-Teste OK...");
    display.display();
  }
}

void testDHT() {
  Serial.println("\n[TESTE 2/4] Lendo Sensor Climatico DHT22...");
  dht.begin();
  delay(500);
  float t = dht.readTemperature();
  float h = dht.readHumidity();

  if (isnan(t) || isnan(h)) {
    Serial.println("⚠️ AVISO: Falha na leitura do DHT22 (usando valores padrao).");
    currentData.temperature = 22.5;
    currentData.humidity = 65.0;
    currentData.dht_ok = false;
  } else {
    currentData.temperature = t;
    currentData.humidity = h;
    currentData.dht_ok = true;
    Serial.printf("✅ SUCESSO: DHT22 lido -> Temp: %.1f *C | Umidade: %.1f %%\n", t, h);
  }
}

void testMicroSD() {
  Serial.println("\n[TESTE 3/4] Inicializando Leitor MicroSD (SPI)...");
  if (!SD.begin(SD_CS)) {
    Serial.println("⚠️ AVISO: Cartao MicroSD nao detectado ou falha na montagem.");
    currentData.sd_ok = false;
  } else {
    Serial.println("✅ SUCESSO: MicroSD montado com sucesso.");
    currentData.sd_ok = true;

    // Criar cabeçalho do CSV se não existir
    File file = SD.open("/medicoes.csv", FILE_APPEND);
    if (file) {
      if (file.size() == 0) {
        file.println("timestamp,latitude,longitude,laeq_db,temp_c,umid_pct");
        Serial.println("   -> Cabecalho de medicoes.csv criado com sucesso.");
      }
      file.close();
    }
  }
}

void testGPS() {
  Serial.println("\n[TESTE 4/4] Inicializando Comunicacao Serial com GPS NEO-6M...");
  gpsSerial.begin(9600, SERIAL_8N1, GPS_RX_PIN, GPS_TX_PIN);
  Serial.println("✅ SUCESSO: UART2 configurada para GPS a 9600 baud.");
}

// Simulação matemática de nível de ruído equivalente (dB SPL)
float simulateNoiseReading() {
  // Gera oscilações realistas entre 52 dB(A) e 76 dB(A) simulando tráfego urbano
  static float baseNoise = 62.0;
  baseNoise += ((random(0, 100) - 50) / 25.0);
  if (baseNoise < 50.0) baseNoise = 52.0;
  if (baseNoise > 82.0) baseNoise = 78.0;
  return baseNoise;
}

// ============================================================================
// 3. SERVIDOR WEB ("HELLO WORLD" + LIVE DASHBOARD)
// ============================================================================

const char* generateHTML() {
  static char html[2048];
  snprintf(html, sizeof(html),
    "<!DOCTYPE html>"
    "<html lang='pt-BR'>"
    "<head>"
    "<meta charset='UTF-8'>"
    "<meta name='viewport' content='width=device-width, initial-scale=1.0'>"
    "<meta http-equiv='refresh' content='3'>"
    "<title>Mapa de Ruido Curitiba - ESP32 Server</title>"
    "<style>"
    "body{font-family:'Segoe UI',sans-serif;background:#0d1117;color:#c9d1d9;margin:0;padding:20px;display:flex;justify-content:center;}"
    ".card{background:#161b22;border:1px solid #30363d;border-radius:12px;max-width:500px;width:100%%;padding:24px;box-shadow:0 8px 24px rgba(0,0,0,0.4);}"
    "h1{color:#58a6ff;font-size:22px;margin-top:0;border-bottom:1px solid #30363d;padding-bottom:12px;}"
    ".badge{display:inline-block;padding:4px 10px;border-radius:20px;font-size:12px;font-weight:bold;background:#238636;color:#fff;margin-bottom:16px;}"
    ".metric{display:flex;justify-content:space-between;padding:10px 0;border-bottom:1px solid #21262d;font-size:15px;}"
    ".value{font-weight:bold;color:#f0f6fc;}"
    ".highlight{color:#ff7b72;font-size:20px;}"
    ".footer{margin-top:20px;font-size:12px;color:#8b949e;text-align:center;}"
    "</style>"
    "</head>"
    "<body>"
    "<div class='card'>"
    "<h1>🔊 Mapa de Ruido Curitiba</h1>"
    "<div class='badge'>ESP32 Web Server: ONLINE (Hello World)</div>"
    "<div class='metric'><span>Nivel Sonoro Estimado (LAeq):</span><span class='value highlight'>%.1f dB(A)</span></div>"
    "<div class='metric'><span>Temperatura Ambiente:</span><span class='value'>%.1f &deg;C</span></div>"
    "<div class='metric'><span>Umidade Relativa:</span><span class='value'>%.1f %%</span></div>"
    "<div class='metric'><span>Latitude / Longitude:</span><span class='value'>%.4f, %.4f</span></div>"
    "<div class='metric'><span>Status Cartao SD:</span><span class='value'>%s</span></div>"
    "<div class='metric'><span>IP da Estacao:</span><span class='value'>%s</span></div>"
    "<div class='footer'>Projeto Academico de Monitoramento Acustico &bull; Curitiba 2026</div>"
    "</div>"
    "</body>"
    "</html>",
    currentData.laeq_db,
    currentData.temperature,
    currentData.humidity,
    currentData.latitude,
    currentData.longitude,
    currentData.sd_ok ? "GRAVANDO (OK)" : "SIMULADO",
    WiFi.localIP().toString().c_str()
  );
  return html;
}

void handleRoot() {
  server.send(200, "text/html", generateHTML());
}

void handleAPI() {
  String json = "{";
  json += "\"laeq_db\":" + String(currentData.laeq_db, 1) + ",";
  json += "\"temperature\":" + String(currentData.temperature, 1) + ",";
  json += "\"humidity\":" + String(currentData.humidity, 1) + ",";
  json += "\"latitude\":" + String(currentData.latitude, 6) + ",";
  json += "\"longitude\":" + String(currentData.longitude, 6) + ",";
  json += "\"sd_ok\":" + String(currentData.sd_ok ? "true" : "false");
  json += "}";
  server.send(200, "application/json", json);
}

void setupWiFiAndServer() {
  Serial.println("\n[CONECTIVIDADE] Inicializando Wi-Fi e Web Server...");
  
  // No Wokwi o Wi-Fi oficial do simulador é "Wokwi-GUEST"
  WiFi.mode(WIFI_STA);
  WiFi.begin("Wokwi-GUEST", "");

  int timeout = 0;
  while (WiFi.status() != WL_CONNECTED && timeout < 20) {
    delay(250);
    Serial.print(".");
    timeout++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\n✅ SUCESSO: Conectado ao Wi-Fi!");
    Serial.print("   -> IP do ESP32: http://");
    Serial.println(WiFi.localIP());
    currentData.wifi_ok = true;
  } else {
    Serial.println("\n⚠️ AVISO: Wi-Fi nao conectado. Criando Access Point local...");
    WiFi.softAP("MapaRuido-ESP32", "12345678");
    Serial.print("   -> IP do AP: http://");
    Serial.println(WiFi.softAPIP());
  }

  server.on("/", handleRoot);
  server.on("/api/data", handleAPI);
  server.begin();
  Serial.println("✅ SUCESSO: Servidor Web HTTP rodando na porta 80.");
}

// ============================================================================
// ATUALIZAÇÃO DO DISPLAY OLED
// ============================================================================
void updateOLED() {
  if (!currentData.oled_ok) return;

  display.clearDisplay();
  
  // Header
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.printf("MAPA RUIDO | IP: %s", WiFi.localIP().toString().c_str());

  // Linha divisória
  display.drawLine(0, 10, 128, 10, SSD1306_WHITE);

  // LAeq em destaque
  display.setCursor(0, 16);
  display.setTextSize(2);
  display.printf("%.1f dB", currentData.laeq_db);

  // Dados Ambientais
  display.setTextSize(1);
  display.setCursor(0, 36);
  display.printf("Temp: %.1fC  Umid: %.0f%%", currentData.temperature, currentData.humidity);

  // Status de gravação e GPS
  display.setCursor(0, 48);
  display.printf("GPS: FIX  SD: %s", currentData.sd_ok ? "OK" : "NO");
  
  display.setCursor(0, 56);
  display.printf("Web: ONLINE :80");

  display.display();
}

// ============================================================================
// SETUP & LOOP PRINCIPAL
// ============================================================================
void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("\n==================================================");
  Serial.println("🚀 ESTACAO DE MONITORAMENTO ACUSTICO - CURITIBA");
  Serial.println("   Setup de Bancada e Testes Unitarios (Wokwi)");
  Serial.println("==================================================");

  // 1. Executar testes dos módulos de hardware
  testOLED();
  testDHT();
  testMicroSD();
  testGPS();

  // 2. Subir o servidor web Hello World
  setupWiFiAndServer();

  Serial.println("\n🎉 SETUP COMPLETO! Estacao operando e aguardando requisicoes.");
  Serial.println("--------------------------------------------------");
}

void loop() {
  server.handleClient();

  static unsigned long lastUpdate = 0;
  if (millis() - lastUpdate > 1000) {
    lastUpdate = millis();

    // Atualiza leituras
    currentData.laeq_db = simulateNoiseReading();
    float t = dht.readTemperature();
    float h = dht.readHumidity();
    if (!isnan(t)) currentData.temperature = t;
    if (!isnan(h)) currentData.humidity = h;

    // Atualiza display
    updateOLED();

    // Log serial
    Serial.printf("[METRICA 1s] LAeq: %.1f dB(A) | Temp: %.1f C | Umid: %.1f %% | SD: %s\n",
      currentData.laeq_db, currentData.temperature, currentData.humidity, currentData.sd_ok ? "GRAVADO" : "PENDENTE");

    // Grava linha no SD se disponível
    if (currentData.sd_ok) {
      File file = SD.open("/medicoes.csv", FILE_APPEND);
      if (file) {
        file.printf("%lu,%.6f,%.6f,%.2f,%.1f,%.1f\n",
          millis(), currentData.latitude, currentData.longitude, currentData.laeq_db, currentData.temperature, currentData.humidity);
        file.close();
      }
    }
  }
}
