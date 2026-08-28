# Acústica e dB(A)

> [!important] Nota obrigatória para todos os 5 membros
> É o vocabulário mínimo pra conversar sobre o projeto — e pra responder pergunta no stand sem enrolar.

## O que é

Som é **variação de pressão** no ar. O ouvido humano percebe uma faixa enorme de pressões, então usa-se uma escala **logarítmica**: o decibel.

O **nível de pressão sonora (SPL)** compara a pressão medida com uma pressão de referência (o limiar aproximado da audição humana). Como é logarítmico:

- **+3 dB** ≈ o dobro da energia sonora
- **+10 dB** ≈ percebido como "duas vezes mais alto" pelo ouvido
- Dois ruídos iguais somados dão **+3 dB**, não o dobro do número

> [!warning] Decibel não soma como número normal
> 60 dB + 60 dB = 63 dB, não 120 dB. Isso vale pra qualquer conta que o pipeline fizer — média de dB é média **energética**, não aritmética. Errar isso é o erro clássico de projeto de ruído.

## O "A" do dB(A)

O ouvido **não escuta todas as frequências com a mesma sensibilidade** — é bem menos sensível a graves. Um som grave e um agudo com a mesma pressão física não são percebidos com a mesma intensidade.

A **ponderação A** é um filtro que corrige a medição pra aproximar essa percepção, atenuando fortemente as baixas frequências. É por isso que o descritor padrão de ruído urbano é **dB(A)** e não dB puro.

Detalhes de implementação em [[Ponderação A e LAeq]].

## Por que neste projeto

- Todo o projeto mede **dB(A)** — sem entender o que isso significa, não dá pra defender o resultado
- A [[Calibração]] existe pra transformar número interno do microfone em dB SPL de verdade
- A soma logarítmica aparece no pipeline, na agregação de amostras
- No stand, alguém **vai** perguntar "isso é decibel de verdade?" — e a resposta precisa ser sólida

## Fundamentos a dominar

- Pressão sonora e por que a escala é logarítmica
- Nível de referência e o que significa 0 dB SPL
- Soma e média **energética** de níveis (nunca aritmética)
- O que a ponderação A faz e por que existe
- Diferença entre **nível instantâneo** e **nível equivalente** (LAeq)
- Ordens de grandeza de referência, pra ter noção de escala:

| Ambiente | Ordem de grandeza |
|---|---|
| Quarto silencioso à noite | ~30 dB(A) |
| Conversa normal | ~60 dB(A) |
| Calçada de via movimentada | ~70–80 dB(A) |
| Buzina próxima / obra | 90+ dB(A) |

*(valores aproximados, pra calibrar intuição — não são referência de norma)*

## Onde estudar

- Material introdutório de **acústica ambiental** de cursos de engenharia
- Documentação técnica de fabricantes de instrumentos de medição (Brüel & Kjær e similares publicam guias didáticos bons e gratuitos)
- A própria **NBR 10151**, para as definições formais → [[NBR 10151 e Normas]]

## Como saber que entendeu

Você consegue explicar, sem consultar:
1. Por que 60 dB + 60 dB dá 63 dB
2. Por que a medição usa ponderação A em vez de dB puro
3. Por que um valor instantâneo de dB não descreve um ambiente sonoro

Se conseguir explicar os três pra alguém de fora da área em 3 minutos, está pronto pro stand.

Relacionado: [[Ponderação A e LAeq]], [[Calibração]], [[NBR 10151 e Normas]].
