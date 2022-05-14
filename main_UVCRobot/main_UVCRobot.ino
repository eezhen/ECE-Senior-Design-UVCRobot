// ................................................... //  
#include <SparkFun_TB6612.h>
// ................................................... // Front: 
// ................................................... // Left : motor1 --
#define Front_AIN1 36
#define Front_AIN2 37
// ................................................... // Right:        -- motor2
#define Front_BIN1 38
#define Front_BIN2 39
#define Front_PWMA 5
#define Front_PWMB 7
#define Front_STBY 6
// ................................................... // Rear : 
// ................................................... // Left : motor3 --
#define Rear_AIN1 32
#define Rear_AIN2 33
// ................................................... // Right:        -- motor4
#define Rear_BIN1 34
#define Rear_BIN2 35
#define Rear_PWMA 8
#define Rear_PWMB 10
#define Rear_STBY 9
// ................................................... //
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
// ................................................... //
#define Relay_Pin 4
// ................................................... // Front: motor1 -- motor2
// ................................................... // Rear : motor3 -- motor4
const int offsetA = 1;
const int offsetB = 1;
Motor motor1 = Motor(Front_AIN1, Front_AIN2, Front_PWMA, offsetA, Front_STBY);
Motor motor2 = Motor(Front_BIN1, Front_BIN2, Front_PWMB, offsetB, Front_STBY);
Motor motor3 = Motor(Rear_AIN1, Rear_AIN2, Rear_PWMA, offsetA, Rear_STBY);
Motor motor4 = Motor(Rear_BIN1, Rear_BIN2, Rear_PWMB, offsetB, Rear_STBY);

int drive_speed;
int drive_time;
int turning_speed;
int turning_time;

int Right_Distance;
int Right_Front_Distance;
int Front_Distance;
int Left_Front_Distance;
int Left_Distance;

String pi_cmd;
// ................................................... //

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
// ................................................... //
void setup(){
  pinMode(Relay_Pin, OUTPUT);
  
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
  
  Serial.begin(9600);
  
  drive_speed = 70;
  drive_time = 500;
  turning_speed = 130;
  turning_time = 300;
}
// ................................................... // 
void loop(){
  digitalWrite(Relay_Pin, HIGH);
  
  if(Serial.available() > 0){  
    
    Right_Distance = ultrasonic_read(Right_Trig_Pin, Right_Echo_Pin);
    Right_Front_Distance = ultrasonic_read(Right_Front_Trig_Pin, Right_Front_Echo_Pin);
    Front_Distance = ultrasonic_read(Front_Trig_Pin, Front_Echo_Pin);
    Left_Front_Distance = ultrasonic_read(Left_Front_Trig_Pin, Left_Front_Echo_Pin);
    Left_Distance = ultrasonic_read(Left_Trig_Pin, Left_Echo_Pin); 
    
    pi_cmd = Serial.readStringUntil('\n');
    if( pi_cmd == "w" ){
      Serial.println("Robot Moving Forward ...");
      forward(motor1,motor2,drive_speed);
      forward(motor3,motor4,drive_speed);
      delay(drive_time);
      brake(motor1,motor2);
      brake(motor3,motor4);
      pi_cmd = "idle";
    }
    else if( pi_cmd == "s" ){
      Serial.println("Robot Moving Back ...");
      back(motor1,motor2,drive_speed);
      back(motor3,motor4,drive_speed);
      delay(drive_time);
      brake(motor1,motor2);
      brake(motor3,motor4);
      pi_cmd = "idle";
    }
    else if( pi_cmd == "a" ){
      Serial.println("Robot Turning Left ...");
      left(motor1,motor2,turning_speed);
      left(motor3,motor4,turning_speed);
      delay(turning_time);
      brake(motor1,motor2);
      brake(motor3,motor4);     
      pi_cmd = "idle";
    }
    else if( pi_cmd == "d" ){
      Serial.println("Robot Turning Right ...");
      right(motor1,motor2,turning_speed);
      right(motor3,motor4,turning_speed);
      delay(turning_time);
      brake(motor1,motor2);
      brake(motor3,motor4);
      pi_cmd = "idle";
    }
    else if( pi_cmd == "u"){
      Serial.println("Turning on UVC LED for a while ...");   
      digitalWrite(Relay_Pin, LOW);
      delay(500);
      pi_cmd = "idle";
    }
    else if( pi_cmd == "n"){
      Serial.println("Robot Navigating ...");      
      if(Front_Distance <= 20){ // left 175 deg
        brake(motor1,motor2);
        brake(motor3,motor4);
        left(motor1,motor2,turning_speed);
        left(motor3,motor4,turning_speed);
        delay(4800);
        brake(motor1,motor2);
        brake(motor3,motor4);
      }
      else if(Right_Distance <= 20){ // left 15 deg
        brake(motor1,motor2);
        brake(motor3,motor4);
        left(motor1,motor2,turning_speed);
        left(motor3,motor4,turning_speed);
        delay(370);
        brake(motor1,motor2);
        brake(motor3,motor4);
      }
      else if(Left_Distance <= 20){ // right 15 deg
        brake(motor1,motor2);
        brake(motor3,motor4);
        right(motor1,motor2,turning_speed);
        right(motor3,motor4,turning_speed);
        delay(370);
        brake(motor1,motor2);
        brake(motor3,motor4); 
      }
      else if(Right_Front_Distance <= 37){ // left 45
        brake(motor1,motor2);
        brake(motor3,motor4);
        left(motor1,motor2,turning_speed);
        left(motor3,motor4,turning_speed);
        delay(1000);
        brake(motor1,motor2);
        brake(motor3,motor4);    
      }
      else if(Left_Front_Distance <= 37){ // right 45
        brake(motor1,motor2);
        brake(motor3,motor4);
        right(motor1,motor2,turning_speed);
        right(motor3,motor4,turning_speed);
        delay(1000);
        brake(motor1,motor2);
        brake(motor3,motor4);    
      }
      else{
        forward(motor1,motor2,60);
        forward(motor3,motor4,60);
      }
    }
  }
}
