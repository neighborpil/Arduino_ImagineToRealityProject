/* 8-2 */
#define TONE_OUTPUT 8
#define TONE_LENGTH 250
const int INPUT_DIGITAL_PINS[] = {2, 3, 4};

// Do, Re, Mi Fa, Sol, La, Si, Do
const int melody[] = { 262, 294, 330, 349, 392, 440, 494, 523 };

bool isDoButtonPressed = false, isReButtonPressed = false, isMiButtonPressed = false;

void setup() {
  Serial.begin(9600);

  SetDigitalInputPins();

  ShowLog("ProgramStarted");
}

void SetDigitalInputPins() {
  for (int i = 0; i < sizeof(INPUT_DIGITAL_PINS); i++) {
    pinMode(INPUT_DIGITAL_PINS[i], INPUT);
  }
}

void loop() {

  SwitchOn(0, &isDoButtonPressed);
  SwitchOn(1, &isReButtonPressed);
  SwitchOn(2, &isMiButtonPressed);
}

void PlayMusic() {
  for (int i = 0; i < 8; i++) {
    tone(8, melody[i], 250);
    delay(400);
    noTone(8);
  }
}

void SwitchOn(int inputNumber, bool* buttonPressed) {

  int buttonNumber = INPUT_DIGITAL_PINS[inputNumber];

  if (digitalRead(buttonNumber) == HIGH) {
    if (*buttonPressed == false) {

      tone(TONE_OUTPUT, melody[inputNumber], TONE_LENGTH);

      *buttonPressed = true;

      ShowLog("Button " + String(buttonNumber) + ": Pressed");
    }
  }

  if (digitalRead(buttonNumber) == LOW && *buttonPressed == true) {
    *buttonPressed = false;

    ShowLog("Button " + String(buttonNumber) + ": Released");
  }
}

void ShowLog(String message) {
  Serial.println(message);
}
