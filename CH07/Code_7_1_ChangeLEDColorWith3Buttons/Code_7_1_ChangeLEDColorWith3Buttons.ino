int r = 0, g = 0, b = 0;
bool isRedButtonPressed = false, isGreenButtonPressed = false, isBlueButtonPressed = false;

void setup() {
  Serial.begin(9600);
  Serial.println("Start Program");

  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
}

void loop() {
  // red
  SwitchOn(2, &isRedButtonPressed);

  // green
  SwitchOn(3, &isGreenButtonPressed);

  // blue
  SwitchOn(4, &isBlueButtonPressed);

  // change 3 colored LED
  WriteRGB();

  delay(10);
}

void SwitchOn(int inputNumber, bool* buttonPressed) {

  int* rgbValue;
  switch(inputNumber){
    case 2: rgbValue = &r; break;
    case 3: rgbValue = &g; break;
    case 4: rgbValue = &b; break;
    default: break;
  }
  
  if (digitalRead(inputNumber) == HIGH) {

    if (*buttonPressed == false) {
      ShowLog("Button " + String(inputNumber) + ": Pressed");
      *buttonPressed = true;
    }
    ++*rgbValue;
    if (*rgbValue > 255) {
      *rgbValue = 0;
    }
  }

  if (digitalRead(inputNumber) == LOW && *buttonPressed == true) {
    ShowLog("Button " + String(inputNumber) + ": Released");

    ShowRGB();

    *buttonPressed = false;
  }
}

void ShowLog(String message) {
  Serial.println(message);
}

void ShowRGB() {
  Serial.println("R: " + String(r) + ", G: " + String(g) + ", B: " + String(b));
}

void WriteRGB(){
  analogWrite(11, r);
  analogWrite(10, g);
  analogWrite(9, b);
}
