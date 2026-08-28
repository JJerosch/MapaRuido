# Entregáveis

Seis produtos finais. Os três primeiros são o que aparece no stand; os três últimos são o que sustenta o trabalho academicamente.

---

## 1. Estação de medição funcional

Hardware + firmware, medindo dB(A) **ao vivo** no stand.

- Display OLED mostrando o nível em tempo real
- Modo demo servindo uma página HTTP com o valor atualizado (T19)
- Vídeo gravado como plano B ([[Registro de Decisões|D-14]])

## 2. Mapa web interativo

Folium/Leaflet publicado no **GitHub Pages**.

- 12 pontos com marcadores graduados por `LAeq`
- Popup por ponto: tipologia, LAeq, Lmax, L10, L90, contagem de pedestres e veículos, foto
- Camada com a rede de transporte público (GTFS da URBS) → [[GTFS e Dados Abertos]]
- **Tem que abrir bem no celular** — ver [[Verificação]], item 7

## 3. Relatório / pôster

Com o raciocínio completo e as limitações declaradas.

Estrutura sugerida:
1. Problema e a hipótese original
2. Por que a hipótese precisa ser testada → [[A Hipótese em Teste]]
3. Metodologia: estação, calibração, protocolo, amostra
4. Resultados: mapa + as três correlações
5. Discussão: o que o proxy explica e o que não explica
6. **Limitações** → [[Calibração]]
7. Trabalhos futuros

Referências a levantar e citar corretamente:
- **NBR 10151** → [[NBR 10151 e Normas]]
- Diretriz da **OMS** sobre exposição a ruído ⚠️ *buscar a fonte primária antes de citar — ver a nota de normas*
- Legislação municipal de ruído de Curitiba

## 4. Dataset aberto

- CSV georreferenciado das medições (saída da estação)
- Planilha digitalizada da contagem manual
- Ficha dos 12 pontos com coordenadas e fotos
- Publicado no repositório, com dicionário de dados

## 5. Análise de correlação

O teste explícito da hipótese — LAeq × pedestres × veículos × ônibus. É o conteúdo do gráfico principal do pôster.

## 6. Repositório GitHub documentado

- Firmware (`/firmware`)
- Pipeline Python (`/analise`)
- Dados (`/dados`)
- README com metodologia reprodutível e foto da montagem

---

## Ordem de garantia

> [!important] Fazer nesta ordem garante que nunca se fica sem entregar
> Se o cronograma apertar, os itens de baixo saem primeiro.

| Prioridade | Entregável |
|---|---|
| 1 | Estação funcionando (item 1) |
| 2 | Pontos das tipologias 3 e 4 medidos |
| 3 | Um mapa, ainda que estático (item 2 simplificado) |
| 4 | Pôster com o argumento (item 3) |
| 5 | 48 medições completas |
| 6 | Cruzamento com GTFS |
| 7 | Mapa interativo publicado |
| 8 | Dataset e repositório documentados |

Ver o [[Escopo Reformulado|escopo mínimo garantido]] e os gatilhos de corte em [[Riscos]].

---

## Sinergia com o SIA-C

A demo do stand (T19) usa o ESP32 **como servidor HTTP** — exatamente o conceito estudado no SIA-C, a outra disciplina do semestre. Vale reaproveitar o que já foi aprendido lá sobre `ESPAsyncWebServer`, modo STA e mDNS.

Relacionado: [[Roteiro da Feira]], [[Verificação]], [[Progresso do Projeto]].
