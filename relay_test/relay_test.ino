#define Relay_Pin 4

void setup()
{
  pinMode(Relay_Pin, OUTPUT);
}
 
 
void loop(){
// Open loop
  digitalWrite(Relay_Pin, HIGH); 
  
//  delay(2000);

// Pass
//  digitalWrite(Relay_Pin, LOW); 
}
