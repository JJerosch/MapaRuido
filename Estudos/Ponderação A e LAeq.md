# Ponderação A e LAeq

> [!danger] Esta é a parte mais difícil do projeto
> T5, T7 e T8 são as três tarefas de dificuldade **Alta** do [[WBS e Gantt]], e todas passam por aqui. Comece em **S2**, não em S5.

## O que é

Duas coisas separadas, frequentemente confundidas:

**1. Ponderação A** — um *filtro de frequência*. Corrige o sinal pra aproximar a sensibilidade do ouvido humano, atenuando fortemente os graves. Aplica-se **antes** de qualquer cálculo de nível.

**2. LAeq** — o *nível equivalente contínuo ponderado em A*. É a energia sonora média ao longo de um período, expressa como o nível constante que teria a mesma energia. É o descritor padrão de ruído ambiental.

```
amostras I2S → [filtro de ponderação A] → [RMS] → [integração no tempo] → LAeq
```

## Os descritores que vamos registrar

| Descritor | O que é | Por que importa |
|---|---|---|
| **LAeq** | Nível equivalente no período | O descritor principal. Em [[Registro de Decisões\|D-11]], janela de 10 min |
| **Lmax** | Nível máximo no período | Captura eventos: buzina, moto, sirene |
| **L10** | Nível excedido em 10% do tempo | Indicador de picos recorrentes de tráfego |
| **L90** | Nível excedido em 90% do tempo | Indicador de **ruído de fundo** (o "residual" do local) |

> [!tip] L10 e L90 juntos contam uma história
> Um ponto com L10 alto e L90 baixo tem tráfego intermitente (rua de bairro). Um com os dois altos tem fluxo constante (via arterial). É análise que sai de graça e enriquece muito o relatório.

## Por que neste projeto

- É o que separa uma medição séria de "o número subiu quando bati palma"
- Sem ponderação A, os valores não são comparáveis com norma nem com literatura
- Valor instantâneo de dB não descreve ambiente sonoro — só o LAeq descreve

## Fundamentos a dominar

- Por que a ponderação é aplicada **no sinal**, antes do cálculo de nível
- **Filtros IIR e biquads** — a ponderação A costuma ser implementada como cascata de biquads
- **RMS** e por que ele (e não a média simples) representa energia do sinal
- **Integração no tempo** e escolha da janela
- Cálculo de **percentis** (L10, L90) a partir de uma série de níveis curtos
- Por que a média de LAeq entre janelas é **energética**, não aritmética → [[Acústica e dB(A)]]

## Estratégia de implementação

> [!important] Desktop primeiro, ESP32 depois — [[Registro de Decisões|D-13]]
> Depurar DSP dentro do microcontrolador, sem poder inspecionar o sinal, é muito mais lento e frustrante. E o desktop não precisa esperar o hardware chegar.

1. **T5 (S2–S4, no desktop):** implementar o filtro e o cálculo de LAeq em Python ou C. Validar contra um **WAV de referência** (ruído rosa, tons puros), comparando com uma implementação conhecida.
2. **T7 (S3–S4, na bancada):** o INMP441 lendo I2S com RMS estável, ainda **sem** ponderação A. Testa o caminho do sinal isoladamente.
3. **T8 (S4–S5):** juntar os dois. Só aqui o DSP entra no ESP32.

Critérios de aceite em [[Verificação]], itens 1 e 2.

## Onde estudar

- Existem **implementações prontas de ponderação A em C** para microcontroladores — estudar antes de escrever do zero (e citar a fonte no relatório)
- Material de **processamento digital de sinais** sobre filtros IIR e estruturas biquad
- Documentação da API `I2S` do ESP-IDF / Arduino-ESP32 → [[ESP32 e I2S]]
- A norma que define as curvas de ponderação e as classes de instrumento → [[NBR 10151 e Normas]]

> [!note] Usar implementação pronta é legítimo
> O projeto não é sobre reimplementar DSP — é sobre medir ruído urbano com rigor. Usar um filtro conhecido, entender o que ele faz e **validá-lo** é melhor engenharia do que escrever um próprio sem validação. O que não pode é usar sem entender.

## Como saber que entendeu

- Você explica por que a ponderação A vem antes do RMS, e não depois
- Você explica a diferença entre LAeq, Lmax e L90 sem consultar
- Seu filtro, rodado contra um WAV conhecido, dá o resultado esperado
- Você sabe dizer o que aconteceria se aplicasse a média aritmética em vez da energética

Relacionado: [[Acústica e dB(A)]], [[ESP32 e I2S]], [[Calibração]], [[Verificação]].
