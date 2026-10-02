# 📚 Guia de Estudos e Referências

## 1. Fundamentos Acústicos e Normas
* **Ponderação A ($dB(A)$):** Filtro de frequência que atenua frequências graves e agudas para simular a resposta do ouvido humano.
* **Métrica $L_{Aeq}$:** Nível de pressão sonora contínuo equivalente ponderado em A integrado em um intervalo $T$.
* **NBR 10151:** Norma brasileira para avaliação de ruído em áreas habitadas. Define limites para zonas residenciais (~50-55 dB diurno) e comerciais (~60-65 dB diurno).

## 2. Repositórios de Referência no GitHub
1. **`ikostoski/esp32-i2s-slm`**: Decibelímetro digital com ESP32 + INMP441, filtro IIR e cálculo de $L_{Aeq}$. Principal referência para o firmware de áudio.
2. **`stas-sl/esphome-sound-level-meter`**: Medidor de ruído com ESPHome.
3. **`meekm/LoRaSoundkit`**: Estação de monitoramento de ruído com ESP32 para ciência cidadã.
4. **`Ifsttar/NoiseCapture`**: Projeto europeu de mapeamento colaborativo de ruído acústico.

## 3. Stack de Software
* **Firmware:** C/C++ (PlatformIO / Arduino Core para ESP32).
* **Processamento de Dados:** Python 3 (Pandas, NumPy, SciPy).
* **Mapeamento Web:** Folium / Leaflet.js hospedado no GitHub Pages.
