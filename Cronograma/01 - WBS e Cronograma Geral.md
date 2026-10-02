# 📅 WBS e Cronograma Geral

## 1. Fases e Marcos do Projeto (12 Semanas)

| Fase | Semana | Marco | Entregável Principal |
|:---:|:---:|---|---|
| **F0** | S1 | **Escopo & Arquitetura Fechados** | Cofre estruturado e metodologia definida |
| **F1** | S2 | **Simulação & Firmware Wokwi** | Setup Wokwi, auto-teste e WebServer funcionando |
| **F2** | S3–S4 | **Montagem da Bancada Física** | Hardware montado na protoboard e validado |
| **F3** | S5 | **Piloto em Campo & Calibração** | 1ª coleta piloto no ponto-âncora e validação |
| **F4** | S6–S9 | **Campanha de Coletas (12 Pontos)** | 48 sessões de 10 min em Curitiba + contagem |
| **F5** | S10–S11 | **Análise de Dados & Mapa Web** | Pipeline Python + Mapa interativo GitHub Pages |
| **F6** | S12 | **Apresentação na Mostra / Feira** | Stand com estação ao vivo e relatório final |

---

## 2. Divisão de Responsabilidades (5 Integrantes)
* **Firmware & Hardware ESP32:** Desenvolvimento C++, I2S DMA, sensores e montagem do circuito.
* **Coletas de Campo (Todos):** Operação da estação, contagem manual de ônibus, carros e pedestres.
* **Ciência de Dados (Python):** Limpeza de dados, agregação estatística ($L_{Aeq, 15min}$, $L_{10}$, $L_{90}$) e testes de correlação.
* **Mapeamento & Front-end:** Construção do mapa interativo Folium/Leaflet.
* **Documentação & Relatório:** Escrita do relatório técnico acadêmico e slides da banca.

---

## 3. Principais Riscos e Mitigações
1. **Chuva em dias de coleta:** Medição em pista molhada altera o ruído de rolamento dos pneus. *Mitigação:* Sessões são remarcadas para dias de tempo seco.
2. **Saturação do microfone por vento:** *Mitigação:* Uso obrigatório de windscreen (espuma anti-vento) sobre o INMP441.
3. **Falha de hardware na feira:** *Mitigação:* Vídeo demonstrativo gravado em campo com antecedência.
