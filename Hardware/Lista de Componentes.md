# Lista de Componentes

> [!caution] Lista ainda não fechada
> Os componentes estão **pendentes de confirmação** após a pesquisa de preços. Ver [[Status das Pendências]]. O que está fechado são as *decisões técnicas* abaixo, não as marcas e modelos exatos.

Configuração: **estação portátil de ponto fixo**, alimentada por power bank, montada em tripé. Não é embarcada em veículo — ver [[Registro de Decisões|D-02]].

---

## Núcleo da estação

| # | Peça | Escolha | Por quê |
|---|---|---|---|
| 1 | **MCU** | ESP32-S3 DevKitC-1 (N16R8/N8R8) ou ESP32-WROOM-32 DevKit V1 | S3 tem PSRAM e mais folga pro DSP; o WROOM-32 dá conta se o código for enxuto e é ~metade do preço. Decidir na cotação (D-15) |
| 2 | **Microfone** | **INMP441** (I2S digital) | ⚠️ Ver o aviso abaixo. Alternativa superior: ICS-43434 ou SPH0645LM4H |
| 3 | **Armazenamento** | Módulo microSD SPI + cartão 32GB Classe 10 (A1) | Grava local; sem rede em campo ([[Registro de Decisões\|D-08]]) |
| 4 | **RTC** | DS3231 (módulo com bateria) | Timestamp confiável sem GPS e sem rede ([[Registro de Decisões\|D-05]]) |
| 5 | **Display** | OLED SSD1306 0.96" I2C (128×64) | O operador precisa **ver** que está medindo. Vale muito na demo do stand |

> [!danger] O microfone é a decisão que não pode dar errado
> **Não usar KY-038, MAX9814 nem MAX4466.** São módulos analógicos sem sensibilidade especificada em datasheet — entregam *nível relativo*, não dB SPL. Não existe conversão possível para unidade física.
>
> O INMP441 é MEMS digital I2S e **tem sensibilidade em datasheet**, que é o que permite chegar a dB SPL calibrável. Confirmar no datasheet do fabricante os valores de sensibilidade e ponto de sobrecarga acústica antes de fechar a compra. Ver [[Registro de Decisões|D-06]] e [[Calibração]].

---

## Alimentação e montagem

| # | Peça | Situação |
|---|---|---|
| 6 | Power bank 10000mAh+ com saída USB-A | ✅ **Já disponível** — o grupo tem |
| 7 | Cabo USB curto **de dados** (não só de carga) | Comprar |
| 8 | **Windscreen** (espuma anti-vento, bola ~4–5 cm) | Comprar — **obrigatório** |
| 9 | Tripé regulável até 1,3–1,5 m | Comprar, ou improvisar se o orçamento apertar |
| 10 | Caixa de projeto ABS pequena | Comprar, ou imprimir em 3D se a PUC tiver laboratório maker |
| 11 | Jumpers macho-fêmea, protoboard 400 pontos, barra de pinos | Comprar |

---

## Referência de calibração

| # | Peça | Observação |
|---|---|---|
| 12 | **Decibelímetro classe 2** com certificado | Maior item do orçamento. Precisa cobrir ~30–130 dB, ter ponderação A e resposta FAST/SLOW. Modelo pendente (D-16) |
| 13 | Calibrador acústico / pistonfone 94 dB @ 1 kHz | ❌ **Fora do orçamento** (~R$400+). Tentar empréstimo na PUC — ver [[Calibração]] |

---

## O que foi deliberadamente removido

| Removido | Motivo |
|---|---|
| **GPS NEO-6M** | Ponto fixo tem coordenada conhecida; o celular dá precisão equivalente. O RTC resolve o timestamp por ~1/3 do preço e economiza uma fase inteira do cronograma ([[Registro de Decisões\|D-05]]) |
| **Módulo celular (SIM800/SIM7600)** | 2G sendo desligado no Brasil; 4G custa mais que o resto do projeto |
| **Alimentação veicular** | Não há medição em movimento — power bank substitui |
| **Estações adicionais** | Orçamento; resolvido metodologicamente pelo ponto-âncora ([[Registro de Decisões\|D-03]]) |

---

## Prompt de cotação

Usar este texto na pesquisa de preços (adaptado para **1 estação**):

> Preciso cotar componentes para um projeto acadêmico de medição de ruído urbano com ESP32. É uma **estação portátil de ponto fixo**, operada a pé, alimentada por power bank e montada em tripé — **não** é embarcada em veículo.
>
> Para cada item: preço no Brasil (Mercado Livre, Eletrogate, Curto Circuito, Baú da Eletrônica, Robocore, Usinainfo), prazo de entrega, e alternativas equivalentes na mesma faixa.
>
> 1. ESP32-S3 DevKitC-1 (N16R8) **e** ESP32-WROOM-32 DevKit V1 — cotar os dois pra comparar
> 2. INMP441 (módulo I2S breakout). **CRÍTICO:** precisa ser MEMS digital I2S com sensibilidade em datasheet. Não servem KY-038, MAX9814 ou MAX4466. Cotar também ICS-43434 e SPH0645LM4H
> 3. Módulo leitor microSD SPI + cartão 32GB Classe 10 A1
> 4. Módulo RTC DS3231 com bateria
> 5. Display OLED SSD1306 0.96" I2C 128×64
> 6. Cabo USB curto de dados + jumpers macho-fêmea + protoboard 400 pontos
> 7. Espuma anti-vento / windscreen para microfone (precisa caber sobre um módulo breakout pequeno)
> 8. Tripé de câmera com altura regulável até 1,3–1,5 m
> 9. Caixa de projeto ABS pequena
> 10. Decibelímetro digital classe 2 (ex.: Minipa MSL-1325A, Instrutherm DEC-490 ou equivalente). Informar faixa de medição, se tem ponderação A e resposta FAST/SLOW, e se acompanha certificado de calibração
> 11. Calibrador acústico / pistonfone 94 dB @ 1 kHz — **cotar só pra comparar**, provavelmente fora do orçamento
>
> Perguntas adicionais:
> - Existe kit pronto juntando ESP32 + INMP441 + microSD?
> - O INMP441 opera em 3.3V — confirmar que não precisa de level shifter com o ESP32

Relacionado: [[Orçamento em Camadas]], [[Montagem e Ligações]], [[Calibração]].
