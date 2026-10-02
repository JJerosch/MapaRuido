# 🎯 Visão Geral e Escopo do Projeto

## 1. O Projeto em uma Frase
Construção de uma **estação portátil autônoma** baseada em **ESP32 + Microfone I2S (INMP441) + GPS + DHT22** para medir $dB(A)$ em **12 pontos fixos** de Curitiba, gerando um mapa acústico interativo e **testando a hipótese** de que o ruído urbano serve como indicador (*proxy*) de demanda por transporte público.

---

## 2. A Hipótese em Teste (Metodologia Híbrida A + B)
* **Saída A (O Produto):** Mapa de Ruído georreferenciado e interativo de Curitiba (publicado via GitHub Pages com Leaflet/Folium).
* **Saída B (O Teste Científico):** Cruzamento dos níveis de ruído medidos ($L_{Aeq}$) com a contagem manual de fluxo de passageiros e veículos.
* **O Caso do Calçadão da XV de Novembro:** Ponto de controle fundamental — altíssimo fluxo de pedestres/demanda urbana, porém baixo ruído de motores de ônibus/carros. Testa diretamente os limites da hipótese.

---

## 3. O que está DENTRO e FORA do Escopo

| No Escopo (Dentro) | Fora do Escopo (Descartado) |
|---|---|
| 1 estação portátil com operação a pé/tripé | Medição veicular em movimento (evita ruído de cabine e pneu) |
| 12 pontos fixos estratificados por tipologia | Mapeamento contínuo de toda a malha viária da cidade |
| Gravação de dados offline em MicroSD (CSV) | Conectividade 4G em tempo real (custo e obsolescência) |
| Ponto-âncora medido no início/fim de cada sessão | Múltiplas estações simultâneas (orçamento de grupo) |
| Sensor DHT22 para correção acústica ambiental | Decibelímetro comercial de R$ 300 comprado (uso de fórmula de sensibilidade) |
