bool isPressed = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(8, INPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = digitalRead(8);

  if (value == HIGH) {
    if (isPressed == false) {
      ShowLog("Switch Button: Pressed");
      isPressed = true;
    }

    digitalWrite(13, HIGH);
  } else {
    if (isPressed == true) {
      ShowLog("Switch Button: Released");
      isPressed = false;
    }
    digitalWrite(13, LOW);
  }
}

void ShowLog(String message)
{
  Serial.println(message);
}
