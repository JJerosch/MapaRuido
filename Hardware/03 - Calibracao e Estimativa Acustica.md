# 🎛️ Calibração e Estimativa Acústica

## 1. Princípio de Medição com o INMP441
O INMP441 é um microfone MEMS digital com sensibilidade nominal especificada em datasheet de:
$$\text{Sensibilidade} = -26\text{ dBFS} \quad @ \quad 94\text{ dB SPL } (1\text{ kHz})$$

Isso significa que para uma onda senoidal pura de $94\text{ dB SPL}$, a amplitude RMS atinge $-26\text{ dB}$ em relação ao fundo de escala digital ($24\text{ bits}$).

---

## 2. Cálculo do Nível Equivalente ($L_{Aeq}$) no ESP32
1. **Aquisição por DMA (I2S):** Buffer de amostras lido a $44.1\text{ kHz}$ ou $48\text{ kHz}$.
2. **Filtro IIR de Ponderação A:** Aplica a curva de resposta em frequência que simula o ouvido humano.
3. **Cálculo de RMS e dBFS:**
   $$\text{dBFS} = 20 \log_{10}\left(\frac{\text{RMS}}{2^{23}-1}\right)$$
4. **Conversão para dB SPL Estimado:**
   $$L_{Aeq} \approx \text{dBFS} + 94 - (-26) + \Delta_{\text{calib}}$$
   $$L_{Aeq} \approx \text{dBFS} + 120 + \Delta_{\text{calib}}$$
   *(onde $\Delta_{\text{calib}}$ é o fator de ajuste fino obtido na calibração)*

---

## 3. Validação em Laboratório
* Para o rigor acadêmico, o grupo fará uma sessão pontual de validação com decibelímetro classe 2 emprestado no laboratório da faculdade, comparando o valor calculado pela estação com o medidor de referência.
