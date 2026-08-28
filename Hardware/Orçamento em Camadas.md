# Orçamento em Camadas

**Teto:** R$500, lojas nacionais (entrega 3–10 dias).

> [!caution] Os valores abaixo são estimativas de planejamento, não preços verificados
> Servem pra dimensionar o projeto e decidir o que cortar. **Substituir pelos valores reais** assim que a cotação voltar → [[Status das Pendências]].

A lógica das camadas: **cortar de baixo pra cima**. Se o orçamento estourar, a Camada 3 sai primeiro, depois itens da Camada 2 — a Camada 1 nunca sai.

---

## 🔴 Camada 1 — Essencial (~R$150)

Sem isto **não existe projeto**.

| Item | Estimativa |
|---|---|
| ESP32 DevKit (WROOM-32 ~R$45 · S3 ~R$90) | R$45–90 |
| INMP441 (I2S digital) | ~R$35 |
| Módulo microSD SPI + cartão 32GB | ~R$42 |
| Jumpers + protoboard + cabo USB de dados | ~R$30 |
| **Subtotal** | **~R$152–197** |

---

## 🟡 Camada 2 — Recomendado (~R$290)

Sem isto o dado é **relativo, não absoluto** — e o projeto perde o que o diferencia.

| Item | Estimativa |
|---|---|
| **Decibelímetro classe 2** | R$180–250 |
| OLED SSD1306 0.96" | ~R$25 |
| Windscreen / espuma anti-vento | ~R$15 |
| DS3231 (RTC) | ~R$18 |
| **Subtotal** | **~R$238–308** |

> [!important] O decibelímetro é o item mais caro e o que mais agrega valor
> É ele que transforma "o número subiu" em "são 72 dB(A)". Se precisar escolher entre ele e o ESP32-S3, **fique com o decibelímetro e compre o WROOM-32**.

---

## 🟢 Camada 3 — Desejável (~R$85)

Melhora a execução, mas tem substituto improvisado.

| Item | Estimativa | Substituto se cortar |
|---|---|---|
| Tripé regulável até 1,5 m | ~R$60 | Improvisar com cabo de vassoura + braçadeira, ou pedir emprestado |
| Caixa de projeto ABS | ~R$25 | Pote plástico rígido, ou impressão 3D na PUC |

---

## ✅ Já disponível

| Item | Economia |
|---|---|
| Power bank 10000mAh | ~R$70 |

## ❌ Fora do orçamento

| Item | Custo | Alternativa |
|---|---|---|
| Calibrador acústico (pistonfone) | ~R$400+ | Tentar empréstimo na PUC; senão, declarar como limitação → [[Calibração]] |

---

## Fechamento

| Cenário | Total estimado | Cabe em R$500? |
|---|---|---|
| WROOM-32 + tripé improvisado | ~R$435–500 | ✅ Sim |
| WROOM-32 + tripé comprado | ~R$495–560 | ⚠️ No limite |
| ESP32-S3 + tudo comprado | ~R$540–605 | ❌ Estoura |

**Recomendação:** WROOM-32 + decibelímetro bom + tripé improvisado ou emprestado. O S3 é conforto, o decibelímetro é metodologia.

---

## Divisão entre os 5 membros

R$500 ÷ 5 = **R$100 por pessoa**. Vale acertar isso **antes** de comprar, não depois — e guardar todas as notas fiscais, que o pessoal da feira às vezes pede comprovação de custo.

Quem compra o quê também importa: um único CPF comprando tudo simplifica o rastreio e o frete. Combinar em [[Alocação do Grupo]].

Relacionado: [[Lista de Componentes]], [[Riscos]].
