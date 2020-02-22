const int pushButton = 2;
int buttonState = 1;
int lastButtonState = 1;
int ledState = 0;
int interval = 50; //milisec
unsigned long lastDebounceTime = 0 ;

int reading;


void setup() {
  // put your setup code here, to run once:
  //pinMode ( pushButton, INPUT );
  pinMode ( pushButton, INPUT_PULLUP ); 
  //digitalWrite ( pinLed, ledState );
  Serial.begin (9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  reading = digitalRead ( pushButton );
  if ( reading != lastButtonState )
    lastDebounceTime = millis();
  if ( millis() - lastDebounceTime > interval ) {
    if ( reading != buttonState )
      buttonState = reading;
    if ( buttonState == LOW )
      ledState = !ledState;
   }
   Serial.print ( buttonState);
   lastButtonState = reading;
}
