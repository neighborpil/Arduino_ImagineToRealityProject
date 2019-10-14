/* 8-1 */

// Do, Re, Mi Fa, Sol, La, Si, Do
int melody[] = { 262, 294, 330, 349, 392, 440, 494, 523 };

void setup() {
  Serial.begin(9600);

  ShowLog("Music Start");
  PlayMusic();
  ShowLog("Music Ended");
}

void loop() {
}

void ShowLog(String message) {
  Serial.println(message);
}

void PlayMusic(){
  for(int i=0; i<8; i++){
    tone(8, melody[i], 250);
    delay(400);
    noTone(8);
  }
}
