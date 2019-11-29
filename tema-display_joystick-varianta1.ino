#include <LiquidCrystal.h>

const int pinX = A0; // Analog input
const int pinY = A1; // Analog input
const int pinSW = 6;


int valueX = 0;
int valueY = 0;
int valueSW = 0;

const int RS = 12;
const int enable = 11;
const int d4 = 5;
const int d5 = 4;
const int d6 = 3;
const int d7 = 2;


int state = 1;
int index = 5;
int cursorPosition = 0;
int cursorA = 0;
int cursorB = 0;
int cursorC = 0;
int lives = 3;



bool joyMove = false; // to move slower
int minTreshold = 400; // min value of the default joystick state
int maxTreshold = 600; // max value of the default joystick state

const int segSize = 8;

const int defaultX = 511; // customizabil in functie de cat afiseaza in Serial Joystickul
const int defaultY = 514;


LiquidCrystal lcd (RS, enable, d4, d5, d6, d7);


void setup() {
  // put your setup code here, to run once:
  pinMode (pinSW, INPUT_PULLUP);
  lcd.begin( 16, 2 );
  lcd.setCursor (0, 0);
  lcd.print ("Let the game " );
  delay ( 1000 );
  lcd.setCursor ( 0, 1 );
  lcd.print ( " BEGIN ... ");
  delay ( 1000 );
  Serial.begin ( 9600 );
}




int JoystickX(  ){
  index = 3;
  if ( !joyMove && valueX > maxTreshold ) {
    index ++;
    joyMove = true;
    if ( index > 9 )
      index = 0;
    if ( index < 0 )
      index = 9;
  }
  if ( !joyMove && valueX < minTreshold ) {
    index --;
    joyMove = true;
    if ( index > 9 )
      index = 0;
    if ( index < 0 )
      index = 9;
  }

  if ( valueX <= maxTreshold && valueX >= minTreshold )
    joyMove = false;
  return index;
}



void firstMenu() {
  lcd.clear();
  if ( cursorA == 0 ){
    lcd.setCursor (0, 0);
    lcd.print ( "StartGame Menu:"); 
    lcd.setCursor (0, 1);
    lcd.blink(); 
    lcd.print("   >Lives " );
    lcd.setCursor (3, 1);
    delay ( 100 );
    valueSW = digitalRead ( pinSW );
    Serial.println ( pinSW );
//    if ( valueSW == LOW )
//      state = 1;
//    else state = 0;
//    if ( state == 1 ){
//      lcd.clear();
//      lcd.print ("No. of lives : ");
//      lcd.print (lives);
//      delay ( 1000 );
//      // aici trebuie sa adaugi cod pentru a modifica in timp real nr de vieti
//      firstMenu();
//    }
  }
   else{
    if ( cursorA == 1 ){
      lcd.setCursor (0, 0);
      lcd.print("   >Lives " );
      lcd.setCursor (0, 1);
      lcd.blink();
      lcd.print("   >Level " );
      lcd.setCursor (3, 1); 
      valueSW = digitalRead ( pinSW );
      if ( valueSW == LOW )
        state = 1;
      else state = 0;
      if ( state == 1 ){
        lcd.clear();
        lcd.print ("aici e logica"); 
      }
    }
    else {
      lcd.setCursor (0, 0);
      lcd.print("   >Level " );
      lcd.setCursor (0, 1);
      lcd.blink();
      lcd.print("   >Score");
      lcd.setCursor (3, 1);
       valueSW = digitalRead ( pinSW );
      if ( valueSW == LOW )
        state = 1;
      else state = 0;
      if ( state == 1 ){
        lcd.print ("calcul scor");
      }
    }
   }
  delay ( 100 );
}


void secondMenu() {
  lcd.clear();
  lcd.print ( "second" );
}


void thirdMenu() {
  lcd.clear();
  lcd.print ( "third" );
}




void JoystickY2 ( ){
  if ( !joyMove && valueY > maxTreshold ) {
    joyMove = true;
    cursorA ++;
    if ( cursorA > 2 )
      cursorA = 2;
  }
  if ( !joyMove && valueY < minTreshold ) {
    joyMove = true;
    cursorA--;
    if ( cursorA <= 0 )
      cursorA = 0;
    else cursorA = 1;
  }

  if ( valueY <= maxTreshold && valueY >= minTreshold )
    joyMove = false;
    
  if ( joyMove ) 
    firstMenu();
  delay (200);
}



void displayMenu (){ 
  lcd.clear();
  
  if ( cursorPosition == 0 ){
    lcd.setCursor (0, 0);
    lcd.print ( "Menu:"); 
    lcd.setCursor (0, 1);
    lcd.blink(); 
    lcd.print("   >StartGame " );
    lcd.setCursor (3, 1);
    
    valueSW = digitalRead ( pinSW );
    if ( valueSW == LOW )
      state = 1;
    else state = 0;
    if ( state == 1 ){
      while (true )
       firstMenu();
    }
   }
   else{
    if ( cursorPosition == 1 ){
      lcd.setCursor (0, 0);
      lcd.print("   >StartGame " );
      lcd.setCursor (0, 1);
      lcd.blink();
      lcd.print("   >HighScore " );
      lcd.setCursor (3, 1); 
      valueSW = digitalRead ( pinSW );
      if ( valueSW == LOW )
        state = 1;
      else state = 0;
      if ( state == 1 )
        secondMenu();
    }
    else {
      lcd.setCursor (0, 0);
      lcd.print("   >HighScore " );
      lcd.setCursor (0, 1);
      lcd.blink();
      lcd.print("   >Settings");
      lcd.setCursor (3, 1);
       valueSW = digitalRead ( pinSW );
      if ( valueSW == LOW )
        state = 1;
      else state = 0;
      if ( state == 1 )
        thirdMenu();
    }
   }
  delay ( 100 );
}


void JoystickY ( ){
  if ( !joyMove && valueY > maxTreshold ) {
    index ++;
    joyMove = true;
    if ( index > 9 )
      index = 0;
    if ( index < 0 )
      index = 9;
    cursorPosition ++;
    if ( cursorPosition > 2 )
      cursorPosition = 2;
  }
  if ( !joyMove && valueY < minTreshold ) {
    index --;
    joyMove = true;
    if ( index > 9 )
      index = 0;
    if ( index < 0 )
      index = 9;
    cursorPosition--;
    if ( cursorPosition <= 0 )
      cursorPosition = 0;
    else cursorPosition = 1;
  }

  if ( valueY <= maxTreshold && valueY >= minTreshold )
    joyMove = false;
    
  if ( joyMove ) 
    displayMenu();
}


void loop() {
  // put your main code here, to run repeatedly:
  valueX = analogRead ( pinX );
  valueY = analogRead ( pinY );
  valueSW = digitalRead ( pinSW );
  
////test joystick
//  Serial.print ( "X = " );
//  Serial.print ( valueX );
//  Serial.print ( "  Y = " );
//  Serial.print ( valueY );
//  Serial.print ( "  SW = " );
//  Serial.println ( valueSW );

  lcd.clear();
  displayMenu();
 
  JoystickY(  );


  if ( valueSW == LOW )
    state = 1;
  else state = 0;

 
 //// test lcd
//  lcd.setCursor (0, 1);
//  lcd.clear();
//  lcd.print ("Index : ");
//  lcd.print ( index );
//  delay ( 400 );
//
//  lcd.clear();
//  lcd.print ( " X = ");
//  lcd.print ( valueX );
//  delay ( 1000 );
//  
//  lcd.clear ();
//  lcd.print ( " Y = ");
//  lcd.print ( valueY );
//  delay ( 1000 );
//
//  lcd.clear ();
//  lcd.print ( " SW = ");
//  lcd.print ( valueSW );
//  delay ( 1000 );
}
//
//
//To Do:
//  - trebuie sa refaci joystickY2
//  - sa refolosesti codul de la joystickY original
//  - alta metoda pentru a naiva prin meniul de la StartGame
//  - nu mai merge sa selectezi nimic din "Meniu: " 
