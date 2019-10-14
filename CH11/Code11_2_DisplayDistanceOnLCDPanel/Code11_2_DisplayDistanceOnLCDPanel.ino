/* 11-2 */

#include <LiquidCrystal.h>

#define ULTRASONIC_OUTPUT 8
#define ULTRASONIC_INPUT 9
const int INPUT_DIGITAL_PINS[] = { ULTRASONIC_INPUT };
const int OUTPUT_DIGITAL_PINS[] = { ULTRASONIC_OUTPUT };

LiquidCrystal lcd(12, 11, 2, 3, 4, 5);

void setup() {
  Serial.begin(9600);

  SetDigitalPins();

  // LCD 초기화: LCD는 가로 16자, 세로 2줄로 구성
  lcd.begin(16, 2);

  ShowLog("ProgramStarted");
}


void SetDigitalPins() {
  SetDigitalPins(INPUT_DIGITAL_PINS, INPUT);
  SetDigitalPins(OUTPUT_DIGITAL_PINS, OUTPUT);
}

void SetDigitalPins(const int pins[], const int mode) {
  for (int i = 0; i < sizeof(pins); i++) {
    pinMode(pins[i], mode);
  }
}

void loop() {

  TriggerUltraSonicWave();
  long duration = EchoUltraSonicWave();

  if (duration == 0) {
    return;
  }

  long distance = ConvertDurationToDistance(duration);

  ShowDistanceOnLCDPanel(distance);

  ShowLog(String(distance));

  delay(500);
}

void TriggerUltraSonicWave() {
  digitalWrite(ULTRASONIC_OUTPUT, HIGH);
  delayMicroseconds(10);
  digitalWrite(ULTRASONIC_OUTPUT, LOW);
}

long EchoUltraSonicWave() {
  return pulseIn(ULTRASONIC_INPUT, HIGH);
}

long ConvertDurationToDistance(long duration) {
  return duration / 58.2;
}

void ShowDistanceOnLCDPanel(long distance){
  if(distance > 50)
    distance = -1;
  
  lcd.clear();
  lcd.print("Distance");
  lcd.setCursor(0, 1);
  lcd.print(distance);
  lcd.print(" cm");
}

void ShowLog(String message) {
  Serial.println(message);
}
