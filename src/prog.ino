#include <DHT.h>  // Biblioteca para o sensor DHT22 (temperatura e umidade)

// Definição dos pinos usados pelos sensores e atuadores
#define LED_PIN 23       // LED que indica condições de chuva
#define TRIG_PIN 22      // Pino Trigger do sensor ultrassônico
#define ECHO_PIN 21      // Pino Echo do sensor ultrassônico
#define DHT_PIN 27       // Pino do sensor DHT22
#define DHTTYPE DHT22    // Definindo o tipo do sensor DHT
#define BUZZ_PIN 12      // Pino conectado ao buzzer

// Configuração do PWM para o buzzer (controle de som)
#define BUZZ_PWM_CHANNEL 0    // Canal PWM usado no ESP32
#define BUZZ_RESOLUTION 8     // Resolução em bits do PWM
#define BUZZ_FREQUENCY 5000   // Frequência do PWM para o buzzer

// Cria um objeto para o sensor DHT22 com o pino definido
DHT dht(DHT_PIN, DHTTYPE);

unsigned long previousMillis = 0; // Variável para controlar o intervalo de tempo entre leituras
const long interval = 2500; // Intervalo (2,5 segundos)

int sampleNumber = 1; // Contador para número da amostra, usado para simular data e hora

// Função para tocar uma frequência no buzzer usando PWM
void buzzerTone(int freq) {
  ledcWriteTone(BUZZ_PWM_CHANNEL, freq);
}

// Função para desligar o som do buzzer
void buzzerNoTone() {
  ledcWriteTone(BUZZ_PWM_CHANNEL, 0);
}

// Função que realiza a leitura da distância usando sensor ultrassônico HC-SR04
float lerDistancia() {
  digitalWrite(TRIG_PIN, LOW);       // Garante que o trigger está baixo
  delayMicroseconds(2);              // Pequena pausa para estabilização
  digitalWrite(TRIG_PIN, HIGH);      // Envia pulso de trigger
  delayMicroseconds(10);             // Pulso de 10 microssegundos
  digitalWrite(TRIG_PIN, LOW);       // Para o pulso

  // Mede o tempo que o pulso demora para voltar (em microssegundos)
  long duracao = pulseIn(ECHO_PIN, HIGH);

  // Converte o tempo para distância em cm (velocidade do som ~0.034 cm/us)
  return duracao * 0.034 / 2;
}

void setup() {
  Serial.begin(115200);  // Inicializa comunicação serial para debug/impressão
  dht.begin(); // Inicializa o sensor DHT22
  delay(2000); // Dois segundos pra estabilizar o código 

  // Configura os pinos como entrada ou saída conforme o uso
  pinMode(LED_PIN, OUTPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  // Configura o canal PWM para o buzzer
  ledcSetup(BUZZ_PWM_CHANNEL, BUZZ_FREQUENCY, BUZZ_RESOLUTION);
  ledcAttachPin(BUZZ_PIN, BUZZ_PWM_CHANNEL);

  Serial.println("\nSistema em execução\n");  // Mensagem inicial
}

void loop() {
  // Lê temperatura em °C e umidade relativa do sensor DHT22
  float temp = dht.readTemperature();
  float umid = dht.readHumidity();

  // Se a leitura falhar, avisa e interrompe o loop atual
  if (isnan(temp) || isnan(umid)) {
    Serial.println("Falha na leitura do sensor DHT!");
    return;
  }

  // Lê a distância da água usando o sensor ultrassônico
  float distance = lerDistancia();

  // Acende o LED se a temperatura e umidade indicarem possibilidade de chuva
  if (temp <= 17.0 && umid >= 45) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }

  // Controla o buzzer: se a água estiver muito próxima, toca um som crescente e decrescente
  if (distance <= 100) {
    for (int freq = 500; freq <= 1000; freq += 10) {
      buzzerTone(freq);
      delay(10);
    }
    for (int freq = 1000; freq >= 500; freq -= 10) {
      buzzerTone(freq);
      delay(10);
    }
    buzzerNoTone();
  } else {
    buzzerNoTone();  // Se distância maior que 100, buzzer desligado
  }

  // Controle para realizar leituras e impressões a cada intervalo de 2,5 segundos
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    // Simula data e hora baseado no número de amostras coletadas
    unsigned long totalMinutes = (sampleNumber - 1) * 30; // Cada amostra equivale a 30 minutos
    int hour = (totalMinutes / 60) % 24;                 // Horas no formato 24h
    int minute = totalMinutes % 60;                       // Minutos
    int day = 1 + (totalMinutes / (24 * 60));             // Dia do mês (inicia em 1)

    // Imprime os dados no formato CSV para facilitar leitura
    Serial.print("Dia ");
    Serial.print(day);
    Serial.print(", ");
    if (hour < 10) Serial.print("0");   // Zero à esquerda para horas < 10
    Serial.print(hour);
    Serial.print(":");
    if (minute < 10) Serial.print("0"); // Zero à esquerda para minutos < 10
    Serial.print(minute);
    Serial.print(", ");
    Serial.print("Temperatura: ");
    Serial.print(temp, 2);
    Serial.print("°C, ");
    Serial.print("Umidade: ");
    Serial.print((int)umid);
    Serial.print("%, ");
    Serial.print("Distância da Água: ");
    Serial.print(distance);
    Serial.print("cm, ");
    Serial.print("Amostra: ");
    Serial.print(sampleNumber);
    Serial.print("\r\n");

    // Mensagens que aparecem a cada amostra, repetindo enquanto condição for verdadeira
    if (temp <= 17.0 && umid >= 45) {
      Serial.println("A temperatura e a umidade estão propícias para chuva\n");
    } else {
      Serial.println("Temperatura ou umidade voltaram ao normal\n");
    }

    if (distance <= 100) {
      Serial.println("A água está há menos de 100 centímetros\n");
    } else if (distance > 100 && distance <= 250) {
      Serial.println("A água está subindo\n");
    } else if (distance > 250) {
      Serial.println("A água abaixou\n");
    }

    // Incrementa o número da amostra para próxima simulação de tempo
    sampleNumber++;
  }
}
