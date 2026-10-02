# Registro de Decisões

Log de todas as decisões do projeto. Formato: **Contexto → Decisão → Consequência**. Ordenado por tema, não por data. Quando decidir algo novo, adicione aqui **antes** de executar.

> Legenda: `[Reform]` = definido na reformulação de escopo de 26/08/2026.

---

## Fundamentais

### D-01 — Metodologia híbrida A+B `[Reform]`
- **Contexto:** a proposta original assumia que ruído indica demanda por ônibus. A premissa tem furos graves — ver [[A Hipótese em Teste]].
- **Decisão:** o **mapa de ruído é o entregável principal** (Saída A) **e** a hipótese do proxy é **testada explicitamente** com contagem manual de campo (Saída B).
- **Consequência:** o projeto do professor continua de pé, mas para de assumir a conclusão. Exige mão-de-obra de contagem — viável porque o grupo tem 5 pessoas.

### D-02 — Pontos fixos, não medição veicular `[Reform]`
- **Contexto:** medir de dentro de um carro em movimento capta ruído de pneu (que domina acima de ~40 km/h e é do *próprio* veículo), vento, ar-condicionado e a cabine isolando.
- **Decisão:** medição **estacionária** em pontos fixos, com a estação em tripé, chegando ao local a pé, de bicicleta ou de carona.
- **Consequência:** elimina de uma vez o maior risco técnico do projeto original. O carro do grupo vira **logística**, não plataforma de medição. Menos cobertura geográfica, dado muito mais limpo.

### D-03 — Uma única estação `[Reform]`
- **Contexto:** com 5 membros, 3 a 5 estações permitiriam medir pontos simultaneamente. O orçamento de R$500 não comporta.
- **Decisão:** **1 estação**, medição sequencial.
- **Consequência:** diferenças entre pontos podem ser *horário*, não *lugar*. Obriga o mecanismo de **ponto-âncora** — ver D-04 e [[Protocolo de Medição]].

### D-04 — Ponto-âncora para normalização temporal `[Reform]`
- **Contexto:** consequência direta de D-03. Sem controle, um ponto medido às 8h e outro às 11h não são comparáveis.
- **Decisão:** um **ponto de referência fixo** é medido no **início e no fim de cada sessão**. A deriva entre as duas leituras vira fator de normalização da sessão.
- **Consequência:** custa ~20 min por sessão e é **inegociável**. Sessão sem âncora é sessão perdida.

---

## Hardware

### D-05 — GPS NEO-6M para geolocalização e relógio atômico `[Atualizado]`
- **Contexto:** o RTC exigiria conferência manual antes de cada sessão de campo e anotação manual de coordenadas. O grupo optou pela inclusão do GPS NEO-6M.
- **Decisão:** usar o **GPS NEO-6M** conectado via UART (Serial 2). O GPS fornece Latitude, Longitude, Altitude e o timestamp UTC exato.
- **Consequência:** o módulo RTC DS3231 é eliminado. O arquivo CSV já nasce com coordenadas e data/hora automáticas.

### D-06 — Microfone MEMS digital I2S, não analógico `[Reform]`
- **Contexto:** módulos analógicos baratos (KY-038, MAX9814, MAX4466) são o padrão em tutoriais de Arduino.
- **Decisão:** **INMP441** (ou ICS-43434). Inegociável.
- **Consequência:** módulos analógicos entregam **nível relativo**, não dB SPL — não têm sensibilidade especificada em datasheet, então não há como converter para unidade física. Usar um deles invalidaria o projeto inteiro. Ver [[Lista de Componentes]].

### D-07 — Sem calibrador acústico / Decibelímetro comercial dispensado `[Atualizado]`
- **Contexto:** um decibelímetro comercial classe 2 encarece o orçamento em R$ 180–250.
- **Decisão:** dispensar a compra de decibelímetro comercial para a estação. A medição de nível sonoro é calculada matematicamente pela sensibilidade de datasheet do INMP441 ($-26\text{ dBFS}$ @ $94\text{ dB SPL}$). Se houver oportunidade, valida-se pontualmente com equipamento emprestado no laboratório da PUC.
- **Consequência:** orçamento total cai para ~R$ 212 (~R$ 42/pessoa).

### D-08 — Gravação local em microSD, sem conectividade em campo `[Reform]`
- **Contexto:** enviar dados em tempo real exigiria módulo celular (2G sendo desligado no Brasil; 4G caro demais).
- **Decisão:** grava CSV no cartão, transfere depois no WiFi de casa.
- **Consequência:** simplifica muito o firmware. Cria um ponto único de falha — se o cartão corromper, a sessão se perde. Por isso o teste de queda de energia está em [[Verificação]].

### D-15 — ESP32-WROOM-32 DevKit V1 (30 pinos) `[Fechado]`
- **Contexto:** escolha entre WROOM-32 e ESP32-S3.
- **Decisão:** adotar o **ESP32-WROOM-32 (versão 30 pinos)**.
- **Consequência:** excelente custo (~R$ 38), sobra espaço na protoboard 830 pontos e suporta perfeitamente I2S DMA, filtro IIR e UART do GPS.

### D-19 — Inclusão do sensor climático DHT22 `[Novo]`
- **Contexto:** a velocidade e absorção acústica no ar variam com a temperatura e a umidade relativa do ambiente.
- **Decisão:** incluir o sensor **DHT22 (AM2302)** para registrar temperatura (°C) e umidade (%) junto a cada medição acústica.
- **Consequência:** adiciona valor analítico e rigor metodológico para o relatório final.

---

## Metodologia

### D-09 — Amostra estratificada de 12 pontos `[Reform]`
- **Contexto:** cobrir Curitiba inteira é inviável; escolher pontos "no olho" não sustenta análise.
- **Decisão:** **6 tipologias urbanas × 2 pontos cada**, escolhidas para maximizar contraste.
- **Consequência:** 12 pontos não permitem interpolação espacial — o mapa é **de pontos**, não de superfície. Ver [[Amostra Estratificada]].

### D-10 — Calçadão da XV como ponto obrigatório `[Reform]`
- **Contexto:** o argumento contra o proxy precisa de um caso concreto e intuitivo.
- **Decisão:** a Rua XV de Novembro entra na amostra como tipologia própria (calçadão pedonal).
- **Consequência:** é o ponto que sustenta a apresentação inteira — muita gente, quase nenhum veículo. Ver [[A Hipótese em Teste]].

### D-11 — LAeq de 10 minutos por ponto `[Reform]`
- **Contexto:** valores instantâneos de dB não descrevem ambiente sonoro. Janelas curtas demais são instáveis; longas demais inviabilizam o volume de medições.
- **Decisão:** **10 minutos** de medição contínua por ponto, registrando `LAeq`, `Lmax`, `L10` e `L90`.
- **Consequência:** ~4 pontos por sessão de 3h. 48 medições em ~12 sessões. Ver [[Protocolo de Medição]].

### D-12 — Descartar dias de chuva `[Reform]`
- **Contexto:** pista molhada altera significativamente o ruído de rolamento dos pneus.
- **Decisão:** sessão com chuva é **cancelada e refeita**, não corrigida.
- **Consequência:** exige 2 sessões de reserva no cronograma. Ver [[Riscos]].

---

## Execução

### D-13 — Desenvolver no Wokwi antes do hardware chegar `[Reform]`
- **Contexto:** este é o **primeiro projeto do grupo com ESP32 físico** — o SIA anterior foi todo simulado. Além disso, o hardware leva 3–10 dias pra chegar.
- **Decisão:** T4 (esqueleto de firmware) roda no **Wokwi** e T5 (filtro de ponderação A) roda **no desktop, validado contra WAV**, ambos em paralelo à entrega das peças.
- **Consequência:** o grupo chega na bancada com código pronto, e a parte mais difícil do projeto sai do caminho crítico. Ver [[WBS e Gantt]] e [[Wokwi e Firmware]].

### D-14 — Vídeo gravado como plano B da demo `[Reform]`
- **Contexto:** hardware falha em feira — bateria acaba, conexão cai, alguém esbarra na mesa.
- **Decisão:** gravar um vídeo da estação funcionando **antes** do dia da feira.
- **Consequência:** o stand nunca fica sem demonstração. Ver [[Roteiro da Feira]].

---

## Decisões pendentes

Estas ainda **não** foram tomadas e estão rastreadas em [[Status das Pendências]]:

- **D-17** — Ponto-âncora: qual local exato será usado
- **D-18** — Data exata da feira (o cronograma assume S12)

---

## Como adicionar uma decisão

Copie o modelo abaixo, use o próximo número livre e **registre antes de executar**:

> ### D-nn — Título curto e afirmativo
> - **Contexto:** o que estava em jogo, qual era o problema.
> - **Decisão:** o que foi decidido, sem ambiguidade.
> - **Consequência:** o que isso obriga, permite ou impede daqui pra frente.

