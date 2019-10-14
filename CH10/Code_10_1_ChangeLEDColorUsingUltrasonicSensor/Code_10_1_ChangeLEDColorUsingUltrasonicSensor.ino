/* 10-1 */
#define ULTRASONIC_INPUT 3
#define ULTRASONIC_OUTPUT 2
#define RED_OUTPUT 11
#define GREEN_OUTPUT 10
#define BLUE_OUTPUT 9


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
  ResetRGBColor();

  TriggerUltraSonicWave();
  long duration = EchoUltraSonicWave();

  if (duration == 0) {
    return;
  }

  long distance = ConvertDurationToDistance(duration);
  
  ShowDistanceThroughLED(distance);
}

void ResetRGBColor() {
  analogWrite(11, 0);
  analogWrite(10, 0);
  analogWrite(9, 0);
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

void ShowDistanceThroughLED(long distance){
  if(distance < 10){
    analogWrite(RED_OUTPUT, 255);
  } else if(distance < 20){
    analogWrite(GREEN_OUTPUT, 255);
  } else if(distance < 30){
    analogWrite(BLUE_OUTPUT, 255);
  }
}

void ShowLog(String message) {
  Serial.println(message);
}
