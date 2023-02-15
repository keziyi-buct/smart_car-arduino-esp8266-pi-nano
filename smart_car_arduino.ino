int IN1 = 2;
int IN2 = 3;
int EN_A = 9;
int left_motor_speed = 0;
int right_motor_speed = 0;

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(EN_A, OUTPUT);
}

void loop() {
  left_motor_speed = map(pulseIn(4, HIGH, 20000), 1000, 2000, 0, 255);
  right_motor_speed = map(pulseIn(5, HIGH, 20000), 1000, 2000, 0, 255);
  analogWrite(EN_A, 255);
  
  if (left_motor_speed < 128) {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
  } else {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
  }
  
  if (right_motor_speed < 128) {
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  } else {
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  }
}
