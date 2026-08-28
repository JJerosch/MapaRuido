# 📋 Backlog do Produto — Mapa de Ruído de Curitiba

43 user stories em 6 épicos, 133 pontos, 255 tarefas — sendo 12 delas as sessões de campo, que não carregam pontos. Visão geral, carga e plano de corte em [[Scrum do Projeto]].

**Legenda das frentes:** 🧩 Coordenação · 💻 Firmware/DSP · 🔧 Hardware/calibração · 🚶 Campo · 📊 Dados/mapa · ✍️ Escrita/apresentação

**Rastreio:** cada story carrega a **Origem** — o ID `T1`–`T21` de [[WBS e Gantt]], ou a pendência `P-xx` de [[Status das Pendências]] que a originou. As 21 tarefas do cofre continuam existindo; este backlog é a forma executável delas.

> [!info] Criado em 28/08/2026, no meio da Sprint 1 · atualizado no mesmo dia com a cotação
> A Sprint 1 (26/08–01/09) **já está correndo**. A `US-14` (cotação) foi concluída; T1 continua sem acontecer. A sprint entra com carga reduzida (7 pts em 4 dias úteis) e só com o que destrava o resto.

> [!danger] O que a cotação mudou
> O decibelímetro classe 2 custa **R$1.400 a R$1.890**, contra os R$180–250 que [[Orçamento em Camadas]] estimava. Ele **sai do orçamento**, e com ele o plano B da calibração. Toda a calibração passa a depender de empréstimo na PUC — por isso a `US-19` saiu da Sprint 5 e foi para a **Sprint 2**. Detalhe em `US-14` e `US-19`.

> [!warning] Três coisas deste backlog são suposição, não fato
> **P-03** — a data da feira segue sem confirmação; o plano assume a Sprint 12 (**11–17/11/2026**).
> **P-14** — as janelas horárias de campo estão em revisão; só a janela da tarde é viável hoje.
> **P-12** — o modelo do ESP32 (WROOM-32 ou S3) ficou **deliberadamente em aberto**, para ser discutido com o professor. Onde esses três aparecem, são premissa.

---

## Índice dos épicos

| Épico | Frente | Stories | Pontos | Tarefas T1–T21 cobertas |
|---|---|---|---|---|
| E1 | 🧩 Coordenação | 5 | 9 | T1 |
| E2 | 💻 Firmware / DSP | 8 | 33 | T4, T5, T7, T8, T19 |
| E3 | 🔧 Hardware / calibração | 7 | 20 | T2, T6, T9, T10 |
| E4 | 🚶 Campo | 7 | 16 | T3, T11, T12, T13 |
| E5 | 📊 Dados / mapa | 9 | 33 | T14, T15, T16, T17, T18 |
| E6 | ✍️ Escrita / apresentação | 7 | 22 | T20, T21 |
| | **Total** | **43** | **133** | **21 de 21** |

---

## E1 — Coordenação

> O que destrava todo o resto: o professor, o dinheiro, o repositório e as datas.

**5 stories · 9 pontos · Sprints 1 a 3**

### US-01 — Alinhar a reformulação com o professor

`Sprint 1` · `3 pts` · 🧩 · 👤 **João** · **Origem: T1** · resolve **P-02**

> Como **equipe**, quero apresentar a reformulação de escopo ao professor e obter uma resposta explícita, para comprar hardware sabendo que o recorte está aceito.

**Critérios de aceite**

- [ ] A conversa começou pelo que **mantém** a proposta dele, não pela crítica
- [ ] O argumento do calçadão da XV foi apresentado como *pergunta interessante*, não como correção
- [ ] Existe resposta explícita registrada: aceito · aceito com ressalvas · recusado
- [ ] O novo título do trabalho foi confirmado com ele
- [ ] O resultado está em [[Registro de Decisões]] com data
- [ ] **P-02** foi fechada em [[Status das Pendências]]

**Tarefas**

- [ ] `US-01.1` Reler [[A Hipótese em Teste]] e montar o roteiro de 5 minutos
- [ ] `US-01.2` Marcar a conversa (presencial, ou e-mail com o argumento escrito)
- [ ] `US-01.3` Apresentar o calçadão da XV como caso concreto
- [ ] `US-01.4` Confirmar o título e o recorte
- [ ] `US-01.5` Registrar a resposta em [[Registro de Decisões]]
- [ ] `US-01.6` Fechar P-02 em [[Status das Pendências]]

### US-02 — Fechar o rateio financeiro e quem compra

`Sprint 1` · `1 pt` · 🧩 · 👤 **Guilherme Falcão** · **Origem: P-07, P-08**

> Como **grupo**, quero o dinheiro acertado antes da compra, para ninguém adiantar R$500 e cobrar depois.

**Critérios de aceite**

- [ ] O valor por pessoa está definido e comunicado aos 5 (~R$100, ver [[Orçamento em Camadas]])
- [ ] Existe **um único responsável pela compra**, nominal
- [ ] Existe prazo de reembolso combinado, não "depois a gente vê"
- [ ] Ficou combinado que **todas as notas fiscais são guardadas** — a feira às vezes pede comprovação de custo
- [ ] **P-07** e **P-08** fechadas

**Tarefas**

- [ ] `US-02.1` Levar o total estimado de [[Orçamento em Camadas]] para o grupo
- [ ] `US-02.2` Definir quem compra (um CPF só, para simplificar frete e rastreio)
- [ ] `US-02.3` Combinar prazo e forma de reembolso
- [ ] `US-02.4` Combinar quem guarda as notas fiscais
- [ ] `US-02.5` Fechar P-07 e P-08

### US-03 — Repositório GitHub com estrutura e README

`Sprint 2` · `2 pts` · 🧩 · 👤 **Arthur** · **Origem: P-09** · sustenta **T18** e o entregável 6

> Como **equipe**, quero o projeto versionado desde antes da primeira linha de firmware, para não reorganizar arquivos soltos na véspera da feira.

**Critérios de aceite**

- [ ] O repositório existe e os 5 membros têm acesso de escrita
- [ ] A árvore é `/firmware`, `/analise`, `/dados` — a estrutura prevista em [[Entregáveis]]
- [ ] O `.gitignore` foi criado **antes** do primeiro commit
- [ ] O README traz título, resumo de uma frase e link para o cofre
- [ ] **GitHub Pages está habilitado** — é onde T18 publica o mapa
- [ ] **P-09** fechada

**Tarefas**

- [ ] `US-03.1` Criar o repositório e convidar os 5
- [ ] `US-03.2` Escrever o `.gitignore` (dados brutos grandes, `__pycache__`, `.DS_Store`)
- [ ] `US-03.3` Criar `/firmware`, `/analise`, `/dados` com `.gitkeep`
- [ ] `US-03.4` Escrever o esqueleto do README
- [ ] `US-03.5` Habilitar GitHub Pages e confirmar que uma página vazia abre
- [ ] `US-03.6` Fechar P-09

### US-04 — Confirmar a data da feira e reancorar o cronograma

`Sprint 2` · `1 pt` · 🧩 · 👤 **Gustavo Juks** · **Origem: P-03**

> Como **equipe**, quero a data real da feira, para parar de planejar em cima de uma suposição que desloca 12 sprints se estiver errada.

**Critérios de aceite**

- [ ] A data (ou a semana) da feira está confirmada por fonte oficial — coordenação, edital ou o professor
- [ ] Se for diferente de 11–17/11/2026, [[Plano de Sprints]] e [[WBS e Gantt]] foram reancorados **na mesma semana**
- [ ] O critério de avaliação está confirmado por escrito: **demo ao vivo, relatório entregue e arguição oral**
- [ ] **P-03** fechada

**Tarefas**

- [ ] `US-04.1` Perguntar à coordenação ou ao professor a data e o formato
- [ ] `US-04.2` Confirmar o que pontua e com que peso
- [ ] `US-04.3` Se a data mudou, deslocar as sprints em [[Plano de Sprints]]
- [ ] `US-04.4` Atualizar a âncora em [[WBS e Gantt]] e em [[Progresso do Projeto]]
- [ ] `US-04.5` Fechar P-03

### US-05 — Fechar as 12 datas de campo com confirmação nominal

`Sprint 3` · `2 pts` · 🧩 · 👤 **Guilherme Falcão** · **Origem: P-06** · habilita **T13**

> Como **equipe**, quero as 12 sessões marcadas no calendário com o nome de quem vai, para descobrir agora — e não em outubro — que as 5 agendas não fecham.

> [!danger] Prazo duro: fim da Sprint 3 (15/09/2026)
> [[Alocação do Grupo]] e [[Riscos]] chamam isso de risco mais subestimado do projeto. Não é problema de esforço, é problema de agenda de 5 universitários.

**Critérios de aceite**

- [ ] As 12 datas estão num calendário compartilhado, cada uma com os **5 nomes confirmados**
- [ ] Existem **2 datas de reserva** para chuva ([[Registro de Decisões|D-12]])
- [ ] Cada sessão tem motorista definido, ponto de encontro e horário de saída
- [ ] Está definido quem imprime as planilhas antes de cada sessão
- [ ] A decisão de janela horária (**P-14**) está refletida no horário marcado
- [ ] **P-06** fechada

**Tarefas**

- [ ] `US-05.1` Levantar a grade de aula e os compromissos fixos dos 5
- [ ] `US-05.2` Propor as 12 datas dentro da janela viável
- [ ] `US-05.3` Obter confirmação nominal de cada um, por escrito
- [ ] `US-05.4` Marcar as 2 datas de reserva
- [ ] `US-05.5` Definir motorista, ponto de encontro e horário por sessão
- [ ] `US-05.6` Publicar o calendário e fechar P-06

---

## E2 — Firmware / DSP

> A estação transforma pressão sonora em CSV. É onde estão três das quatro tarefas de dificuldade Alta do projeto.

**8 stories · 33 pontos · Sprints 2 a 9**

> [!warning] Este é o épico mais pesado e o que menos gente consegue pegar
> Só 2 pessoas do grupo conseguem tocar T5, T7 e T8. Ver a análise de gargalo em [[Scrum do Projeto]].

### US-06 — Esqueleto do firmware no Wokwi

`Sprint 2` · `5 pts` · 💻 · 👤 **João** · **Origem: T4** · aplica **D-13**

> Como **equipe sem hardware na mão**, quero o firmware rodando no simulador, para chegar na bancada com código pronto em vez de começar do zero quando as peças chegarem.

**Critérios de aceite**

- [ ] O projeto Wokwi abre com ESP32 + SD + OLED SSD1306 + RTC DS3231
- [ ] O RTC entrega data e hora formatadas
- [ ] O OLED mostra a tela de campo: nível, ponto, tempo decorrido
- [ ] O firmware escreve uma linha por medição no cartão e **fecha o arquivo** a cada escrita
- [ ] Existe máquina de estados: ocioso → medindo → gravando → ocioso
- [ ] O link do projeto Wokwi está no README do repositório

**Tarefas**

- [ ] `US-06.1` Montar o circuito no Wokwi (ver [[Wokwi e Firmware]])
- [ ] `US-06.2` Ler e formatar a hora do DS3231 (I2C)
- [ ] `US-06.3` Desenhar a tela de campo no SSD1306
- [ ] `US-06.4` Escrever e ler arquivo no cartão SD (SPI, FAT32)
- [ ] `US-06.5` Implementar a máquina de estados da sessão
- [ ] `US-06.6` Tratar erro de cartão ausente sem travar o loop
- [ ] `US-06.7` Commitar em `/firmware` e linkar no README

### US-07 — Congelar o formato do CSV da estação

`Sprint 2` · `2 pts` · 💻 · 👤 **João** · **Origem: T4**

> Como **pipeline de dados**, quero o formato do arquivo definido antes de existir dado, para não descobrir em S9 que falta uma coluna em 48 medições.

**Critérios de aceite**

- [ ] O cabeçalho está congelado: `timestamp_iso, ponto_id, sessao_id, laeq_db, lmax_db, l10_db, l90_db, amostras, temp_c, obs`
- [ ] `sessao_id` e `ponto_id` casam com os campos da planilha de [[Contagem Manual]] — é a chave que junta os dois conjuntos
- [ ] O ponto-âncora é gravado com `ponto_id` reservado e reconhecível
- [ ] Existe arquivo de exemplo commitado em `/dados`
- [ ] O formato está documentado em [[Protocolo de Medição]]

**Tarefas**

- [ ] `US-07.1` Conferir o cabeçalho contra [[Protocolo de Medição]]
- [ ] `US-07.2` Definir o `ponto_id` reservado da âncora
- [ ] `US-07.3` Definir a convenção de `sessao_id`
- [ ] `US-07.4` Gerar um CSV de exemplo com 5 linhas e commitar
- [ ] `US-07.5` Registrar o formato congelado no cofre

### US-08 — Filtro de ponderação A no desktop

`Sprint 3` · `5 pts` · 💻 · 👤 **João** · **Origem: T5** · dificuldade **Alta**

> Como **estação de medição**, quero aplicar a ponderação A ao sinal, para produzir dB(A) e não dB puro — que é o descritor que norma e literatura usam.

> [!danger] A tarefa mais difícil do projeto começa aqui
> [[Ponderação A e LAeq]] manda começar cedo e validar no desktop **antes** de portar. Depurar DSP dentro do microcontrolador, sem inspecionar o sinal, é muito mais lento.

**Critérios de aceite**

- [ ] O filtro roda no desktop sobre um arquivo WAV, sem hardware
- [ ] A resposta em frequência do filtro implementado foi comparada com a curva de ponderação A de referência
- [ ] A diferença aceita foi **definida e registrada** como número, não como "ficou parecido"
- [ ] O código está em `/analise`, com o WAV de teste em `/dados`

**Tarefas**

- [ ] `US-08.1` Estudar [[Ponderação A e LAeq]] e escolher a forma de implementação
- [ ] `US-08.2` Implementar o filtro no desktop
- [ ] `US-08.3` Gerar tons puros de teste em frequências conhecidas
- [ ] `US-08.4` Levantar a resposta do filtro e comparar com a curva de referência
- [ ] `US-08.5` Registrar a tolerância aceita
- [ ] `US-08.6` Commitar em `/analise`

### US-09 — LAeq, Lmax, L10 e L90 validados contra WAV

`Sprint 4` · `5 pts` · 💻 · 👤 **João** · **Origem: T5** · dificuldade **Alta**

> Como **relatório**, quero os quatro descritores calculados corretamente, para poder afirmar um número em dB(A) sem que a banca o derrube.

**Critérios de aceite**

- [ ] `LAeq`, `Lmax`, `L10` e `L90` são calculados a partir do sinal ponderado em A
- [ ] A média é **energética**, nunca aritmética — ver o aviso em [[Acústica e dB(A)]]
- [ ] O resultado foi comparado com uma implementação de referência sobre o mesmo WAV
- [ ] A diferença encontrada foi anotada **com o número**, conforme [[Verificação]] item 2
- [ ] O cálculo roda sobre uma janela de 10 minutos ([[Registro de Decisões|D-11]])

**Tarefas**

- [ ] `US-09.1` Implementar RMS e integração no tempo
- [ ] `US-09.2` Implementar os percentis L10 e L90
- [ ] `US-09.3` Conferir que a média de dB é energética
- [ ] `US-09.4` Rodar contra o WAV de referência e comparar
- [ ] `US-09.5` Anotar o número da diferença em [[Verificação]]
- [ ] `US-09.6` Testar com janela de 10 min

### US-10 — INMP441 lendo I2S com RMS estável

`Sprint 5` · `5 pts` · 💻 · 👤 **João** · **Origem: T7** · dificuldade **Alta**

> Como **operador**, quero o microfone entregando amostras reais na bancada, para saber que existe sinal antes de investir em DSP embarcado.

**Critérios de aceite**

- [ ] O ESP32 lê amostras I2S do INMP441 sem `NaN` e sem valor constante
- [ ] Teste de [[Verificação]] item 1 passa: silêncio → palma → música → silêncio, e o valor **volta ao repouso**
- [ ] O RMS em silêncio é estável — oscilação em silêncio é piso de ruído ou aterramento ruim
- [ ] A pinagem usada foi preenchida na tabela de [[Montagem e Ligações]]

**Tarefas**

- [ ] `US-10.1` Estudar [[ESP32 e I2S]] e conferir o pino L/R
- [ ] `US-10.2` Configurar o periférico I2S e imprimir amostras cruas
- [ ] `US-10.3` Calcular RMS por bloco e imprimir
- [ ] `US-10.4` Rodar o teste silêncio → palma → música → silêncio
- [ ] `US-10.5` Diagnosticar leitura de zeros, se ocorrer (L/R, WS/SCK trocados)
- [ ] `US-10.6` Preencher a pinagem em [[Montagem e Ligações]]

### US-11 — DSP no ESP32 gravando CSV no microSD

`Sprint 6` · `5 pts` · 💻 · 👤 **João** · **Origem: T8** · dificuldade **Alta**

> Como **estação**, quero calcular os descritores a bordo e gravar no cartão, para produzir em campo o arquivo que o pipeline espera.

**Critérios de aceite**

- [ ] O filtro validado na US-08 roda no ESP32 sem estourar o tempo real
- [ ] Uma medição de 10 min gera **uma linha** no CSV, no formato congelado da US-07
- [ ] O OLED mostra o nível se movendo durante a medição
- [ ] O valor a bordo bate com o cálculo do desktop sobre a mesma entrada, dentro da tolerância registrada

**Tarefas**

- [ ] `US-11.1` Portar o filtro de ponderação A para o ESP32
- [ ] `US-11.2` Integrar RMS e percentis no loop de aquisição
- [ ] `US-11.3` Medir o tempo de processamento por bloco e confirmar que sobra folga
- [ ] `US-11.4` Gravar a linha de CSV ao fim da janela de 10 min
- [ ] `US-11.5` Comparar o resultado a bordo com o do desktop
- [ ] `US-11.6` Exibir o nível ao vivo no OLED

### US-12 — O dado sobrevive a queda de energia

`Sprint 6` · `3 pts` · 💻 · 👤 **João** · **Origem: T8** · [[Verificação]] item 4

> Como **grupo que só tem um cartão de memória**, quero garantir que puxar o cabo não corrompe o arquivo, para não perder uma sessão de campo inteira por causa de um arquivo truncado.

> [!danger] É o teste que ninguém faz e todo mundo se arrepende
> [[Registro de Decisões|D-08]] fez do cartão um ponto único de falha. Perder uma sessão por arquivo corrompido é o pior fracasso possível deste projeto — e é totalmente evitável.

**Critérios de aceite**

- [ ] A estação foi desligada **na tomada** no meio de uma gravação, pelo menos 3 vezes
- [ ] O arquivo da medição anterior está íntegro e legível nas 3 vezes
- [ ] O arquivo é fechado a cada linha escrita, não só no fim da sessão
- [ ] O resultado foi anotado em [[Verificação]]

**Tarefas**

- [ ] `US-12.1` Garantir `flush`/`close` a cada linha gravada
- [ ] `US-12.2` Executar 3 desligamentos abruptos no meio da gravação
- [ ] `US-12.3` Abrir os arquivos e conferir integridade
- [ ] `US-12.4` Testar cartão ausente e cartão cheio
- [ ] `US-12.5` Anotar o resultado em [[Verificação]]

### US-13 — Modo demo: dB ao vivo via HTTP e OLED

`Sprint 9` · `3 pts` · 💻 · 👤 **João** · **Origem: T19** · entregável 1

> Como **visitante do stand**, quero falar perto do microfone e ver o número subir, para entender em 15 segundos o que o projeto faz.

> [!tip] É o ímã do stand e o gancho do pitch
> [[Roteiro da Feira]] abre com "fala perto do microfone". Sem isso, o stand começa por uma explicação em vez de uma demonstração.

**Critérios de aceite**

- [ ] O OLED mostra dB(A) atualizando pelo menos 2× por segundo
- [ ] O ESP32 sobe um servidor HTTP servindo o valor atual
- [ ] A página abre no celular pela rede local, sem instalar nada
- [ ] A estação entra em modo demo **em menos de 1 minuto** desde ligar ([[Verificação]] item 8)
- [ ] O modo demo não interfere no modo de medição

**Tarefas**

- [ ] `US-13.1` Reaproveitar o que foi aprendido no SIA-C sobre servidor HTTP no ESP32
- [ ] `US-13.2` Servir o valor atual numa página simples que se atualiza sozinha
- [ ] `US-13.3` Separar modo demo de modo medição na máquina de estados
- [ ] `US-13.4` Medir o tempo de boot até mostrar número
- [ ] `US-13.5` Testar num celular alheio

---

## E3 — Hardware / calibração

> Comprar, montar e transformar número relativo em dB SPL de verdade.

**7 stories · 20 pontos · Sprints 1 a 7**

> [!danger] Este épico mudou depois da cotação de 28/08/2026
> O decibelímetro classe 2 saiu do orçamento (R$1.400+ contra teto de R$500). `US-19` foi antecipada da Sprint 5 para a **Sprint 2** e virou o maior risco isolado do projeto: sem empréstimo na PUC, não existe calibração absoluta.

### US-14 — Cotação e fechamento do modelo de ESP32 e decibelímetro ✅

`Sprint 1` · `3 pts` · 🔧 · 👤 **João** · **Origem: T2** · resolve **P-01** e **P-13** · **P-12 segue aberta**

> Como **comprador**, quero preços reais em mãos, para decidir entre WROOM-32 e S3 com número, e não com preferência.

> [!success] Concluída em 28/08/2026
> A cotação está em `Projeto - Estação Portátil de Ruído.docx`. Fecha **P-01** e responde as seis perguntas técnicas. Mas derrubou uma premissa do orçamento — ver o alerta abaixo.

> [!danger] O decibelímetro classe 2 custa ~7× o que o cofre estimava
> [[Orçamento em Camadas]] previa **R$180–250**. O preço real de um classe 2 com certificado é **R$1.400** (Minipa MSL-1325A) ou **R$1.890** (Instrutherm DEC-490). A estimativa antiga era o preço de decibelímetro genérico, que **não é classe 2 e não tem certificado** — ou seja, a especificação nunca havia sido precificada.
>
> **Consequência:** o instrumento de referência **sai do orçamento**. [[Registro de Decisões|D-07]] previa calibração por transferência contra um classe 2 comprado; isso não é mais possível dentro de R$500. Toda a calibração passa a depender de empréstimo — ver `US-19`.

**O que a cotação fechou**

| Achado | Valor |
|---|---|
| Carrinho completo, com ESP32-S3, sem decibelímetro | **R$398** (frete R$10) |
| Carrinho com WROOM-32, sem tripé nem caixa | **R$335** (frete R$0) |
| Sensibilidade do INMP441 (datasheet InvenSense/TDK) | **−26 dBFS ±3 dB @ 1 kHz / 94 dB SPL** |
| Ponto de sobrecarga acústica (AOP) do INMP441 | **120 dB SPL** — acima disso, clipping |
| Level shifter entre INMP441 e ESP32 | **Não é necessário** (1,8–3,3 V) |
| Alimentação do módulo microSD | ⚠️ **5V/VIN**, não 3V3 — o AMS1117 do módulo derruba a tensão e o cartão falha |
| Aluguel de calibrador acústico | ~**R$200/diária** (CAL-5000, 94/114 dB @ 1 kHz) |
| Estratégia de frete | Carrinho único no Mercado Livre Full = frete R$0; comprar em 6 lojas somaria >R$150 |

**Critérios de aceite**

- [x] O prompt de cotação de [[Lista de Componentes]] foi rodado e as respostas estão registradas
- [ ] Os valores reais substituíram as estimativas em [[Orçamento em Camadas]] — *pendente da padronização do cofre*
- [ ] **P-12** decidida: WROOM-32 ou ESP32-S3 — ⚠️ **deliberadamente em aberto**, será discutida com o professor
- [x] **P-13** encerrada: o decibelímetro **não será comprado**, por preço
- [x] O total cabe em R$500 — R$398 no cenário completo, **desde que o decibelímetro fique de fora**
- [x] Confirmado no datasheet do INMP441: sensibilidade e ponto de sobrecarga acústica
- [x] **P-01** fechada

**Tarefas**

- [x] `US-14.1` Rodar o prompt de cotação de [[Lista de Componentes]]
- [ ] `US-14.2` Preencher os preços reais em [[Orçamento em Camadas]]
- [ ] `US-14.3` Comparar WROOM-32 × S3 — ⚠️ **levar as duas opções ao professor** (P-12)
- [x] `US-14.4` Decibelímetro: descartado da compra por preço (P-13)
- [ ] `US-14.5` Registrar a sensibilidade do INMP441 em [[Calibração]]
- [x] `US-14.6` Conferir se o total cabe em R$500 — cabe, sem o decibelímetro
- [x] `US-14.7` Fechar P-01; P-13 encerrada; P-12 mantida aberta de propósito
- [ ] `US-14.8` Corrigir a regra de alimentação do microSD em [[Montagem e Ligações]] — é 5V/VIN, não 3V3

### US-15 — Compra efetivada

`Sprint 2` · `1 pt` · 🔧 · 👤 **Guilherme Falcão** · **Origem: T2** · **início do caminho crítico**

> Como **projeto**, quero o pedido feito, para o relógio de 3 a 10 dias de entrega começar a correr o quanto antes.

> [!danger] Espera de entrega não é trabalho e não tem pontos
> A story vale 1 ponto porque comprar leva 20 minutos. O que custa é o **calendário**: 3 a 10 dias em que ninguém consegue acelerar nada. Ver [[Scrum do Projeto]].

**Critérios de aceite**

> [!warning] Bloqueada por uma decisão que não é do grupo
> O modelo do ESP32 (**P-12**) ficou **deliberadamente em aberto** para ser discutido com o professor. A compra não fecha antes disso — mas também não pode esperar muito, porque é o início do caminho crítico. Levar as duas opções na conversa de `US-01`.

**O carrinho, conforme a cotação de `US-14`**

| | Com ESP32-S3 | Com WROOM-32 |
|---|---|---|
| Total com frete | **R$398** | **R$365** |
| Onde | Carrinho único no Mercado Livre Full, exceto o cartão microSD (Amazon) e a espuma (Shopee) | idem |

**Critérios de aceite**

- [ ] **P-12 decidida** com o professor antes de fechar o carrinho
- [ ] O pedido foi feito em loja nacional, por um único CPF
- [ ] O grosso do pedido foi consolidado num **carrinho único no Mercado Livre Full**, para zerar o frete — comprar espalhado em 6 lojas somaria >R$150 de frete
- [ ] O cartão microSD SanDisk foi comprado **na Amazon, vendido e entregue pela Amazon** — falsificação de cartão corrompe log em campo
- [ ] **2 unidades do INMP441** foram compradas — é a peça mais crítica e a mais frágil ([[Riscos]])
- [ ] O cabo USB é **de dados** e tem o conector certo para o DevKit escolhido (USB-C no S3, micro-USB no WROOM-32)
- [ ] Nada foi comprado na UsinaInfo — a cotação alerta para atrasos superiores a 7 dias para Curitiba
- [ ] O número de rastreio está registrado e compartilhado com o grupo
- [ ] A data prevista de entrega está anotada em [[Progresso do Projeto]]
- [ ] As notas fiscais foram guardadas

**Tarefas**

- [ ] `US-15.1` Fechar P-12 com o professor
- [ ] `US-15.2` Montar o carrinho consolidado no Mercado Livre Full
- [ ] `US-15.3` Comprar o cartão microSD à parte, na Amazon
- [ ] `US-15.4` Comprar a espuma anti-vento (Shopee ou loja de áudio)
- [ ] `US-15.5` Comprar e guardar todas as notas fiscais
- [ ] `US-15.6` Registrar rastreio e data prevista
- [ ] `US-15.7` Avisar o grupo e cobrar o reembolso combinado na US-02

### US-16 — Recebimento, inventário e montagem em protoboard

`Sprint 4` · `5 pts` · 🔧 · 👤 **Guilherme Conde** · **Origem: T6**

> Como **grupo sem experiência com ESP32 físico**, quero montar um módulo por vez, para saber exatamente qual peça quebrou quando algo não funcionar.

**Critérios de aceite**

- [ ] Todas as peças do pedido foram conferidas contra a nota e nada falta
- [ ] A tensão 3V3 foi conferida **com multímetro** antes de energizar qualquer módulo
- [ ] A ordem de [[Montagem e Ligações]] foi seguida: ESP32 → OLED → RTC → microSD → INMP441
- [ ] Cada etapa passou antes da seguinte começar
- [ ] O RTC mantém a hora depois de desligar e religar (teste da bateria)
- [ ] O cartão foi formatado em FAT32 e um arquivo de teste foi escrito e lido
- [ ] Foto da montagem tirada e commitada

**Tarefas**

- [ ] `US-16.1` Conferir o pedido item a item contra a nota fiscal
- [ ] `US-16.2` Medir 3V3 e VIN com multímetro e anotar a serigrafia da placa
- [ ] `US-16.3` Blink só com o ESP32, com cabo **de dados**
- [ ] `US-16.4` Ligar o OLED e mostrar um "Hello" (I2C)
- [ ] `US-16.5` Ligar o RTC, acertar a hora e testar o desliga-religa
- [ ] `US-16.6` Ligar o microSD e escrever/ler um arquivo (FAT32)
- [ ] `US-16.7` Ligar o INMP441 e confirmar que chegam bits
- [ ] `US-16.8` Fotografar a montagem e commitar

### US-17 — Montagem física: caixa, windscreen e tripé

`Sprint 5` · `3 pts` · 🔧 · 👤 **Guilherme Conde** · **Origem: T10**

> Como **operador em campo**, quero a estação num corpo rígido em cima do tripé, para o dado não depender de nenhum fio balançando.

**Critérios de aceite**

- [ ] O microfone fica **fora da caixa**, com windscreen — microfone dentro de caixa fechada mede a caixa
- [ ] O furo do microfone está vedado contra chuva leve sem obstruir a porta acústica do MEMS
- [ ] Nenhum fio fica solto: tudo preso com abraçadeira ou cola quente depois de validado
- [ ] O cartão SD é acessível sem abrir a caixa
- [ ] O display fica visível com a caixa fechada
- [ ] A estação fixa no tripé e chega a **1,3–1,5 m** do solo

**Tarefas**

- [ ] `US-17.1` Furar a caixa para microfone, cabo e visor
- [ ] `US-17.2` Montar o microfone externo com o windscreen
- [ ] `US-17.3` Vedar o furo sem tampar a porta acústica
- [ ] `US-17.4` Prender os fios e revalidar cada módulo depois de fechar
- [ ] `US-17.5` Resolver a fixação no tripé (rosca 1/4" ou braçadeira)
- [ ] `US-17.6` Conferir a altura de 1,3–1,5 m

### US-18 — Autonomia de 3 horas no power bank

`Sprint 6` · `2 pts` · 🔧 · 👤 **Guilherme Conde** · **Origem: T10** · [[Verificação]] item 5

> Como **grupo em campo**, quero saber que a bateria aguenta a sessão inteira, para não descobrir isso no terceiro ponto de uma saída de sábado.

**Critérios de aceite**

- [ ] A estação mediu **3 horas contínuas** alimentada só pelo power bank
- [ ] Nenhum reinício e nenhum brownout no período
- [ ] O arquivo gerado nas 3 horas está íntegro
- [ ] O resultado foi anotado com o número em [[Verificação]]

**Tarefas**

- [ ] `US-18.1` Carregar o power bank e iniciar a medição de 3h
- [ ] `US-18.2` Registrar quedas, reinícios e consumo aproximado
- [ ] `US-18.3` Abrir o arquivo e conferir a continuidade dos timestamps
- [ ] `US-18.4` Anotar o resultado em [[Verificação]]

### US-19 — Conseguir o instrumento de referência emprestado

`Sprint 2` · `1 pt` · 🔧 · 👤 **Guilherme Conde** · **Origem: T9** · resolve **P-05** · 🔴 **dependência externa sem plano B financiado**

> Como **responsável pela calibração**, quero descobrir o quanto antes se a PUC empresta um instrumento de referência, porque **não existe mais alternativa comprada** se a resposta for não.

> [!danger] Esta story virou o maior risco isolado do projeto
> No plano original ela era confortável: perguntar era bom, mas havia um decibelímetro classe 2 comprado como plano B. **A cotação eliminou esse plano B** — o instrumento custa R$1.400 a R$1.890, contra um orçamento total de R$500 (`US-14`).
>
> Hoje, se a PUC não emprestar, o projeto **não tem como produzir dB SPL absoluto**. Por isso a story saiu da Sprint 5 e foi para a **Sprint 2**: são cinco sprints de antecedência até a calibração, e é a única folga que existe para arrumar outra saída.

**Critérios de aceite**

- [ ] O laboratório de física **e** o de engenharia da PUC foram perguntados, com nome de quem respondeu em cada um
- [ ] A pergunta cobriu as **duas** possibilidades: calibrador acústico (pistonfone 94 dB @ 1 kHz) **ou** decibelímetro classe 2 emprestado
- [ ] Existe resposta clara de cada um: empresta · não empresta · empresta com condição
- [ ] Se emprestar: marca, modelo, condições e **data de disponibilidade** anotados em [[Calibração]]
- [ ] Se emprestar com data marcada: a data é **posterior** ao fechamento da caixa e do windscreen (`US-17`), porque a calibração precisa ser feita com a estação montada
- [ ] Se **ninguém** emprestar: a decisão de contingência foi tomada e registrada, escolhendo entre as três saídas da tabela abaixo — **e não empurrada para a frente**
- [ ] **P-05** fechada

**Se a resposta for não — as três saídas, com o custo de cada uma**

| Saída | Como cabe em R$500 | O que se perde |
|---|---|---|
| **Alugar calibrador por 1 diária** (~R$200) | Só cortando: WROOM-32 em vez do S3 (−R$33), sem tripé (−R$55), sem caixa ABS (−R$25) → R$285 + R$200 = **R$485** | Tripé improvisado e caixa improvisada. A calibração fica **melhor** que a original: 94 dB rastreável em vez de transferência |
| **Decibelímetro genérico** (~R$150–250) | Cabe, cortando o tripé | Não é classe 2 e não tem certificado. A limitação do relatório fica muito mais pesada |
| **Entregar em nível relativo** | Custo zero | É o plano B de [[Riscos]]. Perde o que separa o projeto de um sensor de barulho — e a arguição vai perguntar |

**Tarefas**

- [ ] `US-19.1` Identificar a quem perguntar no laboratório de física e no de engenharia
- [ ] `US-19.2` Perguntar por calibrador acústico / pistonfone 94 dB @ 1 kHz
- [ ] `US-19.3` Perguntar também por decibelímetro classe 2 emprestado
- [ ] `US-19.4` Perguntar ao professor se ele conhece outro caminho (contato em laboratório, empresa, outro curso)
- [ ] `US-19.5` Registrar cada resposta e o nome do contato em [[Calibração]]
- [ ] `US-19.6` Se não houver empréstimo, decidir a contingência **na mesma sprint** e registrar em [[Registro de Decisões]]
- [ ] `US-19.7` Fechar P-05

### US-20 — Calibração por transferência com R² > 0,95

`Sprint 7` · `5 pts` · 🔧 · 👤 **Guilherme Conde** · **Origem: T9** · [[Verificação]] item 3

> Como **trabalho acadêmico**, quero a estação medindo em dB SPL absoluto, para o número ser comparável com norma e literatura em vez de ser "o valor subiu".

> [!warning] Esta story depende inteiramente de `US-19`
> O instrumento de referência **não está comprado** e não cabe no orçamento. Se a Sprint 2 fechar sem empréstimo confirmado e sem contingência decidida, esta story não tem como começar — e o projeto entrega em nível relativo por omissão, não por decisão.
>
> Se a saída escolhida for o **calibrador acústico** em vez do decibelímetro, o procedimento muda: passa a ser calibração de **um ponto** a 94 dB, muito mais simples e rastreável. Ainda assim faça as comparações em 3 níveis para verificar linearidade — é o que [[Calibração]] já previa.

**Critérios de aceite**

- [ ] Estação e instrumento de referência mediram **simultaneamente**, lado a lado, mesma altura e mesma distância da fonte
- [ ] Foram cobertos **≥3 níveis distintos** (~35, ~60 e ~75 dB(A))
- [ ] Várias leituras por nível, usando a média
- [ ] A regressão estação × referência é **linear com R² > 0,95**
- [ ] O offset (e o ganho, se a inclinação não for 1) virou constante no firmware
- [ ] A validação foi **repetida depois** de fechar a caixa e pôr o windscreen
- [ ] As limitações de [[Calibração]] estão escritas para entrar no relatório

**Tarefas**

- [ ] `US-20.1` Preparar os 3 ambientes de nível distinto
- [ ] `US-20.2` Medir simultaneamente e registrar os pares
- [ ] `US-20.3` Ajustar a reta e calcular o R²
- [ ] `US-20.4` Investigar não-linearidade, se houver (saturação, piso de ruído, posicionamento)
- [ ] `US-20.5` Gravar a constante de calibração no firmware
- [ ] `US-20.6` Repetir a validação com caixa fechada e windscreen
- [ ] `US-20.7` Anotar o R² obtido em [[Verificação]]

---

## E4 — Campo

> Onde o dado nasce. É também o único épico em que o gargalo é agenda, não trabalho.

**7 stories · 16 pontos · Sprints 2 a 11**

### US-43 — Reunião de definição dos 12 pontos e da rota

`Sprint 2` · `2 pts` · 🚶 · 👤 **time inteiro** · **Origem: T3** · resolve **P-17**

> Como **quem vai dirigir no reconhecimento**, quero os 12 pontos e a rota decididos em grupo antes de sair, para não passar o dia rodando Curitiba sem saber para onde ir.

> [!important] Esta reunião vem antes do reconhecimento, não durante
> [[Amostra Estratificada]] define as **6 tipologias** e dá exemplos, mas **não define os 12 pontos**. Escolher no dia, dentro do carro, é como se perde uma tarde e se volta com ficha incompleta. A escolha é decisão de grupo; a visita é execução.

**Critérios de aceite**

- [ ] Os 12 pontos candidatos estão escolhidos: **6 tipologias × 2 pontos**, conforme [[Amostra Estratificada]]
- [ ] Cada candidato tem endereço de referência e coordenada aproximada, marcados num mapa compartilhado
- [ ] As **tipologias 3 e 4** estão cobertas com folga — são o par que sustenta o argumento e as últimas a sair em qualquer corte
- [ ] O calçadão da XV está entre eles ([[Registro de Decisões|D-10]])
- [ ] A rota está **agrupada por região**, para o carro não cruzar a cidade duas vezes
- [ ] Existe pelo menos **1 candidato reserva por tipologia**, para o caso de o ponto reprovar nos critérios em campo
- [ ] A data do reconhecimento está marcada e **quem dirige está definido**
- [ ] **P-17** fechada

**Tarefas**

- [ ] `US-43.1` Levantar candidatos por tipologia a partir de [[Amostra Estratificada]]
- [ ] `US-43.2` Marcar todos num mapa compartilhado, com endereço de referência
- [ ] `US-43.3` Conferir que as tipologias 3 e 4 estão bem cobertas
- [ ] `US-43.4` Escolher 1 reserva por tipologia
- [ ] `US-43.5` Agrupar por região e desenhar a rota do carro
- [ ] `US-43.6` Marcar a data do reconhecimento e definir quem dirige
- [ ] `US-43.7` Fechar P-17

### US-21 — Reconhecimento e ficha dos 12 pontos

`Sprint 3` · `4 pts` · 🚶 · 👤 **Guilherme Falcão + time** · **Origem: T3**

> Como **grupo**, quero cada ponto visitado e fichado antes da primeira medição, para não improvisar posicionamento no dia e perder a comparabilidade entre pontos.

> [!note] A escolha dos pontos já aconteceu na `US-43`
> Esta story é a **visita**: aplicar os critérios em campo, fichar e fotografar. Se um candidato reprovar nos critérios, use o reserva definido na reunião em vez de escolher outro na hora.

**Critérios de aceite**

- [ ] Os 12 pontos definidos na `US-43` foram **visitados**
- [ ] Cada ponto passou nos 6 critérios de escolha (≥2 m de refletor, sem fonte atípica, espaço para tripé, seguro para 5 pessoas, acessível)
- [ ] Candidato que reprovou foi substituído pelo **reserva da mesma tipologia**, e a troca ficou registrada
- [ ] Cada ponto tem ficha completa: ID, tipologia, endereço, coordenada, distância à via, refletor mais próximo, foto e observações
- [ ] A **linha imaginária de contagem** de cada ponto está definida por referência física ([[Contagem Manual]])
- [ ] As fichas e fotos estão em `/dados`

**Tarefas**

- [ ] `US-21.2` Visitar e aplicar os 6 critérios de [[Amostra Estratificada]]
- [ ] `US-21.3` Registrar coordenada pelo celular, com média de leituras
- [ ] `US-21.4` Medir e anotar distância à via e ao refletor mais próximo
- [ ] `US-21.5` Definir a linha de contagem de pedestres e veículos por ponto
- [ ] `US-21.6` Fotografar cada ponto e o entorno
- [ ] `US-21.7` Preencher as 12 fichas e commitar em `/dados`

### US-22 — Ponto-âncora escolhido e registrado

`Sprint 4` · `2 pts` · 🚶 · 👤 **Guilherme Falcão** · **Origem: T3, P-04** · aplica **D-04**

> Como **pipeline de normalização**, quero um ponto de referência fixo definido, para poder comparar uma sessão de terça com uma de sábado.

> [!danger] Sem âncora, nenhuma sessão pode acontecer
> [[Registro de Decisões|D-04]] é inegociável: sessão sem âncora é sessão perdida. Esta story **bloqueia** o piloto e as 12 coletas.

**Critérios de aceite**

- [ ] O local é central em relação às rotas, para não custar deslocamento
- [ ] O ruído do local é **estável e previsível** — nem parque silencioso, nem via expressa caótica
- [ ] É acessível em qualquer horário e clima
- [ ] A **posição exata** está marcada com foto e coordenada, para ser repetida sem dúvida
- [ ] O `ponto_id` reservado da US-07 está associado a ele
- [ ] **P-04** fechada

**Tarefas**

- [ ] `US-22.1` Levantar 2 ou 3 candidatos pelos critérios de [[Amostra Estratificada]]
- [ ] `US-22.2` Medir o candidato em dois horários diferentes para checar estabilidade
- [ ] `US-22.3` Escolher e fotografar a posição exata
- [ ] `US-22.4` Registrar coordenada e associar ao `ponto_id` reservado
- [ ] `US-22.5` Fechar P-04

### US-23 — Coleta piloto: o ciclo inteiro em 1 ponto

`Sprint 7` · `3 pts` · 🚶 · 👤 **time inteiro** · **Origem: T11** · [[Verificação]] item 6

> Como **grupo**, quero levar um único ponto do microfone até o mapa, para descobrir com 1 medição o que custaria refazer com 48.

> [!important] Se o dado não atravessa o pipeline com 1 ponto, não vai atravessar com 48
> O piloto existe para descobrir que falta uma coluna no CSV, que o `sessao_id` não bate, ou que a planilha não junta com o dado da estação. Descobrir isso agora custa um ajuste; descobrir em outubro custa refazer.

**Critérios de aceite**

- [ ] Sessão completa com âncora no início **e** no fim
- [ ] Medição de 10 min com os 5 papéis ocupados e **não acumulados**
- [ ] Planilha de contagem preenchida e foto do ponto tirada
- [ ] CSV copiado do cartão **no mesmo dia**
- [ ] O dado atravessou até aparecer num mapa, **sem intervenção manual improvisada**
- [ ] Tudo que deu errado ficou anotado, mesmo o que já foi resolvido

**Tarefas**

- [ ] `US-23.1` Rodar a checklist "antes de sair" de [[Protocolo de Medição]]
- [ ] `US-23.2` Medir a âncora, o ponto e a âncora de novo
- [ ] `US-23.3` Executar a contagem manual na mesma janela de 10 min
- [ ] `US-23.4` Copiar o CSV e digitalizar a planilha no mesmo dia
- [ ] `US-23.5` Passar o dado pelo pipeline até um mapa
- [ ] `US-23.6` Anotar cada atrito encontrado

### US-24 — Ajustes pós-piloto no protocolo e no firmware

`Sprint 8` · `3 pts` · 🚶 · 👤 **time inteiro** · **Origem: T12**

> Como **grupo prestes a fazer 12 sessões**, quero corrigir o que o piloto revelou, para não repetir o mesmo erro 12 vezes.

**Critérios de aceite**

- [ ] Cada atrito anotado na US-23 tem destino: corrigido · aceito · vira limitação
- [ ] Se o CSV mudou, a mudança está refletida no formato congelado **e** no pipeline
- [ ] O tempo real da sessão foi medido e a quantidade de pontos por sessão foi ajustada ao que cabe
- [ ] [[Protocolo de Medição]] foi atualizado com o que mudou
- [ ] Qualquer decisão nova está em [[Registro de Decisões]]

**Tarefas**

- [ ] `US-24.1` Revisar a lista de atritos do piloto com os 5
- [ ] `US-24.2` Corrigir o firmware, se necessário
- [ ] `US-24.3` Ajustar a planilha de contagem, se necessário
- [ ] `US-24.4` Recalcular quantos pontos cabem numa sessão real
- [ ] `US-24.5` Atualizar [[Protocolo de Medição]] e [[Registro de Decisões]]

### US-25 — Executar as 12 sessões de campo

`Sprints 8 a 11` · `sem pontos — 12 janelas agendadas` · 🚶 · 👤 **time inteiro** · **Origem: T13**

> Como **conjunto de dados**, quero as 48 medições e as contagens correspondentes, para que exista o que analisar.

> [!danger] Esta story não tem story points de propósito
> T13 é **tempo de calendário, não esforço**. Exige 5 pessoas simultâneas, em janela de pico, em dia sem chuva. Não acelera com mais trabalho, não cabe numa estimativa, e não compete com as outras stories pela capacidade da sprint. Ela é modelada como **12 janelas agendadas** em [[Plano de Sprints]], 3 por sprint das Sprints 8 a 11, mais 2 reservas.
>
> O custo de calendário existe e é grande: ~3,5 h × 5 pessoas × 12 sessões ≈ **210 h-pessoa**, fora do orçamento de pontos. Ver [[Scrum do Projeto]].

**Critérios de aceite (por sessão, não da story inteira)**

- [ ] A sessão atende à **Definição de Sessão de Campo Válida** de [[Definição de Pronto]]
- [ ] Âncora medida no início **e** no fim
- [ ] Os 5 papéis ocupados, sem acumular
- [ ] Foto de cada ponto medido
- [ ] Planilha de contagem preenchida e fotografada antes de digitar
- [ ] CSV copiado no mesmo dia
- [ ] Sessão com chuva foi **cancelada e refeita**, nunca corrigida ([[Registro de Decisões|D-12]])
- [ ] Ao fim: 48 medições nos 12 pontos, 2 janelas, 2 repetições em dias distintos

**Tarefas (uma por sessão)**

- [ ] `US-25.1` a `US-25.12` — sessões 1 a 12, cada uma com a checklist completa de [[Protocolo de Medição]]
- [ ] `US-25.R1` e `US-25.R2` — sessões de reserva para chuva
- [ ] `US-25.13` Conferir a cobertura final: 12 pontos × 2 janelas × 2 repetições

### US-26 — Kit de sessão e distribuição de papéis

`Sprint 7` · `2 pts` · 🚶 · 👤 **Guilherme Falcão** · **Origem: T13**

> Como **escriba**, quero o material pronto antes de cada saída, para a sessão não falhar por falta de uma folha impressa.

**Critérios de aceite**

- [ ] A planilha de campo de [[Contagem Manual]] está diagramada e pronta para imprimir
- [ ] Existe uma folha **por ponto por sessão**
- [ ] O kit físico está montado: tripé, planilhas, canetas, cronômetro, windscreen reserva, cabo USB reserva
- [ ] A escala de papéis está definida, com **rodízio entre sessões**
- [ ] Está escrito e comunicado que o **operador não conta** ([[Contagem Manual]])

**Tarefas**

- [ ] `US-26.1` Diagramar a planilha de campo em uma página
- [ ] `US-26.2` Imprimir o lote das primeiras sessões
- [ ] `US-26.3` Montar o kit físico numa mochila só
- [ ] `US-26.4` Definir a escala de rodízio dos 5 papéis
- [ ] `US-26.5` Fazer um ensaio de 10 min de contagem, para calibrar o ritmo

---

## E5 — Dados / mapa

> Onde os números viram resultado. É o segundo épico mais pesado e o que mais aparece na feira.

**9 stories · 33 pontos · Sprints 8 a 12**

### US-27 — Digitalizar as planilhas no mesmo dia

`Sprint 8` · `3 pts` · 📊 · 👤 **Guilherme Falcão** · **Origem: T14**

> Como **análise de correlação**, quero as contagens em planilha digital, para que exista o outro lado do teste da hipótese.

**Critérios de aceite**

- [ ] As folhas são **fotografadas antes de digitar** — papel se perde, foto no celular não
- [ ] A digitação acontece **no mesmo dia** da coleta
- [ ] Uma linha por ponto por sessão, numa planilha única
- [ ] `sessao_id` e `ponto_id` batem exatamente com o CSV da estação
- [ ] **Conferência cruzada:** quem digita não é quem contou
- [ ] A planilha está em `/dados`

**Tarefas**

- [ ] `US-27.1` Criar a planilha única com as colunas de [[Contagem Manual]]
- [ ] `US-27.2` Fotografar as folhas de cada sessão
- [ ] `US-27.3` Digitar no mesmo dia
- [ ] `US-27.4` Fazer a conferência cruzada
- [ ] `US-27.5` Commitar em `/dados` a cada sessão

### US-28 — Pipeline: leitura, limpeza e descarte de sessão inválida

`Sprint 9` · `5 pts` · 📊 · 👤 **Arthur** · **Origem: T15** · dificuldade **Alta**

> Como **analista**, quero os CSVs de todas as sessões lidos e limpos, para trabalhar sobre um conjunto em que confio.

**Critérios de aceite**

- [ ] O pipeline lê todos os CSVs de `/dados` e junta com a planilha de contagem por `sessao_id` + `ponto_id`
- [ ] Sessões marcadas como inválidas (chuva, protocolo quebrado) são descartadas **explicitamente**, com o motivo registrado
- [ ] Outliers são **sinalizados e investigados**, nunca apagados em silêncio
- [ ] Toda linha descartada aparece num relatório de limpeza, com contagem
- [ ] Roda com os dados das primeiras sessões, sem esperar as 12

**Tarefas**

- [ ] `US-28.1` Ler e concatenar os CSVs de sessão
- [ ] `US-28.2` Fazer o join com a planilha de contagem manual
- [ ] `US-28.3` Detectar chave órfã (medição sem contagem, e vice-versa)
- [ ] `US-28.4` Implementar o descarte de sessão inválida com motivo
- [ ] `US-28.5` Sinalizar outliers e cruzar com o campo de ocorrências do escriba
- [ ] `US-28.6` Emitir o relatório de limpeza

### US-29 — Normalização pela deriva do ponto-âncora

`Sprint 9` · `5 pts` · 📊 · 👤 **Arthur** · **Origem: T15** · dificuldade **Alta** · aplica **D-03, D-04**

> Como **mapa**, quero as sessões corrigidas pela deriva medida na âncora, para que a diferença entre dois pontos seja lugar, e não horário.

> [!warning] Etapa que não existe em projeto normal de mapa de ruído
> Ela existe só porque o grupo tem **uma estação**. A fórmula escolhida é uma decisão metodológica, não um detalhe técnico — precisa estar documentada no relatório.

**Critérios de aceite**

- [ ] Para cada sessão, a diferença entre a âncora inicial e a final é calculada
- [ ] A correção é aplicada aos pontos daquela sessão
- [ ] A conta respeita a natureza logarítmica do dB — média **energética**, não aritmética
- [ ] A fórmula está escrita em prosa em [[Python para Análise Geoespacial]], pronta para o relatório
- [ ] Existe um antes/depois mostrando o efeito da normalização em pelo menos uma sessão
- [ ] Sessão sem âncora é **rejeitada pelo pipeline**, não estimada

**Tarefas**

- [ ] `US-29.1` Extrair as duas leituras de âncora por sessão
- [ ] `US-29.2` Definir e implementar a fórmula de correção
- [ ] `US-29.3` Garantir que a média de dB é energética
- [ ] `US-29.4` Rejeitar sessão sem âncora com erro claro
- [ ] `US-29.5` Gerar o comparativo antes/depois
- [ ] `US-29.6` Escrever a justificativa da fórmula no cofre

### US-30 — Agregação por ponto e por tipologia

`Sprint 10` · `3 pts` · 📊 · 👤 **Arthur** · **Origem: T15**

> Como **mapa e como relatório**, quero um valor por ponto e um por tipologia, para poder desenhar o marcador e comparar as 6 tipologias entre si.

**Critérios de aceite**

- [ ] Cada um dos 12 pontos tem `LAeq`, `Lmax`, `L10` e `L90` agregados das repetições
- [ ] A agregação é feita **por janela horária** também, não só no total
- [ ] Existe o agregado por tipologia, com dispersão entre os 2 pontos de cada uma
- [ ] O número de medições que sustenta cada agregado aparece junto do valor
- [ ] A saída é um CSV único que alimenta o mapa e a análise

**Tarefas**

- [ ] `US-30.1` Agregar por ponto, respeitando média energética
- [ ] `US-30.2` Agregar por ponto × janela horária
- [ ] `US-30.3` Agregar por tipologia com medida de dispersão
- [ ] `US-30.4` Anexar o N de cada agregado
- [ ] `US-30.5` Exportar o CSV agregado para `/dados`

### US-31 — GTFS da URBS cruzado com os 12 pontos

`Sprint 8` · `3 pts` · 📊 · 👤 **Arthur** · **Origem: T16**

> Como **argumento do trabalho**, quero saber quantas linhas e paradas de ônibus existem perto de cada ponto, para que o mapa de ruído converse com a pergunta original do professor.

**Critérios de aceite**

- [ ] O feed GTFS da URBS foi baixado, com **data de download e licença registradas** — vai no relatório
- [ ] Para cada um dos 12 pontos existe a contagem de paradas e de linhas num raio definido e declarado
- [ ] O raio escolhido está justificado, não é arbitrário
- [ ] A camada de rede está pronta para entrar no mapa da US-33
- [ ] Se o feed não estiver disponível, isso está registrado como limitação, não escondido

**Tarefas**

- [ ] `US-31.1` Localizar e baixar o feed GTFS atual da URBS
- [ ] `US-31.2` Registrar data de download, endereço e licença
- [ ] `US-31.3` Carregar `stops` e `routes` e projetar corretamente
- [ ] `US-31.4` Definir e justificar o raio de vizinhança
- [ ] `US-31.5` Contar paradas e linhas por ponto
- [ ] `US-31.6` Exportar a camada para o mapa

### US-32 — Correlação LAeq × pedestres × veículos × ônibus

`Sprint 10` · `5 pts` · 📊 · 👤 **Arthur** · **Origem: T17** · **o resultado do trabalho**

> Como **pesquisa**, quero o teste explícito da hipótese do proxy, para poder afirmar com número se ruído estima demanda ou não.

> [!important] Os dois resultados são publicáveis
> R² alto prova o proxy; R² baixo prova que ele não funciona — resultado igualmente válido e mais interessante. O que não é aceitável é assumir a resposta sem medir. Ver [[A Hipótese em Teste]].

**Critérios de aceite**

- [ ] As três correlações estão calculadas: LAeq × veículos, LAeq × ônibus, LAeq × **pedestres**
- [ ] Cada uma vem com coeficiente, R² e o N que a sustenta
- [ ] As medições **extrapoladas** (sub-janela de 2 min) estão marcadas e o efeito de incluí-las ou não foi verificado
- [ ] O ponto do calçadão da XV aparece identificado no gráfico — é o outlier que carrega o argumento
- [ ] Existe **um gráfico principal**, pronto para o pôster e para o stand
- [ ] A conclusão está escrita em uma frase, sem hedge

**Tarefas**

- [ ] `US-32.1` Montar a tabela ponto × LAeq × contagens
- [ ] `US-32.2` Calcular as três correlações com R² e N
- [ ] `US-32.3` Testar a sensibilidade aos dados extrapolados
- [ ] `US-32.4` Gerar o gráfico principal com a XV destacada
- [ ] `US-32.5` Escrever a conclusão em uma frase
- [ ] `US-32.6` Conferir a interpretação contra [[A Hipótese em Teste]]

### US-33 — Mapa web publicado no GitHub Pages

`Sprint 11` · `5 pts` · 📊 · 👤 **Arthur** · **Origem: T18** · entregável 2

> Como **visitante do stand**, quero abrir o mapa e ver os 12 pontos, para explorar o resultado por conta própria.

**Critérios de aceite**

- [ ] Os 12 pontos aparecem com marcador **graduado por LAeq**
- [ ] O popup de cada ponto traz tipologia, LAeq, Lmax, L10, L90, contagens e a foto
- [ ] A camada de transporte público da US-31 está presente e pode ser ligada/desligada
- [ ] O mapa está **publicado** e o endereço abre de fora da máquina de quem fez
- [ ] O QR code do repositório e do mapa foi gerado e testado

**Tarefas**

- [ ] `US-33.1` Montar o mapa com marcadores graduados
- [ ] `US-33.2` Montar o popup com dados e foto
- [ ] `US-33.3` Adicionar a camada GTFS como camada alternável
- [ ] `US-33.4` Publicar no GitHub Pages
- [ ] `US-33.5` Gerar e testar o QR code
- [ ] `US-33.6` Abrir o endereço de outra máquina para confirmar

### US-34 — O mapa abre no celular, em rede móvel

`Sprint 12` · `2 pts` · 📊 · 👤 **Arthur** · **Origem: T18** · [[Verificação]] item 7

> Como **pessoa no corredor da feira**, quero abrir o mapa no meu celular, para levar o trabalho embora sem depender do WiFi do evento.

**Critérios de aceite**

- [ ] O mapa foi aberto **num celular, em rede móvel, fora de casa**
- [ ] Carrega em tempo razoável e é navegável com o dedo
- [ ] As fotos dos popups estão comprimidas o bastante para não travar o carregamento
- [ ] O QR code leva direto ao mapa, testado por alguém de fora do grupo

**Tarefas**

- [ ] `US-34.1` Comprimir as fotos dos popups
- [ ] `US-34.2` Medir o tempo de carregamento em rede móvel
- [ ] `US-34.3` Testar a navegação por toque
- [ ] `US-34.4` Pedir a alguém de fora para abrir pelo QR code

### US-35 — Dataset aberto com dicionário de dados

`Sprint 11` · `2 pts` · 📊 · 👤 **Gustavo Juks** · **Origem: [[Entregáveis]] item 4**

> Como **avaliador**, quero baixar os dados e entender cada coluna, para verificar o que o grupo afirma.

**Critérios de aceite**

- [ ] `/dados` traz o CSV bruto da estação, a planilha de contagem digitalizada, as fichas dos 12 pontos e o CSV agregado
- [ ] Existe **dicionário de dados**: cada coluna com nome, unidade e significado
- [ ] As fotos dos pontos estão no repositório e referenciadas pelas fichas
- [ ] Está declarado o que foi descartado e por quê
- [ ] A licença dos dados está declarada

**Tarefas**

- [ ] `US-35.1` Organizar `/dados` em bruto, intermediário e agregado
- [ ] `US-35.2` Escrever o dicionário de dados
- [ ] `US-35.3` Publicar o relatório de limpeza da US-28
- [ ] `US-35.4` Declarar a licença

---

## E6 — Escrita / apresentação

> Metade da nota. Começa antes de existirem resultados, porque metodologia não depende de resultado.

**7 stories · 22 pontos · Sprints 5 a 12**

> [!tip] A frente de Escrita não é o prêmio de consolação
> A feira pontua **demo ao vivo, relatório entregue e arguição oral**. Quem pega esta frente precisa entender o argumento central tão bem quanto quem escreveu o firmware. Ver [[Alocação do Grupo]].

### US-36 — NBR 10151 e a fonte primária da OMS

`Sprint 5` · `2 pts` · ✍️ · 👤 **Gustavo Juks** · **Origem: P-10, P-11**

> Como **relatório**, quero as referências normativas conferidas na fonte, para não ter um número errado atribuído a uma norma derrubando a credibilidade do trabalho inteiro.

> [!danger] Não cite número de norma que você não leu
> Existem versões diferentes da NBR 10151, e valores repassados de blogs circulam desatualizados. Ver [[NBR 10151 e Normas]].

**Critérios de aceite**

- [ ] A biblioteca da PUCPR foi consultada sobre acesso ao acervo ABNT (Target GEDWeb ou equivalente)
- [ ] Existe resposta: há acesso · não há acesso
- [ ] Se houver: a **versão vigente** foi identificada e o que será citado foi lido no texto oficial
- [ ] Se não houver: fica registrado que a norma é citada só como referência, sem reproduzir limites
- [ ] A afirmação da OMS sobre exposição noturna foi rastreada até a **publicação original**, com o número e o contexto conferidos — ou foi retirada
- [ ] **P-10** e **P-11** fechadas

**Tarefas**

- [ ] `US-36.1` Perguntar à biblioteca sobre acesso ao acervo ABNT
- [ ] `US-36.2` Identificar a versão vigente da NBR 10151 no catálogo
- [ ] `US-36.3` Ler o que será citado e anotar em [[NBR 10151 e Normas]]
- [ ] `US-36.4` Localizar a publicação original da diretriz da OMS
- [ ] `US-36.5` Conferir número e contexto, ou retirar a afirmação
- [ ] `US-36.6` Fechar P-10 e P-11

### US-37 — Relatório: problema, hipótese e metodologia

`Sprint 7` · `5 pts` · ✍️ · 👤 **Gustavo Juks** · **Origem: T20**

> Como **grupo**, quero a metade do relatório que não depende de resultado escrita antes dos resultados existirem, para não escrever 20 páginas na última semana.

**Critérios de aceite**

- [ ] Seção 1 escrita: problema e a hipótese original do professor
- [ ] Seção 2 escrita: por que a hipótese precisa ser testada, com o argumento do calçadão da XV
- [ ] Seção 3 escrita: metodologia — estação, calibração por transferência, protocolo, amostra estratificada
- [ ] A fórmula de normalização por âncora está explicada em prosa
- [ ] As referências da US-36 estão citadas corretamente
- [ ] O texto foi lido por alguém do grupo que **não** escreveu

**Tarefas**

- [ ] `US-37.1` Escrever problema e hipótese original
- [ ] `US-37.2` Escrever o argumento de por que testar, a partir de [[A Hipótese em Teste]]
- [ ] `US-37.3` Escrever a metodologia a partir de [[Protocolo de Medição]] e [[Amostra Estratificada]]
- [ ] `US-37.4` Escrever a seção de calibração a partir de [[Calibração]]
- [ ] `US-37.5` Explicar a normalização por âncora
- [ ] `US-37.6` Revisão cruzada por outro membro

### US-38 — Relatório: resultados, discussão e limitações

`Sprint 11` · `5 pts` · ✍️ · 👤 **Gustavo Juks** · **Origem: T20**

> Como **banca**, quero ver o resultado, o que ele significa e o que o trabalho não sustenta, para avaliar maturidade e não só esforço.

> [!warning] Declarar limitação não enfraquece o trabalho — esconder, sim
> Uma banca perdoa incerteza declarada. Não perdoa número apresentado como exato quando não é.

**Critérios de aceite**

- [ ] Seção 4: resultados — o mapa e as três correlações, com R² e N
- [ ] Seção 5: discussão — o que o proxy explica e o que não explica
- [ ] Seção 6: **limitações**, cobrindo as quatro de [[Calibração]] mais as do desenho amostral
- [ ] Está escrito que 12 pontos **não sustentam interpolação espacial** — o mapa é de pontos, não de superfície
- [ ] Está escrito que recomendação real de alocação de linhas exigiria dados de demanda da URBS que o grupo não tem
- [ ] Se a janela horária mudou (**P-14**), isso aparece como limitação
- [ ] Seção 7: trabalhos futuros

**Tarefas**

- [ ] `US-38.1` Escrever os resultados a partir da US-32
- [ ] `US-38.2` Escrever a discussão do proxy
- [ ] `US-38.3` Escrever as limitações de calibração
- [ ] `US-38.4` Escrever as limitações do desenho amostral
- [ ] `US-38.5` Escrever trabalhos futuros
- [ ] `US-38.6` Revisão final e formatação de entrega

### US-39 — Pôster do stand

`Sprint 12` · `3 pts` · ✍️ · 👤 **Gustavo Juks** · **Origem: T20**

> Como **stand**, quero um pôster que carregue o argumento sozinho, para o trabalho comunicar mesmo quando o hardware falhar e ninguém estiver livre para falar.

**Critérios de aceite**

- [ ] O **gráfico principal** da US-32 é o elemento central, legível a 2 metros
- [ ] A frase que a pessoa tem que levar embora está no pôster, em destaque
- [ ] Há foto da estação montada e da montagem interna
- [ ] Há QR code do repositório e do mapa
- [ ] **Impresso com 3 dias de antecedência**, não na véspera ([[Roteiro da Feira]])

**Tarefas**

- [ ] `US-39.1` Definir o layout e a frase de destaque
- [ ] `US-39.2` Montar o gráfico principal em tamanho de pôster
- [ ] `US-39.3` Selecionar as fotos
- [ ] `US-39.4` Inserir os QR codes e testá-los impressos
- [ ] `US-39.5` Enviar para impressão com 3 dias de folga

### US-40 — Roteiro do pitch de 2 minutos

`Sprint 12` · `2 pts` · ✍️ · 👤 **Gustavo Juks** · **Origem: T20**

> Como **qualquer um dos 5**, quero saber dar o pitch, para não depender de o "apresentador oficial" estar livre quando alguém chegar no stand.

**Critérios de aceite**

- [ ] O roteiro de 6 passos de [[Roteiro da Feira]] está escrito e impresso
- [ ] A tabela de perguntas prováveis e respostas curtas está com o grupo
- [ ] **Os 5 conseguem dar o pitch** — não só um
- [ ] Alguém explica o argumento do calçadão da XV em **menos de 2 minutos**
- [ ] Está definida a escala de quem fica no stand em cada horário

**Tarefas**

- [ ] `US-40.1` Escrever o roteiro dos 6 passos
- [ ] `US-40.2` Revisar as respostas às perguntas prováveis
- [ ] `US-40.3` Cada um treina o pitch uma vez, cronometrado
- [ ] `US-40.4` Montar a escala do stand

### US-41 — Vídeo plano B da demo

`Sprint 12` · `2 pts` · ✍️ · 👤 **João** · **Origem: T21** · aplica **D-14**

> Como **stand**, quero um vídeo da estação funcionando, para nunca ficar sem demonstração quando a bateria acabar ou alguém esbarrar na mesa.

**Critérios de aceite**

- [ ] O vídeo mostra a estação ligando, medindo e o número reagindo a som
- [ ] Dura menos de 60 segundos
- [ ] Está **no celular de pelo menos duas pessoas** do grupo, offline
- [ ] Foi gravado **antes** do dia da feira, não no dia
- [ ] Também está no repositório

**Tarefas**

- [ ] `US-41.1` Roteirizar as tomadas
- [ ] `US-41.2` Gravar com a estação já calibrada e montada
- [ ] `US-41.3` Editar para menos de 60 s
- [ ] `US-41.4` Copiar para 2 celulares e para o repositório

### US-42 — Ensaio do stand com alguém de fora

`Sprint 12` · `3 pts` · ✍️ · 👤 **time inteiro** · **Origem: T21** · [[Verificação]] item 8

> Como **grupo**, quero ensaiar com uma pessoa que não conhece o projeto, para descobrir o que não está claro antes de descobrir na banca.

**Critérios de aceite**

- [ ] Ensaio completo com a demo ligada e alguém de fora assistindo
- [ ] A estação liga e mostra número em **menos de 1 minuto**
- [ ] O mapa abre
- [ ] A pessoa de fora consegue repetir a ideia principal com as próprias palavras
- [ ] O vídeo plano B está em 2 celulares
- [ ] Cabo reserva e power bank carregado estão na mochila
- [ ] A checklist do dia de [[Roteiro da Feira]] foi percorrida inteira

**Tarefas**

- [ ] `US-42.1` Montar o stand completo em casa ou na sala
- [ ] `US-42.2` Rodar o pitch para a pessoa de fora
- [ ] `US-42.3` Cronometrar o boot da estação
- [ ] `US-42.4` Perguntar à pessoa o que ela entendeu, e corrigir o que não passou
- [ ] `US-42.5` Percorrer a checklist do dia
- [ ] `US-42.6` Preparar a mochila com reservas

---

## Mapeamento T1–T21 → stories

Nenhum ID do cofre foi perdido. Esta tabela é o que mantém [[WBS e Gantt]] apontando para cá.

| Tarefa | Frente | Stories | Pontos |
|---|---|---|---|
| **T1** | 🧩 Coordenação | US-01 | 3 |
| **T2** | 🔧 Hardware | US-14, US-15 | 4 |
| **T3** | 🚶 Campo | US-43, US-21, US-22 | 8 |
| **T4** | 💻 Firmware | US-06, US-07 | 7 |
| **T5** | 💻 Firmware | US-08, US-09 | 10 |
| **T6** | 🔧 Hardware | US-16 | 5 |
| **T7** | 💻 Firmware | US-10 | 5 |
| **T8** | 💻 Firmware | US-11, US-12 | 8 |
| **T9** | 🔧 Hardware | US-19, US-20 | 6 |
| **T10** | 🔧 Hardware | US-17, US-18 | 5 |
| **T11** | 🚶 Campo | US-23 | 3 |
| **T12** | 🚶 Campo | US-24 | 3 |
| **T13** | 🚶 Campo | US-25, US-26 | 2 + 12 janelas |
| **T14** | 📊 Dados | US-27 | 3 |
| **T15** | 📊 Dados | US-28, US-29, US-30 | 13 |
| **T16** | 📊 Dados | US-31 | 3 |
| **T17** | 📊 Dados | US-32 | 5 |
| **T18** | 📊 Dados | US-33, US-34 | 7 |
| **T19** | 💻 Firmware | US-13 | 3 |
| **T20** | ✍️ Escrita | US-37, US-38, US-39, US-40 | 15 |
| **T21** | ✍️ Escrita | US-41, US-42 | 5 |

### Stories sem origem em T1–T21

Sete stories nascem de pendências já abertas no cofre ou de entregáveis já contratados — **não são escopo novo**, são trabalho que [[WBS e Gantt]] não tinha numerado.

| Story | Origem no cofre | Pontos |
|---|---|---|
| US-02 | P-07 e P-08 — rateio e quem compra | 1 |
| US-03 | P-09 — repositório GitHub | 2 |
| US-04 | P-03 — data da feira | 1 |
| US-05 | P-06 — as 12 datas de campo | 2 |
| US-22 | P-04 — ponto-âncora *(também T3)* | 2 |
| US-35 | [[Entregáveis]] item 4 — dataset aberto | 2 |
| US-36 | P-10 e P-11 — OMS e NBR 10151 | 2 |

---

**Relacionadas:** [[Scrum do Projeto]] · [[Plano de Sprints]] · [[Definição de Pronto]] · [[WBS e Gantt]] · [[Status das Pendências]] · [[Escopo Reformulado]]
