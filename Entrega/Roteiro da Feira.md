# Roteiro da Feira

O formato é **feira/mostra**, não banca de TCC. Isso muda a prioridade: **demo funcionando > rigor de artigo**. As pessoas passam pelo stand em 2 minutos e precisam sair entendendo uma ideia.

---

## A ideia que a pessoa tem que levar embora

> "Eles construíram um medidor de ruído de R$500 e descobriram que **barulho não indica onde as pessoas estão** — o calçadão da XV tem multidão e pouco ruído."

Se a pessoa sai sabendo disso, o stand funcionou. Todo o resto é apoio.

---

## Montagem do stand

| Elemento | Função |
|---|---|
| **Estação ligada**, medindo ao vivo com OLED visível | O ímã que para a pessoa |
| **Pôster** com o gráfico de correlação | O argumento |
| **Notebook/tablet** com o mapa web aberto | A profundidade, pra quem quiser mais |
| Placa com QR code do repositório | Pra quem quiser levar |
| Os componentes soltos ao lado (INMP441, DS3231) | Deixa tocar — funciona muito bem em feira |

---

## O pitch de 2 minutos

1. **Gancho (15s)** — "Fala perto do microfone." A pessoa vê o número subir no display. Agora ela está interessada.
2. **O problema (20s)** — "Um professor propôs usar ruído pra decidir onde colocar mais ônibus. Parece fazer sentido: mais barulho, mais movimento."
3. **A virada (30s)** — "Só que a gente foi medir o calçadão da XV. Multidão de pedestres, quase nenhum veículo — ruído baixo. Se seguíssemos a lógica original, a XV não precisaria de ônibus."
4. **O que fizemos (30s)** — "Construímos essa estação por ~R$500, medimos 12 pontos de Curitiba em 6 tipologias diferentes, e contamos pedestres e veículos na mão ao mesmo tempo pra testar a hipótese."
5. **O resultado (25s)** — mostrar o gráfico: "ruído prevê **veículos** muito bem. Prevê **pessoas**, não."
6. **Fechamento** — apontar o mapa web e o QR code.

> [!tip] Todo mundo do grupo precisa saber dar esse pitch
> Não é o "apresentador oficial" que fala — é quem estiver livre quando a pessoa chegar. Ensaiar em T21 com alguém de fora do grupo ouvindo.

---

## Perguntas que vão fazer (e as respostas)

| Pergunta | Resposta curta |
|---|---|
| "Isso é preciso mesmo?" | "Calibramos por comparação com um decibelímetro comercial em três níveis. Não é padrão de laboratório e a gente declara isso — mas a resposta é linear e consistente." |
| "Por que não usaram um app de celular?" | "Microfone de celular não tem sensibilidade especificada e o sistema aplica processamento automático. O INMP441 tem datasheet, e a gente controla a cadeia inteira." |
| "Por que não mediram a cidade toda?" | "Com uma estação e 12 semanas, cobertura ampla sairia rasa. Preferimos 12 pontos bem escolhidos por tipologia, com repetição e controle temporal." |
| "E o professor concordou com vocês?" | "A proposta dele continua de pé — a gente só parou de assumir a resposta e passou a medir. Os dois resultados possíveis eram interessantes." |
| "Dá pra usar isso pra alguma coisa de verdade?" | "O mapa de ruído sim — exposição a ruído urbano é questão de saúde pública. Pra alocar ônibus, precisaria de dados de demanda da URBS, que a gente não tem." |

---

## Plano B — quando o hardware falha

> [!danger] Hardware falha em feira. Sempre.
> Bateria acaba, alguém esbarra na mesa, o WiFi do evento não coopera.

- **Vídeo gravado** da estação funcionando, no celular de **pelo menos duas pessoas** do grupo ([[Registro de Decisões|D-14]])
- **Mapa web** funciona sem hardware nenhum — e está publicado, então abre de qualquer celular
- **Pôster** carrega o argumento sozinho
- Power bank carregado + **cabo USB reserva** na mochila

Ordem de degradação: estação ao vivo → vídeo → mapa → pôster. Em qualquer nível, o stand ainda comunica a ideia principal.

---

## Checklist do dia

- [ ] Estação carregada e testada **na véspera**
- [ ] Cabo USB reserva + power bank cheio
- [ ] Vídeo plano B em 2 celulares
- [ ] Pôster impresso (imprimir com 3 dias de antecedência, não na véspera)
- [ ] Mapa web aberto e testado na rede do evento
- [ ] QR code do repositório testado
- [ ] Componentes soltos pra mostrar
- [ ] Escala de quem fica no stand em cada horário

Relacionado: [[Entregáveis]], [[Verificação]], [[A Hipótese em Teste]].
