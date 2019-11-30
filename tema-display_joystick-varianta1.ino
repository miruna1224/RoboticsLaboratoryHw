#include <LiquidCrystal.h>

const int pinX = A0; // Analog input
const int pinY = A1; // Analog input
const int pinSW = 10;


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
int level = 1;
int score = 0;
int highscore = 0;



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




int JoystickX( int index ){
  if ( !joyMove && valueX > maxTreshold ) {
    index ++;
    joyMove = true;
    if ( index > 10 )
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
     // Serial.println ( pinSW );
    if ( valueSW == LOW )
      state = 1;
    else state = 0;
    if ( state == 1 ){
      lcd.clear();
      lcd.blink();
      lcd.print ("No. of lives : ");
      lcd.print (lives);
      delay ( 1000 );
      do{
        lcd.clear();
        valueSW = digitalRead ( pinSW );
        if ( valueSW == LOW )
           state = 1;
         else state = 0;
        joyMove = false;
        valueX = 0;
        valueY = 0;
        lives = JoystickX( lives );    
        lcd.print ("No. of lives : ");
        lcd.print (lives);
        delay ( 1000 );
       } while (valueSW == 1);
       // aici trebuie sa adaugi cod pentru a modifica in timp real nr de vieti
       firstMenu();
    }
  }
   else{
    if ( cursorA == 1 ){
      lcd.setCursor (0, 0);
      lcd.print("   >Lives " );
      lcd.setCursor (0, 1);
      lcd.blink();
      lcd.print("   >Level " );
      lcd.setCursor (3, 1);
      delay ( 100 );
      valueSW = digitalRead ( pinSW );
       // Serial.println ( pinSW );
      if ( valueSW == LOW )
        state = 1;
      else state = 0;
      if ( state == 1 ){
        do{
          lcd.clear();
          valueSW = digitalRead ( pinSW );
          if ( valueSW == LOW )
             state = 1;
           else state = 0;
          joyMove = false;
          valueX = 0;
          valueY = 0;
          level = millis() / 10000;    
          lcd.print ("Level : ");
          lcd.print (level);
          delay ( 100 );
         } while (valueSW == 0 && level < 10);
          valueSW = digitalRead ( pinSW );
           // Serial.println ( pinSW );
          if ( valueSW == LOW )
            state = 1;
          else state = 0;
         while( level == 10 && state == 0 ){
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print ("Congratulation! You finished the game ");
          lcd.setCursor (0, 1);
          lcd.print ("Press Switch Joystick Button to exit" );
          valueSW = digitalRead ( pinSW );
           // Serial.println ( pinSW );
          if ( valueSW == LOW )
            state = 1;
          else state = 0;
         }
         // aici trebuie sa adaugi cod pentru a modifica in timp real levelul
         firstMenu();
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
       // Serial.println ( pinSW );
      if ( valueSW == LOW )
        state = 1;
      else state = 0;
      if ( state == 1 ){
        lcd.clear();
        valueSW = digitalRead ( pinSW );
        if ( valueSW == LOW )
           state = 1;
         else state = 0;
        if ( valueSW == 1 ){
          score = level * 3;    
          lcd.print ("Score : ");
          lcd.print (score);
          if (score > highscore )
            highscore = score;
          delay ( 1000 );
        }
        firstMenu();
      }
    }
   }
  delay ( 100 );
}

void displayMenu ();

void secondMenu() {
  lcd.clear();
  lcd.setCursor( 0, 0 );
  lcd.print ( "HighScore : " );
  lcd.setCursor( 0, 1 );
  lcd.print( highscore);
  do{
    valueSW = digitalRead ( pinSW );
    // Serial.println ( pinSW );
    if ( valueSW == LOW )
      state = 1;
    else state = 0;
  } while ( state == 0);
  
   valueX = 0;
   valueY = 0;
  valueSW = 0;
  displayMenu();
}


void thirdMenu() {
  lcd.clear();
  lcd.setCursor (0, 0);
  lcd.print ( " No. of lives : " );
  lcd.setCursor(1, 7);
  lcd.print ( lives ); 
  valueSW = digitalRead ( pinSW );
  
  
   if ( valueSW == LOW )
        state = 1;
      else state = 0;
  if ( state == 1 ){
    delay (20);
    do{
      valueSW = digitalRead ( pinSW );
       if ( valueSW == LOW )
        state = 1;
      else state = 0;
      joyMove = false;
      valueX = 0;
      valueY = 0;
      valueSW = 0;
      lives = JoystickX ( lives );
    } while ( state == 0 );
  }
  
  displayMenu();
}




void JoystickY_FM ( ){
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
    firstMenu();
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
    while ( state == 1 ){
        joyMove = false;
        valueX = 0;
        valueY = 0;
        valueSW = 0;
        JoystickY_FM();
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
      if ( state == 1 ){
        joyMove = false;
        valueX = 0;
        valueY = 0;
        valueSW = 0;
        secondMenu();
      }
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

//
//  if ( valueSW == LOW )
//    state = 1;
//  else state = 0;

 
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
