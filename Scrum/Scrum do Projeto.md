# 🏃 Scrum do Projeto — Mapa de Ruído de Curitiba

O hub da camada de execução: os números, a carga por sprint, quem faz o quê, as cerimônias, os riscos e o plano de corte. O detalhe de cada story está em [[Backlog do Produto]]; a distribuição no calendário, em [[Plano de Sprints]].

**Criado em 28/08/2026**, no meio da Sprint 1, com o escopo já fechado por [[Escopo Reformulado]] e as 21 tarefas de [[WBS e Gantt]] convertidas em backlog executável.

> [!info] Esta camada não muda o escopo
> [[Escopo Reformulado]] continua sendo o contrato. O que existe aqui é a **forma executável** dele: as mesmas 21 tarefas, os mesmos 12 pontos, as mesmas 48 medições, agora com dono, critério de aceite e semana.

---

## Os números

| | |
|---|---|
| Épicos | 6 — as 5 frentes de [[Alocação do Grupo]] mais Coordenação |
| User stories | 43 |
| Tarefas | 255 |
| Story points | 133 |
| Sprints | 12 de 1 semana, mais 1 de buffer |
| Tarefas T1–T21 cobertas | 21 de 21 |
| Sessões de campo | 12, mais 2 reservas — **sem pontos**, são calendário |

**Calibração:** 1 ponto ≈ **1 hora ideal de trabalho de uma pessoa**. É a mesma régua usada no cofre do Audocão, o que permite comparar os dois projetos.

---

## Quem é quem

Divisão fechada pelo grupo em **28/08/2026**. Fecha a pendência **P-15**.

| Pessoa | Frente | Épico | Stories | Pontos |
|---|---|---|---|---|
| **João** | 💻 Firmware / DSP | E2 + T1 + vídeo | 11 | **41** |
| **Arthur** | 📊 Dados / mapa | E5 + repositório | 8 | **30** |
| **Gustavo Juks** | ✍️ Documentação / escrita | E6 + dataset | 7 | **20** |
| **Guilherme Conde** | 🔧 Montagem / calibração | E3 | 5 | **16** |
| **Guilherme Falcão** | 🚶 Campo / logística / carro | E4 + compra + datas | 7 | **15** |
| ⬛ **Time inteiro** | reunião de pontos, piloto, ajustes, ensaio | — | 4 | **11** |

> [!note] Duas escolhas de alocação que eu fiz e que vocês precisam confirmar
> **A frente de Coordenação (E1) não tinha dono na divisão de vocês.** Distribuí as 5 stories por afinidade: o professor com o João, o repositório com o Arthur (é ele quem vai usar `/analise`), a data da feira com o Gustavo, e o dinheiro e as 12 datas com o Guilherme Falcão.
>
> **"Guilherme Falcão com o carro" virou a frente de Campo inteira** — logística, reconhecimento dos pontos, ponto-âncora, kit de sessão e digitalização das planilhas. Se o combinado é que ele só dirige, esses 15 pontos precisam de outro dono.

---

## 🔴 O gargalo, agora com nome

> [!danger] O backlog pede 133 h de trabalho. A disponibilidade declarada entrega ~96 h.
> João declarou **~3 h/semana**; os outros quatro, **1 h a 1h30**. São 37 h de diferença — e elas não estão espalhadas.

| Pessoa | Carga | Capacidade em 12 sprints | Situação |
|---|---|---|---|
| **Arthur** | 30 pts + ~2 do time | ~15 h | 🔴 **faltam ~17 h** |
| **João** | 41 pts *(3 já feitos)* + ~2 | ~36 h | 🟡 fecha no total, **mas mal distribuído** |
| **Gustavo Juks** | 20 pts + ~2 | ~15 h | 🟡 faltam ~7 h |
| **Guilherme Conde** | 16 pts + ~2 | ~15 h | 🟢 faltam ~3 h |
| **Guilherme Falcão** | 15 pts + ~2 | ~15 h | 🟢 no limite |

### O problema do Arthur é concentração, não volume

Dos 30 pontos dele, **28 caem nas Sprints 8 a 12** — porque o pipeline, a correlação e o mapa dependem do dado de campo existir. São 5 semanas.

| | |
|---|---|
| Precisa entregar nas Sprints 8–12 | **28 pontos** |
| Capacidade dele nessas 5 semanas | **~6 h** |
| Ritmo necessário | **~5,6 h/semana**, contra 1h30 declarados |

> [!warning] Por que não dá para simplesmente "começar antes"
> O pipeline precisa de dado real. `US-28` e `US-29` já estão o mais cedo possível — na Sprint 9, rodando sobre as sessões da Sprint 8 e re-executadas quando as últimas chegarem. Não há como puxar mais para a esquerda.

### O problema do João é o oposto: tudo na frente

| Período | Carga | Ritmo necessário |
|---|---|---|
| **Sprints 2–6** | 30 pontos | **~6 h/semana** |
| **Sprints 7–12** | 5 pontos (`US-13` e `US-41`) | ~0,8 h/semana |

> [!tip] E é exatamente aí que está a reserva do projeto
> O João fica com **~13 h livres nas Sprints 7 a 12** — bem em cima do buraco do Arthur. Se ele pegar `US-30` (agregação, 3 pts) e `US-33` (mapa web, 5 pts), o Arthur cai para 22 pontos e o João continua abaixo da capacidade dele no período.
>
> A contrapartida é real: o João precisa **antecipar**, rodando a ~6 h/semana até a Sprint 6, não a 3 h. É a mesma média que ele declarou, só que concentrada onde o caminho crítico está.

### As quatro saídas

| Saída | O que resolve | Quando decidir |
|---|---|---|
| **João reforça o Arthur nas Sprints 9–11** (`US-30` + `US-33`) | Tira 8 pts do gargalo usando capacidade que já existe e está ociosa | Até a Sprint 6 |
| **Uma terceira pessoa entra em Dados** — Gustavo ou G. Falcão em `US-27` e `US-35`, que não pedem Python | Já aplicado neste plano. Tirou 5 pts do Arthur | ✅ feito |
| **Cortar E5 pelo plano de corte** — `US-35`, `US-31`, `US-34` e mapa estático | Devolve ~12 pontos. E5 cai para ~18 | Até a Sprint 8 |
| **Cortar para 24 medições** (1 repetição) | Devolve ~105 h-pessoa de campo, que viram horas de análise | Até a Sprint 4, junto com o gatilho de hardware |

Enquanto nada for decidido, o [[Plano de Sprints]] mantém a alocação da tabela acima.

### E as 12 sessões continuam fora dessa conta

12 sessões × ~3,5 h × 5 pessoas ≈ **210 h-pessoa**, ou **~42 h por pessoa** — mais que o dobro do que [[Alocação do Grupo]] estimava para o projeto inteiro. Não são story points e não competem com o backlog, mas **são tempo real na agenda de todo mundo**.

Somando trabalho e campo, o número honesto por pessoa é de **~40 a 55 h ao longo das 12 semanas**, não os 15–22 h que o cofre estima.

---

## Carga por sprint

| Sprint | Datas | Meta | Stories | Pontos | Campo |
|---|---|---|---|---|---|
| **1** | 26/08 – 01/09 | Professor alinhado, dinheiro acertado, cotação fechada | 3 | 7 | — |
| **2** | 02/09 – 08/09 | Pedido saiu, 12 pontos escolhidos, PUC respondeu sobre o calibrador | 7 | 14 | — |
| **3** | 09/09 – 15/09 | 12 pontos visitados e fichados, 12 datas fechadas | 3 | 11 | — |
| **4** | 16/09 – 22/09 | Peças montadas na protoboard, DSP validado no desktop | 3 | 12 | — |
| **5** | 23/09 – 29/09 | O microfone lê de verdade e a estação tem corpo | 3 | 10 | — |
| **6** | 30/09 – 06/10 | A estação grava CSV e o dado sobrevive a queda de energia | 3 | 10 | — |
| **7** | 07/10 – 13/10 | Calibrada em dB(A) absoluto e o ciclo fechou com 1 ponto | 4 | 15 | piloto |
| **8** | 14/10 – 20/10 | O campo começou e a digitalização acompanha | 3 | 9 | 3 sessões |
| **9** | 21/10 – 27/10 | Pipeline lê, limpa e normaliza pela âncora | 3 | 13 | 3 sessões |
| **10** | 28/10 – 03/11 | As três correlações existem | 2 | 8 | 3 sessões |
| **11** | 04/11 – 10/11 | Campo fechado, mapa publicado, relatório inteiro | 3 | 12 | 3 sessões |
| **12** | 11/11 – 17/11 | O stand funciona, inclusive sem hardware | 5 | 12 | **FEIRA** |
| **13** | 18/11 – 24/11 | Buffer | 0 | 0 | — |

```
Sprint  1  ███████                  7
Sprint  2  ██████████████          14
Sprint  3  ███████████             11
Sprint  4  ████████████            12
Sprint  5  ██████████              10
Sprint  6  ██████████              10
Sprint  7  ███████████████         15   + piloto
Sprint  8  █████████                9   + 3 sessões
Sprint  9  █████████████           13   + 3 sessões
Sprint 10  ████████                 8   + 3 sessões
Sprint 11  ████████████            12   + 3 sessões
Sprint 12  ████████████            12   ← FEIRA
Sprint 13  ·                        0   ← buffer
```

**Média:** 11 pontos por sprint. O pico é a Sprint 7 (15), mas distribuído entre 4 pessoas diferentes. O aperto real é a **Sprint 9** (13 pontos + 3 sessões de campo), e ali quase tudo está no Arthur.

---

## As 6 frentes como épicos

| Épico | Frente | Quantas pessoas | Stories | Pontos | Concentração |
|---|---|---|---|---|---|
| E1 | 🧩 Coordenação | distribuída entre os 4 | 5 | 9 | Sprints 1–3 |
| E2 | 💻 Firmware / DSP | **João** | 8 | 33 | 🔴 Sprints 2–6 |
| E3 | 🔧 Hardware / calibração | **G. Conde** | 7 | 20 | 🟢 Sprints 4–7 |
| E4 | 🚶 Campo | **G. Falcão** + os 5 | 7 | 16 | 🟡 Sprints 2–11 |
| E5 | 📊 Dados / mapa | **Arthur** (+ apoio) | 9 | 33 | 🔴 Sprints 8–12 |
| E6 | ✍️ Escrita / apresentação | **Gustavo Juks** | 7 | 22 | 🟡 Sprints 7–12 |

> [!danger] A ideia de "firmware e dados na mesma pessoa" não sobrevive à conta
> [[Alocação do Grupo]] sugeria que E2 e E5 podiam ser da mesma pessoa, porque concentram em sprints diferentes. Com a disponibilidade real declarada, isso deixa de valer: os 33 pontos de E2 **já consomem inteiras** as 36 h de capacidade do João nas 12 sprints. Acumular E5 exigiria ~5,5 h/semana dele.
>
> **E5 precisa de dono próprio, e provavelmente de mais de uma pessoa.** Ver a análise de gargalo acima.

### Os 5 papéis de campo continuam valendo

Em cada ponto medido: operador, contador de pedestres sentido 1, contador de pedestres sentido 2, contador de veículos, escriba. **Simultâneos e não acumuláveis** — está no DoD de sessão válida em [[Definição de Pronto]]. Rodízio entre sessões é recomendado.

> [!success] Os 5 nomes estão registrados desde 28/08/2026
> A divisão está na seção **Quem é quem**, no topo desta nota, e o dono de cada story está em [[Backlog do Produto]] e em [[Plano de Sprints]]. **P-15 fechada.**

> [!warning] O rodízio de papéis de campo é separado da frente de cada um
> O Guilherme Falcão é dono da frente de Campo, mas isso **não** quer dizer que ele seja sempre o operador da estação. Em campo os 5 papéis rodam entre sessões — quem opera precisa conhecer o firmware, então o João e o Guilherme Conde são os naturais para esse papel. Ver [[Contagem Manual]].

---

## Cerimônias

Sprint de 1 semana pede cerimônia curta. O total abaixo custa menos de **1h30 por semana**, e cabe dentro da própria estimativa de disponibilidade.

As sprints correm de **quarta a terça**, porque a âncora S1 de [[WBS e Gantt]] começa numa quarta-feira, 26/08/2026.

| Cerimônia | Quando | Duração | Para quê |
|---|---|---|---|
| **Planning** | Quarta, no início | 30 min | Escolher as stories da sprint e confirmar dono de cada uma |
| **Daily assíncrona** | Todo dia, no grupo | 5 min | O que fiz, o que farei, o que me trava |
| **Review** | Terça | 30 min | Demonstrar o que ficou pronto, funcionando |
| **Retrospectiva** | Terça, depois da review | 15 min | O que manter e o que mudar |
| **Revisão de pendências** | Quarta, junto da planning | 10 min | Percorrer [[Status das Pendências]] e [[Progresso do Projeto]] |

> [!important] A review é uma demonstração, não um relato
> Ninguém "conta" o que fez. Liga a estação, abre o CSV, mostra o gráfico. O que não roda não entrou na sprint.

> [!tip] Uma pendência 🔴 aberta por mais de uma semana é sinal de cobrança
> Não de que ela é difícil. Está escrito em [[Status das Pendências]] e vale como regra de retrospectiva.

---

## Papéis

| Papel | Responsabilidade |
|---|---|
| **Product Owner** | Protege o escopo. Diz o que entra em cada sprint e recusa o que não está em [[Escopo Reformulado]] |
| **Scrum Master** | Conduz as cerimônias e remove impedimento. Não é chefe, e não é quem faz mais |
| **Time** | Escreve, monta, mede e analisa. **Quem faz é quem estima** |

---

## O que este projeto quebra num Scrum ingênuo

> [!danger] Três coisas não são story points, e fingir que são destrói o plano

### 1. As 12 coletas (`US-25`, T13) são tempo de calendário

Exigem **5 pessoas simultâneas**, em janela de pico, em dia sem chuva. Não aceleram com mais trabalho, não se dividem entre menos pessoas, não cabem numa estimativa de esforço.

**Como está modelado:** 12 janelas agendadas, 3 por sprint das Sprints 8 a 11, com 2 reservas. Zero pontos. A capacidade da sprint é reduzida nas semanas de campo — Sprint 8 tem só 9 pontos por isso.

**O que as destrava:** a story `US-05`, com prazo duro em **15/09/2026**. Combinar em S3, não em S6.

### 2. A compra (`US-15`, T2) tem 3 a 10 dias de espera

Comprar leva 20 minutos e vale **1 ponto**. Esperar a entrega vale **zero** e custa até 10 dias de calendário que ninguém recupera trabalhando mais.

**Como está modelado:** compra no primeiro dia da Sprint 2. As Sprints 2 e 3 carregam só o que **não depende de peça** — Wokwi, formato do CSV, repositório, reconhecimento dos pontos, ponderação A. É a decisão [[Registro de Decisões|D-13]] aplicada ao calendário.

### 3. A calibração (`US-20`, T9) depende de equipamento de terceiro

Depende de conseguir um decibelímetro ou calibrador emprestado. É dependência externa: o risco não é o esforço, é o tempo de resposta de um laboratório.

**Como está modelado:** a pergunta é uma story separada (`US-19`, 1 ponto) na **Sprint 5**, duas sprints antes de a calibração acontecer na 7.

**Plano B, já contratado:** decibelímetro classe 2 comprado, calibração por transferência em ≥3 níveis, e a limitação declarada no relatório ([[Registro de Decisões|D-07]] e [[Calibração]]).

---

## Plano de corte

Se o buffer da Sprint 13 for consumido antes da Sprint 10, ou se um dos gatilhos de [[Riscos]] disparar, corte **nesta ordem** e só até destravar.

O destino do corte é o **escopo mínimo garantido** de [[Escopo Reformulado]]: estação medindo ao vivo, tipologias 3 e 4 medidas, um mapa ainda que estático, e o pôster com o argumento.

| # | O que cortar | Pontos / calendário devolvidos | O que se perde |
|---|---|---|---|
| 1 | **Segunda repetição das medições** (48 → 24) | ~105 h-pessoa de campo | Deixa de separar "é assim" de "foi assim naquele dia" |
| 2 | **`US-35` dataset com dicionário** | 2 pts | O repositório fica sem os dados documentados |
| 3 | **`US-31` cruzamento com GTFS** | 3 pts | O mapa perde a camada de ônibus; a discussão fica sem a rede real |
| 4 | **`US-34` mapa otimizado para celular** | 2 pts | O mapa continua abrindo, só mais devagar na rede da feira |
| 5 | **`US-13` modo demo HTTP** | 3 pts | O OLED sozinho ainda para a pessoa no stand |
| 6 | **Tipologias 5 e 6** (parque e entorno da PUC) | 4 pontos de medição a menos | Perde o controle de piso de ruído. **Manter 3 e 4** |
| 7 | **`US-33` mapa interativo → mapa estático** | 5 pts | Vira imagem no pôster; o argumento sobrevive |

> [!danger] O que nunca cortar
> **`US-20`** (calibração — é o que separa o projeto de um sensor de barulho), **`US-12`** (queda de energia — perder uma sessão é irreversível), **os pontos das tipologias 3 e 4** (são o resultado do trabalho), **`US-32`** (a correlação — é a pesquisa), **`US-38`** (limitações declaradas), **`US-41`** (vídeo plano B) e **`US-42`** (ensaio). São os mais baratos e os que mais pesam na nota.

> [!warning] Cortar cedo custa menos que cortar tarde
> Cortar a segunda repetição na Sprint 4, quando o gatilho de hardware dispara, devolve 105 h-pessoa. Cortar em novembro não devolve nada — as sessões já aconteceram.

---

## Riscos da execução

Complementa [[Riscos]], que cobre os riscos técnicos. Aqui só o que o Scrum enxerga.

| Risco | Impacto | O que fazer |
|---|---|---|
| **A PUC não emprestar instrumento de referência** | 🔴 **Sem plano B financiado.** O projeto não produz dB SPL absoluto e perde o que o diferencia | `US-19` foi antecipada para a **Sprint 2**. Se a resposta for não, decidir a contingência na mesma sprint — as três saídas estão em [[Backlog do Produto]] |
| **A frente de Dados ficar com uma pessoa a 1h30/semana** | 🔴 Faltam ~25 h nas Sprints 8–12; o mapa e a correlação não ficam prontos | Definir 2 ou 3 pessoas em E5 até a Sprint 6, ou acionar o corte de E5 |
| **A Sprint 1 fechar sem T1** | 🔴 A compra atrasa e come o buffer. Agora carrega também a decisão P-12 | `US-01` é a única story que não pode escorregar. Se a conversa não acontece, mandar por escrito |
| **P-12 ficar aberta por semanas** | 🟡 A compra não fecha, e a compra é o início do caminho crítico | Levar as duas opções de ESP32 já na conversa de `US-01`, com preço e justificativa técnica na mão |
| **As 12 datas não fecharem até 15/09** | 🔴 O campo não cabe nas Sprints 8–11 | `US-05` tem prazo duro. Uma pendência 🔴 aberta há mais de uma semana é cobrança, não dificuldade |
| **A janela horária não ser resolvida (P-14)** | 🟡 O desenho de 48 medições não fecha | Decidir durante o reconhecimento, na Sprint 3. Três opções, todas com consequência declarada |
| **A data da feira mudar depois da Sprint 4** | 🟡 Replanejamento no meio do campo | `US-04` está na Sprint 2 justamente para descobrir cedo |
| **Sprints 9 e 10 com 13 pontos e 3 sessões cada** | 🟡 São as duas semanas mais apertadas do plano | `US-13` (3 pts) é a primeira a escorregar da 9; `US-37` da 10 |
| **Membros sumirem perto de provas** | 🟡 Padrão em trabalho de grupo | Frentes com dono nominal desde a Sprint 1; daily assíncrona faz a ausência aparecer em dias, não em semanas |
| **O pipeline só ser entendido por uma pessoa** | 🟡 Ponto único de falha na arguição | Programar em par em `US-29` — a normalização por âncora é o que a banca vai perguntar |

---

## Pendências que esta camada abriu

Nascem do planejamento e ainda **não estão numeradas** em [[Status das Pendências]] — entram lá quando o cofre for padronizado.

| # | Pendência | Situação | Prazo |
|---|---|---|---|
| **P-12** | Modelo do ESP32: WROOM-32 ou S3 | 🔴 **aberta de propósito** — vai ser discutida com o professor. A cotação recomenda o S3 (PSRAM evita perder amostra I2S), mas a decisão não é só técnica | Sprint 1, junto com `US-01` |
| **P-13** | Marca e modelo do decibelímetro | ✅ **encerrada em 28/08/2026** — não será comprado. R$1.400+ contra teto de R$500 | — |
| **P-14** | Segunda janela horária de campo — só a tarde é viável | 🟡 aberta | Sprint 3, no reconhecimento (`US-21`) |
| **P-15** | Nomes dos 5 e dono de cada frente | ✅ **fechada em 28/08/2026** — João firmware, Arthur dados/mapa, Gustavo Juks documentação, Guilherme Conde montagem, Guilherme Falcão campo e logística | — |
| **P-16** | Instrumento de referência para calibração — só resta empréstimo | 🔴 aberta. Absorve e agrava P-05: não há mais alternativa comprada | Sprint 2 (`US-19`) |
| **P-17** | Os 12 pontos candidatos e a rota do reconhecimento não estão definidos | 🟡 aberta. [[Amostra Estratificada]] define as 6 tipologias, mas não os pontos. Sem isso, quem dirige sai sem rota | Sprint 2 (`US-43`) |

> [!danger] O orçamento mudou de forma, não de tamanho
> O teto segue **R$500 duro**. Mas o decibelímetro classe 2 saiu de dentro dele, e com ele saiu o plano B da calibração. Sobra folga na compra (R$398 no cenário completo), e essa folga **não cobre** o aluguel de calibrador de ~R$200/diária sem cortar tripé e caixa — a conta está em `US-19`.

> [!note] "D-15" a "D-18" eram links para decisões que ninguém escreveu
> [[Status das Pendências]] e [[WBS e Gantt]] apontavam para elas; [[Registro de Decisões]] parava na D-14 e as listava só como "pendentes". Nenhuma das quatro estava decidida — então viram pendência numerada, não decisão. **D-17** (ponto-âncora) já era coberta por P-04 e **D-18** (data da feira) por P-03; as outras duas viram P-12 e P-13. A limpeza acontece na padronização do cofre.

---

**Relacionadas:** [[Backlog do Produto]] · [[Plano de Sprints]] · [[Definição de Pronto]] · [[WBS e Gantt]] · [[Alocação do Grupo]] · [[Riscos]] · [[Status das Pendências]] · [[Escopo Reformulado]] · [[Progresso do Projeto]]
