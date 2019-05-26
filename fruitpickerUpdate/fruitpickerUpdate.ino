
/*
  Example sketch FruitPickers2.ino version 7.01.
  From Kjell & Company's book "Hur funkar Arduino?" version 7.01.
  From Kjell & Company's book "Hvordan virker Arduino?" version 7.01.
  This code is in the public domain.
*/


#include <Button.h>

// Create a button object for each GPIO pin in use
Button btnAddLittleBasketAlice(5);
Button btnAddLittleBasketBob(4);
Button btnAddBigBasketAlice(3);
Button btnAddBigBasketBob(2);


// Declare global variables for total number of apples.
unsigned int fruitsAlice;
unsigned int fruitsBob; 

// Declare global constants for number of apples in baskets.
const int littleBasketSize = 25;
const int bigBasketSize = 40;


// Declare global fruit String
String fruit = " apples";

void setup() {

    // Start buttons
  btnAddLittleBasketAlice.begin();
  btnAddLittleBasketBob.begin();
  btnAddBigBasketAlice.begin();
  btnAddBigBasketBob.begin();
  
  // Open serial connection at 9600 Bd.
  Serial.begin(9600);
}

void loop() {

   // Add little basket to Alice
  if(btnAddLittleBasketAlice.pressed()) {

    updateStatus(littleBasketSize, 0);

  }

  // Add little basket to Bob
  if(btnAddLittleBasketBob.pressed()) {

   // 0 till Alice, en liten korg till bob.
    updateStatus(0, littleBasketSize);

  }

  // Add big basket to Alice
  if(btnAddBigBasketAlice.pressed()) {
     updateStatus(bigBasketSize, 0);

  }  

  // Add big basket to Bob
  if(btnAddBigBasketBob.pressed()) {
    updateStatus(0, bigBasketSize);  // 0 till Alice, en stor korg till bob.
    
  }
}

void updateStatus(int addAlice, int addBob)
{
  
    fruitsAlice = fruitsAlice + addAlice;
    fruitsBob = fruitsBob + addBob;
    
    Serial.print("Alice has picked: ");
    Serial.print(fruitsAlice);
    Serial.println(fruit);
    Serial.print("Bob has picked: ");
    Serial.print(fruitsBob);
    Serial.println(fruit);
    Serial.println("------------------------------");
  
}
