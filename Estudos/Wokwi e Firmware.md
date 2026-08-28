# Wokwi e Firmware

## O que é

**Wokwi** é um simulador de ESP32/Arduino que roda no navegador, com componentes virtuais (display, cartão SD, RTC, botões). O grupo já usou no SIA — é a única experiência prévia com ESP32 que existe aqui, já que aquele projeto foi **inteiramente simulado**.

## Por que neste projeto

Duas razões, e a segunda é a que importa mais:

1. **O hardware ainda não chegou.** Entrega nacional leva 3–10 dias e a compra é T2, na semana 1.
2. **Ninguém do grupo montou um ESP32 físico antes.** Chegar na bancada com código já funcionando reduz muito o risco da fase mais crítica.

Isso é [[Registro de Decisões|D-13]]: **T4 roda no Wokwi em paralelo à entrega.**

## O que dá pra fazer no simulador (T4)

| Componente | Simulável? | Observação |
|---|---|---|
| **Cartão SD** (SPI) | ✅ | Escrita de CSV, rotação de arquivo, tratamento de erro |
| **OLED SSD1306** (I2C) | ✅ | Layout da tela de campo |
| **RTC DS3231** (I2C) | ✅ | Timestamp, formatação de data |
| Botões / lógica de sessão | ✅ | Iniciar/parar medição |
| Estrutura geral do firmware | ✅ | Máquina de estados, loop principal |
| **INMP441 / I2S** | ❌ | **Não** — precisa de hardware real (T7) |

> [!important] Congele o formato do CSV ainda no Wokwi
> É a entrega mais valiosa de T4. Se o formato estiver definido e testado antes do piloto, o pipeline Python (T15) pode começar a ser escrito com dados sintéticos — e nada trava esperando o outro.

## O que precisa de hardware real

- **Leitura I2S do microfone** (T7) → [[ESP32 e I2S]]
- Desempenho real do filtro de ponderação A no chip (T8)
- Comportamento de alimentação, brownout, autonomia (T10)
- Integridade do cartão em queda de energia → [[Verificação]], item 4

E o **filtro de ponderação A** não precisa nem do Wokwi nem do ESP32 — desenvolve-se no desktop contra um WAV (T5). Ver [[Ponderação A e LAeq]].

## Fundamentos a dominar

- Estrutura de um sketch Arduino / projeto PlatformIO
- Bibliotecas: `SD`, `Adafruit_SSD1306` (ou `U8g2`), `RTClib`
- **Máquina de estados** simples: ocioso → medindo → gravando → erro
- Escrita segura em cartão: abrir, escrever, **fechar** (arquivo aberto é arquivo que corrompe)
- Como configurar o `diagram.json` do Wokwi pra montar o circuito virtual
- Modo servidor HTTP para a demo (T19) — reaproveitar o que foi estudado no SIA-C

## Organização do código

Sugestão de estrutura, pra que T5 (desktop) e T8 (ESP32) possam compartilhar o filtro:

```
/firmware
  ├── main            → loop, máquina de estados
  ├── dsp             → ponderação A + RMS + percentis  ← compartilhado com o desktop
  ├── storage         → CSV no SD
  ├── display         → OLED
  └── demo            → servidor HTTP do stand
/analise
  └── validacao_dsp   → roda o mesmo DSP contra WAV de referência
```

Manter o DSP isolado do resto é o que permite validá-lo no desktop antes de portar.

## Onde estudar

- **wokwi.com/docs** — especialmente a documentação do `diagram.json`
- Documentação das bibliotecas Arduino de SD, OLED e RTC
- **PlatformIO** vale a pena se o grupo for versionar o firmware direito (integra melhor com Git que a Arduino IDE)

## Como saber que entendeu

- No Wokwi, o firmware grava um CSV bem formado, mostra estado no OLED e usa a hora do RTC
- Você desliga e religa a simulação e o arquivo anterior continua legível
- O formato do CSV está **congelado e documentado** em [[Protocolo de Medição]]
- Alguém da frente de Dados consegue começar o pipeline usando um CSV sintético que você gerou

Relacionado: [[ESP32 e I2S]], [[Montagem e Ligações]], [[Ponderação A e LAeq]], [[WBS e Gantt]].
