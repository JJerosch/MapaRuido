# A Hipótese em Teste

> [!important] Esta é a nota mais importante do cofre
> É o que diferencia o projeto de uma coleta de números. Leia antes de falar com o professor e antes de montar o pôster.

## A hipótese original

> "Lugares mais barulhentos são mais movimentados; lugares mais movimentados têm mais demanda por ônibus; logo, o mapa de ruído indica onde alocar ônibus."

## Por que ela não se sustenta sozinha

A cadeia lógica tem furos em cada elo:

- **Ruído mede tráfego de veículos, não pessoas.** Uma via expressa cheia de carros é ensurdecedora e pode não ter um único pedestre.
- **Demanda por ônibus vem de densidade residencial e renda**, não de decibéis. Um bairro residencial denso é relativamente silencioso e cheio de gente que depende de transporte público.
- **Curitiba já tem BRT nos eixos estruturais** — que são justamente os mais barulhentos. O mapa tende a "descobrir" corredores que já são super atendidos.
- **Confundidores**: tipo de asfalto, limite de velocidade, tráfego de caminhões, obras, efeito de cânion entre prédios, distância do microfone à via.

## O argumento decisivo — o calçadão da Rua XV

> [!tip] Use este exemplo com o professor e no stand
> A **Rua XV de Novembro** é um calçadão exclusivo de pedestres. Tem **muitíssima gente** e **quase nenhum veículo**.
>
> Se a hipótese valesse, a XV seria "silenciosa, logo sem demanda de transporte" — o que é obviamente absurdo para qualquer pessoa que já andou por lá.
>
> Isso derruba o proxy **sem precisar de uma linha de estatística**. É por isso que a XV está na [[Amostra Estratificada]] como ponto obrigatório.

O par oposto é a **rua residencial densa** (tipologia 3): baixo ruído, alta demanda real. Juntos, esses dois pontos são o resultado do trabalho.

## O que fazemos em vez de descartar

Não se descarta a ideia do professor — **para-se de assumir a conclusão e passa-se a investigá-la**. Metodologia híbrida:

**Saída A — o mapa é o produto.**
O mapa de ruído tem valor próprio, independente de ônibus: exposição a ruído urbano é questão de saúde pública, e a cidade tem legislação de ruído. O entregável principal é o mapa e sua metodologia.

**Saída B — o proxy vira a pergunta de pesquisa.**
Coleta-se ruído **e** verdade de campo (contagem manual de pedestres e veículos), e calcula-se a correlação:

| Resultado esperado | Interpretação |
|---|---|
| LAeq × contagem de **veículos** → correlação forte | Confirma que o sensor funciona e mede o que deveria |
| LAeq × contagem de **pedestres** → correlação fraca ou nula | **A descoberta:** o proxy não serve pra estimar demanda |

> [!note] Os dois resultados são publicáveis
> R² alto → você *provou* o proxy. R² baixo → você *provou que ele não funciona*, resultado igualmente válido e mais interessante. O que não é aceitável é assumir a resposta sem medir.

## Como apresentar isso ao professor

1. Comece pelo que **mantém** a ideia dele: o projeto continua sendo ruído + transporte público em Curitiba.
2. Apresente o calçadão da XV como caso concreto — não como crítica, como *pergunta interessante*.
3. Proponha a reformulação como **ganho de rigor**: "em vez de assumir, a gente mede e mostra".
4. Registre o resultado da conversa em [[Registro de Decisões]].

Relacionado: [[Escopo Reformulado]], [[Contagem Manual]], [[Amostra Estratificada]].
