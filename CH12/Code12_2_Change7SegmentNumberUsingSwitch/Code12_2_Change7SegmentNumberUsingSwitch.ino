/* 12-2 */

#define PLUS_INPUT 11
#define MINUS_INPUT 12
const int INPUT_DIGITAL_PINS[] = { PLUS_INPUT, MINUS_INPUT };
const int OUTPUT_DIGITAL_PINS[] = { 2, 3, 4, 5, 6, 7, 8, 9 };

byte digits[10][7] = {
  { 0, 0, 0, 0, 0, 0, 1 }, // 0
  { 1, 0, 0, 1, 1, 1, 1 }, // 1
  { 0, 0, 1, 0, 0, 1, 0 }, // 2
  { 0, 0, 0, 0, 1, 1, 0 }, // 3
  { 1, 0, 0, 1, 1, 0, 0 }, // 4
  { 0, 1, 0, 0, 1, 0, 0 }, // 5
  { 0, 1, 0, 0, 0, 0, 0 }, // 6
  { 0, 0, 0, 1, 1, 1, 1 }, // 7
  { 0, 0, 0, 0, 0, 0, 0 }, // 8
  { 0, 0, 0, 1, 1, 0, 0 }, // 9
};

int digit = 0;

void setup() {

  Serial.begin(9600);

  SetDigitalPins();

  digitalWrite(9, HIGH); // 점은 끈다

  DisplayADigit(0);
  
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

  //DisplayDigits();
  SwitchDigit();

  DisplayCurrentDigit();

  delay(1000);
}

void SwitchDigit(){

  // plus
  if(digitalRead(PLUS_INPUT) == HIGH){
    digit++;

    if(digit > 9){
      digit = 0;
    }
  }

  // minus
  if(digitalRead(MINUS_INPUT) == HIGH){
    digit--;

     if(digit < 0){
      digit = 0;
    }
  }
}

void DisplayCurrentDigit(){
  DisplayADigit(digit);
}

void DisplayADigit(int number) {
  
  int digitalOutputStart = 2;

  for (int i = 0; i < 7; i++) {
    digitalWrite(digitalOutputStart + i, digits[number][i]);
  }
}

void ShowLog(String message) {
  Serial.println(message);
}
