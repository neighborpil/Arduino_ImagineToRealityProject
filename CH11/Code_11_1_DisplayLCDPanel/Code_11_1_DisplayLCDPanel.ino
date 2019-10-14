/* 11-1 */
/*
 * LiquidCrystal(RS, E, D4, D5, D6, D7)
 * 
 * #매개변수
 *  - RS: RS 핀이 연결된아두이노 보드 번호
 *  - E: E 핀이 연결된아두이노 보드 번호
 *  - D4: D4 핀이 연결된아두이노 보드 번호
 *  - D5: D5 핀이 연결된아두이노 보드 번호
 *  - D6: D6 핀이 연결된아두이노 보드 번호
 *  - D7: D7 핀이 연결된아두이노 보드 번호
 */
#include <LiquidCrystal.h>

const int INPUT_DIGITAL_PINS[] = {};
const int OUTPUT_DIGITAL_PINS[] = {};

LiquidCrystal lcd(12, 11, 2, 3, 4, 5);

void setup() {
  Serial.begin(9600);

  SetDigitalPins();

  // LCD 초기화: LCD는 가로 16자, 세로 2줄로 구성
  lcd.begin(16, 2);

  ShowLog("ProgramStarted");
}


void SetDigitalPins(){
  SetDigitalPins(INPUT_DIGITAL_PINS, INPUT);
  SetDigitalPins(OUTPUT_DIGITAL_PINS, OUTPUT);
}

void SetDigitalPins(const int pins[], const int mode) {
  for (int i = 0; i < sizeof(pins); i++) {
    pinMode(pins[i], mode);
  }
}

void loop() {

  int lightIntensity = analogRead(A0);

  ShowLightIntensityOnLCD(lightIntensity);
  
  ShowLog(String(lightIntensity));

  delay(500);
}


void ShowLightIntensityOnLCD(int lightIntensity){
  lcd.clear();
  lcd.print("Light: " + String(lightIntensity));
}

void ShowLog(String message) {
  Serial.println(message);
}
