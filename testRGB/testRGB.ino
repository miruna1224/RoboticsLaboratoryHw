int red_light_pin= 11;
int green_light_pin = 10;
int blue_light_pin = 9;

const int pushButton = 3;
int buttonState = 0;
int prev = 0;


void setup() {
  pinMode(red_light_pin, OUTPUT);
  pinMode(green_light_pin, OUTPUT);
  pinMode(blue_light_pin, OUTPUT);
  pinMode(pushButton, INPUT_PULLUP);
  Serial.begin (9600); 
}


void loop() {
//  buttonState = digitalRead ( pushButton );
//  Serial.println (buttonState );
//  buttonState = digitalRead (pushButton);
//  if ( prev != buttonState ){
//    Serial.print ( "move column");
//  }
  RGB_color(255, 0, 0); // Red
  delay(500);
  RGB_color(0, 255, 0); // Green
  delay(500);
  RGB_color(0, 0, 255); // Blue
  delay(500);
  RGB_color(255, 255, 125); // Raspberry
  delay(500);
  RGB_color(0, 255, 255); // Cyan
  delay(500);
  RGB_color(255, 0, 255); // Magenta
  delay(500);
  RGB_color(255, 255, 0); // Yellow
  delay(500);
  RGB_color(255, 255, 255); // White
  delay(500);
  RGB_color(0, 0, 0); // OFF
  delay(500);
  prev = buttonState;
}


void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
 {
  analogWrite(red_light_pin, red_light_value);
  analogWrite(green_light_pin, green_light_value);
  analogWrite(blue_light_pin, blue_light_value);
}
