# GTFS e Dados Abertos

## O que é

**GTFS** (*General Transit Feed Specification*) é o formato padrão internacional para publicar dados de transporte público. É um conjunto de arquivos CSV dentro de um `.zip`, com linhas, pontos de parada, itinerários e horários.

É o mesmo formato que o Google Maps consome pra mostrar rotas de ônibus.

## Por que neste projeto

É o que transforma "coletamos uns números" em **análise urbana**. Sem cruzar com a rede real de ônibus, o mapa de ruído fica solto; com o cruzamento, ele conversa com a pergunta original do professor.

É a tarefa **T16** do [[WBS e Gantt]].

## Fontes

| Fonte | O que tem |
|---|---|
| **URBS** | Dados do transporte de Curitiba: linhas, pontos, itinerários, feed GTFS |
| **Portal de dados abertos da Prefeitura de Curitiba** | Camadas urbanas diversas |
| **OpenStreetMap** | Malha viária, se precisar de contexto de rua no mapa |

> [!note] Verificar disponibilidade e licença antes de contar com o dado
> Portais de dados abertos mudam de endereço, formato e política de acesso. **Confirme o que está publicado hoje** antes de planejar a análise em cima disso — e registre a data de download e a licença, porque isso vai no relatório.

## Arquivos GTFS que interessam

| Arquivo | Conteúdo | Uso aqui |
|---|---|---|
| `stops.txt` | Pontos de parada, com lat/lon | Distância de cada ponto de medição à parada mais próxima |
| `routes.txt` | Linhas | Identificar tipo de linha (BRT, alimentador, convencional) |
| `trips.txt` | Viagens de cada linha | Ligar linha ↔ itinerário |
| `stop_times.txt` | Horários por parada | **Frequência de atendimento** por parada — a variável mais interessante |
| `shapes.txt` | Traçado geográfico das linhas | Desenhar a rede no mapa |

> [!warning] `stop_times.txt` é grande
> É de longe o maior arquivo do feed. Carregue com `pandas` filtrando só as colunas necessárias, ou o notebook vai engasgar.

## O que a análise vai extrair

Para cada um dos 12 pontos de medição:

1. **Distância à parada de ônibus mais próxima**
2. **Frequência de atendimento** dessa parada na janela horária medida (viagens por hora)
3. **Tipo de linha** que atende (BRT vs. convencional)

Isso permite responder a pergunta que o professor levantou, agora com dado:

> Os pontos mais barulhentos são os que **já têm** mais atendimento? (Hipótese: sim, porque são os eixos estruturais — o que mostra que o proxy indicaria reforçar quem já é atendido.)

E cruzar com a contagem manual:

> Os pontos com mais **pedestres** são os mais barulhentos? (Hipótese: não — ver [[A Hipótese em Teste]].)

## Fundamentos a dominar

- Estrutura do GTFS e as chaves que ligam os arquivos (`stop_id`, `route_id`, `trip_id`)
- Cálculo de **distância geodésica** entre coordenadas (não usar distância euclidiana em lat/lon)
- Junção espacial: encontrar a parada mais próxima de cada ponto
- Contagem de frequência a partir de `stop_times.txt`
- Desenhar camadas sobrepostas em `folium` → [[Python para Análise Geoespacial]]

## Onde estudar

- **gtfs.org** — a especificação oficial, bem documentada
- Documentação do **pandas** para as junções
- Bibliotecas Python de GTFS existem e podem poupar trabalho — avaliar antes de escrever tudo na mão

## Como saber que entendeu

- Você carrega o feed e responde: "qual a parada mais próxima do ponto P07 e quantas viagens ela recebe por hora no pico da manhã?"
- O mapa mostra os pontos de medição **e** a rede de ônibus, em camadas que dá pra ligar e desligar
- Você registrou a data de download e a licença do dado para o relatório

Relacionado: [[Python para Análise Geoespacial]], [[Amostra Estratificada]], [[A Hipótese em Teste]], [[Entregáveis]].
