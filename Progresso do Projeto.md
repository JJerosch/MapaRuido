# 📌 Progresso do Projeto — Mapa de Ruído de Curitiba

> [!abstract] Leia isto primeiro
> Esta é a **foto do "onde estamos agora"**. O [[00 - Índice]] diz *o que existe no cofre*; **este arquivo diz o que já foi feito e qual é o próximo passo.**

**Última atualização:** 2026-08-26
**Fase atual:** Escopo reformulado e aprovado → **prestes a comprar hardware (T2)**
**Nenhuma peça comprada, nenhuma linha de firmware escrita.**

---

## 🎯 Onde estamos, em uma frase

O escopo foi **reformulado e fechado** (metodologia híbrida A+B, pontos fixos, 1 estação, 12 pontos, feira em novembro). O próximo passo concreto é **fechar a lista de componentes e comprar** — é o início do caminho crítico, e todo dia de atraso aqui empurra o projeto inteiro.

---

## ✅ FASE 0 — Definição de escopo (CONCLUÍDA)

- [x] Análise crítica da proposta original do professor → `Plano/_Histórico/`
- [x] Premissa "ruído = demanda por ônibus" identificada como frágil → [[A Hipótese em Teste]]
- [x] Método de coleta definido: **pontos fixos**, não medição veicular → [[Registro de Decisões|D-02]]
- [x] Metodologia definida: **híbrido A+B** (mapa é o produto, proxy é testado) → [[Escopo Reformulado]]
- [x] Amostra desenhada: 6 tipologias × 2 pontos = 12 pontos → [[Amostra Estratificada]]
- [x] Protocolo de medição definido, com ponto-âncora → [[Protocolo de Medição]]
- [x] Divisão de papéis em campo definida → [[Contagem Manual]]
- [x] Hardware especificado, com RTC no lugar do GPS → [[Lista de Componentes]]
- [x] Orçamento em camadas montado (~R$500) → [[Orçamento em Camadas]]
- [x] WBS de 21 tarefas com dependências e caminho crítico → [[WBS e Gantt]]
- [x] Riscos mapeados com mitigação → [[Riscos]]
- [x] Cofre Obsidian criado como memória viva → [[Como usar este cofre]]

---

## 🔜 FASE 1 — Compra e bancada (A FAZER — próximo passo)

- [ ] **T1 — Alinhar reformulação com o professor** ⭐ *(faça antes de comprar)*
  - [ ] Apresentar o argumento do calçadão da XV → [[A Hipótese em Teste]]
  - [ ] Confirmar que o novo título e o recorte estão aceitos
- [ ] **T2 — Cotar e comprar o hardware** ⭐ *(início do caminho crítico)*
  - [ ] Rodar a pesquisa de preços → [[Lista de Componentes]]
  - [ ] Fechar as camadas do orçamento → [[Orçamento em Camadas]]
  - [ ] Comprar (só lojas nacionais, entrega 3–10 dias)
- [ ] **T4 — Firmware no Wokwi** *(não espera peça chegar)*
  - [ ] Esqueleto: leitura, gravação em SD, OLED, RTC
  - [ ] Definir e congelar o formato do CSV
- [ ] **T5 — A-weighting no desktop** *(não espera peça chegar, e é a tarefa mais difícil)*
  - [ ] Implementar o filtro e validar contra WAV de referência → [[Ponderação A e LAeq]]
- [ ] **T3 — Reconhecimento dos 12 pontos** → [[Amostra Estratificada]]
- [ ] Criar repositório GitHub
- [ ] Verificar se a PUC empresta calibrador acústico → [[Calibração]]
- [ ] Combinar as 12 datas de campo com os 5 membros → [[Alocação do Grupo]]

---

## 📅 Marcos

| Marco | Semana | Situação |
|---|---|---|
| Escopo fechado | S1 | ✅ Feito |
| Hardware comprado | S1 | ⬜ **Próximo** |
| Estação medindo na bancada | S4 | ⬜ |
| Estação calibrada | S5 | ⬜ |
| Coleta piloto validada | S5 | ⬜ |
| 48 medições concluídas | S9 | ⬜ |
| Mapa web publicado | S11 | ⬜ |
| Feira | S12 | ⬜ |

Detalhamento completo em [[WBS e Gantt]].

---

## ⚠️ O que mais preocupa agora

1. **Ninguém do grupo montou um ESP32 físico antes** — o SIA anterior foi todo simulado. Mitigação: T4 e T5 rodam em paralelo à entrega.
2. **A compra ainda não foi feita** e é o início do caminho crítico.
3. **As 12 datas de campo dependem de 5 pessoas simultaneamente** — é agenda, não esforço. Combinar já em S3.

Ver [[Riscos]] para a lista completa.
