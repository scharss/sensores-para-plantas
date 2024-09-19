#include <DHT.h>

// Definir los pines de los sensores
#define DHTPIN 8            // Pin digital conectado al DHT11
#define DHTTYPE DHT11       // Definir el tipo de sensor DHT
#define soilMoisturePin A0  // Pin analógico para el sensor de humedad del suelo
#define lightSensorPin 7    // Pin digital para el sensor de luz LM393

// Crear instancia del sensor DHT
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();  // Inicializar el DHT11
  pinMode(lightSensorPin, INPUT); // Configurar el pin del sensor de luz como entrada
}

void loop() {
  // Leer y mostrar la humedad y temperatura del ambiente
  float humedadAmbiente = dht.readHumidity();
  float temperatura = dht.readTemperature();
  
  if (isnan(humedadAmbiente) || isnan(temperatura)) {
    Serial.println("Error leyendo el DHT11");
  } else {
    Serial.print("Humedad Ambiente: ");
    Serial.print(humedadAmbiente);
    Serial.println("%");
    Serial.print("Temperatura: ");
    Serial.print(temperatura);
    Serial.println("°C");
  }

  // Leer y mostrar la humedad del suelo
  int valorHumedadSuelo = map(analogRead(soilMoisturePin), 0, 1023, 100, 0);
  Serial.print("Humedad del Suelo: ");
  Serial.print(valorHumedadSuelo);
  Serial.println("%");

  // Leer y mostrar el estado del sensor de luz
  int estadoLuz = digitalRead(lightSensorPin);
  Serial.print("Estado del sensor de luz: ");
  Serial.println(estadoLuz);  // Mostrar el estado digital directamente

  if (estadoLuz == HIGH) {
    Serial.println("Luz detectada");
  } else {
    Serial.println("No hay luz");
  }

  delay(2000); // Espera 2 segundos entre lecturas
}
