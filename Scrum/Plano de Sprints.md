# 🗓️ Plano de Sprints — Mapa de Ruído de Curitiba

12 sprints de 1 semana mais 1 de buffer, 133 pontos, 43 stories. O detalhe de cada story está em [[Backlog do Produto]]; os números e o plano de corte em [[Scrum do Projeto]].

**Âncora:** Sprint 1 = **26/08 a 01/09/2026**, a mesma S1 de [[WBS e Gantt]]. As sprints correm de **quarta a terça**, porque 26/08/2026 é uma quarta-feira.

> [!caution] Três premissas, não três fatos
> **P-03 — a data da feira não está confirmada.** Este plano assume a Sprint 12, 11–17/11/2026. Se a data real for outra, todas as sprints deslocam junto — é a story **US-04**, na Sprint 2, que fecha isso.
>
> **P-14 — as janelas horárias de campo estão em revisão.** Hoje só a janela da tarde é viável para os 5, e o desenho de 48 medições supõe duas janelas. A decisão foi adiada para o reconhecimento dos pontos, na Sprint 3.
>
> **P-12 — o modelo do ESP32 ficou deliberadamente em aberto**, para ser discutido com o professor. `US-15` (a compra) não fecha antes disso.

> [!warning] A Sprint 1 já está pela metade
> Hoje é 28/08/2026 e a Sprint 1 começou em 26/08. A `US-14` (cotação) já foi concluída; **T1 continua sem acontecer**. A sprint fica com **7 pontos em 4 dias**, só com o que destrava o resto.

> [!danger] A cotação de 28/08 mudou este plano
> O decibelímetro classe 2 custa **R$1.400 a R$1.890**, não os R$180–250 estimados. Ele sai do orçamento, e com ele o plano B da calibração. **`US-19` foi antecipada da Sprint 5 para a Sprint 2.**
>
> Entrou também a **`US-43`** — a reunião que define os 12 pontos e a rota **antes** de o carro sair para o reconhecimento. O backlog foi de 132 para **133 pontos**.

---

## Calendário das 13 sprints

| Sprint | Semana | Datas | Pontos | Janelas de campo |
|---|---|---|---|---|
| **1** | S1 | 26/08 – 01/09 | 7 | — |
| **2** | S2 | 02/09 – 08/09 | 14 | — |
| **3** | S3 | 09/09 – 15/09 | 11 | — |
| **4** | S4 | 16/09 – 22/09 | 12 | — |
| **5** | S5 | 23/09 – 29/09 | 10 | — |
| **6** | S6 | 30/09 – 06/10 | 10 | — |
| **7** | S7 | 07/10 – 13/10 | 15 | piloto |
| **8** | S8 | 14/10 – 20/10 | 9 | 3 sessões |
| **9** | S9 | 21/10 – 27/10 | 13 | 3 sessões |
| **10** | S10 | 28/10 – 03/11 | 8 | 3 sessões |
| **11** | S11 | 04/11 – 10/11 | 12 | 3 sessões |
| **12** | S12 | 11/11 – 17/11 | 12 | **FEIRA** *(suposta)* |
| **13** | S13 | 18/11 – 24/11 | 0 | **buffer** |

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

---

## Sprint 1 — 7 pontos · 26/08 a 01/09

> [!abstract] Meta da sprint
> O professor sabe do novo recorte, o dinheiro está acertado e a cotação está fechada.

| ID | Story | Frente | Dono | Origem | Pts |
|---|---|---|---|---|---|
| US-01 | Alinhar a reformulação com o professor | 🧩 | João | T1 | 3 |
| US-02 | Fechar o rateio financeiro e quem compra | 🧩 | G. Falcão | P-07, P-08 | 1 |
| US-14 ✅ | Cotação e fechamento do modelo de ESP32 e decibelímetro | 🔧 | João | T2 | 3 |

**Foco:** nada aqui produz código. Tudo aqui destrava a Sprint 2. `US-01` bloqueia `US-15`, e `US-15` é o início do caminho crítico.

**Demonstrável na review:** o e-mail ou o registro da conversa com o professor, e a cotação com os preços reais e os três cenários de carrinho fechado.

> [!success] `US-14` concluída em 28/08/2026
> Restam **4 pontos** na sprint. A cotação fechou P-01, respondeu as seis perguntas técnicas e encerrou P-13 (o decibelímetro não será comprado). **P-12 ficou aberta de propósito**, para ir junto na conversa com o professor.

> [!danger] Sprint encurtada, e `US-01` é a que não pode escorregar
> Restam 4 dias e a conversa com o professor ainda não aconteceu. Ela agora carrega **duas** perguntas: o aceite da reformulação, e a escolha entre WROOM-32 e S3 (P-12). Enquanto ela não acontece, a compra não sai — e a compra é o início do caminho crítico.

---

## Sprint 2 — 14 pontos · 02/09 a 08/09

> [!abstract] Meta da sprint
> O pedido saiu, o repositório existe, os 12 pontos estão escolhidos e o firmware simulado começou a andar.

| ID | Story | Frente | Dono | Origem | Pts |
|---|---|---|---|---|---|
| US-15 | Compra efetivada | 🔧 | G. Falcão | T2 | 1 |
| US-19 | Conseguir o instrumento de referência emprestado | 🔧 | G. Conde | T9, P-05 | 1 |
| US-03 | Repositório GitHub com estrutura e README | 🧩 | Arthur | P-09 | 2 |
| US-04 | Confirmar a data da feira e reancorar o cronograma | 🧩 | Gustavo | P-03 | 1 |
| US-43 | Reunião de definição dos 12 pontos e da rota | 🚶 | ⬛ time | T3 | 2 |
| US-06 | Esqueleto do firmware no Wokwi | 💻 | João | T4 | 5 |
| US-07 | Congelar o formato do CSV da estação | 💻 | João | T4 | 2 |

**Foco:** comprar **no primeiro dia da sprint**, não no último. A partir daí corre um relógio de 3 a 10 dias que ninguém controla.

**Demonstrável na review:** o número de rastreio do pedido, o repositório clonável, o projeto Wokwi escrevendo uma linha de CSV — e a **resposta do laboratório da PUC**, mesmo que seja um "não".

> [!danger] `US-19` foi antecipada da Sprint 5 para cá, e é o item mais importante da semana
> A cotação de 28/08 mostrou que o decibelímetro classe 2 custa R$1.400 a R$1.890, contra um orçamento total de R$500. **O plano B comprado deixou de existir.** Se a PUC não emprestar, o projeto não tem como produzir dB SPL absoluto.
>
> Perguntar agora dá **cinco sprints** de antecedência até a calibração da Sprint 7. É a única folga disponível para arrumar outra saída — e as três saídas possíveis estão na tabela de `US-19` em [[Backlog do Produto]].

> [!warning] `US-15` está bloqueada por uma decisão que não é do grupo
> O modelo do ESP32 (**P-12**) ficou em aberto para discutir com o professor. Levar as duas opções na conversa de `US-01`, e comprar assim que ele responder — a compra é o início do caminho crítico e não pode ficar esperando semanas.

> [!warning] Espera de entrega não é trabalho e não tem pontos
> Comprar vale 1 ponto porque leva 20 minutos. O que custa é o **calendário**. Por isso as Sprints 2 e 3 são carregadas de tarefas que **não dependem de peça**: Wokwi, CSV, repositório, reconhecimento dos pontos.

> [!tip] `US-43` é a reunião, `US-21` é a visita — nesta ordem
> Escolher os 12 pontos é decisão de grupo e acontece **sentado**, num mapa. Visitar é execução e acontece na semana seguinte, com o carro. Trocar a ordem custa uma tarde: o motorista sai sem rota e o grupo volta com ficha incompleta.
>
> 14 pontos é o segundo pico do plano, mas está espalhado por 5 pessoas — o João leva 7 e ninguém mais passa de 2.

---

## Sprint 3 — 11 pontos · 09/09 a 15/09

> [!abstract] Meta da sprint
> Os 12 pontos foram visitados e fichados, as 12 datas existem no calendário, e a tarefa mais difícil do projeto começou.

| ID | Story | Frente | Dono | Origem | Pts |
|---|---|---|---|---|---|
| US-21 | Reconhecimento e ficha dos 12 pontos | 🚶 | G. Falcão + ⬛ | T3 | 4 |
| US-05 | Fechar as 12 datas de campo com confirmação nominal | 🧩 | G. Falcão | P-06 | 2 |
| US-08 | Filtro de ponderação A no desktop | 💻 | João | T5 | 5 |

**Foco:** `US-05` tem **prazo duro no fim desta sprint**. [[Alocação do Grupo]] e [[Riscos]] são explícitos: as datas se combinam em S3, não em S6. Uma agenda de 5 universitários não se resolve em cima da hora.

**Demonstrável na review:** as 12 fichas de ponto preenchidas com foto e coordenada, o calendário com os 5 nomes confirmados em cada sessão, e a resposta em frequência do filtro de ponderação A comparada com a curva de referência.

> [!danger] A decisão de janela horária vence aqui
> Só a janela da tarde é viável hoje, e o desenho de 48 medições supõe duas. Durante o reconhecimento (`US-21`) o grupo precisa fechar **P-14**: trocar a manhã por um horário de entre-pico à tarde, cair para 24 medições, ou levar a manhã para sábado. Cada opção tem consequência declarada em [[Escopo Reformulado]] e no relatório.

---

## Sprint 4 — 12 pontos · 16/09 a 22/09

> [!abstract] Meta da sprint
> As peças chegaram e estão montadas na protoboard; o DSP está validado no desktop.

| ID | Story | Frente | Dono | Origem | Pts |
|---|---|---|---|---|---|
| US-16 | Recebimento, inventário e montagem em protoboard | 🔧 | G. Conde | T6 | 5 |
| US-09 | LAeq, Lmax, L10 e L90 validados contra WAV | 💻 | João | T5 | 5 |
| US-22 | Ponto-âncora escolhido e registrado | 🚶 | G. Falcão | T3, P-04 | 2 |

**Foco:** `US-16` monta **um módulo por vez**, na ordem de [[Montagem e Ligações]]. Nunca ligar tudo de uma vez e tentar descobrir o que não funciona — é a primeira vez que o grupo toca ESP32 físico.

**Demonstrável na review:** o OLED mostrando a hora do RTC depois de um desliga-religa, um arquivo lido do cartão SD, e o LAeq calculado sobre o WAV de referência batendo com a implementação de comparação.

> [!warning] Se a peça não chegou até o fim desta sprint
> É o gatilho de corte de [[Riscos]]: cortar a segunda repetição das medições, de 48 para 24. Cortar **agora**, não em outubro.

---

## Sprint 5 — 10 pontos · 23/09 a 29/09

> [!abstract] Meta da sprint
> O microfone lê de verdade, e a estação tem corpo.

| ID | Story | Frente | Dono | Origem | Pts |
|---|---|---|---|---|---|
| US-10 | INMP441 lendo I2S com RMS estável | 💻 | João | T7 | 5 |
| US-17 | Montagem física: caixa, windscreen e tripé | 🔧 | G. Conde | T10 | 3 |
| US-36 | NBR 10151 e a fonte primária da OMS | ✍️ | Gustavo | P-10, P-11 | 2 |

**Foco:** `US-10` é a etapa mais difícil da montagem — ler zeros é o sintoma clássico, e a causa costuma ser o pino L/R ou WS/SCK trocados.

**Demonstrável na review:** o teste de [[Verificação]] item 1 ao vivo — silêncio → palma → música → silêncio, com o valor voltando ao repouso.

> [!note] `US-19` saiu desta sprint
> Foi antecipada para a **Sprint 2** depois da cotação de 28/08/2026. A sprint caiu de 11 para 10 pontos.

> [!warning] Se `US-19` voltou sem empréstimo, a contingência já tinha que estar decidida
> A calibração é na Sprint 7. Se até aqui ainda não se sabe com que instrumento ela vai ser feita, `US-17` precisa levar isso em conta — alugar calibrador exige cortar o tripé e a caixa ABS do orçamento, e essa decisão muda o que se monta nesta semana.

---

## Sprint 6 — 10 pontos · 30/09 a 06/10

> [!abstract] Meta da sprint
> A estação grava CSV sozinha e o dado sobrevive a puxão de tomada.

| ID | Story | Frente | Dono | Origem | Pts |
|---|---|---|---|---|---|
| US-11 | DSP no ESP32 gravando CSV no microSD | 💻 | João | T8 | 5 |
| US-12 | O dado sobrevive a queda de energia | 💻 | João | T8 | 3 |
| US-18 | Autonomia de 3 horas no power bank | 🔧 | G. Conde | T10 | 2 |

**Foco:** aqui as duas metades se juntam — o DSP validado no desktop encontra o microfone que lê. É onde aparece se sobra CPU para o filtro rodar em tempo real.

**Demonstrável na review:** uma medição de 10 minutos virando uma linha de CSV no cartão, e o cabo sendo puxado da tomada no meio de uma gravação sem corromper o arquivo anterior.

> [!danger] `US-12` é o teste que ninguém faz e todo mundo se arrepende
> Perder uma sessão de campo inteira por arquivo corrompido é o pior fracasso possível deste projeto — e é totalmente evitável em uma tarde. Não pule.

---

## Sprint 7 — 15 pontos · 07/10 a 13/10 · **piloto**

> [!abstract] Meta da sprint
> A estação mede em dB(A) absoluto, e o ciclo inteiro fechou com um ponto.

| ID | Story | Frente | Dono | Origem | Pts |
|---|---|---|---|---|---|
| US-20 | Calibração por transferência com R² > 0,95 | 🔧 | G. Conde | T9 | 5 |
| US-23 | Coleta piloto: o ciclo inteiro em 1 ponto | 🚶 | ⬛ time | T11 | 3 |
| US-26 | Kit de sessão e distribuição de papéis | 🚶 | G. Falcão | T13 | 2 |
| US-37 | Relatório: problema, hipótese e metodologia | ✍️ | Gustavo | T20 | 5 |

**Ordem dentro da semana:** `US-20` → `US-26` → `US-23`. O piloto não acontece antes da calibração, e não acontece sem o kit impresso. `US-37` corre em paralelo — é escrita, não depende de nada disso.

> [!note] 15 pontos, mas não na mesma pessoa
> É a sprint mais cheia do plano em número total, e isso é enganoso: são **três pessoas diferentes** trabalhando em paralelo. G. Conde calibra (5), o time faz o piloto (3), G. Falcão monta o kit (2) e Gustavo escreve (5). Ninguém carrega 15 pontos.

> [!tip] `US-37` foi puxada da Sprint 10 para cá de propósito
> A metodologia, o problema e a hipótese **não dependem de resultado nenhum** — estão todos definidos desde a Sprint 4. Escrever agora tira 5 pontos das Sprints 10–12, que é onde o Gustavo estava com 17 pontos em três semanas.

**Foco:** esta é a sprint que decide se as 12 sessões vão funcionar. O piloto existe para descobrir que falta uma coluna no CSV ou que o `sessao_id` não junta com a planilha.

**Demonstrável na review:** o gráfico estação × decibelímetro com o R² escrito nele, e um ponto medido que atravessou até aparecer num mapa **sem intervenção manual improvisada**.

> [!important] Se o dado não atravessa o pipeline com 1 ponto, não vai atravessar com 48
> Descobrir isso agora custa um ajuste. Descobrir em novembro custa refazer o campo, e não há campo para refazer.

---

## Sprint 8 — 9 pontos + 3 sessões · 14/10 a 20/10

> [!abstract] Meta da sprint
> O campo começou e o dado da primeira sessão já foi digitalizado.

| ID | Story | Frente | Dono | Origem | Pts |
|---|---|---|---|---|---|
| US-24 | Ajustes pós-piloto no protocolo e no firmware | 🚶 | ⬛ time | T12 | 3 |
| US-27 | Digitalizar as planilhas no mesmo dia | 📊 | G. Falcão | T14 | 3 |
| US-31 | GTFS da URBS cruzado com os 12 pontos | 📊 | Arthur | T16 | 3 |

**Janelas agendadas:** sessões **1, 2 e 3** de `US-25`. Sem pontos — ver o aviso abaixo.

**Foco:** carga de pontos deliberadamente baixa, porque a semana já tem três saídas de campo comendo o calendário de cinco pessoas.

**Demonstrável na review:** três sessões com âncora no início e no fim, planilhas digitalizadas no mesmo dia, e o número de paradas de ônibus por ponto.

---

## Sprint 9 — 13 pontos + 3 sessões · 21/10 a 27/10

> [!abstract] Meta da sprint
> O pipeline lê, limpa e normaliza — sobre os dados que já existem, sem esperar as 12 sessões.

| ID | Story | Frente | Dono | Origem | Pts |
|---|---|---|---|---|---|
| US-28 | Pipeline: leitura, limpeza e descarte de sessão inválida | 📊 | Arthur | T15 | 5 |
| US-29 | Normalização pela deriva do ponto-âncora | 📊 | Arthur | T15 | 5 |
| US-13 | Modo demo: dB ao vivo via HTTP e OLED | 💻 | João | T19 | 3 |

**Janelas agendadas:** sessões **4, 5 e 6**.

**Foco:** o pipeline é construído **sobre dado parcial e re-rodado depois**. Esperar as 12 sessões para começar a programar deixaria uma única semana entre o fim do campo e a feira.

**Demonstrável na review:** o antes/depois da normalização por âncora numa sessão real, e o número em dB(A) mudando no celular de alguém da banca pela rede local.

---

## Sprint 10 — 8 pontos + 3 sessões · 28/10 a 03/11

> [!abstract] Meta da sprint
> O resultado do trabalho existe: as três correlações estão calculadas.

| ID | Story | Frente | Dono | Origem | Pts |
|---|---|---|---|---|---|
| US-30 | Agregação por ponto e por tipologia | 📊 | Arthur | T15 | 3 |
| US-32 | Correlação LAeq × pedestres × veículos × ônibus | 📊 | Arthur | T17 | 5 |

**Janelas agendadas:** sessões **7, 8 e 9**.

**Foco:** `US-37` escreve a metade do relatório que **não depende de resultado** — problema, hipótese, metodologia. É o que impede que 20 páginas caiam na última semana.

**Demonstrável na review:** o gráfico principal com o calçadão da XV destacado como outlier, e a conclusão escrita em uma frase.

> [!note] A correlação roda com 9 sessões e é re-rodada na Sprint 11
> Rodar cedo com dado parcial é o que revela se falta variável, se o N é insuficiente, ou se a extrapolação de contagem no calçadão distorce o resultado.

---

## Sprint 11 — 12 pontos + 3 sessões · 04/11 a 10/11

> [!abstract] Meta da sprint
> O campo fechou, o mapa está publicado e o relatório está inteiro.

| ID | Story | Frente | Dono | Origem | Pts |
|---|---|---|---|---|---|
| US-33 | Mapa web publicado no GitHub Pages | 📊 | Arthur | T18 | 5 |
| US-38 | Relatório: resultados, discussão e limitações | ✍️ | Gustavo | T20 | 5 |
| US-35 | Dataset aberto com dicionário de dados | 📊 | Gustavo | Entregável 4 | 2 |

**Janelas agendadas:** sessões **10, 11 e 12** — as últimas.

**Foco:** ao fim desta sprint o conteúdo do trabalho está fechado. A Sprint 12 é só apresentação.

**Demonstrável na review:** o endereço do mapa aberto de outra máquina, e o relatório completo com a seção de limitações escrita.

> [!danger] Última chance de usar as sessões de reserva
> As 2 reservas de chuva precisam caber aqui. Se as 12 sessões não fecharem até 10/11, o corte de [[Riscos]] vale: manter as tipologias **3 e 4** e cortar 5 e 6.

---

## Sprint 12 — 12 pontos · 11/11 a 17/11 · **FEIRA** *(data suposta)*

> [!abstract] Meta da sprint
> O stand funciona, e funciona também quando o hardware falha.

| ID | Story | Frente | Dono | Origem | Pts |
|---|---|---|---|---|---|
| US-39 | Pôster do stand | ✍️ | Gustavo | T20 | 3 |
| US-42 | Ensaio do stand com alguém de fora | ✍️ | ⬛ time | T21 | 3 |
| US-34 | O mapa abre no celular, em rede móvel | 📊 | Arthur | T18 | 2 |
| US-40 | Roteiro do pitch de 2 minutos | ✍️ | Gustavo | T20 | 2 |
| US-41 | Vídeo plano B da demo | ✍️ | João | T21 | 2 |

**Ordem dentro da semana:** `US-39` primeiro — o pôster precisa ir para impressão **com 3 dias de antecedência**. Depois `US-41`, `US-40`, `US-34` e `US-42` por último, já com tudo montado.

**Foco:** nada de funcionalidade nova. Só fechar, ensaiar e blindar.

**Demonstrável na review:** o ensaio completo, com alguém de fora do grupo conseguindo repetir a ideia principal com as próprias palavras.

> [!danger] Hardware falha em feira. Sempre.
> Ordem de degradação: estação ao vivo → vídeo → mapa → pôster. Em qualquer nível o stand ainda comunica a ideia. `US-41` não é opcional.

---

## Sprint 13 — buffer · 18/11 a 24/11

Sem stories planejadas. **Toda a folga do cronograma está aqui.**

> [!warning] Se o buffer for consumido antes da Sprint 10
> É o gatilho de [[Riscos]]: ir direto para o [[Escopo Reformulado|escopo mínimo garantido]]. O plano de corte, na ordem exata, está em [[Scrum do Projeto]].

---

## As três coisas que este plano trata como calendário, não como esforço

| O que | Onde aparece | Por que não vira ponto |
|---|---|---|
| **As 12 sessões de campo** (`US-25`, T13) | Sprints 8 a 11, 3 por sprint | Exige 5 pessoas simultâneas, em janela de pico, em dia sem chuva. Não acelera com mais trabalho. ~210 h-pessoa fora do orçamento de pontos |
| **A entrega do hardware** (`US-15`, T2) | Sprint 2 → chega na 3 ou 4 | 3 a 10 dias em que ninguém consegue fazer nada. Comprar vale 1 ponto; esperar não vale nenhum |
| **O empréstimo do calibrador** (`US-19`, T9) | Perguntado na Sprint 5, usado na 7 | Depende da resposta de um laboratório. Duas sprints de folga entre perguntar e precisar |

---

**Relacionadas:** [[Scrum do Projeto]] · [[Backlog do Produto]] · [[Definição de Pronto]] · [[WBS e Gantt]] · [[Riscos]] · [[Alocação do Grupo]]
