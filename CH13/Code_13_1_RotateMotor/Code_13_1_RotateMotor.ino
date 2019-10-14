/* 13-1 */

#include <Servo.h>

const int INPUT_DIGITAL_PINS[] = {};
const int OUTPUT_DIGITAL_PINS[] = {};

Servo myservo;

void setup() {
  Serial.begin(9600);

  SetDigitalPins();

  myservo.attach(9);

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

  RotateMotor();

  delay(1000);
}

void RotateMotor(){
  for(int i=0; i<120; i++){
    myservo.write(i);
    delay(15);
  }

  myservo.write(0);
}

void ShowLog(String message) {
  Serial.println(message);
}
