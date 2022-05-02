// ................................................... //  
#include <SparkFun_TB6612.h>
// ................................................... //
#define RELAY_PIN 7
// ................................................... // Front: 
// ................................................... // Left : motor1 --
#define FAIN1 40
#define FAIN2 41
// ................................................... // Right:        -- motor2
#define FBIN1 42
#define FBIN2 43
#define FPWMA 12
#define FPWMB 13
#define FSTBY 9
// ................................................... // Rear : 
// ................................................... // Left : motor3 --
#define RAIN1 50
#define RAIN2 51
// ................................................... // Right:        -- motor4
#define RBIN1 52
#define RBIN2 53
#define RPWMA 4
#define RPWMB 5
#define RSTBY 8
// ................................................... // Front: motor1 -- motor2
// ................................................... // Rear : motor3 -- motor4
const int offsetA = 1;
const int offsetB = 1;
Motor motor1 = Motor(FAIN1, FAIN2, FPWMA, offsetA, FSTBY);
Motor motor2 = Motor(FBIN1, FBIN2, FPWMB, offsetB, FSTBY);
Motor motor3 = Motor(RAIN1, RAIN2, RPWMA, offsetA, RSTBY);
Motor motor4 = Motor(RBIN1, RBIN2, RPWMB, offsetB, RSTBY);
// ................................................... // Given Lib Functions are only for 2-wheels control:
// ................................................... //                    motor1 -- motor2
// ................................................... //               S>0...forward, S<0...backward
// ................................................... // motorN.drive( S , T ): drive motorN @ S speed for T duration 
// ................................................... // motorN.brake(): brake motorN
// ................................................... // forward( M1 , M2 , S ): make 2 motors move forward @ S speed
// ................................................... // back( M1 , M2 , S ): make 2 motors move backware @ S speed
// ................................................... // left( M1 , M2 , S ): make 2 motors turn left @ S speed
// ................................................... // right( M1 , M2 , S ): make 2 motors turn right @ S speed
// ................................................... // brake( M1 , M2 ): brake 2 motors
// ................................................... // || || || || || || || || || || || || || || || || || || || ||
// ................................................... // \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/
// ................................................... // Define Functions for 4-wheels control based on Lib Functions:
// ................................................... // robot_FB(motor1,motor2,motor3,motor4,50,1000);
// ................................................... // robot_FB(motor1,motor2,motor3,motor4,-50,1000);
// ................................................... // robot_L(motor1,motor2,motor3,motor4,100,1000);
// ................................................... // robot_R(motor1,motor2,motor3,motor4,100,1000);
void robot_FB(Motor m1, Motor m2, Motor m3, Motor m4, int s, int t){
  forward(m1,m2,s);
  forward(m3,m4,s);
  delay(t);
  brake(m1,m2);
  brake(m3,m4);
}

void robot_L(Motor m1, Motor m2, Motor m3, Motor m4, int s, int t){
  left(m1,m2,s);
  left(m3,m4,s);
  delay(t);
  brake(m1,m2);
  brake(m3,m4);
}

void robot_R(Motor m1, Motor m2, Motor m3, Motor m4, int s, int t){
  right(m1,m2,s);
  right(m3,m4,s);
  delay(t);
  brake(m1,m2);
  brake(m3,m4);
}

char checki;

void setup()
{
  pinMode(RELAY_PIN, OUTPUT);
}
 
 
void loop(){
  digitalWrite(RELAY_PIN, HIGH);
  delay(2000);
  
  digitalWrite(RELAY_PIN, LOW);
  robot_FB(motor1,motor2,motor3,motor4,-50,200);
}
