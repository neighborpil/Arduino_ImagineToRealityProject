/* 7-2 */

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(A0));
}

void loop() {

  int r = random(256);
  int g = random(256);
  int b = random(256);
  analogWrite(11, r);
  analogWrite(10, g);
  analogWrite(9, b);

  ShowLog("R: " + String(r) + ", G: " + String(g) + ", B: " + String(b));

  delay(1000);
}

void ShowLog(String message) {
  Serial.println(message);
}
