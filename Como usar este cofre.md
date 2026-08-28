# Como usar este cofre

Este cofre existe pra o grupo **nunca perder o rastro** de uma decisão e pra qualquer membro conseguir **retomar de onde parou** — inclusive quem não estava na conversa que definiu o escopo. Ele responde quatro perguntas:

| Quando você pensar... | Vá para... |
|---|---|
| "Por que decidimos X?" | [[Registro de Decisões]] |
| "Como eu meço esse ponto?" | [[Protocolo de Medição]] |
| "O que eu preciso estudar pra entender isso?" | [[Cronograma de Estudos]] |
| "O que ainda falta decidir/comprar?" | [[Status das Pendências]] |

## As camadas de registro

1. **Escopo** — o *o quê*. O [[Escopo Reformulado]] é o contrato. Se alguém propuser algo que não está lá, isso vira uma decisão registrada, não uma mudança silenciosa.
2. **Decisões** — o *porquê*. Cada escolha importante vira uma entrada no [[Registro de Decisões]] no formato **Contexto → Decisão → Consequência**. É o que você lê pra defender a escolha na banca ou pro professor.
3. **Metodologia** — o *como medir*. É a parte que separa este projeto de "um sensor de barulho de Arduino". Se o protocolo não for seguido, o dado não vale.
4. **Estudos** — o *como aprender*. Pra cada assunto, o que é, por que está no projeto, os fundamentos a dominar e onde estudar.

## Regras de campo

> [!warning] O protocolo não é sugestão
> Uma sessão de campo feita fora do [[Protocolo de Medição]] é uma sessão **perdida** — não dá pra "consertar depois na análise". Se algo der errado em campo (chuva, obra, bateria), **registre e refaça**, não improvise.

- Toda sessão registra o **ponto-âncora** no início e no fim. Sem isso os dados da sessão não são comparáveis com os das outras.
- Quem opera a estação **não conta** pedestres. São papéis diferentes — ver [[Contagem Manual]].
- Foto de cada ponto, sempre. Serve pro relatório e pra explicar outlier depois.

## Como isso conecta com o código

- O firmware e o pipeline Python vivem no repositório GitHub; este cofre guarda o **porquê** de cada escolha técnica.
- Ao decidir algo novo durante a implementação, **registre aqui primeiro**, depois code. O cofre nunca fica atrás do código.
- Ao aprender algo que te destravou, adicione uma linha na nota de Estudos correspondente. O cofre cresce com o grupo.

## Links `[[assim]]`

No Obsidian, `[[Nome da Nota]]` cria um link navegável. Abra o **grafo** na lateral pra ver o mapa de como escopo, decisões, metodologia e estudos se conectam. Um link pra nota que ainda não existe aparece "apagado" — é um lembrete do que falta escrever.
