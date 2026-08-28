# Montagem e Ligações

> [!caution] Primeiro projeto do grupo com ESP32 físico
> O SIA anterior foi inteiramente simulado. Hardware real traz problemas que simulador nunca mostra: solda fria, alimentação insuficiente, cartão que não monta, jumper meio solto. **Monte e teste um módulo por vez** — nunca ligue tudo de uma vez e tente descobrir o que não funciona.

---

## Regra de ouro da alimentação

> [!danger] Tudo é 3.3V
> O **INMP441 opera em 3.3V**. Ligar em 5V pode danificar o módulo. O mesmo vale para o SSD1306 e o cartão microSD (muitos módulos SD trazem regulador próprio — **conferir no seu**).
>
> Antes de energizar pela primeira vez, confira com multímetro qual pino do seu DevKit é 3V3 e qual é VIN/5V. Placas de fabricantes diferentes trocam a posição.

---

## Barramentos usados

A estação usa três barramentos independentes — o que é bom, porque permite testar um de cada vez:

| Barramento | Quem usa | Observação |
|---|---|---|
| **I2S** | INMP441 | Periférico de hardware do ESP32; é o que carrega o áudio |
| **SPI** | Módulo microSD | Barramento próprio |
| **I2C** | OLED SSD1306 + RTC DS3231 | **Compartilham o mesmo barramento** (endereços diferentes) |

> [!tip] I2C compartilhado é normal
> OLED e RTC dividem SDA e SCL. Cada um tem endereço distinto, então não conflitam. Se um dos dois sumir, rode um *I2C scanner* pra ver quais endereços aparecem — é o diagnóstico mais rápido.

---

## Ordem de montagem (uma etapa por vez)

1. **Só o ESP32** — carregue um blink. Confirma que a placa, o cabo e o driver USB funcionam.
   - ⚠️ Cabo **de dados**, não de carga. É a causa nº 1 de "meu ESP32 não aparece".
2. **+ OLED (I2C)** — mostre um "Hello". Confirma I2C e alimentação 3.3V.
3. **+ RTC (I2C)** — acerte a hora e leia de volta. Desligue e religue: a hora tem que sobreviver (é o teste da bateria).
4. **+ microSD (SPI)** — escreva e leia um arquivo de teste. **Formate em FAT32.**
5. **+ INMP441 (I2S)** — leia amostras cruas e imprima. É a etapa mais difícil (T7 no [[WBS e Gantt]]).
6. **Integração** — DSP + gravação + display juntos (T8).
7. **Montagem física** — caixa, windscreen, tripé (T10).

Só passe pra etapa seguinte quando a anterior estiver funcionando. Se pular e quebrar, você não sabe qual das duas coisas causou.

---

## Pinagem

> [!note] A definir na bancada
> A pinagem exata depende do modelo de DevKit comprado (WROOM-32 e S3 têm mapas diferentes). **Preencher esta tabela em T6**, depois de conferir a serigrafia da placa recebida, e tirar uma foto da montagem antes de fechar a caixa.

| Sinal | Pino ESP32 | Vai para |
|---|---|---|
| I2S SCK (BCLK) | ⬜ | INMP441 SCK |
| I2S WS (LRCL) | ⬜ | INMP441 WS |
| I2S SD (DOUT) | ⬜ | INMP441 SD |
| INMP441 L/R | ⬜ | GND ou 3V3 (define canal esq/dir) |
| SPI MOSI | ⬜ | microSD MOSI |
| SPI MISO | ⬜ | microSD MISO |
| SPI SCK | ⬜ | microSD SCK |
| SPI CS | ⬜ | microSD CS |
| I2C SDA | ⬜ | OLED SDA + DS3231 SDA |
| I2C SCL | ⬜ | OLED SCL + DS3231 SCL |
| 3V3 | — | Todos os VCC |
| GND | — | Todos os GND |

---

## Montagem física

- **Microfone para fora da caixa**, com o windscreen. Microfone dentro de caixa fechada mede a caixa, não a rua.
- **Furo do microfone selado** contra chuva leve, mas sem obstruir a porta acústica do MEMS.
- **Nada de fio solto** — o que balança em campo é o que desconecta. Prender com abraçadeira ou hot glue depois de validado.
- **Acesso ao cartão SD sem abrir a caixa**, se possível. Você vai tirar o cartão dezenas de vezes.
- **Display visível** com a caixa fechada.
- Encaixe do tripé: rosca padrão 1/4" na base da caixa, ou braçadeira.

---

## Erros comuns e diagnóstico rápido

| Sintoma | Causa provável |
|---|---|
| ESP32 não aparece na porta serial | Cabo de carga (sem dados) ou driver USB-serial faltando |
| Reinício aleatório / brownout | Alimentação insuficiente — testar outra fonte antes de suspeitar do código |
| OLED ou RTC não responde | Endereço I2C errado, SDA/SCL trocados, ou 5V onde devia ser 3.3V |
| Cartão SD não monta | Formatação errada (usar FAT32), CS no pino errado, cartão de má qualidade |
| INMP441 lê só zeros ou ruído constante | L/R não conectado, WS/SCK trocados, ou config de I2S incorreta |
| Valores absurdos e instáveis | Falta de aterramento comum entre módulos |

Relacionado: [[Lista de Componentes]], [[ESP32 e I2S]], [[Wokwi e Firmware]], [[Verificação]].
