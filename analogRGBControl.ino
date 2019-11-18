
const int potPin1 = A0;
const int potPin2 = A1;
const int potPin3 = A2;
const int ledPin1 = 5;
const int ledPin2 = 6;
const int ledPin3 = 7;
int potValue1 = 0;
int potValue2 = 0;
int potValue3 = 0;
int ledValue1 = 0;
int ledValue2 = 0;
int ledValue3 = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode ( potPin1, INPUT);
  pinMode ( ledPin1, OUTPUT);
  Serial.begin ( 9600 ); // boud rate -> bits per sec
  pinMode ( potPin2, INPUT);
  pinMode ( ledPin2, OUTPUT);
  pinMode ( potPin3, INPUT);
  pinMode ( ledPin3, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  potValue1 = analogRead( potPin1 );  // 0 - 1023
  //analogWrite  -> 0 - 255
  //analogWrite ( ledPin, 1023); // 1023 mod 255
  ledValue1 = map ( potValue1, 0, 1023, 0 , 255 );
  analogWrite( ledPin1, ledValue1); 
  
  potValue2 = analogRead( potPin2 );
  ledValue2 = map ( potValue2, 0, 1023, 0 , 255 );
  analogWrite( ledPin2, ledValue2);
  
  potValue3 = analogRead( potPin3);
  ledValue3 = map ( potValue3, 0, 1023, 0 , 255 );
  analogWrite( ledPin3, ledValue3);
}
