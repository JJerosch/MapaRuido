# WBS e Gantt

Estrutura pronta pra importar em MS Project, GanttProject ou montar no Excel: cada tarefa tem ID, duração em semanas, dependências e frente de trabalho.

**Âncora:** S1 = **26/08 a 01/09/2026** · **Alvo da feira: S12 (11–17/11)** · **S13 = buffer**

> [!caution] Data da feira ainda não confirmada
> O cronograma assume meados de novembro. Se a data real for diferente, deslocar as semanas → [[Status das Pendências]] (D-18).

---

## As 21 tarefas

| ID | Tarefa | Semanas | Depende de | Frente | Dificuldade |
|---|---|---|---|---|---|
| **T1** | Alinhar reformulação com o professor | S1 | — | Coordenação | Baixa |
| **T2** | Cotar e **comprar** hardware | S1 | T1 | Hardware | Baixa |
| **T3** | Definir e visitar os 12 pontos (reconhecimento) | S2–S3 | T1 | Campo | Baixa |
| **T4** | Firmware no **Wokwi**: SD, OLED, RTC, formato do CSV | S1–S3 | — | Firmware | Média |
| **T5** | A-weighting + LAeq no desktop, validado contra WAV | S2–S4 | — | Firmware | **Alta** |
| **T6** | Recebimento, inventário e montagem em protoboard | S3 | T2 | Hardware | Média |
| **T7** | Bancada: INMP441 lendo I2S + RMS estável | S3–S4 | T4, T6 | Firmware | **Alta** |
| **T8** | Integrar DSP no firmware + gravar CSV no SD | S4–S5 | T5, T7 | Firmware | **Alta** |
| **T9** | **Calibração** por comparação com decibelímetro (≥3 níveis) | S5 | T8 | Hardware | Média |
| **T10** | Montagem física: caixa, windscreen, tripé, power bank | S5 | T6 | Hardware | Baixa |
| **T11** | **Coleta piloto** — 1 ponto, ciclo completo | S5 | T9, T10, T3 | Campo | Média |
| **T12** | Ajustes pós-piloto (protocolo e firmware) | S6 | T11 | Todas | Média |
| **T13** | **Coletas de campo** — 12 sessões | S6–S9 | T12 | Campo | Baixa (volume alto) |
| **T14** | Digitalização das planilhas de contagem manual | S7–S9 | T13 | Dados | Baixa |
| **T15** | Pipeline Python: limpeza, normalização por âncora, agregação | S8–S10 | T13 | Dados | **Alta** |
| **T16** | Baixar GTFS da URBS + cruzar pontos com a rede | S9–S10 | T3 | Dados | Média |
| **T17** | Análise de correlação LAeq × pedestres × veículos | S10 | T14, T15 | Dados | Média |
| **T18** | Mapa web Folium/Leaflet + publicar no GitHub Pages | S10–S11 | T15, T16 | Web | Média |
| **T19** | Modo demo: ESP32 servindo dB ao vivo via HTTP + OLED | S10–S11 | T8 | Firmware | Média |
| **T20** | Relatório / pôster + roteiro de apresentação | S10–S12 | T17 | Escrita | Média |
| **T21** | Ensaio do stand e plano B de demo (vídeo gravado) | S12 | T18, T19, T20 | Todas | Baixa |

---

## Caminho crítico

```
T2 → T6 → T7 → T8 → T9 → T11 → T13 → T15 → T17 → T20
```

> [!danger] Todo atraso em T2 empurra o projeto inteiro
> A compra é o início do caminho crítico e não tem folga nenhuma antes dela. Entrega nacional leva 3–10 dias, e esse tempo é **calendário**, não esforço — não adianta trabalhar mais pra recuperar.

**Toda a folga do cronograma está em S13.** Se ela for consumida antes de S10, o escopo precisa ser cortado — comece pelo [[Escopo Reformulado|escopo mínimo garantido]].

---

## Tarefas que não bloqueiam (comece por elas)

| Tarefa | Por que começar já |
|---|---|
| **T4** (Wokwi) | Não depende de nada. Roda enquanto o hardware não chega |
| **T5** (A-weighting) | Não depende de nada, e é **a tarefa mais difícil do projeto**. Começando cedo, deixa de ser risco |
| **T3** (reconhecimento) | Só depende do alinhamento com o professor |

Isso é [[Registro de Decisões|D-13]]: o grupo chega na bancada com código pronto em vez de começar do zero.

---

## Marcos

| Marco | Semana |
|---|---|
| Escopo fechado | S1 ✅ |
| Hardware comprado | S1 |
| Estação medindo na bancada | S4 |
| Estação calibrada | S5 |
| Coleta piloto validada | S5 |
| 48 medições concluídas | S9 |
| Mapa web publicado | S11 |
| **Feira** | **S12** |

---

## O que o Gantt não mostra

> [!warning] T13 é tempo de calendário, não de esforço
> As 12 sessões exigem **5 pessoas presentes simultaneamente**, em picos de manhã e tarde, em dias sem chuva. No Gantt ela ocupa 4 semanas, mas o que a atrasa é **agenda de gente**, não trabalho.
>
> Por isso as datas precisam estar combinadas já em **S3**, não em S6. Ver [[Alocação do Grupo]].

O mesmo vale, em menor grau, para T2 (espera de entrega) e T9 (depende de conseguir o decibelímetro).

Relacionado: [[Alocação do Grupo]], [[Riscos]], [[Progresso do Projeto]].
