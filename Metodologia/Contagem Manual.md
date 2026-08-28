# Contagem Manual

A contagem manual é a **verdade de campo** que permite testar a hipótese do proxy ([[A Hipótese em Teste]]). Sem ela o projeto vira só um mapa; com ela vira pesquisa.

É também o que justifica um grupo de 5 pessoas — enquanto uma opera a estação, as outras quatro contam.

---

## Os 5 papéis

| Papel | Tarefa | Perfil |
|---|---|---|
| **Operador** | Monta o tripé, opera a estação, cronometra, confere o OLED | Quem conhece o firmware |
| **Contador A** | Pedestres, sentido 1 | Qualquer um |
| **Contador B** | Pedestres, sentido 2 | Qualquer um |
| **Contador C** | Veículos, separando leves / pesados / ônibus | Qualquer um |
| **Escriba** | Planilha, fotos, coordenada, ocorrências | Quem escreve rápido |

> [!warning] O operador não conta
> São papéis distintos por um motivo: quem está contando pedestres não consegue vigiar se a estação parou de gravar. Trocar de papel entre sessões é bom (todo mundo aprende); acumular papéis na mesma sessão não é.

---

## Como contar

- **Janela:** os mesmos 10 minutos da medição, iniciando no mesmo instante.
- **Pedestres:** conta-se quem **cruza uma linha imaginária** definida no reconhecimento do ponto (uma referência física: poste, faixa, esquina). Cada sentido tem seu contador.
- **Veículos:** conta-se quem cruza a mesma linha, separando em três categorias. Ônibus contam **também** como pesados? **Não** — categoria separada, porque é justamente a variável de interesse.
- **Contador manual (tally counter)** ajuda muito e é barato, mas risquinho em papel funciona.
- Se o fluxo for grande demais pra contar (calçadão em pico), conte em **sub-janelas de 2 min** e extrapole — e **anote que foi extrapolado**.

---

## Planilha de campo

Uma folha por ponto por sessão. Imprimir com antecedência.

| Campo | Preenchido por |
|---|---|
| `sessao_id` | Escriba |
| `ponto_id` | Escriba |
| Data e hora de início | Escriba |
| Janela (manhã/tarde) | Escriba |
| Clima (sol/nublado/vento) | Escriba |
| Pedestres sentido 1 | Contador A |
| Pedestres sentido 2 | Contador B |
| Veículos leves | Contador C |
| Veículos pesados | Contador C |
| **Ônibus** | Contador C |
| Extrapolado? (S/N) | Quem contou |
| Ocorrências atípicas | Escriba |
| Foto tirada? (S/N) | Escriba |

O `sessao_id` + `ponto_id` são a chave que liga esta planilha ao CSV da estação. Sem eles, os dois conjuntos de dados não se juntam.

---

## O que a análise vai fazer com isso

| Correlação | Expectativa | Significado |
|---|---|---|
| LAeq × veículos (leves + pesados) | **Forte** | Valida que a estação mede o que deveria medir |
| LAeq × ônibus | Moderada | Ônibus são fonte de ruído relevante |
| LAeq × **pedestres** | **Fraca ou nula** | 👈 **A descoberta** — o proxy não estima demanda |

O ponto de tipologia 4 (calçadão da XV) deve aparecer como **outlier extremo**: fluxo de pedestres altíssimo com LAeq comparativamente baixo. É o gráfico que vai no pôster.

---

## Digitalização

- Digitar as planilhas **no mesmo dia** da coleta (T14 no [[WBS e Gantt]]).
- Uma linha por ponto/sessão, numa planilha única.
- **Fotografar as folhas antes de digitar** — papel se perde, foto no celular não.
- Conferência cruzada: quem digita não é quem contou.

Relacionado: [[Protocolo de Medição]], [[Amostra Estratificada]], [[Alocação do Grupo]].
