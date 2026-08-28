# O que é o projeto

## Em uma página

Uma **estação portátil de medição de ruído** construída com ESP32 e microfone digital I2S, orçamento de ~R$500, usada para medir níveis sonoros em **12 pontos fixos** de Curitiba escolhidos por tipologia urbana. Os dados viram um **mapa de ruído web interativo**, cruzado com a rede de transporte público (GTFS da URBS).

Em paralelo à medição, o grupo faz **contagem manual de pedestres e veículos** nos mesmos pontos e horários. Isso permite **testar estatisticamente** a hipótese que originou o projeto — em vez de assumi-la. Ver [[A Hipótese em Teste]].

## Título

> **"Ruído urbano e transporte público em Curitiba: mapeamento de baixo custo com ESP32 em pontos fixos e teste da hipótese do ruído como proxy de demanda"**

## De onde veio

A proposta original de um professor era um ESP32 embarcado num carro medindo dB(A) + GPS pelas ruas, para indicar **onde alocar ônibus**, partindo da premissa "mais ruído = mais movimento = mais demanda".

Três problemas mataram a versão ingênua dessa proposta:

1. **A premissa não fecha** — ruído correlaciona com tráfego de *veículos*, não com *pessoas precisando de ônibus*. Detalhado em [[A Hipótese em Teste]].
2. **Medir de dentro de um carro em movimento é ruim** — ruído de pneu domina acima de ~40 km/h e vem do *próprio* veículo; vento destrói o sinal; a cabine isola.
3. **Ninguém do grupo tinha experiência com ESP32 físico** — o projeto anterior (SIA) foi inteiramente simulado.

A reformulação resolve o problema 2 de graça (pontos fixos) e transforma o problema 1 na **contribuição do trabalho**.

## Contexto de entrega

| | |
|---|---|
| Formato | Feira / mostra de projetos |
| Data | Novembro/2026 |
| Equipe | 5 membros, perfis mistos |
| Orçamento | Até R$500, lojas nacionais |
| Consequência do formato | **Demo funcionando > rigor de artigo.** O stand precisa de algo vivo. |

## Por onde começar a ler

1. [[Escopo Reformulado]] — o contrato completo
2. [[A Hipótese em Teste]] — o coração do argumento
3. [[Protocolo de Medição]] — o que fazer em campo
4. [[WBS e Gantt]] — quando fazer cada coisa
