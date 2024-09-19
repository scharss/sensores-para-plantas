#define sensorPin A0  // Definir correctamente el pin del sensor
int valor = 0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int valor = map(analogRead(sensorPin), 0, 1023, 100, 0); 
  // Se hace un mapeo de la lectura del sensor a un valor porcentual
  Serial.print("Humedad: ");
  Serial.print(valor);
  Serial.println("%");
  delay(100);
}