# Status das Pendências

O que ainda está aberto, quem resolve e o que cada pendência bloqueia.

**Última revisão:** 2026-08-26

---

## 🔴 Bloqueia o caminho crítico

### P-01 — Lista final de componentes
- **Situação:** aberta. A pesquisa de preços ainda não voltou.
- **Bloqueia:** T2 (compra) → e portanto **todo o caminho crítico**
- **Quem resolve:** João
- **Como:** rodar o prompt de cotação em [[Lista de Componentes]] e preencher os valores reais em [[Orçamento em Camadas]]
- **Decisões dependentes:** D-15 (WROOM-32 vs. S3), D-16 (modelo do decibelímetro)

### P-02 — Alinhamento com o professor
- **Situação:** aberta. Ele sinalizou flexibilidade — aceita outra proposta desde que ligada a mapa de ruído.
- **Bloqueia:** T2 e T3 (não comprar antes de confirmar o recorte)
- **Quem resolve:** João
- **Como:** apresentar o argumento do calçadão da XV → [[A Hipótese em Teste]]
- **Registrar o resultado** em [[Registro de Decisões]]

---

## 🟡 Bloqueia uma fase

### P-03 — Data exata da feira
- **Situação:** aberta. O cronograma assume **S12 (11–17/11/2026)**.
- **Bloqueia:** o ancoramento de [[WBS e Gantt]] — se a data real for outra, todas as semanas deslocam
- **Decisão dependente:** D-18

### P-04 — Escolha do ponto-âncora
- **Situação:** aberta.
- **Bloqueia:** T11 (piloto) e T13 (coletas) — **nenhuma sessão pode acontecer sem âncora definida**
- **Como:** aplicar os critérios em [[Amostra Estratificada]] durante o reconhecimento (T3)
- **Decisão dependente:** D-17

### P-05 — Calibrador acústico na PUC
- **Situação:** aberta. Ninguém perguntou ainda.
- **Bloqueia:** nada — há plano B (calibração por transferência)
- **Impacto se houver:** simplifica muito T9 e melhora a defensabilidade → [[Calibração]]
- **Como:** perguntar no laboratório de física / engenharia

### P-06 — As 12 datas de campo
- **Situação:** aberta.
- **Bloqueia:** T13 — e este é o risco **mais subestimado** do projeto
- **Prazo pra resolver:** **S3**, não S6
- **Como:** checklist em [[Alocação do Grupo]]

---

## 🟢 Não bloqueia, mas precisa resolver

### P-07 — Rateio financeiro entre os 5
- ~R$100 por pessoa. Acertar **antes** da compra, não depois. Ver [[Orçamento em Camadas]].

### P-08 — Quem faz a compra
- Um CPF só simplifica frete e rastreio.

### P-09 — Repositório GitHub
- Criar e definir a estrutura (`/firmware`, `/analise`, `/dados`).

### P-10 — Fonte primária da diretriz da OMS
- O documento original citava "OMS associa exposição noturna acima de 55 dB(A) a risco cardiovascular". **Localizar a publicação original e conferir o número e o contexto antes de citar no relatório** — ver [[NBR 10151 e Normas]].

### P-11 — Acesso à NBR 10151
- Norma é paga. Verificar se a PUC tem assinatura (Target GEDWeb ou similar) pela biblioteca.

---

## ✅ Resolvidas

| # | Pendência | Resolução |
|---|---|---|
| — | Formato do projeto | Feira/mostra, novembro/2026 |
| — | Individual ou grupo | Grupo de 5, perfis mistos |
| — | Método de coleta | Pontos fixos, a pé/bicicleta (D-02) |
| — | Metodologia | Híbrido A+B (D-01) |
| — | Motorista disponível | Sim, carro comum — usado como **logística**, não plataforma |
| — | Decibelímetro | Vai ser comprado (entra no orçamento) |
| — | Recorte geográfico | Amostra estratificada, 12 pontos (D-09) |
| — | Número de estações | 1 unidade (D-03) |
| — | GPS | Removido, substituído por RTC (D-05) |

---

## Como usar esta nota

Revise no início de cada semana junto com o [[Progresso do Projeto]]. Uma pendência 🔴 aberta por mais de uma semana é sinal de que alguém precisa ser cobrado — não de que ela é difícil.
