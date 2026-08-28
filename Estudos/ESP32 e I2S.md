# ESP32 e I2S

## O que é

**I2S** (*Inter-IC Sound*) é um barramento serial digital feito especificamente para transportar áudio entre chips. O ESP32 tem **periférico I2S em hardware**, o que significa que ele recebe as amostras sem gastar CPU no processo — essencial pra sobrar processamento pro filtro de ponderação A.

O **INMP441** é um microfone MEMS com conversor analógico-digital embutido: ele já entrega **amostras digitais** pela saída I2S, não um sinal analógico.

### Os três sinais

| Sinal | Nome comum | Função |
|---|---|---|
| **SCK** | BCLK, bit clock | Marca cada bit |
| **WS** | LRCL, word select | Indica qual canal (esquerdo/direito) |
| **SD** | DOUT, data | Os dados de áudio |

Há ainda o pino **L/R** no INMP441, que define em qual canal ele transmite. Ligá-lo errado é uma das causas mais comuns de "só leio zeros".

## Por que neste projeto

É **todo o caminho do sinal**. Se o I2S não funcionar, não existe medição.

É a tarefa **T7** do [[WBS e Gantt]] — e uma das três de dificuldade Alta. Também é o primeiro contato real do grupo com hardware ESP32, já que o SIA anterior foi simulado.

## Fundamentos a dominar

- Diferença entre microfone **analógico** e **MEMS digital I2S** — e por que só o segundo serve ([[Registro de Decisões|D-06]])
- Configuração do periférico I2S: **taxa de amostragem**, **profundidade de bits**, formato de dados, modo master/slave
- Por que o INMP441 transmite **24 bits dentro de um frame de 32 bits** — e como extrair o valor correto (é a origem de metade dos bugs de leitura)
- **Buffers e DMA**: como as amostras chegam sem travar o loop principal
- Como calcular **RMS** sobre um bloco de amostras
- Alimentação **3.3V** e aterramento comum → [[Montagem e Ligações]]

## Armadilhas conhecidas

| Sintoma | Causa provável |
|---|---|
| Lê só zeros | Pino **L/R** não conectado, ou canal configurado errado |
| Ruído constante sem relação com o som | WS e SCK trocados |
| Valores absurdos / estouro | Extração errada dos 24 bits dentro do frame de 32 |
| Funciona e para depois de alguns segundos | Buffer estourando — revisar tamanho e frequência de leitura |
| Nada funciona e a placa reinicia | Alimentação, não código. Ver [[Montagem e Ligações]] |

> [!tip] Teste o I2S isolado antes de somar DSP
> T7 pede **só** o microfone lendo com RMS estável — sem ponderação A, sem SD, sem OLED. Se você juntar tudo e não funcionar, não vai saber qual das cinco coisas quebrou.

## Onde estudar

- **Documentação do ESP-IDF** sobre o driver I2S (e a diferença entre a API antiga e a nova — muitos tutoriais usam a antiga e não compilam mais)
- Documentação do **Arduino-ESP32** se o grupo usar Arduino IDE / PlatformIO
- **Datasheet do INMP441** (InvenSense/TDK) — sensibilidade, ponto de sobrecarga acústica, formato de dados. Registrar os valores em [[Calibração]]
- Projetos abertos de "ESP32 sound level meter" — vale ler o código antes de escrever o seu

## Como saber que entendeu

- Você lê amostras cruas e imprime valores que **mudam com o som e voltam ao repouso**
- Você explica por que o dado vem em 32 bits mas só 24 têm informação
- Você sabe dizer, olhando a configuração, qual taxa de amostragem está usando e por quê
- Você diagnostica "só leio zeros" sem precisar de tentativa e erro

Relacionado: [[Ponderação A e LAeq]], [[Montagem e Ligações]], [[Wokwi e Firmware]], [[Lista de Componentes]].
