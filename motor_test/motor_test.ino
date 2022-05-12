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
// ................................................... // Front: motor1 -- motor2
// ................................................... // Rear : motor3 -- motor4
const int offsetA = 1;
const int offsetB = 1;
Motor motor1 = Motor(Front_AIN1, Front_AIN2, Front_PWMA, offsetA, Front_STBY);
Motor motor2 = Motor(Front_BIN1, Front_BIN2, Front_PWMB, offsetB, Front_STBY);
Motor motor3 = Motor(Rear_AIN1, Rear_AIN2, Rear_PWMA, offsetA, Rear_STBY);
Motor motor4 = Motor(Rear_BIN1, Rear_BIN2, Rear_PWMB, offsetB, Rear_STBY);
// Given Lib Functions are only for 2-wheels control:
//                    motor1 -- motor2
//               S>0...forward, S<0...backward
// motorN.drive( S , T ): drive motorN @ S speed for T duration 
// motorN.brake(): brake motorN
// forward( M1 , M2 , S ): make 2 motors move forward @ S speed
// back( M1 , M2 , S ): make 2 motors move backware @ S speed
// left( M1 , M2 , S ): make 2 motors turn left @ S speed
// right( M1 , M2 , S ): make 2 motors turn right @ S speed
// brake( M1 , M2 ): brake 2 motors
// || || || || || || || || || || || || || || || || || || || ||
// \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/
// Define Functions for 4-wheels control based on Lib Functions:
// robot_FB(motor1,motor2,motor3,motor4,50,1000);
// robot_FB(motor1,motor2,motor3,motor4,-50,1000);
// robot_L(motor1,motor2,motor3,motor4,100,1000);
// robot_R(motor1,motor2,motor3,motor4,100,1000);
// ................................................... //
void robot_FB(Motor m1, Motor m2, Motor m3, Motor m4, int s, int t){
  forward(m1,m2,s);
  forward(m3,m4,s);
  delay(t);
  brake(m1,m2);
  brake(m3,m4);
}
// ................................................... //
void robot_L(Motor m1, Motor m2, Motor m3, Motor m4, int s, int t){
  left(m1,m2,s);
  left(m3,m4,s);
  delay(t);
  brake(m1,m2);
  brake(m3,m4);
}
// ................................................... //
void robot_R(Motor m1, Motor m2, Motor m3, Motor m4, int s, int t){
  right(m1,m2,s);
  right(m3,m4,s);
  delay(t);
  brake(m1,m2);
  brake(m3,m4);
}
// ................................................... //
int drive_speed;
int drive_time;
char checki;
// ................................................... //
void setup()
{
  Serial.begin(9600);
  Serial.println("Robot Motor Testing Ready:");
  drive_speed = 100;
  drive_time  = 500;
}
// ................................................... // 
void loop(){
  checki = Serial.read();
  if( checki == 'w' ){
    forward(motor1,motor2,drive_speed);
    forward(motor3,motor4,drive_speed);
    delay(drive_time);
    brake(motor1,motor2);
    brake(motor3,motor4);
    Serial.print("Robot Moving Forward ...");
    Serial.println();
    checki = '0';
  }
  
  if( checki == 's' ){
    back(motor1,motor2,drive_speed);
    back(motor3,motor4,drive_speed);
    delay(drive_time);
    brake(motor1,motor2);
    brake(motor3,motor4);
    Serial.print("Robot Moving Back ...");
    Serial.println();
    checki = '0';
  }

  if( checki == 'a' ){
    left(motor1,motor2,drive_speed);
    left(motor3,motor4,drive_speed);
    delay(drive_time);
    brake(motor1,motor2);
    brake(motor3,motor4);
    Serial.print("Robot Turning Left ...");
    Serial.println();
    checki = '0';
  }
  
  if( checki == 'd' ){
    right(motor1,motor2,drive_speed);
    right(motor3,motor4,drive_speed);
    delay(drive_time);
    brake(motor1,motor2);
    brake(motor3,motor4);
    Serial.print("Robot Turning Right ...");
    Serial.println();
    checki = '0';
  }
}
