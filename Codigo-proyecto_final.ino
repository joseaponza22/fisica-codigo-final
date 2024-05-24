#include <LiquidCrystal_I2C.h>

// Crear un objeto de la clase LiquidCrystal_I2C para controlar la pantalla LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Definir el pin del sensor de humedad
const int sensorPin = A0;

// Variables para almacenar el valor leído del sensor y el valor porcentual de humedad
int sensorValue = 0;
int percentValue = 0;

void setup() {
  // Inicializar la pantalla LCD
  lcd.init();
  
  // Encender la luz de fondo de la pantalla LCD
  lcd.backlight();
  
  // Establecer el cursor en la primera columna y primera fila
  lcd.setCursor(0, 0);
  
  // Mostrar el mensaje de bienvenida
  lcd.print("Bienvenido.......");
  
  // Esperar 4 segundos
  delay(4000);
  
  // Limpiar la pantalla LCD
  lcd.clear();
}

void loop() {
  // Leer el valor analógico del sensor de humedad
  sensorValue = analogRead(sensorPin);
  
  // Mapear el valor leído del sensor (rango 1023 a 200) a un valor porcentual (rango 0 a 100)
  percentValue = map(sensorValue, 1023, 200, 0, 100);
  
  // Establecer el cursor en la primera columna y primera fila
  lcd.setCursor(0, 0);
  
  // Mostrar el título "HUMEDAD"
  lcd.print(" ---HUMEDAD--- ");
  
  // Establecer el cursor en la séptima columna y segunda fila
  lcd.setCursor(7, 1);
  
  // Mostrar el valor porcentual de la humedad seguido del símbolo de porcentaje
  lcd.print(percentValue);
  lcd.print("%");

  // Esperar 1 segundo
  delay(1000);
  
  // Limpiar la pantalla LCD para la próxima lectura
  lcd.clear();
}

