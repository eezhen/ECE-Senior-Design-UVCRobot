#define Right_Echo_Pin 51
#define Right_Trig_Pin 50

#define Right_Front_Echo_Pin 49
#define Right_Front_Trig_Pin 48 

#define Front_Echo_Pin 47
#define Front_Trig_Pin 46

#define Left_Front_Echo_Pin 45
#define Left_Front_Trig_Pin 44

#define Left_Echo_Pin 43
#define Left_Trig_Pin 42

int ultrasonic_read(int trig, int echo) {
  long duration;
  int distance;
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = duration * 0.034 / 2;
  return distance;
}

int Right_Distance;
int Right_Front_Distance;
int Front_Distance;
int Left_Front_Distance;
int Left_Distance;

void setup() {
  pinMode(Right_Trig_Pin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(Right_Echo_Pin, INPUT); // Sets the echoPin as an INPUT

  pinMode(Right_Front_Trig_Pin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(Right_Front_Echo_Pin, INPUT); // Sets the echoPin as an INPUT

  pinMode(Front_Trig_Pin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(Front_Echo_Pin, INPUT); // Sets the echoPin as an INPUT

  pinMode(Left_Front_Trig_Pin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(Left_Front_Echo_Pin, INPUT); // Sets the echoPin as an INPUT

  pinMode(Left_Trig_Pin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(Left_Echo_Pin, INPUT); // Sets the echoPin as an INPUT

  
  Serial.begin(9600);     // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Ultrasonic Sensor HC-SR04 Test:");
}

void loop() {
  Right_Distance = ultrasonic_read(Right_Trig_Pin, Right_Echo_Pin);
  Right_Front_Distance = ultrasonic_read(Right_Front_Trig_Pin, Right_Front_Echo_Pin);
  Front_Distance = ultrasonic_read(Front_Trig_Pin, Front_Echo_Pin);
  Left_Front_Distance = ultrasonic_read(Left_Front_Trig_Pin, Left_Front_Echo_Pin);
  Left_Distance = ultrasonic_read(Left_Trig_Pin, Left_Echo_Pin);

  Serial.print("Right Distance: ");
  Serial.print(Right_Distance);
  Serial.print(" cm");

  Serial.print("  Right Front Distance: ");
  Serial.print(Right_Front_Distance);
  Serial.print(" cm");

  Serial.print("  Front Distance: ");
  Serial.print(Front_Distance);
  Serial.print(" cm");

  Serial.print("  Left Front Distance: ");
  Serial.print(Left_Front_Distance);
  Serial.print(" cm");

  Serial.print("  Left Distance: ");
  Serial.print(Left_Distance);
  Serial.print(" cm");

  Serial.println();
}
