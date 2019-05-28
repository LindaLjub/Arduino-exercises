#include <Button.h>

// skapar ett button objekt.
Button knapp1(2);

// den inbyggda lampan i Arduinon, kräver inget motstånd.
const byte ledPin = 13;

void setup() {

  // starta knappobjekt
  knapp1.begin();

  //sätter ledPin till Output.
  pinMode(ledPin, OUTPUT);

}

void loop() {

  // om knappen trycks in
  if(knapp1.pressed()) {

    // så länge som knappen är intryckt, kör morseanrop.
    while(!knapp1.released()){
     morseBlink('s');
     morseBlink('o');
     morseBlink('s');

     // morseBlink('l');
     // morseBlink('i');
     // morseBlink('n');
     // morseBlink('d');
     // morseBlink('a');
    }
  }
}


// funktion kort morsepuls
void shortBlink()
{
  // skapar en kort puls
  digitalWrite(ledPin, HIGH);
  delay(200);
  digitalWrite(ledPin, LOW);
  delay(200);
  
}


// funktion lång morsepuls
void longBlink()
{
  // skapar en lång puls
  digitalWrite(ledPin, HIGH);
  delay(600);
  digitalWrite(ledPin, LOW);
  delay(200);
}


// Morse-Alfabet. Tar in en bokstav som parameter.
void morseBlink(char bokstav){

  // skapar morsealfabetet genom att anropa kort eller lång puls.
  switch(bokstav){
    case 'a':
      shortBlink();
      longBlink();
      break;
    case 'b':
      longBlink();
      shortBlink();
      shortBlink();
      shortBlink();
      break;
    case 'c':
      longBlink();
      shortBlink();
      longBlink();
      shortBlink();
      break;
    case 'd':
      longBlink();
      shortBlink();
      shortBlink();
      break;
    case 'e':
      shortBlink();
      break;
    case 'f':
      shortBlink();
      shortBlink();
      longBlink();
      shortBlink();
      break;
    case 'g':
      longBlink();
      longBlink();
      shortBlink();
      break;
    case 'h':
      shortBlink();
      shortBlink();
      shortBlink();
      shortBlink();
      break;
    case 'i':
      shortBlink();
      shortBlink();
      break;
    case 'j':
      shortBlink();
      longBlink();
      longBlink();
      longBlink();
      break;
    case 'k':
      longBlink();
      shortBlink();
      longBlink();
      break;
    case 'l':
      shortBlink();
      longBlink();
      shortBlink();
      shortBlink();
      break;
    case 'm':
      longBlink();
      longBlink();
      break;
    case 'n':
      longBlink();
      shortBlink();
      break;
    case 'o':
      longBlink();
      longBlink();
      longBlink();
      break;
    case 'p':
      shortBlink();
      longBlink();
      longBlink();
      shortBlink();
      break;
    case 'q':
      longBlink();
      longBlink();
      shortBlink();
      longBlink();
      break;
    case 'r':
      shortBlink();
      longBlink();
      shortBlink();
      break;
    case 's':
      shortBlink();
      shortBlink();
      shortBlink();
      break;
    case 't':
      longBlink();
      break;
    case 'u':
      shortBlink();
      shortBlink();
      longBlink();
      break;
    case 'v':
      shortBlink();
      shortBlink();
      shortBlink();
      longBlink();
      break;
    case 'w':
      shortBlink();
      longBlink();
      longBlink();
      break;
    case 'x':
      longBlink();
      shortBlink();
      shortBlink();
      longBlink();
      break;
    case 'y':
      longBlink();
      shortBlink();
      longBlink();
      longBlink();
      break;
    case 'z':
      longBlink();
      longBlink();
      shortBlink();
      shortBlink();
      break;
  }
}
