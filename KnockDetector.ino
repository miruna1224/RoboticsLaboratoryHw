const int photoPin = A0;
int photoValue = 0;

const int pushButton = 2;
const int pinLed = 13;
int buttonState = 1;
int lastButtonState = 1;
int reading;
int ledState = 0;
int ledState2 = 0;
int interval = 50; //milisec
int sunet = -1;
unsigned long lastDebounceTime = 0 ;

const int startMusicThreshold = 90;

const int passiveBuzzerPin = A2;
const int activeBuzzerPin = 8;

int pauseBetweenNotes;
int lastNoteTime;
int noteDuration;

const int noteLen = 8; 
int currentNote = 0; 


int lastChange = 0;
bool lastState = LOW;
bool newState;
bool lastReadState = LOW;
bool newReadState;
bool musicIsPlaying = false;


int melody[noteLen] = {262, 196, 196, 220, 196, 0, 247, 262};
int noteDurations[noteLen] = {4, 8, 8, 4, 4, 4, 4, 4};




void setup() {
  // put your setup code here, to run once:
    // put your setup code here, to run once:
  //pinMode ( pushButton, INPUT );
  Serial.begin (9600);
  pinMode ( photoPin, INPUT);
  pinMode ( pushButton, INPUT_PULLUP ); 
  pinMode ( pinLed, OUTPUT ); 
  pinMode (passiveBuzzerPin, INPUT);
  pinMode (activeBuzzerPin, OUTPUT);
  digitalWrite (pinLed,HIGH);

}



void playMusic()
{
  if (millis() < lastNoteTime + pauseBetweenNotes) 
  {
    return;
   } 
  // stop the tone playing:
  noTone(activeBuzzerPin);
  // to calculate the note duration, take one second divided by the note type.
  //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
  noteDuration = 1000 / noteDurations[currentNote];
  tone(activeBuzzerPin, melody[currentNote], noteDuration);
  Serial.println ("Note");
  lastNoteTime = millis();

  // to distinguish the notes, set a minimum time between them.
  // the note's duration + 30% seems to work well:
  pauseBetweenNotes = noteDuration * 1.30;
  currentNote = (currentNote + 1) % noteLen;
}

void stopMusicListener()
{
  newReadState = !digitalRead (pushButton);
  if (lastReadState != newReadState) {
    lastChange = millis();
    lastReadState = newReadState;
  }
  if (millis() > lastChange + 50)
  {
    newState = newReadState;
    if (lastState != newState)
    {
      lastChange = millis();
      if (newState == HIGH)
      {
        noTone (activeBuzzerPin);
        Serial.println ("Music stopped");
        digitalWrite (pinLed, HIGH);
        musicIsPlaying = false;
      }
      lastState = newState;
    }
  }
}




void loop() {
//  // put your main code here, to run repeatedly:
//  // put your main code here, to run repeatedly:
//  //buttonState = digitalRead ( pushButton );
//  reading = digitalRead ( pushButton );
//  if ( reading != lastButtonState )
//    lastDebounceTime = millis();
//  if ( millis() - lastDebounceTime > interval ) {
//    if ( reading != buttonState )
//      buttonState = reading;
//    if ( buttonState == LOW )
//      ledState = !ledState;
//   }
//   photoValue = analogRead( photoPin );
//   if ( ledState != 0  ){
//     if (musicIsPlaying) {
//        playMusic();
//        stopMusicListener();
//      }
//    else {
//      startMusicListener();
//    }
//    sunet = 8;
//    ledState2 = map ( photoValue, 100, 400, 0, 255 );
//   }
//   else{
//    sunet = -1;
//    ledState2 = 0;
//   }
//   //digitalWrite(pinLed, ledState );
//   //tone ( 8, sunet, ledState2 ); 
//   analogWrite (pinLed, ledState2);
//   Serial.println( photoValue ); 
//   lastButtonState = reading;
   if (musicIsPlaying) {
    playMusic();
    stopMusicListener();
  }
  else {
    startMusicListener();
  }
}





void startMusicListener() 
{
  int buzzer = analogRead (passiveBuzzerPin);
  Serial.println(buzzer);
  if (analogRead (passiveBuzzerPin) > startMusicThreshold) 
  {
    Serial.println(buzzer);
    lastNoteTime = millis();
    digitalWrite (pinLed, LOW);
    musicIsPlaying = true;
    currentNote = 0;
    pauseBetweenNotes = 5000;
  }
}
