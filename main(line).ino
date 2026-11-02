/*
  Line Follower Robot - Arduino UNO + 2 IR Sensors + L298N
  IMPORTANT:
  - This is a basic two-sensor example.
  - Many IR modules output LOW on black, but some output HIGH.
  - If your sensor behaves in the opposite way, change BLACK to HIGH.
  - Connect ENA and ENB jumpers on the L298N for full-speed operation,
    or use PWM pins and analogWrite() if you want speed control.
*/

// IR sensor connections
const int LEFT_SENSOR  = 2;
const int RIGHT_SENSOR = 3;

// L298N motor driver connections
const int ENA = 5;   // Left motor enable (PWM)
const int IN1 = 8;
const int IN2 = 9;

const int ENB = 6;   // Right motor enable (PWM)
const int IN3 = 10;
const int IN4 = 11;

// Change to HIGH if your IR module gives HIGH on a black surface.
const int BLACK = LOW;

const int MOTOR_SPEED = 150; // Range: 0 to 255

void setLeftMotor(int speedValue) {
  if (speedValue > 0) {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(ENA, speedValue);
  } else if (speedValue < 0) {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    analogWrite(ENA, -speedValue);
  } else {
    analogWrite(ENA, 0);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
  }
}

void setRightMotor(int speedValue) {
  if (speedValue > 0) {
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENB, speedValue);
  } else if (speedValue < 0) {
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(ENB, -speedValue);
  } else {
    analogWrite(ENB, 0);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  }
}

void stopRobot() {
  setLeftMotor(0);
  setRightMotor(0);
}

void setup() {
  pinMode(LEFT_SENSOR, INPUT);
  pinMode(RIGHT_SENSOR, INPUT);

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  Serial.begin(9600);
  stopRobot();
}

void loop() {
  int leftValue  = digitalRead(LEFT_SENSOR);
  int rightValue = digitalRead(RIGHT_SENSOR);

  bool leftOnBlack  = (leftValue == BLACK);
  bool rightOnBlack = (rightValue == BLACK);

  Serial.print("Left: ");
  Serial.print(leftValue);
  Serial.print("  Right: ");
  Serial.println(rightValue);

  if (leftOnBlack && rightOnBlack) {
    // Both sensors see the line: move forward.
    setLeftMotor(MOTOR_SPEED);
    setRightMotor(MOTOR_SPEED);
  } else if (leftOnBlack && !rightOnBlack) {
    // Line is toward the left sensor: steer left.
    setLeftMotor(0);
    setRightMotor(MOTOR_SPEED);
  } else if (!leftOnBlack && rightOnBlack) {
    // Line is toward the right sensor: steer right.
    setLeftMotor(MOTOR_SPEED);
    setRightMotor(0);
  } else {
    // Both sensors see the background: stop (basic safe behaviour).
    stopRobot();
  }

  delay(10);
}
