# 🔊 Mapa de Ruído de Curitiba — Índice do Cofre

Este cofre é a **documentação central e memória viva** do projeto de medição acústica urbana em Curitiba.

> [!important] Quer ver o estado atual e os próximos passos imediatos? → [[Progresso do Projeto]]

---

## 🧭 Estrutura Consolidada do Cofre (4 Pastas)

### 1. 🎯 [[Planejamento]] (O Que e Como Fazer)
* [[01 - Visao Geral e Escopo|01 — Visão Geral e Escopo]]: O projeto em uma frase, a hipótese do proxy acústico e limites do escopo.
* [[02 - Metodologia de Medicao|02 — Metodologia de Medição]]: Os 12 pontos estratificados, o protocolo do ponto-âncora e a contagem manual de fluxo.
* [[03 - Entregaveis e Validacao|03 — Entregáveis e Validação]]: Os 6 produtos finais, roteiro de demonstração da feira e plano de testes.
* [[04 - Guia de Estudos e Referencias|04 — Guia de Estudos e Referências]]: Acústica, $dB(A)$, NBR 10151, repositórios de referência (`esp32-i2s-slm`) e stack de software.

### 2. 📅 [[Cronograma]] (Quando e Quem)
* [[01 - WBS e Cronograma Geral|01 — WBS e Cronograma Geral]]: As 12 semanas do projeto, caminho crítico, divisão de papéis e matriz de riscos.
* [[02 - Sprints e Backlog|02 — Sprints e Backlog]]: Backlog do produto organizado em sprints quinzenais.
* [[03 - Pendencias e Status|03 — Pendências e Status]]: Rastreamento de bloqueios e pendências resolvidas.

### 3. 🔌 [[Hardware]] (Com o Quê)
* [[01 - Lista de Componentes e Orcamento|01 — Lista de Componentes e Orçamento]]: Lista oficial dos 10 itens (~R$ 212 total / ~R$ 42,40 por membro).
* [[02 - Montagem e Pinagem|02 — Montagem e Pinagem]]: Mapeamento de pinos do ESP32 (I2S, SPI, I2C, UART, GPIO) e cuidados de montagem.
* [[03 - Calibracao e Estimativa Acustica|03 — Calibração e Estimativa Acústica]]: Conversão de sensibilidade MEMS ($-26\text{ dBFS}$) para $L_{Aeq}\text{ dB SPL}$.

### 4. ⚖️ [[Decisões]] (Por Quê)
* [[Registro de Decisões]]: Log histórico de todas as decisões técnicas e metodológicas (D-01 a D-19).

---

## 💻 Ambiente de Simulação e Firmware
* [diagram.json](file:///c:/MapaRuido/diagram.json): Circuito virtual no Wokwi (ESP32 + OLED + DHT22 + SD).
* [wokwi.toml](file:///c:/MapaRuido/wokwi.toml): Configuração de execução do simulador Wokwi.
* [platformio.ini](file:///c:/MapaRuido/platformio.ini): Gerenciamento de dependências e compilação em C++.
* [src/main.cpp](file:///c:/MapaRuido/src/main.cpp): Firmware com máquina de estados, auto-teste e WebServer.
* [dashboard_preview.html](file:///c:/MapaRuido/dashboard_preview.html): Visualização web local dos dados em tempo real.
