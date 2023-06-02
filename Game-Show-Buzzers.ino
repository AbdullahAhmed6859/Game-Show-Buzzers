char teams[5] = {'a', 'b', 'c', 'd', 'e'};
int pins[5] = {2, 4, 6, 8, 10};
// int pinsLed[5] = {7, 8, 9, 10, 11};
int buzzer = 12;
int redLed = 9;

void shuffle() {
  
  for (int i=0; i < 5; i++) {
    int n = random(0, 5);  // Integer from 0 to questionCount-1
    char temp1 = teams[n];
    int temp2 = pins[n];
    pins[n] = pins[i];
    teams[n] = teams[i];
    teams[i] = temp1;
    pins[i] = temp2;
  }
}

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 5; i++) {pinMode(pins[i], INPUT_PULLUP);}
  pinMode(buzzer, OUTPUT);
}

void loop() {
  bool not_pressed = true;
  Serial.println("press to start");
  while (not_pressed == 1) {
    for (int i = 0; i < 5; i++) {
      not_pressed = digitalRead(pins[i]);
      if (not_pressed == 0) {
        Serial.print("team: ");
        Serial.println(teams[i]);
        // digitalWrite(pinsLed[i], HIGH);
        Serial.println("delay...");
        digitalWrite(buzzer, HIGH);
        delay(1000);
        digitalWrite(buzzer, LOW);
        delay(1000);
        shuffle();
        break;
      }
    }
  }
}