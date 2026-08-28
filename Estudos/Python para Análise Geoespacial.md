# Python para Análise Geoespacial

## O que é

O pipeline que transforma os CSVs brutos da estação e as planilhas de contagem manual em **mapa** e **análise de correlação**. É a frente de Dados (T14–T18 no [[WBS e Gantt]]).

## Por que neste projeto

> [!important] É a parte mais subestimada e a que mais rende
> O firmware produz números. A análise é o que os transforma em resultado apresentável. Num projeto de feira, o mapa é o que as pessoas olham.

## O pipeline, etapa por etapa

### 1. Limpeza (T15)
- Ler os CSVs de todas as sessões
- Descartar sessões marcadas como inválidas (chuva, protocolo quebrado) → [[Protocolo de Medição]]
- Detectar e **investigar** outliers — não apagar sem entender. Um outlier pode ser a obra que o escriba anotou

### 2. Normalização por ponto-âncora (T15)
> [!warning] Etapa que não existe em projeto normal de mapa de ruído
> Como o grupo tem **uma única estação** ([[Registro de Decisões|D-03]]), cada sessão precisa ser corrigida pela deriva medida na âncora. Sem isso, sessões diferentes não são comparáveis.
>
> A lógica: para cada sessão, calcule a diferença entre as duas leituras da âncora (início e fim), e aplique a correção aos pontos daquela sessão. **Documentar bem a fórmula escolhida no relatório** — é uma decisão metodológica, não um detalhe técnico.

### 3. Agregação (T15)
- Média **energética** dos LAeq por ponto e janela — nunca aritmética ([[Acústica e dB(A)]])
- Percentis L10 e L90 consolidados
- Junção com a planilha de contagem manual pela chave `sessao_id` + `ponto_id`

### 4. Correlação (T17)
- LAeq × veículos → esperado **forte**
- LAeq × pedestres → esperado **fraco** ← a descoberta
- LAeq × ônibus
- Gráfico de dispersão com o calçadão da XV destacado como outlier — é a figura principal do pôster

### 5. Mapa (T18)
- Marcadores graduados por LAeq nos 12 pontos
- Popup com todos os descritores + foto
- Camada da rede de transporte → [[GTFS e Dados Abertos]]
- Exportar HTML estático e publicar no **GitHub Pages**

## Bibliotecas

| Biblioteca | Para quê |
|---|---|
| **pandas** | Leitura de CSV, limpeza, junção, agregação |
| **numpy** | Contas vetorizadas, percentis |
| **matplotlib** | Gráficos de dispersão e regressão do pôster |
| **scipy** | Correlação e regressão linear |
| **folium** | Mapa interativo (gera Leaflet, exporta HTML estático) |
| **geopandas** | Se precisar manipular geometrias das linhas de ônibus |

> [!note] Não precisa de OSMnx nem map matching
> A análise original previa map matching (associar pontos GPS a segmentos de rua), necessário na coleta móvel. Com **pontos fixos** ([[Registro de Decisões|D-02]]), cada medição já tem coordenada conhecida — essa complexidade inteira sai do escopo.

## Fundamentos a dominar

- `pandas`: `read_csv`, `merge`, `groupby`, tratamento de datas
- Por que a média de dB é **energética** — e como implementar isso corretamente
- Correlação de Pearson × Spearman, e quando cada uma se aplica
- Interpretação honesta de R²: correlação não é causalidade, e é justamente disso que trata [[A Hipótese em Teste]]
- `folium`: `Map`, `CircleMarker`, `Popup`, `LayerControl`, `save`

## Onde estudar

- Documentação do **pandas** ("10 minutes to pandas" é um bom começo)
- Documentação do **folium** — os exemplos cobrem quase tudo que o projeto precisa
- Qualquer material introdutório de **estatística descritiva e correlação**

## Como saber que entendeu

- O pipeline roda do CSV bruto ao mapa **sem intervenção manual**
- Você explica o que a normalização por âncora faz e por que ela é necessária
- Você calcula a média de LAeq corretamente e sabe demonstrar por que a aritmética estaria errada
- O mapa abre bem num celular em rede móvel → [[Verificação]], item 7

Relacionado: [[GTFS e Dados Abertos]], [[Contagem Manual]], [[Acústica e dB(A)]], [[Entregáveis]].
