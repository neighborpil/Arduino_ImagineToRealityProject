/* 9-2 */

/*
 * int map(int p1, int p2, int p3, int p4, int p5) 값을 원래 있던 범위에서 다른 범위 기준으로 바꿔준다
 * 
 * # 매개변수
 * - p1: 범위를 바꾸고자 하는 값
 * - p2: 원래 값이 속한 범위의 최소값
 * - p3: 원래 값이 속한 범위의 최대값
 * - p4: 값을 옮기려는 목표 범위의 최소값
 * - p5: 값을 옮기려는 목표 범위의 최대값
 * 
 * # 반환값
 *  - 변경된 값
 */
 
void setup() {
  Serial.begin(9600);

  ShowLog("ProgramStarted");
}

void loop() {
  int lightIntensity = analogRead(A0);
  int hertz = map(lightIntensity, 0, 1023, 31, 4978);

  tone(8, hertz, 100);
  delay(100);
  noTone(8);
  delay(100);
}

void ShowLog(String message) {
  Serial.println(message);
}
