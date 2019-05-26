

// denna kod är till distansmätaren


#include <NewPing.h>
const int echo = 8;
const int trig = 6;

NewPing sonar(trig, echo, 4500); 


void setup() {
  // initialize serial communication:
  Serial.begin(9600);


}

void loop() { 
  
 int cm = sonar.ping_cm(); 
 Serial.println(cm); 
 delay(200);
  
}
