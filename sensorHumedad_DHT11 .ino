#include <DHT.h>

// Definir el pin del DHT11
#define DHTPIN 8    // Pin digital conectado al DHT11 (cambiado a pin 8)
#define DHTTYPE DHT11   // Define el tipo de sensor DHT que estás usando (DHT11)

DHT dht(DHTPIN, DHTTYPE);

// Definir el pin del sensor de humedad del suelo
#define sensorPin A0  
int valorHumedadSuelo = 0;

void setup() {
  Serial.begin(9600);
  dht.begin(); // Inicializar el DHT11
}

void loop() {
  // Leer temperatura y humedad del ambiente desde el DHT11
  float humedadAmbiente = dht.readHumidity();
  float temperatura = dht.readTemperature();
  
  // Verificar si la lectura es válida
  if (isnan(humedadAmbiente) || isnan(temperatura)) {
    Serial.println("Falla al leer del DHT11!");
  } else {
    Serial.print("Humedad Ambiente: ");
    Serial.print(humedadAmbiente);
    Serial.println("%");
    
    Serial.print("Temperatura: ");
    Serial.print(temperatura);
    Serial.println("°C");
  }

  // Leer la humedad del suelo desde el sensor de humedad del suelo
  int valorHumedadSuelo = map(analogRead(sensorPin), 0, 1023, 100, 0); 
  Serial.print("Humedad del Suelo: ");
  Serial.print(valorHumedadSuelo);
  Serial.println("%");

  delay(2000); // Espera 2 segundos entre lecturas
}
