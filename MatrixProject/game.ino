#include <LiquidCrystal.h>
#include <LedControl.h>
#include <EEPROM.h>


byte heart[] = {
  B00000,
  B11011,
  B11111,
  B11111,
  B01110,
  B00100,
  B00000,
  B00000
}; 
 // lcd animation for lives that you have in game -> you lost one when you hit a wall , you win one when you hit a score uninterrupted
 

bool Pacman1[8][8] = {  {0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 1, 1, 1, 1, 1, 0},
                      {0, 1, 1, 0, 1, 1, 0, 0},
                      {0, 1, 1, 0, 1, 0, 0, 0},
                      {0, 1, 1, 1, 1, 0, 0, 0},
                      {0, 1, 1, 1, 1, 1, 0, 0},
                      {0, 0, 1, 1, 1, 1, 1, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0}};
bool Pacman2[8][8] = { {0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 1, 1, 1, 0, 0},
                       {0, 0, 1, 1, 0, 1, 1, 0},
                       {0, 1, 1, 1, 0, 1, 1, 1},
                       {0, 1, 1, 1, 1, 1, 1, 1},
                       {0, 0, 1, 1, 1, 1, 1, 0},
                       {0, 0, 0, 1, 1, 1, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0}};
// Matrixed for game over animation




bool artf1[8][8] = { {0, 0, 0, 0, 0, 0, 0, 0},
                 {0, 0, 0, 0, 0, 0, 0, 0}, 
                 {0, 0, 0, 0, 0, 0, 0, 0},
                 {0, 0, 0, 1, 1, 0, 0, 0},
                 {0, 0, 0, 1, 1, 0, 0, 0},
                 {0, 0, 0, 0, 0, 0, 0, 0},
                 {0, 0, 0, 0, 0, 0, 0, 0},
                 {0, 0, 0, 0, 0, 0, 0, 0} };
bool artf2[8][8] = { {0, 0, 0, 0, 0, 0, 0, 0},
                 {0, 1, 0, 0, 0, 0, 1, 0},
                 {0, 0, 1, 0, 0, 1, 0, 0},
                 {0, 0, 0, 0, 0, 0, 0, 0},
                 {0, 0, 1, 0, 0, 1, 0, 0},
                 {0, 1, 0, 0, 0, 0, 1, 0},
                 {0, 0, 0, 0, 0, 0, 0, 0},
                 {0, 0, 0, 0, 0, 0, 0, 0}};
bool artf3[8][8] = { {1, 0, 0, 0, 0, 0, 0, 1},
                {0, 1, 1, 0, 0, 1, 1, 0},
                {0, 1, 1, 0, 0, 1, 1, 0},
                {0, 0, 0, 0, 0, 0, 0, 0},
                {0, 1, 1, 0, 0, 1, 1, 0},
                {0, 1, 1, 0, 0, 1, 1, 0},
                {1, 0, 0, 0, 0, 0, 0, 1},
                {0, 0, 0, 0, 0, 0, 0, 0} };
bool artf4[8][8] = { {1, 1, 0, 0, 0, 0, 1, 1},
                {1, 0, 0, 0, 0, 0, 0, 1},
                {0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0},
                {1, 0, 0, 0, 0, 0, 0, 1},
                {1, 1, 0, 0, 0, 0, 1, 1} };
//matrixes for win animation
				
				
				
bool nul[8][8] = { {0, 0, 0, 0, 0, 0, 0, 0},
               {0, 0, 0, 0, 0, 0, 0, 0},
               {0, 0, 0, 0, 0, 0, 0, 0}, 
               {0, 0, 0, 0, 0, 0, 0, 0}, 
               {0, 0, 0, 0, 0, 0, 0, 0}, 
               {0, 0, 0, 0, 0, 0, 0, 0}, 
               {0, 0, 0, 0, 0, 0, 0, 0}, 
               {0, 0, 0, 0, 0, 0, 0, 0} };
// null matrix	 -> all leds off		


bool levelUp1[8][8] ={
    {1, 0, 0, 1, 1, 0, 0, 0},
    {1, 0, 0, 1, 0, 0, 0, 0},
    {1, 0, 0, 1, 1, 0, 0, 0},
    {1, 0, 0, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 1, 0, 1, 1},
    {0, 0, 1, 1, 1, 0, 1, 0}
};

bool levelUp2[8][8] = {
  {1, 0, 1, 1, 1, 0, 1, 0},
  {1, 0, 1, 1, 0, 0, 1, 0},
  {1, 0, 1, 1, 1, 0, 1, 0},
  {1, 0, 1, 1, 0, 0, 1, 0},
  {0, 1, 0, 1, 1, 0, 1, 1},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}
};
// animations for level up



byte LPacman1[] = {
  B00000,
  B01110,
  B11111,
  B11111,
  B11111,
  B01110,
  B00000,
  B00000
};

byte LPacman2[] = {
  B00000,
  B01111,
  B11100,
  B11000,
  B11100,
  B01111,
  B00000,
  B00000
};
// pacmans for display animation


byte phantom[] = {
  B00000,
  B11111,
  B10101,
  B10101,
  B11111,
  B11111,
  B11111,
  B00000
};

byte phantom2[] = {
  B00000,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B00000
};
//phantom for display animation -> loading screen


bool map1[8][8] = { {1, 1, 0, 0, 0, 1, 1, 0},
                {0, 0, 0, 0, 1, 0, 1, 0},
                {0, 1, 0, 0, 1, 0, 0 ,0},
                {0, 0, 0, 0, 0, 0, 0, 0},
                {1, 0, 0, 1, 1, 0, 1, 1},
                {1, 0, 1, 1, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 1, 0, 0},
                {0, 0, 1, 1, 0, 1, 0, 0} };
bool map2[8][8] = { {1, 0, 0, 0, 1, 0, 0, 0},
                {1, 1, 0, 0, 1, 0, 1, 0},
                {1, 0, 0, 0, 1, 0, 0, 1},
                {0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 1, 1, 0, 1, 1, 1},
                {1, 0, 0, 0, 0, 1, 0, 1},
                {1, 1, 1, 0, 0, 0, 0, 0},
                {0, 0, 1, 1, 0, 1, 0, 0} };
				
// matrixes for map on led matrixes				


const int pinX = A1; // OX pin joystick
const int pinY = A0; // OY pin joystick
const int pinSW = 6; // switch pin joysticl


int valueX = 0;
int valueY = 0;
int valueSW = 0;
// joystick values
int dificulty = 0;

int delays = 0; // delay values
int delayLevel = 20; // delay values witch increase from level to level
int speedLevel = 200; // speed time

const int RS = 11;
const int enable = 10;
const int d4 = 5;
const int d5 = 4;
const int d6 = 3;
const int d7 = 2;
// lcd pins


int state = 1;
int index = 5;
int cursorPosition = 0;
int cursorA = 0;
int cursorB = 0;
int cursorC = 0;

int lives = 3; // no of  lives initially
int nolevel = 1; // level counter
int score = 0; // score variable
int highscore[3] = {0, 0, 0}; // highscore vector

int var = 0;


bool joyMove = false; // to move slower
int minTreshold = 400; // min value of the default joystick state
int maxTreshold = 600; // max value of the default joystick state

const int segSize = 8;

const int defaultX = 511; 
const int defaultY = 514;


LiquidCrystal lcd (RS, enable, d4, d5, d6, d7);
LedControl lc1 = LedControl( A2, 13, 12, 1); 
LedControl lc2 = LedControl( A5, A4, A3, 1); 
// initialize the lcd and led matrixes


int prevX = 3, prevY = 3, posx = 3, posy = 3;
// positions and previous positions on Ox and Oy axes
boolean movedX = false, movedY = false;
// boolean for movement

int noF = 4;
int Fx[4] = {0, 0, 0, 0};
int Fy[4] = {0, 0, 0, 0};
int Time1F [4];
int Time2F [4];
// variable for fruits : position and time to appear and current time




void loading (){
  lcd.clear();
   for (int i = 0; i < 16 ; i++ )
      lcd.createChar(i, phantom);
   lcd.home();
  for (int i = 0; i < 16 ; i++ ){
    lcd.write(i);
    delay(100);
  }
  delay(100);
  lcd.clear();
}
// loading animation


void turnOffM (){
  for (int i = 0; i< 8; i++ )
    for (int j =0 ;j < 8; j++ ) {
      lc1.setLed (0, j, i, false);
      lc2.setLed (0, j, i, false);
    }
}
// turn off led matrixes function



void initHighscore(){
  for (int i = 0; i < 3; i++ ) 
    highscore[i] = EEPROM.read(i);
}
//initialize highscore vector -> eeprom


void writeHighscore (){
  for(int i = 0; i < 3; i++ )
    EEPROM.write(i, highscore[i]);
}
// write new highscore vector -> eeprom



void setup() {
  // put your setup code here, to run once:
  
  Serial.begin ( 9600 );
  pinMode (pinSW, INPUT_PULLUP);
  lcd.begin( 16, 2 );
  
  lcd.setCursor (0, 0);
  lcd.print ("Let the game " );
  delay ( 400 );
  lcd.setCursor ( 0, 1 );
  lcd.print ( " BEGIN ... ");
  delay ( 400 );

  loading();

  initHighscore();


  lc1.shutdown ( 0, false); 
  lc1.setIntensity ( 0, 2 );
  lc1.clearDisplay ( 0 ); 
  
  lc2.shutdown ( 0, false); 
  lc2.setIntensity ( 0, 2 );
  lc2.clearDisplay ( 0 ); 
  
  loading();
}




void displayMenu (); // the antet for a function to be called before delcaration





void highscoreVector( int n ){
  if ( highscore[0] == 0 )
    highscore[0] = n;
   else{
    if ( n > highscore[0]){
      highscore[2] = highscore[1];
      highscore[1] = highscore[0];
      highscore[0] = n;
    }
    else{
      if ( n < highscore[0] && n > highscore[1]){
        highscore[2] = highscore[1];
        highscore[1] = n;
      }
      else {
        if ( n > highscore[2] && n < highscore[1] ){
          highscore[2] = n;
        }
      }
    }
   }
   writeHighscore();
}
// calculate the highscore vector -> place the variable n in vector





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
// joystick movement to modify index variable



void setLab (){
  turnOffM ();
  for(int i = 0; i < 8; i++ )
    for( int j = 0; j < 8; j++ ){
      lc1.setLed (0, j, i, map1[i][j]);
      lc2.setLed (0, j, i, map1[i][j]);
    }
}
// turn on the led in led matrixes coresponding to maps



void GameLCD(){
  delay (15);
  lcd.clear();
  lcd.setCursor (0, 0);
  for (int i = 0; i < lives; i++ )
    lcd.createChar (i, heart);
  lcd.home();
  for (int i = 0; i < lives; i++ )
    lcd.write ((byte) i);
  lcd.setCursor( 8, 0);
  lcd.print (score);
  lcd.setCursor (0, 1);
  lcd.print ( "Lives");
  lcd.setCursor (8, 1);
  lcd.print ("Score");
}
// start game option -> game  :) with score and lives live



void gameOver(){
  loading();
  lcd.clear();
  lcd.print (" Game Over! ");
  lcd.setCursor (0, 1);
  lcd.print (score);
  delay (200);
  for (int i = 0; i < 4; i++ ){
    turnOffM();
    for( int j = 0; j < 8; j++ )
      for (int k = 0; k < 8; k++ ){
        lc1.setLed (0, k, j, Pacman1[j][k]);
        lc2.setLed (0, k, j, Pacman2[j][k]);
      }
    delay ( 400 );
    for( int j = 0; j < 8; j++ )
      for (int k = 0; k < 8; k++ ){
        lc1.setLed (0, k, j, Pacman2[j][k]);
        lc2.setLed (0, k, j, Pacman2[j][k]);
      }
    delay (400);   
    for( int j = 0; j < 8; j++ )
      for (int k = 0; k < 8; k++ ){
        lc1.setLed (0, k, j, Pacman1[j][k]);
        lc2.setLed (0, k, j, Pacman1[j][k]);
      }
    delay(400);
  }
  highscoreVector(score);
}
// game over function 



void Win(){
  lcd.clear();
  lcd.print(" You Win! ");
  for (int i = 0; i < 3; i++ ){
    turnOffM();
    for( int j = 0; j < 8; j++ )
      for (int k = 0; k < 8; k++ ){
        lc1.setLed (0, k, j, artf1[j][k]);
        lc2.setLed (0, k, j, artf1[j][k]);
      }
    delay ( 400 );
    for( int j = 0; j < 8; j++ )
      for (int k = 0; k < 8; k++ ){
        lc1.setLed (0, k, j, artf2[j][k]);
        lc2.setLed (0, k, j, artf2[j][k]);
      }
    delay (400);   
    for( int j = 0; j < 8; j++ )
      for (int k = 0; k < 8; k++ ){
        lc1.setLed (0, k, j, artf3[j][k]);
        lc2.setLed (0, k, j, artf3[j][k]);
      }
    delay(400);
    for( int j = 0; j < 8; j++ )
      for (int k = 0; k < 8; k++ ){
        lc1.setLed (0, k, j, artf4[j][k]);
        lc2.setLed (0, k, j, artf4[j][k]);
      }
  }
}
// win function


void changeLevel(){
  lcd.clear();
  lcd.setCursor (0, 0);
  lcd.print ("Level : ");
  lcd.setCursor (0, 1);
  lcd.print (nolevel);
  turnOffM();
  for (int i = 0; i < 8; i++ )
    for (int j = 0; j < 8; j++ ){
      lc1.setLed (0, j, i, levelUp1[i][j]);
      lc2.setLed (0, j, i, levelUp2[i][j]);
    }
  delay (100);
  turnOffM();
}
//change level functiom



void moveP(){

  for (int i = 0; i < noF; i++ ){
    Time2F[i] = millis() / 1000;
    if ( Time2F[i] - Time1F[i] > i * 67 ){
      Time1F[i] = Time2F[i];
      if (Fx[i] < 8)
          lc1.setLed (0, Fy[i], Fx[i], false );
      else
        lc2.setLed (0, Fy[i], Fx[i] % 8, false );
      do{
        Fx[i] = random (0, 16);
        Fy[i] = random (0, 8);
      } while ( verif(i) );
      if (Fx[i] < 8){
        lc1.setLed (0, Fy[i], Fx[i], true );
        lc1.setLed (0, Fy[i], Fx[i], false );
        lc1.setLed (0, Fy[i], Fx[i], true );
      }
      else{
        lc2.setLed (0, Fy[i], Fx[i] % 8, true );
        lc2.setLed (0, Fy[i], Fx[i] % 8, false);
        lc2.setLed (0, Fy[i], Fx[i] % 8, true );
      }
    }
  }
  
  valueX = analogRead(pinX);
  valueY = analogRead(pinY);  

  if (valueY > maxTreshold)
  {
    if (movedY == false)
    {
      prevY = posy;
      posy++;
      movedY = true;
    }
  }
  else
  {
    if (valueY < minTreshold)
    {
      if (movedY == false)
      {
        prevY = posy;
        posy--;
        movedY = true;
      }
    }
    else movedY = false;
  }

  if (valueX < minTreshold)
  {
    if (movedX == false)
    {
      prevX = posx;
      posx--;
      movedX = true;
    }
  }
  else
  {
    if (valueX > maxTreshold)
    {
      if (movedX == false)
      {
        prevX = posx;
        posx++;
        movedX = true;
      }
    }
    else movedX = false;
  }

  if ( posx < 0)
    posx = 15;
  if (posy < 0 )
    posy = 7;
  if (posx > 15 )
    posx = 0;
  if (posy > 7 )
    posy = 0;  

  if ( posx < 8 ){
    if( map1[posx][posy] ){
      lives --;
    }
  }
  else{
    if ( map2[posx % 8][posy] ){
      lives --;
    }
  }
  
}
// movement function -> to move in lab  -> logic for score and lives to ++ or -- , for changing level, win or lose


bool verif (int i){
  if (Fx[i] < 8){
    if (map1[Fx[i]][Fy[i]] == 1 )
      return true;
  }
  else {
    if (map2[Fx[i] % 8][Fy[i]] == 1 )
      return true;
  }
  if ( Fx[i] == posx && Fy[i] == posy )
    return true;
  return false;
}
// verify if a fruit can be spawned in Fx[i] and Fy[i] position



void firstMenu() {
  
  setLab();

  for (int i = 0; i < noF; i++ ){
    Time1F[i] = millis() / 1000;
    do{
      Fx[i] = random (0, 16);
      Fy[i] = random (0, 8);
    } while ( verif(i) );
    if (Fx[i] < 8 ){
      lc1.setLed (0, Fy[i], Fx[i], true );
      lc1.setLed (0, Fy[i], Fx[i], false );
      lc1.setLed (0, Fy[i], Fx[i], true );
    }
    else{
      lc2.setLed (0, Fy[i], Fx[i] % 8, true );
      lc2.setLed (0, Fy[i], Fx[i] % 8, false );
      lc2.setLed (0, Fy[i], Fx[i] % 8, true );
    }
  }
  
  score = 0;
  lives = 3;
  nolevel = 1;
  posx = 3;
  posy = 2;
  prevX = 3;
  prevY = 2; 
  
  int sL = speedLevel;
  int dL = delayLevel;

  while (lives > 0 && nolevel < 10 ){
    valueX = 0;
    valueY = 0;
    valueSW = 0;
    GameLCD();
    int t = millis() / 1000;
    if ( t % 7 == 0 && t > 5 )
      score ++;
    if (posx < 8){
      lc1.setLed (0, posy, posx, true);
      delay (20);
      lc1.setLed (0, posy, posx, false);
      delay(20);
      lc1.setLed (0, posy, posx, true);
    }
    else {
      lc2.setLed (0, posy, posx % 8, true);
      delay(20);
      lc2.setLed (0, posy, posx % 8, false);
      delay(20);
      lc2.setLed (0, posy, posx % 8, true);
    }
     if (posx < 8)
      lc1.setLed (0, posy, posx, false);
    else
      lc2.setLed (0, posy, posx % 8, false);
    for (int i = 0; i < noF; i++ ){
      if (Fx[i] == posx && Fy[i] == posy ){
        score += 20;
        if (Fx[i] < 8)
          lc1.setLed (0, Fy[i], Fx[i], false);
        else lc2.setLed (0, Fy[i], Fx[i] % 8, false);
      }
      Time2F[i] = Time1F[i];
    }
    moveP();
    delay (sL);
    if ( score % 95 == 0 && score > 94 ){
      nolevel++;
      if ( nolevel % 3 == 0 )
        noF --;
      changeLevel();
      delay (200);
      for (int i = 0; i < 8; i++ )
        for (int j = 0; j < 8; j++){
          lc1.setLed (0, j, i, map1[i][j]);
          lc2.setLed (0, j, i, map2[i][j]);
        }
      if ( sL - dL > 20 )
        sL -= dL;
    }
    GameLCD();
  } 
  Serial.println ( score);
  highscoreVector (score); 
  if ( lives == 0 ){
    highscoreVector( score );
    gameOver();
   }
  else{
    Win();
    highscore[0] = -1;
  }
  displayMenu();
}
// start game option from menu
// game first menu : reset variables, move logic, speed modification, calculate score, comapare highscores, reset lab, spawn fruits


void secondMenu() {
  lcd.clear();
  lcd.setCursor( 0, 0 );
  lcd.print ( "highscore : " );
  lcd.setCursor( 0, 1 );
  lcd.print (highscore[0]);
  delay (600);
  lcd.clear();
  lcd.setCursor (0, 0);
  lcd.print (highscore[1] );
  lcd.setCursor (0, 1);
  lcd.print (highscore[2]);
  delay (600);
  valueX = 0;
  valueY = 0;
  valueSW = 0;
  valueSW = digitalRead ( pinSW );
  if ( valueSW == LOW )
    state = 1;
  else state = 0;
  if ( state == 1)
    displayMenu();
}
// display highscore from highscore option from menu



void thirdMenu() {
  valueSW = digitalRead ( pinSW );
  if ( valueSW == LOW )
    state = 1;
  else state = 0;
  if ( state == 1)
    displayMenu();
  int s = 1;
  while ( state == 0 ){
    lcd.clear();
    valueX = analogRead (pinX);
    valueY = analogRead (pinY );
    if ( valueX > maxTreshold || valueY > maxTreshold )
      s ++;
    if (valueX < minTreshold || valueY < minTreshold)
      break;
    s = s % 3;
    lcd.setCursor ( 0, 0 );
    lcd.print ( "Speed Level :" );
    delay (20);
    lcd.setCursor (4, 1);
    if ( s == 1){
      speedLevel = 200;
      delayLevel = 8;
      lcd.print ("Medium");
    }
     else {
        if (s == 0 ){
          speedLevel = 200;
          delayLevel = 15;
          lcd.print ("Easy");
        }
        else{ 
          lcd.print ("Hard");
          delayLevel = 1;
          speedLevel = 20;
        }
     }
    delay (20);  
     
    valueSW = digitalRead ( pinSW );
    if ( valueSW == LOW )
      state = 1;
    else state = 0;
  }
  
  joyMove = false;
  valueX = 0;
  valueY = 0;
  valueSW = 0;
  displayMenu();
}
// settings option from menu
// can change the difficulty of the game


void lastMenu(){
  lcd.clear();
  lcd.setCursor ( 0, 0 );
  lcd.print ( "Game maker :" );
  delay (20);
  lcd.setCursor (4, 1);
  lcd.print ("Miruna");
  delay (1000);
  lcd.clear();
  lcd.setCursor ( 0, 0 );
  lcd.print ( "Shell maker :" );
  delay (20);
  lcd.setCursor (4, 1);
  lcd.print ("Alex");
  delay (1000);
  valueSW = digitalRead ( pinSW );
  if ( valueSW == LOW )
    state = 1;
  else state = 0;
  if ( state == 1)
    displayMenu();
}
// credits options from menu





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
// joystick movement on oy axes





void displayMenu (){ 
  turnOffM();
  lcd.clear();
  
  if ( cursorPosition == 0 ){
    lcd.clear();
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
      lcd.clear();
      lcd.setCursor (0, 0);
      lcd.print("   >StartGame " );
      lcd.setCursor (0, 1);
      lcd.blink();
      lcd.print("   >highscore " );
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
        if ( cursorPosition == 2 ){
            lcd.clear();
            lcd.setCursor (0, 0);
            lcd.print("   >highscore " );
            lcd.setCursor (0, 1);
            lcd.blink();
            lcd.print("   >Settings " );
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
              thirdMenu();
            }
         } else {
          lcd.clear();
          lcd.setCursor (0, 0);
          lcd.print("   >Settings " );
          lcd.setCursor (0, 1);
          lcd.blink();
          lcd.print("   >Credits");
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
              lastMenu();
            }
      }
     }
    }
  delay ( 100 );
}// display menu


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
      cursorPosition = 3;
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

  lcd.clear();
  displayMenu();

  JoystickY(  );

}
// main -> call menu, clear lcd
