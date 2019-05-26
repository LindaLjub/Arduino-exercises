
int sensor_pin = A0; // Soil Sensor input at Analog PIN A0
int output_value;  // for storing the output of the sensor.
bool check = true;


void setup() {
  
   Serial.begin(9600); // för att se i serial monitor
   Serial.println("Reading From the Sensor ...");
   delay(2000);
  
}

void loop() {
  
   output_value= analogRead(sensor_pin); // hämtar in värde från sensor
   output_value = map(output_value,550,10,0,100); // we will map the output values to 0-100, because the moisture is measured in percentage.

   //  When we took the readings from the dry soil, 
   //then the sensor value was 550 and in the wet soil, the sensor value was 10. So, we mapped these values to get the moisture

   //Serial.print("Mositure : ");
  // Serial.print(output_value);
  // Serial.println("%");
   delay(1000);

   if(output_value < 0)
   {
     Serial.println("Give me water.. ");
     delay(1000);
     check = false;
   }
   
   if (output_value > 0)
   {
    if(check == false)
    {
    Serial.println("Thanks!");
    delay(1000);
    check = true;
    }

   }
   
   

}
