int switchState = 0;
int die_pins [] = {3, 4, 5, 8, 11, 12};
int button_pin = 2;

void setup() {
  Serial.begin(9600);
  Serial.println("Setting up the die...");
  for (int i = 0; i < 6; i++) {
    pinMode(die_pins[i], OUTPUT);
  }
  pinMode(button_pin, INPUT);

  for (int i = 0; i < 6; i++) {
    digitalWrite(die_pins[i], LOW);
  }
  startup();
}

void loop() {
  switchState = digitalRead(button_pin);
  Serial.print("Switch state: ");
  Serial.println(switchState);
  if (switchState == HIGH) {
    roll();
  }
  delay(100);

}
void startup() {
  for (int j = 0; j < 3; j++) {
    for (int i = 0; i < 6; i++) {
      digitalWrite(die_pins[i], HIGH);
    }
    delay(300);
    for (int i = 0; i < 6; i++) {
      digitalWrite(die_pins[i], LOW);
    }
    delay(300);
  }
}
void roll() {
  Serial.println("Rolling...");
  for (int j = 0; j < 10; j++) {
    for (int i = 0; i < 6; i++) {
      digitalWrite(die_pins[i], HIGH);
      delay(100);
      digitalWrite(die_pins[i], LOW);
    }
  }
  showresult();
  for (int i = 0; i < 6; i++) {
    digitalWrite(die_pins[i], LOW);
  }
}
void showresult() {
  int r = random(6);
  Serial.print("Die result: ");
  Serial.println(r);

  digitalWrite(die_pins[r], HIGH);
  delay(10000);
}
