# Resumo — Brainstorm de Projetos ESP32

> Conversa de 24/08/2026 · João Pedro

---

## Índice

1. [Ideia descartada: reconhecimento facial](#1-ideia-descartada-reconhecimento-facial-biométrico)
2. [Sugestões gerais de projeto](#2-sugestões-gerais-de-projeto)
3. [**Projeto atual: mapeamento de ruído urbano**](#3-projeto-atual-mapeamento-de-ruído-urbano-em-curitiba) ⬅ foco
4. [Próximos passos](#4-próximos-passos)

---

## 1. Ideia descartada: reconhecimento facial biométrico

Explorada e depois abandonada. Resumo do que ficou de aprendizado:

**Pipeline de reconhecimento facial:**
```
captura → detecção → alinhamento → embedding → comparação → decisão
```
O embedding é um vetor (ex: 512 floats) que funciona como "assinatura" do rosto. Rostos da mesma pessoa geram vetores próximos; a comparação é uma distância (euclidiana ou cosseno) contra um **threshold**.

**Duas arquiteturas possíveis:**
- **On-device** — ESP32-S3 + ESP-DL/esp-who. Offline e privado, mas limitado (~10 faces, 1–3 FPS).
- **ESP32 como sensor + backend** — ESP32 manda JPEG pra API Django. Mais preciso, escalável, e alinhado ao stack do João. *Era a recomendação.*

**Sobre machine learning:** você **usaria** ML, mas não **treinaria** nada. Modelos como ArcFace/FaceNet já vêm prontos. O que sobraria de ML real: escolher modelo, calibrar threshold (FAR × FRR) e avaliar. Projeto seria ~80% engenharia de software, 20% ML aplicado.

**Pontos que valem pra qualquer projeto futuro:**
- Cadastrar uma pessoa **não é treinar** — só salva um vetor no banco.
- Biometria facial é **dado sensível pela LGPD** (Art. 5º, II). Guardar embedding, não foto.
- Anti-spoofing (liveness) é quase sempre esquecido — uma foto no celular engana sistemas ingênuos.

**Estimativa que ficou:** ~50–70h.

**Armadilhas identificadas (valem pra outros projetos):**
- ⚠️ Instalar `dlib`/`face_recognition` no Windows exige compilar C++ e trava iniciantes por dias. Alternativa: **InsightFace + onnxruntime** (instala com pip) ou rodar em WSL2.
- ⚠️ ESP32-CAM precisa de **fonte 5V/2A externa**. Reinício aleatório e brownout são quase sempre alimentação, não código.
- ⚠️ Hardware de site chinês leva 30–60 dias — não entra na estimativa de código, mas entra no prazo.

---

## 2. Sugestões gerais de projeto

Filtradas pelo objetivo de transferir pra dev no Grupo RP até jan/2027.

### Tier 1 — Maior alavancagem pra transferência
Exploram a vantagem de estar **dentro do suporte** e ver os problemas reais.

| # | Ideia | Observação |
|---|---|---|
| 1 | Dashboard de chamados do suporte | Problemas recorrentes, tempo médio, picos por horário/cliente |
| 2 | Busca semântica na base de chamados antigos | Embeddings aplicados a texto; resolve o conhecimento que só existe na cabeça dos veteranos |
| 3 | Automatizar a tarefa mais repetitiva do dia | Menor escopo (~15h), maior visibilidade |

> ⚠️ Dado de cliente é sensível — pedir autorização antes de puxar qualquer base, preferir dados anonimizados.

### Tier 2 — Profundidade técnica
| # | Ideia | Observação |
|---|---|---|
| 4 | API REST "completa" | Django REST + JWT + testes + Docker + CI/CD + monitoramento. Cobre o roadmap de estudo |
| 5 | Terminar e polir o Projeto Adoção | Faltam testes, Docker, deploy, README |
| 6 | Encurtador de URL com analytics | Escopo pequeno (~25h): hashing, Redis, concorrência, rate limiting |

### Tier 3 — Nota + portfólio
| # | Ideia | Observação |
|---|---|---|
| 7 | Estender o SIA-C além do requisito | Backend Django em cima do ESP32; melhor esforço/retorno |

### Princípio que ficou
> **Projeto pequeno e 100% terminado > projeto ambicioso e 80% pronto.**
> O gargalo raramente é falta de ideia — é falta de "concluído".

---

## 3. Projeto atual: mapeamento de ruído urbano em Curitiba

**Origem:** sugestão de professor. ESP32 num carro (de preferência elétrico) mede decibéis das ruas + GPS, pra indicar onde alocar ônibus em locais mais barulhentos (= mais movimentados).

### 3.1 Veredito

| | |
|---|---|
| Complexidade técnica | **Média-alta** ⚠️ |
| Esforço estimado | ~70–110h |
| Onde está a dificuldade | Não é o firmware — é **calibração acústica** e **análise de dados** |
| Risco principal | A premissa "ruído = demanda por ônibus" não se sustenta sozinha |

É, na prática, um projeto de **instrumentação + ciência de dados** com um ESP32 no meio.

### 3.2 Arquitetura

```
[Carro em movimento]
   ├── Microfone I2S ──> DSP (A-weighting + RMS) ──> LAeq
   ├── GPS ──> lat, lon, velocidade, timestamp UTC
   └── ESP32 ──> grava CSV no cartão SD
                      ↓ (depois, no WiFi de casa)
              [Pipeline Python: limpeza → map matching → agregação por via]
                      ↓
              [Mapa de calor de ruído + cruzamento com dados da URBS]
```

Três blocos independentes: **firmware embarcado**, **coleta de campo**, **análise geoespacial**. O terceiro é o mais subestimado e o que mais dá nota.

### 3.3 Hardware (~R$ 150–250)

| Peça | Recomendação | Por quê |
|---|---|---|
| MCU | ESP32-S3 (ou WROOM-32) | S3 tem mais RAM e melhor desempenho pra DSP |
| Microfone | **INMP441** ou ICS-43434 (I2S digital) | ⚠️ **Não usar KY-038 nem MAX9814** — analógicos baratos dão nível relativo, não dB. O INMP441 tem sensibilidade em datasheet, o que permite converter pra dB SPL |
| GPS | NEO-6M (barato) ou NEO-M8N (melhor) | UART/NMEA. Também fornece relógio UTC de graça |
| Armazenamento | Módulo microSD (SPI) | Essencial — não depender de rede móvel |
| Alimentação | Carregador USB veicular | Rede elétrica de carro tem transientes; carregador comercial já protege |

**Conectividade:** gravar tudo no SD e fazer upload depois via WiFi. Evitar módulo celular — o 2G está sendo desligado no Brasil e o 4G (SIM7600) custa mais que o resto do projeto.

### 3.4 Dificuldade nº 1 — medir decibel de verdade

O que separa um projeto sério de um "sensor de barulho de Arduino":

1. **Ponderação A (dB(A))** — o ouvido não escuta todas as frequências igual. Implementar filtro IIR de ponderação A no ESP32 (cascata de biquads, existem implementações prontas em C).
2. **LAeq, não valor instantâneo** — o descritor padrão é o nível equivalente contínuo (RMS integrado em janela de 1s). Registrar também `Lmax`, `L10`, `L90` — são os nomes que aparecem em norma.
3. **Calibração** — precisa de offset conhecido. Ideal: pegar emprestado um **decibelímetro do laboratório da PUC** e medir junto em ambientes de níveis diferentes. Sem isso, os números são só relativos.

📌 Pesquisar a **NBR 10151** (avaliação de ruído em áreas habitadas) — citar norma pesa muito no relatório.

### 3.5 Dificuldade nº 2 — medir de dentro de um carro em movimento

O carro elétrico resolve só metade do problema.

O microfone vai captar:
- ✅ Ruído da rua (o que se quer)
- ❌ Ruído do motor → resolvido pelo elétrico
- ❌ **Ruído de pneu no asfalto** — domina acima de ~40 km/h, e é do *próprio* carro
- ❌ **Ruído aerodinâmico (vento)** — destrói o sinal se o mic ficar exposto
- ❌ Ar-condicionado, rádio, conversa na cabine
- ❌ Isolamento acústico, se medir com janela fechada

**Mitigações:**
- Microfone **fora**, com espuma anti-vento (windscreen) — obrigatório
- **Filtrar por velocidade:** descartar amostras acima de ~40 km/h, ou modelar o ruído próprio em função da velocidade e subtrair
- Registrar velocidade do GPS junto — vira variável de controle na análise
- **Alternativa mais limpa:** coletar parado ou a pé, em pontos fixos de 5 min. Menos cobertura, dados muito melhores. Um híbrido (transecto de carro + pontos fixos de validação) é o desenho mais defensável.

### 3.6 Dificuldade nº 3 — a premissa, e como salvar o projeto

**Ruído não mede demanda por transporte público.** Furos na cadeia lógica:

- Ruído correlaciona com **tráfego de veículos**, não com **pessoas precisando de ônibus**
- Via rápida é ensurdecedora e não tem pedestre; bairro residencial denso é silencioso e cheio de gente que depende de ônibus
- Confundidores: tipo de asfalto, limite de velocidade, caminhões, obras, efeito de cânion entre prédios, distância do mic à via
- Curitiba já tem BRT nos eixos estruturais — justamente os mais barulhentos. O mapa provavelmente vai "descobrir" corredores que já são super atendidos

Isso não mata o projeto — mata a versão ingênua dele. Duas saídas:

#### Saída A — o mapa de ruído é o produto ✅ *(recomendada)*

Reformular o título para algo como:

> *"Mapeamento móvel de ruído urbano de baixo custo em Curitiba com ESP32 e GPS: metodologia, validação e análise exploratória frente à rede de transporte público"*

O entregável passa a ser o **mapa de ruído**, que tem valor próprio: a OMS associa exposição noturna acima de 55 dB(A) a risco cardiovascular, e Curitiba tem legislação de ruído. A questão dos ônibus vira **seção de discussão**, não afirmação.

#### Saída B — validar o proxy vira a contribuição

Manter a hipótese do professor, mas **testá-la explicitamente**: coletar ruído E verdade de campo (contagem manual de veículos e pedestres em ~10 pontos, 15 min cada) e calcular a correlação.

- R² bom → você *provou* o proxy
- R² ruim → você provou que não funciona, resultado igualmente publicável e mais interessante

Nos dois casos o projeto do professor continua de pé. Só se para de assumir a conclusão e passa a investigá-la.

### 3.7 Trunfo: dados abertos de Curitiba

- **URBS** publica dados do transporte (linhas, pontos, itinerários, feed **GTFS**)
- **Portal de dados abertos da Prefeitura** tem camadas urbanas
- **OpenStreetMap** dá a malha viária pro *map matching* (associar cada ponto GPS a um segmento de rua) — direto com `OSMnx` em Python

Cruzar o mapa de ruído com a rede real de ônibus transforma "coletei uns números" em análise.

### 3.8 Estimativa por fase

| Fase | Horas |
|---|---|
| 1. Mic I2S lendo e calculando RMS na bancada | 6–10h |
| 2. Filtro A-weighting + calibração com decibelímetro | 8–12h |
| 3. GPS: parsing NMEA, fix, sincronismo de tempo | 5–8h |
| 4. Logging em CSV no SD | 4–6h |
| 5. Montagem física, caixa, alimentação veicular | 5–8h |
| 6. **Coletas de campo** (várias rotas e horários) | 10–20h |
| 7. Pipeline Python: limpeza, map matching, agregação | 12–20h |
| 8. Mapa de calor + cruzamento com dados URBS | 10–15h |
| 9. Relatório / artigo | 10–15h |
| **Total** | **~70–110h** |

Em ~10h/semana: **8 a 11 semanas.** Cabe num semestre, mas sem folga. A fase 6 é tempo de calendário — precisa de dias distintos, pico e fora de pico, e de preferência sem chuva (altera o ruído de rolamento).

### 3.9 Logística

- **João tem 17 anos e não dirige** — depende de alguém pra rodar as coletas, e são várias saídas, não uma. Alinhar cedo. Plano B totalmente viável: **pontos fixos a pé + bicicleta**, com dados mais limpos.
- **Carro elétrico:** ótimo se conseguir, mas não travar o projeto nisso. Combustão a baixa velocidade com mic externo bem posicionado ainda funciona — a limitação vira seção honesta de "trabalhos futuros".

### 3.10 Escopo mínimo vs. completo

**Mínimo entregável (~40h):** mic + GPS + SD gravando LAeq georreferenciado, uma rota coletada, um mapa de calor gerado. Já é projeto completo e apresentável.

Tudo depois disso — calibração fina, map matching, cruzamento com URBS, validação do proxy — é **incremento de qualidade, não requisito de existência**.

> Fazer nessa ordem garante que nunca se fica sem entregar.

---

## 4. Próximos passos

### Perguntas em aberto
- [ ] Qual o **prazo e formato**? (TDE, TCC, iniciação científica, feira) — muda o rigor esperado
- [ ] É **individual ou em grupo**? 100h sozinho ≠ 100h divididas em três
- [ ] Tem acesso a um **decibelímetro** pela PUC? Se sim, a calibração deixa de ser problema

### Ações imediatas
- [ ] Comprar o hardware **agora** (prazo de entrega não entra na estimativa de código, mas entra no prazo real)
- [ ] Confirmar com o professor a reformulação do escopo (Saída A ou B)
- [ ] Checar disponibilidade do decibelímetro no laboratório
- [ ] Definir quem dirige nas coletas — ou assumir o plano B (a pé/bicicleta)

### Tópicos que podem ser aprofundados
- Matemática do A-weighting e conversão pra dB SPL
- Esquema de ligação (pinout I2S + UART + SPI) e formato do CSV
- Pipeline de map matching com OSMnx
