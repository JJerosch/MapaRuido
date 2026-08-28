# Protocolo de Medição

> [!warning] Isto não é sugestão
> Uma sessão feita fora deste protocolo é uma sessão **perdida** — não dá pra consertar depois na análise. Se algo der errado em campo, **registre e refaça**.

---

## Por que o protocolo é tão rígido

O grupo tem **uma única estação** ([[Registro de Decisões|D-03]]). Isso significa medição **sequencial**: o ponto A é medido às 8h e o ponto B às 11h. Sem controle, a diferença entre eles pode ser **horário**, não **lugar** — e aí o mapa inteiro não significa nada.

Todo o resto deste protocolo existe pra resolver isso.

---

## O ponto-âncora (inegociável)

Toda sessão começa e termina no **mesmo ponto de referência**, sempre na mesma posição exata.

```
[Âncora] → P_a → P_b → P_c → P_d → [Âncora]
  8h00     8h30  9h20  10h10  11h00   11h40
```

A diferença entre a leitura inicial e final da âncora mede a **deriva da sessão** (mudança geral de tráfego, clima, condição do dia). Esse valor vira fator de normalização aplicado a todos os pontos daquela sessão no pipeline.

**Custo:** ~20 min por sessão. **Benefício:** os dados de sessões diferentes passam a ser comparáveis. Sem isso, não são.

---

## Parâmetros de cada medição

| Parâmetro | Valor | Por quê |
|---|---|---|
| **Duração** | 10 min contínuos | Estabiliza o LAeq sem inviabilizar 48 medições ([[Registro de Decisões\|D-11]]) |
| **Métricas** | `LAeq`, `Lmax`, `L10`, `L90` | São os descritores que aparecem em norma — ver [[Ponderação A e LAeq]] |
| **Altura** | 1,3–1,5 m do solo | Altura de referência; **nunca na mão** — o corpo do operador reflete som |
| **Afastamento** | ≥2 m de parede/muro/poste | Superfície refletora próxima infla a medida |
| **Windscreen** | **Sempre**, mesmo sem vento aparente | Vento destrói o sinal e você não percebe olhando |
| **Janelas** | Pico manhã 7h30–8h30 · Pico tarde 17h30–18h30 | Compara o mesmo ponto em condições de fluxo distintas |
| **Repetição** | ≥2 dias diferentes por ponto | Separa "é assim" de "foi assim naquele dia" |
| **Chuva** | Cancelar e refazer | Pista molhada muda o ruído de rolamento ([[Registro de Decisões\|D-12]]) |

---

## Checklist de sessão

### Antes de sair
- [ ] Power bank carregado (testado por ≥3h antes da primeira sessão real)
- [ ] Cartão microSD com espaço e **arquivo da sessão anterior já copiado**
- [ ] RTC com hora certa
- [ ] Windscreen no lugar
- [ ] Tripé, planilhas impressas, canetas, cronômetro (ou celular)
- [ ] Previsão do tempo checada
- [ ] Os 5 papéis distribuídos → [[Contagem Manual]]

### Em cada ponto
- [ ] Montar o tripé na altura e no afastamento corretos
- [ ] Conferir no OLED que a estação está medindo (número se movendo)
- [ ] Registrar na planilha: ID do ponto, hora de início, clima, ocorrências
- [ ] **Iniciar a contagem manual no mesmo instante** da medição
- [ ] 10 minutos parados — sem conversa alta perto do microfone
- [ ] Foto do ponto e do entorno
- [ ] Fechar o registro, conferir que gravou

### Ao voltar
- [ ] Copiar o CSV do cartão **no mesmo dia** (D-08 diz que o cartão é ponto único de falha)
- [ ] Digitalizar as planilhas de contagem enquanto a memória está fresca
- [ ] Anotar no [[Progresso do Projeto]] quais pontos foram fechados

---

## Erros que invalidam a medição

| Erro | O que fazer |
|---|---|
| Esqueceu a âncora | A sessão inteira não é comparável. **Refazer.** |
| Choveu no meio | Descartar os pontos afetados e refazer |
| Segurou na mão em vez do tripé | Descartar aquele ponto |
| Windscreen caiu / esqueceu | Descartar aquele ponto |
| Obra ou evento atípico no ponto | **Não descartar** — registrar e decidir na análise |
| Cartão não gravou | Descobrir isso em campo é ruim; descobrir em casa é pior. Conferir no OLED sempre |

---

## O que o CSV precisa conter

Formato congelado ainda em T4, antes do hardware chegar:

```
timestamp_iso, ponto_id, sessao_id, laeq_db, lmax_db, l10_db, l90_db, amostras, temp_c, obs
```

O `sessao_id` é o que permite ligar cada medição à sua âncora no pipeline.

Relacionado: [[Amostra Estratificada]], [[Contagem Manual]], [[Calibração]], [[Verificação]].
