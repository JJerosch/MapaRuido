# Escopo Reformulado

> [!important] Este documento é o contrato
> Só muda com decisão explícita registrada em [[Registro de Decisões]]. Se alguém propuser algo que não está aqui, isso é mudança de escopo — não um detalhe de execução.

**Definido em:** 26/08/2026
**Substitui:** a proposta original do professor e a seção 3 da análise em `Plano/_Histórico/`

---

## Decisões que definem o projeto

| Eixo | Decisão | Consequência |
|---|---|---|
| Vínculo | Feira / mostra de projetos | Demo funcionando > rigor de artigo |
| Prazo | Novembro/2026 (~12 semanas) | Compra de hardware é tarefa da **semana 1** |
| Equipe | 5 membros, perfis mistos | Contagem manual de campo vira viável |
| Metodologia | **Híbrido A+B** | Mapa é o produto; o proxy é testado, não assumido |
| Coleta | **Pontos fixos**, a pé/bicicleta | Elimina ruído de pneu e vento — o maior risco técnico some |
| Carro | Só logística (leva equipe e equipamento) | Zero impacto na qualidade do dado |
| Estações | **1 unidade** | Medição sequencial → exige ponto-âncora |
| Orçamento | Até R$500, lojas nacionais | Corta calibrador acústico; GPS vira opcional |
| Recorte | Amostra estratificada, 12 pontos | 6 tipologias × 2 pontos |
| Volume | 48 medições | 12 pontos × 2 janelas × 2 repetições |

---

## Arquitetura

```
[Estação portátil em tripé, 1,3–1,5 m]
   ├── INMP441 (I2S) ──> DSP: ponderação A + RMS ──> LAeq / Lmax / L10 / L90
   ├── DS3231 (RTC) ──> timestamp confiável sem rede
   ├── OLED SSD1306 ──> feedback ao operador em campo + demo no stand
   └── ESP32 ──> CSV no microSD
                    │
                    │  (no WiFi de casa, depois da sessão)
                    ↓
   [Pipeline Python: limpeza → normalização por âncora → agregação por ponto]
                    ↓
   [Mapa web Folium/Leaflet]  +  [Correlação LAeq × pedestres × veículos]
                    ↓                          ↓
   [GitHub Pages]                   [Cruzamento com GTFS da URBS]

   ── em paralelo, coletado por 4 pessoas ──
   [Planilha de contagem manual: pedestres e veículos]
```

Quatro frentes independentes: **firmware/DSP**, **hardware/calibração**, **campo**, **dados/web**. Ver [[Alocação do Grupo]].

---

## ✅ Dentro do escopo

- Estação única de medição, portátil, alimentada por power bank → [[Lista de Componentes]]
- Cálculo de `LAeq`, `Lmax`, `L10` e `L90` com ponderação A a bordo → [[Ponderação A e LAeq]]
- Calibração por comparação com decibelímetro classe 2 → [[Calibração]]
- 12 pontos, 6 tipologias, 48 medições → [[Amostra Estratificada]]
- Contagem manual simultânea de pedestres e veículos → [[Contagem Manual]]
- Pipeline Python de limpeza, normalização e agregação
- Cruzamento com o GTFS da URBS → [[GTFS e Dados Abertos]]
- Mapa web interativo publicado
- Demo ao vivo no stand → [[Roteiro da Feira]]
- Relatório/pôster com análise de correlação

## ❌ Fora do escopo (e por quê)

| Ficou de fora | Por quê |
|---|---|
| Medição embarcada em carro em movimento | Ruído de pneu e vento contaminam o sinal irremediavelmente |
| GPS a bordo | Ponto fixo tem coordenada conhecida; o RTC resolve o timestamp mais barato (D-05) |
| Múltiplas estações simultâneas | Orçamento de R$500 não comporta; resolvido pelo ponto-âncora |
| Calibrador acústico (pistonfone) | ~R$400+, fora do orçamento. Tentar empréstimo; senão, declarar limitação |
| Conectividade celular (2G/4G) | 2G sendo desligado no Brasil; 4G custa mais que o resto do projeto |
| Medição noturna | Fora da janela de disponibilidade do grupo; a referência da OMS sobre período noturno entra só como discussão |
| Modelagem preditiva / mapa interpolado | 12 pontos não sustentam interpolação espacial; o mapa é de pontos, não de superfície |
| Recomendação real de alocação de linhas | Exigiria dados de demanda da URBS que não temos. Vira seção de discussão |

---

## Escopo mínimo garantido

Se tudo der errado, o que **precisa** existir no dia da feira:

1. Estação medindo dB ao vivo no stand
2. Pelo menos os pontos das tipologias 3 e 4 medidos (o par que sustenta o argumento)
3. Um mapa, ainda que estático
4. O pôster com o raciocínio de [[A Hipótese em Teste]]

Tudo além disso — calibração fina, 48 medições completas, cruzamento com GTFS, mapa interativo — é **incremento de qualidade, não requisito de existência**. Fazer nessa ordem garante que nunca se fica sem entregar.
