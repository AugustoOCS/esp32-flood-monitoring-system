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


---

# 🌧️ Smart Flood Alert System (English Version)

IoT-based intelligent monitoring system designed to prevent floods and heavy rain impacts using ESP32 and environmental sensors. The system collects temperature, humidity, and water level data to detect risk conditions and trigger visual and audible alerts in real time.

## 🎯 Project Objective

To develop a practical and accessible IoT solution that supports flood prevention, especially in areas near rivers, using sensor data to assist decision-making.

## 🧠 Technologies Used

* ESP32 DevKit V4
* DHT22 Sensor (temperature and humidity)
* HC-SR04 Ultrasonic Sensor (water level)
* LED (visual alert)
* Buzzer (audible alert)
* Arduino / C++
* Wokwi (circuit simulation)

## ⚙️ System Operation

* The **DHT22** sensor monitors ambient temperature and humidity
* When conditions indicate possible rainfall, the **LED is activated**
* The **ultrasonic sensor** measures the distance to the water level
* If the water reaches a critical threshold, the **buzzer emits an alert sound**
* All readings are displayed in an organized format on the **Serial Monitor**

## 📁 Repository Structure

```
├── src/
│   └── prog.ino     # Main ESP32 source code
├── diagram.json     # Circuit diagram (Wokwi)
├── wokwi.toml       # Wokwi environment configuration
└── README.md        # Project documentation
```

## 🧪 Simulation

The project can be fully tested and executed using **Wokwi**, allowing complete hardware simulation and alert visualization.

## 🎥 Demonstration

System demonstration video:
[https://youtu.be/4qRYuLY9ueQ](https://youtu.be/4qRYuLY9ueQ)

## 👥 Authors

* Augusto Oliveira Codo de Sousa
* Felipe de Oliveira Cabral
* Sofia Bueris Netto de Souza

## 🎓 Academic Context

Project developed as part of the **Global Solution – AI Computer Systems and Sensors**, within the **Artificial Intelligence Technology** degree program.

## 🚀 Future Improvements

* Integration with weather APIs
* Alert notifications via mobile app or SMS
* Cloud-based data storage
* Web dashboard for historical data visualization
