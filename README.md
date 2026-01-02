# 🌧️ Smart Flood Alert System

Projeto IoT de monitoramento inteligente voltado à prevenção de chuvas e enchentes, utilizando ESP32 e sensores ambientais. O sistema coleta dados de temperatura, umidade e nível da água, analisando condições de risco e emitindo alertas visuais e sonoros em tempo real.

## 🎯 Objetivo

Desenvolver uma solução prática e acessível para apoio à prevenção de enchentes, especialmente em áreas próximas a rios, utilizando sensores e microcontroladores para tomada de decisão baseada em dados ambientais.

## 🧠 Tecnologias Utilizadas

* ESP32 DevKit V4
* Sensor DHT22 (temperatura e umidade)
* Sensor Ultrassônico HC-SR04 (nível da água)
* LED (alerta visual)
* Buzzer (alerta sonoro)
* Arduino / C++
* Wokwi (simulação do circuito)

## ⚙️ Funcionamento

* O sensor **DHT22** monitora a temperatura e a umidade do ambiente
* Quando os valores indicam condições propícias à chuva, o **LED é acionado**
* O sensor **ultrassônico** mede a distância até o nível da água
* Caso o nível fique abaixo de um limite crítico, o **buzzer emite um alerta sonoro**
* Todas as leituras são exibidas no **Serial Monitor** em formato organizado

## 📁 Estrutura do Repositório

```
├── src/
│   └── prog.ino     # Código principal do ESP32
├── diagram.json     # Diagrama do circuito (Wokwi)
├── platformio.ini   # Inicialização do platformio
├── wokwi.toml       # Configuração do ambiente Wokwi
└── README.md        # Documentação do projeto
```

## 🧪 Simulação
O projeto pode ser executado e testado diretamente no **Wokwi**, permitindo simulação completa do hardware e visualização dos alertas.

## 🎥 Demonstração
Vídeo do sistema em funcionamento:
https://youtu.be/4qRYuLY9ueQ

## 👥 Autores
- Augusto Oliveira Codo de Sousa
- Felipe de Oliveira Cabral
- Sofia Bueris Netto de Souza

## 🎓 Contexto Acadêmico
Projeto desenvolvido como parte da **Global Solution – AI Computer Systems and Sensors**, no curso de **Tecnologia em Inteligência Artificial**.

## 🚀 Possíveis Melhorias Futuras
- Integração com APIs meteorológicas
- Envio de alertas via aplicativo ou SMS
- Armazenamento de dados em nuvem
- Dashboard web para visualização histórica

