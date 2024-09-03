// Definimos los pines del potenciómetro, joystick y switch
const int potPin = A0;      // Pin analógico para el potenciómetro
const int joyXPin = A1;     // Pin analógico para el joystick X
const int joyYPin = A2;     // Pin analógico para el joystick Y
const int switchPin = 2;    // Pin digital para el switch (botón)

// Variables para almacenar los valores leídos
int potValue;               // Valor del potenciómetro
int joystickXValue;         // Valor del joystick X (eje X del joystick)
int joystickYValue;         // Valor del joystick Y (eje Y del joystick)
int switchState;            // Estado del switch (0: apagado, 1: encendido)

void setup() {
  // Configuramos los pines del switch y el joystick como entradas con resistencias pull-up internas
  pinMode(switchPin, INPUT_PULLUP);
  pinMode(joyXPin, INPUT_PULLUP);
  pinMode(joyYPin, INPUT_PULLUP);

  // Abrimos el monitor serial para ver los resultados
  Serial.begin(9600);
}

void loop() {
  // Leemos el valor del potenciómetro (valor analógico entre 0 y 1023)
  potValue = analogRead(potPin);

  // Leemos los valores del joystick (valores analógicos entre 0 y 1023)
  joystickXValue = analogRead(joyXPin);
  joystickYValue = analogRead(joyYPin);

  // Leemos el estado del switch (LOW cuando está presionado, HIGH cuando está abierto)
  switchState = !digitalRead(switchPin); // Invertimos el valor leído

  // Mapeamos los valores del potenciómetro y el joystick al rango de -100 a 100
  int mappedPotValue = map(potValue, 0, 1023, -100, 100);
  int mappedXValue = map(joystickXValue, 0, 1023, -100, 100);
  int mappedYValue = map(joystickYValue, 0, 1023, -100, 100);

  // Imprimimos los resultados en el monitor serial
  Serial.print("Potentiometer Value: ");
  Serial.print(mappedPotValue);
  Serial.print("\tJoystick X Value: ");
  Serial.print(mappedXValue);
  Serial.print("\tJoystick Y Value: ");
  Serial.print(mappedYValue);
  Serial.print("\tSwitch State: ");
  Serial.println(switchState);

  delay(100); // Pausa de 100 milisegundos para evitar lecturas erráticas
}
