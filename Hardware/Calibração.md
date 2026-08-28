# Calibração

> [!important] É isto que separa o projeto de "um sensor de barulho de Arduino"
> Sem calibração, a estação produz um número que **sobe quando fica mais barulhento** — o que não é dB SPL, é nível relativo. Com calibração, produz uma medida em unidade física, comparável com norma e com literatura.

---

## O problema

O INMP441 entrega amostras digitais numa escala interna (dBFS — relativo ao fundo de escala do conversor). Para chegar a **dB SPL** (a escala física de pressão sonora), é preciso saber quanto vale 1 unidade digital em pressão real.

O datasheet do microfone dá a **sensibilidade nominal** — quanto de sinal digital ele produz para um nível de referência conhecido. Isso dá o ponto de partida. Mas a peça real varia do nominal, a montagem afeta a resposta, e o windscreen atenua. Daí a calibração.

> [!note] Conferir no datasheet antes de codar
> Pegue a sensibilidade e o ponto de sobrecarga acústica no datasheet oficial do INMP441 (InvenSense/TDK) e registre aqui. **Não confie em valores de tutorial de blog** — variam entre revisões da peça.

---

## Como vamos calibrar: por transferência

O padrão-ouro seria um **calibrador acústico** (pistonfone), que gera um nível conhecido e estável — tipicamente 94 dB @ 1 kHz. Custa ~R$400+ e está fora do orçamento ([[Registro de Decisões|D-07]]).

Nosso método: **comparação com um decibelímetro classe 2**, usado como *padrão de transferência*.

### Procedimento

1. Posicione a estação e o decibelímetro **lado a lado**, microfones na mesma altura e mesma distância da fonte. Diferença de posição vira erro de calibração.
2. Meça **simultaneamente** em **pelo menos 3 níveis bem distintos**:

| Ambiente | Faixa aproximada |
|---|---|
| Sala silenciosa, à noite | ~35 dB(A) |
| Conversa normal / sala de aula | ~60 dB(A) |
| Calçada de via movimentada | ~75 dB(A) |

3. Para cada nível, registre pares `(leitura_estação, leitura_decibelímetro)`. Faça várias leituras por nível e use a média.
4. Plote **estação × referência** e ajuste uma reta.
5. O **offset** (e o ganho, se a reta não tiver inclinação 1) vira constante de calibração no firmware.
6. **Repita a validação depois** de fechar a caixa e pôr o windscreen — os dois alteram a resposta.

### Critério de aceite

- Regressão **linear** com **R² > 0,95**
- Se a relação não for linear, algo está errado: saturação em nível alto, piso de ruído do microfone dominando em nível baixo, ou posicionamento inconsistente

Ver [[Verificação]], item 3.

---

## Verificação de deriva

A calibração não é feita uma vez e esquecida:

- **Antes da primeira sessão de campo** — calibração completa
- **No meio da campanha** (por volta de S7) — checagem rápida em 1 nível
- **Depois da última sessão** — checagem final, pra provar que não houve deriva

Se der deriva significativa, isso é resultado, não fracasso: registre e discuta no relatório.

---

## Limitações a declarar no relatório

> [!warning] Escrever isto explicitamente — é o que mostra maturidade
> - A calibração é por **transferência** contra um decibelímetro **classe 2**, não contra calibrador acústico rastreável. A incerteza herda a incerteza do instrumento de referência.
> - O decibelímetro de referência é de entrada e **não é padrão de laboratório**.
> - A calibração foi feita em **banda larga**, não por bandas de frequência. A resposta em frequência do conjunto (microfone + windscreen + caixa) não foi levantada.
> - Não houve verificação em câmara anecoica ou ambiente controlado.

Declarar limitação não enfraquece o trabalho — **esconder limitação, sim**. Uma banca perdoa incerteza declarada; não perdoa número apresentado como exato quando não é.

---

## Se conseguir um calibrador emprestado

Vale muito perguntar no laboratório de física / engenharia da PUC. Com pistonfone:

- A calibração vira de **um ponto** (94 dB @ 1 kHz), muito mais simples e rastreável
- Ainda assim, faça as medições comparativas nos 3 níveis pra verificar linearidade
- E mencione no relatório qual equipamento foi usado, marca e modelo

Está na lista de ações imediatas do [[Progresso do Projeto]].

Relacionado: [[Ponderação A e LAeq]], [[Acústica e dB(A)]], [[NBR 10151 e Normas]], [[Lista de Componentes]].
