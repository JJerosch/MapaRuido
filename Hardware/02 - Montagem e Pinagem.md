# 🛠️ Montagem e Pinagem da Estação

## 1. Tensão e Alimentação
* **Tensão Lógica:** 3.3V (ESP32).
* **Alimentação dos Módulos:**
  * INMP441: **3.3V**
  * OLED SSD1306: **3.3V**
  * DHT22: **3.3V** (com pull-up)
  * MicroSD: **3.3V / 5V** (conforme serigrafia do módulo)
  * GPS NEO-6M: **5V / VIN** (regulador 3.3V integrado)

---

## 2. Mapa de Pinagem (ESP32 DevKit 30 pinos)

| Periférico | Barramento | Pino do Módulo | Pino no ESP32 | Função |
|---|---|---|---|---|
| **INMP441** | I2S | SCK / BCLK | **GPIO 14** | Clock I2S |
| | | WS / LRCL | **GPIO 15** | Word Select (Canal) |
| | | SD / DOUT | **GPIO 32** | Dados de Áudio |
| | | L/R | **GND** | Canal Esquerdo |
| **MicroSD** | SPI | MOSI | **GPIO 23** | VSPI MOSI |
| | | MISO | **GPIO 19** | VSPI MISO |
| | | SCK | **GPIO 18** | VSPI SCK |
| | | CS | **GPIO 5** | Chip Select |
| **OLED** | I2C | SDA | **GPIO 21** | Dados I2C |
| | | SCL | **GPIO 22** | Clock I2C |
| **GPS** | UART2 | TX | **GPIO 16 (RX2)** | Recepção NMEA |
| | | RX | **GPIO 17 (TX2)** | *(Opcional)* |
| **DHT22** | 1-Wire | DATA | **GPIO 4** | Leitura Clima |

---

## 3. Cuidados de Montagem
* O microfone INMP441 deve ficar **externo à caixa**, envolvido pela espuma anti-vento.
* A antena cerâmica do GPS deve ficar apontada para cima, desobstruída.
