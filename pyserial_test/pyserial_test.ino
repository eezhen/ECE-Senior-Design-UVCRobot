#define Relay_Pin 4
// Open loop
//  digitalWrite(Relay_Pin, HIGH); 

// Pass
//  digitalWrite(Relay_Pin, LOW);

String pi_cmd;

void setup()
{
  pinMode(Relay_Pin, OUTPUT);
  Serial.begin(9600);
}
 
 
void loop(){
  if(Serial.available() > 0){
    pi_cmd = Serial.readStringUntil('\n');
    Serial.print("Pi makes Ardu to: ");
    Serial.println(pi_cmd);
  
    if( pi_cmd == "w" ){
      digitalWrite(Relay_Pin, HIGH);
      delay(1000);
      Serial.print("Ardu did: ");
      Serial.println(pi_cmd);  
      pi_cmd = "idle";
    }
    else if( pi_cmd == "s" ){
      digitalWrite(Relay_Pin, HIGH);
      delay(500);
      digitalWrite(Relay_Pin, LOW);
      delay(500);
      Serial.print("Ardu did: ");
      Serial.println(pi_cmd);  
      pi_cmd = "idle";
    }
    else if( pi_cmd == "a" ){
      digitalWrite(Relay_Pin, HIGH);
      delay(500);
      digitalWrite(Relay_Pin, LOW);
      delay(500);
      digitalWrite(Relay_Pin, HIGH);
      delay(500);
      Serial.print("Ardu did: ");
      Serial.println(pi_cmd);      
      pi_cmd = "idle";
    }
    else if( pi_cmd == "d" ){
      digitalWrite(Relay_Pin, HIGH);
      delay(500);
      digitalWrite(Relay_Pin, LOW);
      delay(500);
      digitalWrite(Relay_Pin, HIGH);
      delay(500);
      digitalWrite(Relay_Pin, LOW);
      delay(500);
      digitalWrite(Relay_Pin, HIGH);
      delay(500);
      Serial.print("Ardu did: ");
      Serial.println(pi_cmd);    
      pi_cmd = "idle";
    }
    else{
      Serial.println("Ardu says: Waiting for input!");
      delay(500); 
    }
  }
}
