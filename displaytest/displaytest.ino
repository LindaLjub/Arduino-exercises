


#include <LiquidCrystal_I2C.h>
#include <Wire.h>

int test = 0;

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); // Set the LCD I2c adress


void setup() {

  // Setup size of LCD 20 characters and 2 lines
  lcd.begin(20,2);
  // Back light on
  lcd.backlight();



}

void loop() {


    lcd.setCursor(0,0);
    lcd.print("HELLO ");
    lcd.print(test);

    test++;
    delay(1000);
    lcd.setCursor(0,1);
    lcd.print("HELLO");
    lcd.print(" tgggjj");


}
