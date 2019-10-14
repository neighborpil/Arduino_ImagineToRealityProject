/* 10-2 */
#define ULTRASONIC_INPUT 3
#define ULTRASONIC_OUTPUT 2
#define PIEZO_OUTPUT 8

const int INPUT_DIGITAL_PINS[] = { ULTRASONIC_INPUT };
const int OUTPUT_DIGITAL_PINS[] = { ULTRASONIC_OUTPUT };

void setup() {
  Serial.begin(9600);

  SetDigitalPins();

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
  
  ShowDistanceThroughPiezoSpeaker(distance);
}

void TriggerUltraSonicWave() {
  digitalWrite(ULTRASONIC_OUTPUT, HIGH);
  delayMicroseconds(10);
  digitalWrite(ULTRASONIC_OUTPUT, LOW);
}

long EchoUltraSonicWave() {
  return pulseIn(ULTRASONIC_INPUT, HIGH);
}

long ConvertDurationToDistance(long duration){
  return duration / 58.2;
}

void ShowDistanceThroughPiezoSpeaker(long distance){
  tone(PIEZO_OUTPUT, 1000, 20);
  delay(20);
  noTone(8);

  delay(2 * distance);
}

void ShowLog(String message) {
  Serial.println(message);
}
