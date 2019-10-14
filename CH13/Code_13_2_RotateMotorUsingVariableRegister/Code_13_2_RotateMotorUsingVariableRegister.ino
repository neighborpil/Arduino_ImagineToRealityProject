/* 13-2 */

#include <Servo.h>

#define VARIABLE_REGISTER_INPUT A0

const int INPUT_DIGITAL_PINS[] = {};
const int OUTPUT_DIGITAL_PINS[] = {};

Servo myservo;

void setup() {
  Serial.begin(9600);

  SetDigitalPins();

  myservo.attach(9);

  myservo.write(0);

  ShowLog("ProgramStarted");
}


void SetDigitalPins() {

  int inputPinsLength = sizeof(INPUT_DIGITAL_PINS) / sizeof(INPUT_DIGITAL_PINS[0]);
  SetDigitalPins(INPUT_DIGITAL_PINS, inputPinsLength, INPUT);

  int outputPinsLength = sizeof(OUTPUT_DIGITAL_PINS) / sizeof(OUTPUT_DIGITAL_PINS[0]);
  SetDigitalPins(OUTPUT_DIGITAL_PINS, outputPinsLength, OUTPUT);
}

void SetDigitalPins(int pins[], int pinsLength, const int mode) {

  for (int i = 0; i < pinsLength; i++) {
    pinMode(pins[i], mode);
  }
}

void loop() {
  int angle = ReadAngle();

  RotateMotor(angle);

  delay(15);
}

int ReadAngle(){
  int registerValue = analogRead(VARIABLE_REGISTER_INPUT);
  return map(registerValue, 0, 1023, 0, 120);
}

void RotateMotor(int angle){
  myservo.write(angle);

  ShowLog("Angle: " + String(angle));
}

void ShowLog(String message) {
  Serial.println(message);
}
