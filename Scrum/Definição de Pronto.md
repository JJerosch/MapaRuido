# ✅ Definição de Pronto — Mapa de Ruído de Curitiba

Os contratos de qualidade do grupo. Sem eles, "pronto" quer dizer coisas diferentes para cada pessoa — e num projeto com hardware e campo, isso custa uma sessão inteira.

> [!important] Este projeto tem quatro definições, não uma
> Um DoD só de software não serve aqui. Além do geral, existem contratos separados para **sessão de campo válida**, **medição confiável** e **nota do cofre** — porque cada um falha de um jeito diferente e nenhum deles é verificável clicando num navegador.

---

## Definição de Preparado (DoR)

Uma story só entra numa sprint quando:

- [ ] Está escrita no formato **como / quero / para**
- [ ] Tem critérios de aceite **verificáveis** — dá para dizer sim ou não, sem discussão
- [ ] Está estimada em pontos pelo grupo, e quem estimou é quem vai fazer
- [ ] Não depende de nada que ainda não exista
- [ ] Cabe numa sprint — se passar de **5 pontos**, quebre em duas
- [ ] Tem dono nominal, não "alguém do firmware"
- [ ] Se depende de peça comprada, a peça **já chegou e foi inventariada**
- [ ] Se depende de agenda de campo, a data já está confirmada pelos 5

---

## Definição de Pronto (DoD) — geral

Uma story só é dada como pronta quando **todos** os itens abaixo valem:

### Funcionamento
- [ ] Todos os critérios de aceite passam
- [ ] Foi verificada de verdade, não "deve funcionar"
- [ ] O resultado foi anotado **com o número**, não com a palavra "passou" — 
      "R² = 0,974", não "calibrou bem" ([[Verificação]])
- [ ] Os casos de erro foram testados: cartão ausente, arquivo vazio, sessão sem âncora

### Código e dados
- [ ] Commitado no repositório, na pasta certa (`/firmware`, `/analise`, `/dados`)
- [ ] Nenhum caminho absoluto da máquina de quem escreveu ficou no código
- [ ] Nenhum dado de campo existe **só** na máquina de uma pessoa
- [ ] Se o formato do CSV mudou, mudou **nos dois lados** — firmware e pipeline
- [ ] Média de dB é sempre **energética**, nunca aritmética ([[Acústica e dB(A)]])

### Rastro
- [ ] Qualquer decisão nova tomada no caminho está em [[Registro de Decisões]]
- [ ] Qualquer pendência resolvida foi fechada em [[Status das Pendências]]
- [ ] **O que deu errado ficou anotado, mesmo já resolvido** — é conteúdo de relatório
- [ ] [[Progresso do Projeto]] reflete o novo estado

---

## DoD de **sessão de campo válida**

> [!danger] Uma sessão fora deste contrato é uma sessão perdida
> Não dá para consertar depois na análise. Se algo der errado em campo, **registre e refaça** — não improvise. Este é o contrato que [[Protocolo de Medição]] impõe, transformado em checklist de aceite.

Uma sessão de `US-25` só conta quando **todos** valem:

### Âncora
- [ ] Âncora medida **no início** da sessão, na posição exata registrada em `US-22`
- [ ] Âncora medida **no fim** da sessão, na mesma posição
- [ ] As duas leituras estão no CSV com o `ponto_id` reservado da âncora

> Sem as duas leituras, os dados da sessão **não são comparáveis com os das outras** e a sessão inteira é refeita. É [[Registro de Decisões|D-04]], e é inegociável.

### Papéis
- [ ] Os **5 papéis estavam ocupados**: operador, contador A, contador B, contador C, escriba
- [ ] **Nenhum papel foi acumulado** — quem opera a estação não conta ([[Contagem Manual]])
- [ ] A contagem manual começou **no mesmo instante** da medição, não depois

### Registro
- [ ] **Foto de cada ponto medido** e do entorno
- [ ] Planilha de campo preenchida por ponto: `sessao_id`, `ponto_id`, hora, janela, clima, contagens, ocorrências
- [ ] Se algum fluxo foi contado em sub-janela e extrapolado, **está marcado como extrapolado**
- [ ] Obra, evento, feira ou manifestação no dia foram **anotados** — não cancelam a sessão, mas explicam o outlier três meses depois
- [ ] Coordenada conferida contra a ficha do ponto

### Fechamento no mesmo dia
- [ ] CSV copiado do cartão **no mesmo dia** — o cartão é ponto único de falha ([[Registro de Decisões|D-08]])
- [ ] Planilhas **fotografadas antes** de digitar
- [ ] Planilhas digitalizadas no mesmo dia, com conferência cruzada
- [ ] Pontos fechados anotados em [[Progresso do Projeto]]

### Invalidadores automáticos

Se qualquer um destes ocorreu, a sessão ou o ponto **não passa**:

| Ocorrência | Consequência |
|---|---|
| Faltou a âncora inicial ou a final | **Sessão inteira refeita** |
| Choveu durante a sessão | Pontos afetados descartados e refeitos ([[Registro de Decisões\|D-12]]) |
| A estação foi segurada na mão em vez do tripé | Aquele ponto descartado |
| Windscreen caiu ou foi esquecido | Aquele ponto descartado |
| Papéis acumulados por falta de gente | Sessão não conta — remarcar com os 5 |
| O cartão não gravou | Aquele ponto descartado; conferir no OLED antes de sair de cada ponto |

---

## DoD de **medição confiável**

Todo ponto medido carrega este contrato. Ele é o que separa o projeto de um sensor de barulho de Arduino.

### Instrumento
- [ ] A **calibração está vigente** — a constante de `US-20` está gravada no firmware e não foi alterada desde a última verificação
- [ ] A verificação de deriva está em dia: completa antes da primeira sessão, checagem no meio da campanha, checagem final ([[Calibração]])
- [ ] O windscreen está no lugar, **mesmo sem vento aparente**
- [ ] A calibração vigente foi feita **com a caixa fechada e o windscreen posto** — os dois alteram a resposta

### Posicionamento
- [ ] Altura entre **1,3 e 1,5 m** do solo, no tripé — nunca na mão, o corpo do operador reflete som
- [ ] **≥2 m** de qualquer superfície refletora
- [ ] Distância à via **consistente com os outros pontos da mesma tipologia**, e anotada

### Aquisição
- [ ] **10 minutos contínuos** de medição ([[Registro de Decisões|D-11]])
- [ ] Nenhuma conversa alta perto do microfone durante a janela
- [ ] O OLED foi conferido durante a medição — o número estava se movendo
- [ ] O registro foi fechado e a gravação conferida **antes de sair do ponto**

### Saída
- [ ] A linha gravada está no **formato congelado** de `US-07`, sem coluna faltando
- [ ] `LAeq`, `Lmax`, `L10` e `L90` estão preenchidos, nenhum como `NaN` ou zero
- [ ] `sessao_id` e `ponto_id` batem exatamente com a planilha de contagem correspondente

---

## DoD de **nota do cofre**

Vale para qualquer nota criada ou alterada neste projeto — inclusive as de `Scrum\`.

- [ ] Título com emoji e uma frase de abertura dizendo para que a nota serve
- [ ] Dados comparáveis estão em **tabela**, não em lista solta
- [ ] Ressalvas usam callout do Obsidian (`> [!info]`, `> [!warning]`, `> [!danger]`, `> [!success]`)
- [ ] Todos os links são `[[wikilinks]]` de verdade, e nenhum aponta para nota inexistente
- [ ] Linha final `**Relacionadas:** [[A]] · [[B]]`
- [ ] **Datas absolutas** (`26/08/2026`), nunca "semana que vem"
- [ ] **Os números batem com todas as outras notas** que citam o mesmo número
- [ ] Se a nota foi superada, tem callout dizendo **qual decisão a substituiu** — não se apaga histórico

---

## O teste de ponta a ponta

O projeto está pronto quando isto rodar inteiro, no dia da feira, **sem ninguém do grupo abrir um terminal**:

1. Ligar a estação e ver número em dB(A) no OLED em **menos de 1 minuto**
2. Falar perto do microfone e ver o número subir e voltar
3. Abrir a página do modo demo no celular de uma pessoa de fora
4. Abrir o mapa web publicado, em **rede móvel**, no celular dessa mesma pessoa
5. Clicar num dos 12 pontos e ver LAeq, contagens e foto no popup
6. Ligar a camada de transporte público e ver as paradas de ônibus
7. Mostrar o gráfico principal do pôster, com o calçadão da XV destacado
8. Alguém do grupo — **qualquer um dos 5** — explica o argumento da XV em menos de 2 minutos
9. Desligar a estação no meio de tudo e continuar a apresentação pelo vídeo, pelo mapa e pelo pôster

> [!note] Por que o passo 9 está aqui
> Não é pessimismo. Hardware falha em feira: bateria acaba, alguém esbarra na mesa, o WiFi do evento não coopera. A ordem de degradação — estação ao vivo → vídeo → mapa → pôster — é [[Registro de Decisões|D-14]], e é para ser **ensaiada**, não improvisada.

Os passos 1, 2, 7 e 8 são os que não podem cair se o tempo apertar: são a demo ao vivo e a arguição, que é o que pontua.

---

**Relacionadas:** [[Scrum do Projeto]] · [[Backlog do Produto]] · [[Plano de Sprints]] · [[Protocolo de Medição]] · [[Verificação]] · [[Contagem Manual]] · [[Calibração]]
