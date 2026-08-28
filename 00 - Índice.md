# 🔊 Mapa de Ruído de Curitiba — Índice do Cofre

Ponto de partida de tudo. Este cofre é a **memória viva** do projeto: por que o escopo foi reformulado, como cada medição deve ser feita, o que ainda falta comprar e decidir, e o que estudar pra entender cada parte.

> [!tip] Primeira vez aqui? Leia [[Como usar este cofre]].
> [!important] Quer só saber o estado atual e o próximo passo? → [[Progresso do Projeto]]

---

## 🚀 O projeto em uma frase

Uma estação portátil de ~R$500 com **ESP32 + microfone I2S** medindo dB(A) em **12 pontos fixos** de Curitiba, para produzir um mapa de ruído e **testar** — em vez de assumir — a hipótese de que ruído serve como proxy de demanda por transporte público. Ver [[O que é o projeto]].

**Entrega:** feira/mostra em **novembro/2026**. Grupo de **5 membros**.

---

## 🧭 Navegação

### Status (o "onde estamos")
- [[Progresso do Projeto]] — foto do estado atual e o próximo passo. **Comece por aqui pra retomar.**

### Escopo (o "o quê")
- [[O que é o projeto]] — o projeto inteiro em uma página.
- [[Escopo Reformulado]] — **o contrato**: o que está dentro e o que ficou de fora.
- [[A Hipótese em Teste]] — por que a premissa original não fecha, e o argumento do calçadão da XV.

### Decisões (o "porquê")
- [[Registro de Decisões]] — log de todas as decisões, com contexto e consequência.

### Metodologia (o "como medir")
- [[Amostra Estratificada]] — os 12 pontos e por que cada tipologia está na amostra.
- [[Protocolo de Medição]] — ponto-âncora, janelas horárias, altura, duração.
- [[Contagem Manual]] — os 5 papéis em campo e a planilha.

### Hardware (o "com o quê")
- [[Lista de Componentes]] — o que comprar e o que **não** comprar.
- [[Orçamento em Camadas]] — essencial → recomendado → desejável.
- [[Montagem e Ligações]] — pinagem, alimentação e a caixa.
- [[Calibração]] — como transformar número relativo em dB SPL de verdade.

### Cronograma (o "quando")
- [[WBS e Gantt]] — as 21 tarefas, dependências e caminho crítico.
- [[Alocação do Grupo]] — quem faz o quê, com perfis mistos.
- [[Riscos]] — o que pode dar errado e a mitigação de cada um.

### Entrega (o "resultado")
- [[Entregáveis]] — os 6 produtos finais.
- [[Verificação]] — como saber que cada etapa funcionou de verdade.
- [[Roteiro da Feira]] — o stand, a demo ao vivo e o plano B.

### Pendências (o "o que falta decidir")
- [[Status das Pendências]] — o que está aberto e o que bloqueia o quê.

### Estudos (o "como aprender")
- [[Cronograma de Estudos]] — roteiro na ordem em que o projeto precisa.
- Destaque transversal: [[Acústica e dB(A)]] — o conhecimento que atravessa tudo.

### Documentos-fonte
- `Plano/_Histórico/` — a análise original de 24/08/2026, que originou a reformulação. Mantida só como histórico.

---

> [!note] Convenção de ouro
> O [[Escopo Reformulado|escopo]] é o **contrato** e só muda com decisão explícita registrada em [[Registro de Decisões]]. As notas de Metodologia, Hardware e Estudos são a **memória viva** — atualizadas conforme o projeto anda. Se algo mudar em campo, registre aqui **antes** de continuar.
