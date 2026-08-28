# Verificação

Como saber que cada etapa funcionou **de verdade**. Em ordem — cada item bloqueia o seguinte.

> [!tip] A regra por trás desta lista
> Descobrir um problema na bancada custa uma tarde. Descobrir o mesmo problema depois de 12 sessões de campo custa o projeto.

---

## 1. Bancada — o microfone lê (T7)

O INMP441 entrega amostras I2S com RMS estável e sem `NaN`.

**Teste:** silêncio → palma → música → silêncio.
**Aceite:** os valores se movem na direção certa e **voltam ao repouso**. Um valor que sobe e não desce é integrador travado; um valor que oscila em silêncio é piso de ruído ou aterramento ruim.

## 2. DSP — a ponderação A está correta (T8)

**Teste:** rodar o filtro **no desktop** contra um WAV de referência (ruído rosa ou tons puros), comparando com o resultado de uma implementação conhecida.
**Aceite:** diferença dentro da tolerância que vocês definirem e registrarem.

> [!warning] Só porte pro ESP32 depois que passar no desktop
> Depurar DSP dentro do microcontrolador, sem poder inspecionar o sinal, é muito mais lento. Ver [[Ponderação A e LAeq]].

## 3. Calibração — os dB são absolutos (T9)

**Teste:** medir simultaneamente com o decibelímetro em **≥3 níveis distintos** (~35, ~60, ~75 dB(A)). Plotar estação × referência.
**Aceite:** regressão **linear com R² > 0,95**. O offset vira constante de calibração no firmware.
**Repetir** depois de fechar a caixa e pôr o windscreen. Ver [[Calibração]].

## 4. Cartão SD — o dado sobrevive (T8)

> [!danger] Este é o teste que ninguém faz e todo mundo se arrepende
> **Teste:** desligar a estação **na tomada**, no meio de uma gravação.
> **Aceite:** o arquivo da medição anterior está íntegro e legível.
>
> Perder uma sessão de campo inteira por arquivo corrompido é o pior fracasso possível deste projeto — e é totalmente evitável.

## 5. Autonomia — a bateria aguenta (T10)

**Teste:** medir por **3h contínuas** no power bank, antes da primeira sessão real.
**Aceite:** nenhum reinício, nenhum brownout, arquivo íntegro no fim.

## 6. Piloto — o ciclo inteiro fecha (T11)

**Teste:** um ponto, ciclo completo: medição → contagem manual → digitalização → entrada no pipeline Python → aparece no mapa.
**Aceite:** o dado atravessou tudo sem intervenção manual improvisada.

> [!important] Se o dado não atravessa o pipeline com 1 ponto, não vai atravessar com 48
> O piloto existe pra descobrir que falta uma coluna no CSV, que o `sessao_id` não bate, ou que a planilha não junta com o dado da estação. Descobrir isso em S5 custa um ajuste; descobrir em S9 custa refazer.

## 7. Mapa — abre onde vai ser usado (T18)

**Teste:** abrir o HTML publicado **num celular, em rede móvel, fora de casa**.
**Aceite:** carrega em tempo razoável e é navegável com o dedo.
**Por quê:** feira tem WiFi ruim e as pessoas vão querer abrir no próprio celular.

## 8. Stand — a apresentação roda (T21)

**Teste:** ensaio completo, com a demo ligada e alguém de fora do grupo assistindo.
**Aceite:**
- [ ] A estação liga e mostra número em menos de 1 min
- [ ] O mapa abre
- [ ] Alguém do grupo explica o argumento do calçadão da XV em **menos de 2 minutos**
- [ ] O **vídeo plano B** está no celular de pelo menos duas pessoas
- [ ] Cabo reserva e power bank carregado na mochila

---

## Checklist de fechamento de fase

Antes de declarar uma fase concluída no [[Progresso do Projeto]]:

- [ ] O teste de verificação correspondente passou
- [ ] O resultado foi anotado (não "passou", mas *com que número* passou)
- [ ] Qualquer decisão nova tomada no caminho foi registrada em [[Registro de Decisões]]
- [ ] O que deu errado ficou anotado, mesmo que já resolvido — é conteúdo de relatório

Relacionado: [[Montagem e Ligações]], [[Protocolo de Medição]], [[Riscos]], [[Roteiro da Feira]].
