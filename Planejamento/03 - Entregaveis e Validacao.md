# 📦 Entregáveis e Validação

## 1. Produtos Finais do Projeto
1. **Estação Física Portátil:** ESP32 + INMP441 + GPS + DHT22 + SD + OLED montados em caixa com proteção anti-vento (windscreen).
2. **Firmware C++ (Open Source):** Código PlatformIO com aquisição I2S DMA, filtro ponderado A e WebServer.
3. **Dataset de Medições (.csv):** Dados brutos e agregados dos 12 pontos com timestamps, métricas sonoras e clima.
4. **Pipeline de Análise em Python (Jupyter / Pandas):** Scripts de limpeza, estatística ($L_{10}$, $L_{90}$), teste de correlação de Pearson/Spearman entre ruído e demanda.
5. **Mapa Interativo Web (Folium / Leaflet):** Publicado no GitHub Pages com visualização espacial dos níveis de ruído em Curitiba.
6. **Relatório Técnico Acadêmico:** Monografia/Artigo documentando hipótese, metodologia, resultados e limitações.

---

## 2. Roteiro da Feira / Demonstração
* **Demonstração ao Vivo:** Estação operando na mesa da banca, exibindo $L_{Aeq}$ no OLED e servindo o dashboard web local no Wi-Fi.
* **Mapa Web Interativo:** Computador/Tablet exibindo os pontos de Curitiba no navegador.
* **Plano B (Redundância):** Vídeo gravado da estação operando em campo caso haja falha de bateria ou interferência no local.
