# Riscos

Cada risco tem mitigação já embutida no cronograma. Revisar esta nota no início de cada fase.

---

## 🔴 Alto impacto

### Primeiro projeto do grupo com ESP32 físico
O SIA anterior foi **inteiramente simulado**. Hardware real traz problemas que simulador nunca mostra.

**Mitigação:** T4 roda no Wokwi e T5 no desktop, **em paralelo à entrega das peças** ([[Registro de Decisões|D-13]]). O grupo chega na bancada com código pronto. Além disso, [[Montagem e Ligações]] manda montar **um módulo por vez**, nunca tudo de uma vez.

### Hardware atrasa na entrega
T2 é o início do caminho crítico e a espera é tempo de **calendário** — não dá pra recuperar trabalhando mais.

**Mitigação:** comprar em **S1**, só lojas nacionais (3–10 dias), e manter as tarefas não-bloqueantes rodando nesse intervalo.

### Coletas não acontecem por falta de gente
T13 exige **5 pessoas simultaneamente, 12 vezes, em horário de pico**. É agenda, não esforço.

**Mitigação:** combinar as 12 datas já em **S3**, com confirmação nominal. 2 datas de reserva. Ver [[Alocação do Grupo]].

---

## 🟡 Médio impacto

### Componente queima na montagem
Especialmente o INMP441, que é 3.3V.

**Mitigação:** conferir tensão com multímetro **antes** de energizar; testar módulo por módulo; comprar o INMP441 de fornecedor que aceite troca. Se possível, um sobressalente do microfone.

### Chuva nas semanas de coleta
Pista molhada altera o ruído de rolamento ([[Registro de Decisões|D-12]]).

**Mitigação:** 2 sessões de reserva no cronograma; checar previsão antes de sair; sessão com chuva é **cancelada e refeita**, nunca "corrigida".

### Cartão SD corrompe e perde uma sessão
D-08 fez do cartão o ponto único de falha.

**Mitigação:** teste de queda de energia em [[Verificação]] (item 4); **copiar o CSV no mesmo dia** da coleta; cartão de marca conhecida, não o mais barato.

### Sem acesso a calibrador acústico
O pistonfone está fora do orçamento.

**Mitigação:** calibração por transferência com decibelímetro classe 2, em ≥3 níveis; tentar empréstimo na PUC; **declarar como limitação metodológica** no relatório. Ver [[Calibração]].

### O A-weighting não fica pronto a tempo
É a tarefa mais difícil do projeto (T5/T8).

**Mitigação:** começa em **S2**, fora do caminho crítico, validada no desktop antes de portar. Plano B: entregar o mapa em **nível relativo calibrado por transferência**, declarando que a ponderação A não foi aplicada. Enfraquece o trabalho, mas não o mata.

### Membros somem na reta final
Comum em trabalho de grupo, especialmente perto de provas.

**Mitigação:** frentes com dono nominal desde S1; a frente de Escrita começa em **S10**, não na véspera; [[Progresso do Projeto]] atualizado semanalmente pra que a ausência apareça cedo.

---

## 🟢 Baixo impacto

### Demo falha no dia da feira
Bateria acaba, alguém esbarra na mesa, o WiFi do evento não coopera.

**Mitigação:** **vídeo gravado como plano B** ([[Registro de Decisões|D-14]]); o mapa web funciona sem hardware nenhum; power bank carregado e um segundo cabo USB na mochila.

### Orçamento estoura
As estimativas de [[Orçamento em Camadas]] não são preços verificados.

**Mitigação:** camadas permitem cortar de baixo pra cima sem replanejar. WROOM-32 no lugar do S3 economiza ~R$45; tripé improvisado economiza ~R$60.

### Professor não aceita a reformulação
Ele já sinalizou flexibilidade — aceita outra proposta desde que ligada a mapa de ruído.

**Mitigação:** T1 acontece **antes** da compra. O argumento é o calçadão da XV ([[A Hipótese em Teste]]), apresentado como *pergunta interessante*, não como crítica. Se ele recusar, a Saída A pura (só o mapa) continua sendo um projeto completo.

---

## Gatilhos de corte de escopo

Se qualquer um destes acontecer, **corte antes que o buffer S13 seja consumido**:

| Gatilho | Corte |
|---|---|
| Hardware não chegou até o fim de S3 | Cortar a segunda repetição das medições (48 → 24) |
| Estação não calibrada até o fim de S6 | Entregar em nível relativo, declarando a limitação |
| Menos de 8 sessões feitas até o fim de S9 | Cortar tipologias 5 e 6; **manter 3 e 4** |
| Buffer S13 consumido antes de S10 | Ir direto para o [[Escopo Reformulado\|escopo mínimo garantido]] |

Relacionado: [[WBS e Gantt]], [[Verificação]], [[Progresso do Projeto]].
