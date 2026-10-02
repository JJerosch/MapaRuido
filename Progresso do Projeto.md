# 📌 Progresso do Projeto — Mapa de Ruído de Curitiba

> [!abstract] Foto do "Onde estamos agora"
> O [[00 - Índice]] mostra o mapa completo da documentação. Este arquivo indica o estado atual e o próximo passo imediato.

**Fase atual:** Simulação Wokwi & Firmware Base Concluídos → **Próximo: Compra Centralizada do Hardware (T2)**

---

## 🎯 Onde estamos, em uma frase
O escopo, a metodologia de 12 pontos e a lista oficial de componentes super econômica (~R$ 212 total / ~R$ 42,40 por membro) estão fechados e documentados. O **firmware base do ESP32 com auto-teste e WebServer já foi montado e testado no Wokwi**. O próximo passo é **realizar a compra física dos componentes**.

---

## ✅ FASE 0 — Definição de Escopo e Arquitetura (CONCLUÍDA)
- [x] Análise crítica da hipótese e reformulação metodológica híbrida (A+B) → [[01 - Visao Geral e Escopo]]
- [x] Definição de 12 pontos estratificados e protocolo com ponto-âncora → [[02 - Metodologia de Medicao]]
- [x] Definição dos 6 entregáveis e roteiro da banca → [[03 - Entregaveis e Validacao]]
- [x] Lista de componentes e orçamento fechados no cenário super econômico (~R$ 212) → [[01 - Lista de Componentes e Orcamento]]
- [x] Mapa de pinagem e barramentos definidos → [[02 - Montagem e Pinagem]]
- [x] Registro de todas as decisões técnicas fundamentadas (D-01 a D-19) → [[Registro de Decisões]]

---

## 🔜 FASE 1 — Firmware, Simulação e Bancada (EM ANDAMENTO)
- [x] **Setup Wokwi & Firmware Base (T4)** ✅
  - [x] Circuito virtual montado com ESP32, OLED, DHT22 e SD (`diagram.json`)
  - [x] Firmware com rotina de auto-teste no boot (`src/main.cpp`)
  - [x] Servidor Web HTTP local servindo página com dados em tempo real
  - [x] Arquivo de teste web independente (`dashboard_preview.html`)
- [ ] **Compra do Hardware Físico (T2)** ⭐ *(Início do caminho crítico)*
  - [ ] Realizar compra única centralizada no Mercado Livre / loja especializada
- [ ] **Montagem e Leitura I2S Real (T7 / T8)**
  - [ ] Montar circuito na protoboard 830 pontos
  - [ ] Capturar áudio com INMP441 via I2S DMA e aplicar ponderação A

---

## 📅 Marcos do Cronograma

| Marco | Semana | Situação |
|---|---|---|
| Escopo e Metodologia fechados | S1 | ✅ Concluído |
| Simulação Wokwi & Firmware Base | S2 | ✅ Concluído |
| Hardware comprado e entregue | S2 | ⬜ **Próximo** |
| Estação montada e medindo na bancada | S4 | ⬜ |
| Coleta piloto e calibração validadas | S5 | ⬜ |
| 48 medições nos 12 pontos concluídas | S9 | ⬜ |
| Pipeline Python e Mapa Web publicados | S11 | ⬜ |
| Apresentação na Mostra / Feira | S12 | ⬜ |

Detalhamento em [[01 - WBS e Cronograma Geral]] e [[02 - Sprints e Backlog]].
