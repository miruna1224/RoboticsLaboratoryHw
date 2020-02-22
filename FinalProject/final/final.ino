
int datapin=2;
int clockpin=3;
int latchpin=4;

byte ledB = B11011111;
byte ledG = B10111111;
byte ledR = B01111111;
byte ledV = B01011111;
byte ledY = B00111111;
byte ledT = B10011111;
byte ledW = B00011111;
byte led0 = B11111111;

byte leds[] = {ledR, ledR, ledR, ledR, ledR, ledR, ledR, ledR, ledR, 
               ledW, ledW, ledW, ledW, ledW, ledW, ledW, ledW, ledW, 
               ledB, ledB, ledB, ledB, ledB, ledB, ledB, ledB, ledB, 
               ledG, ledG, ledG, ledG, ledG, ledG, ledG, ledG, ledG, 
               ledY, ledY, ledY, ledY, ledY, ledY, ledY, ledY, ledY, 
               ledV, ledV, ledV, ledV, ledV, ledV, ledV, ledV, ledV};
byte t0 = leds[45], t1 = leds[46], t2 = leds[47], t3 = leds[48], t4 = leds[49], t5 = leds[50], t6 = leds[51], t7 = leds[52], t8 = leds[53];
byte b0 = leds[36], b1 = leds[37], b2 = leds[38], b3 = leds[39], b4 = leds[40], b5 = leds[41], b6 = leds[42], b7 = leds[43], b8 = leds[44];
byte d0 = leds[27], d1 = leds[28], d2 = leds[29], d3 = leds[30], d4 = leds[31], d5 = leds[32], d6 = leds[33], d7 = leds[34], d8 = leds[35];
byte l0 = leds[18], l1 = leds[19], l2 = leds[20], l3 = leds[21], l4 = leds[22], l5 = leds[23], l6 = leds[24], l7 = leds[25], l8 = leds[26];
byte f0 = leds[9], f1 = leds[10], f2 = leds[11], f3 = leds[12], f4 = leds[13], f5 = leds[14], f6 = leds[15], f7 = leds[16], f8 = leds[17];
byte r0 = leds[0], r1 = leds[1], r2 = leds[2], r3 = leds[3], r4 = leds[4], r5 = leds[5], r6 = leds[6], r7 = leds[7], r8 = leds[8];
const int bpin[] = {5, 6, 7, 8, 9, 10, 11, 12, 13, A0, A1, A2};
int wait = 500;



void setup(){
  pinMode(datapin, OUTPUT);
  pinMode(clockpin, OUTPUT);  
  pinMode(latchpin, OUTPUT);
  
  for (int i = 0; i < 12; i++){
    pinMode(bpin[i], INPUT);
    digitalWrite(bpin[i], HIGH);
  }
  digitalWrite(latchpin, LOW);
  for (int i = 0; i < 54; i++) 
    shiftOut(datapin, clockpin, MSBFIRST, leds[i]);
  digitalWrite(latchpin, HIGH);
}




void loop(){ 
  digitalWrite(latchpin,LOW);
  
  for(int i = 0; i < 54; i++) 
    shiftOut(datapin, clockpin, MSBFIRST, leds[i]);
  
  digitalWrite(latchpin, HIGH);
  
  for(int i = 0; i < 12; i++)
   digitalWrite(bpin[i],HIGH);
  
  int b[12]; 
  for (int x = 0; x < 12; x++)
    b[x] = digitalRead(bpin[x]);
  
  if(b[0] == LOW) {
    //rotate left face CCW
    t0 = leds[45];
    t1 = leds[46];
    t2 = leds[47];
    t3 = leds[48];
    t4 = leds[49];
    t5 = leds[50];
    t6 = leds[51];
    t7 = leds[52];
    t8 = leds[53];
    
    b0 = leds[36];
    b1 = leds[37];
    b2 = leds[38];
    b3 = leds[39];
    b4 = leds[40];
    b5 = leds[41];
    b6 = leds[42];
    b7 = leds[43];
    b8 = leds[44];
    
    d0 = leds[27];
    d1 = leds[28];
    d2 = leds[29];
    d3 = leds[30];
    d4 = leds[31];
    d5 = leds[32];
    d6 = leds[33];
    d7 = leds[34]; 
    d8 = leds[35];
    
    l0 = leds[18];
    l1 = leds[19];
    l2 = leds[20];
    l3 = leds[21];
    l4 = leds[22];
    l5 = leds[23];
    l6 = leds[24];
    l7 = leds[25];
    l8 = leds[26];
    
    f0 = leds[9];
    f1 = leds[10];
    f2 = leds[11];
    f3 = leds[12];
    f4 = leds[13];
    f5 = leds[14];
    f6 = leds[15];
    f7 = leds[16];
    f8 = leds[17];
    
    r0 = leds[0];
    r1 = leds[1];
    r2 = leds[2];
    r3 = leds[3];
    r4 = leds[4];
    r5 = leds[5];
    r6 = leds[6];
    r7 = leds[7];
    r8 = leds[8];
    
    leds[51] = leds[15];
    leds[50] = leds[14];
    leds[45] = leds[9];
    leds[42] = t6;
    leds[41] = t5;
    leds[36] = t0;
    leds[33] = b6;
    leds[32] = b5;
    leds[27] = b0;
    leds[15] = d6;
    leds[14] = d5;
    leds[9] = d0;
    leds[26] = leds[24];
    leds[21] = leds[25];
    leds[20] = l8;
    leds[19] = l3;
    leds[18] = l2;
    leds[23] = l1;
    leds[24] = l0;
    leds[25] = l5;
    
    delay(wait);
  }
  
  if(b[2] == LOW){
    //rotate left face CW
    t0 = leds[45];
    t1 = leds[46];
    t2 = leds[47];
    t3 = leds[48];
    t4 = leds[49];
    t5 = leds[50];
    t6 = leds[51];
    t7 = leds[52];
    t8 = leds[53];
    
    b0 = leds[36];
    b1 = leds[37];
    b2 = leds[38];
    b3 = leds[39];
    b4 = leds[40];
    b5 = leds[41];
    b6 = leds[42];
    b7 = leds[43];
    b8 = leds[44];
    
    d0 = leds[27];
    d1 = leds[28];
    d2 = leds[29];
    d3 = leds[30];
    d4 = leds[31];
    d5 = leds[32];
    d6 = leds[33];
    d7 = leds[34];
    d8 = leds[35];
    
    l0 = leds[18];
    l1 = leds[19];
    l2 = leds[20];
    l3 = leds[21];
    l4 = leds[22];
    l5 = leds[23];
    l6 = leds[24];
    l7 = leds[25];
    l8 = leds[26];
    
    f0 = leds[9];
    f1 = leds[10];
    f2 = leds[11];
    f3 = leds[12];
    f4 = leds[13];
    f5 = leds[14];
    f6 = leds[15];
    f7 = leds[16];
    f8 = leds[17];
    
    r0 = leds[0];
    r1 = leds[1];
    r2 = leds[2];
    r3 = leds[3];
    r4 = leds[4];
    r5 = leds[5];
    r6 = leds[6];
    r7 = leds[7];
    r8 = leds[8];
    
    leds[51] = leds[15];
    leds[50] = leds[14];
    leds[45] = leds[9];
    leds[42] = t6;
    leds[41] = t5;
    leds[36] = t0;
    leds[33] = b6;
    leds[32] = b5;
    leds[27] = b0;
    leds[15] = d6;
    leds[14] = d5;
    leds[9] = d0;
    leds[26] = leds[24];
    leds[21] = leds[25];
    leds[20] = l8;
    leds[19] = l3;
    leds[18] = l2;
    leds[23] = l1;
    leds[24] = l0;
    leds[25] = l5;
    
    t0 = leds[45];
    t1 = leds[46];
    t2 = leds[47];
    t3 = leds[48];
    t4 = leds[49];
    t5 = leds[50];
    t6 = leds[51];
    t7 = leds[52];
    t8 = leds[53];
    
    b0 = leds[36];
    b1 = leds[37];
    b2 = leds[38];
    b3 = leds[39];
    b4 = leds[40];
    b5 = leds[41];
    b6 = leds[42];
    b7 = leds[43];
    b8 = leds[44];
    
    d0 = leds[27];
    d1 = leds[28];
    d2 = leds[29];
    d3 = leds[30];
    d4 = leds[31];
    d5 = leds[32];
    d6 = leds[33];
    d7 = leds[34];
    d8 = leds[35];
    
    l0 = leds[18];
    l1 = leds[19];
    l2 = leds[20];
    l3 = leds[21];
    l4 = leds[22];
    l5 = leds[23];
    l6 = leds[24];
    l7 = leds[25];
    l8 = leds[26];
    
    f0 = leds[9];
    f1 = leds[10];
    f2 = leds[11];
    f3 = leds[12];
    f4 = leds[13];
    f5 = leds[14];
    f6 = leds[15];
    f7 = leds[16];
    f8 = leds[17];
    
    r0 = leds[0];
    r1 = leds[1];
    r2 = leds[2];
    r3 = leds[3];
    r4 = leds[4];
    r5 = leds[5];
    r6 = leds[6];
    r7 = leds[7];
    r8 = leds[8];
    
    leds[51] = leds[15];
    leds[50] = leds[14];
    leds[45] = leds[9];
    leds[42] = t6;
    leds[41] = t5;
    leds[36] = t0;
    leds[33] = b6;
    leds[32] = b5;
    leds[27] = b0;
    leds[15] = d6;
    leds[14] = d5;
    leds[9] = d0;
    leds[26] = leds[24];
    leds[21] = leds[25];
    leds[20] = l8;
    leds[19] = l3;
    leds[18] = l2;
    leds[23] = l1;
    leds[24] = l0;
    leds[25] = l5;
    
    t0 = leds[45];
    t1 = leds[46];
    t2 = leds[47];
    t3 = leds[48];
    t4 = leds[49];
    t5 = leds[50];
    t6 = leds[51];
    t7 = leds[52];
    t8 = leds[53];
    
    b0 = leds[36];
    b1 = leds[37];
    b2 = leds[38];
    b3 = leds[39];
    b4 = leds[40];
    b5 = leds[41];
    b6 = leds[42];
    b7 = leds[43];
    b8 = leds[44];
    
    d0 = leds[27];
    d1 = leds[28];
    d2 = leds[29];
    d3 = leds[30];
    d4 = leds[31];
    d5 = leds[32];
    d6 = leds[33];
    d7 = leds[34];
    d8 = leds[35];
    
    l0 = leds[18];
    l1 = leds[19];
    l2 = leds[20];
    l3 = leds[21];
    l4 = leds[22];
    l5 = leds[23];
    l6 = leds[24];
    l7 = leds[25];
    l8 = leds[26];
    
    f0 = leds[9];
    f1 = leds[10];
    f2 = leds[11];
    f3 = leds[12];
    f4 = leds[13];
    f5 = leds[14];
    f6 = leds[15];
    f7 = leds[16];
    f8 = leds[17];
    
    r0 = leds[0];
    r1 = leds[1];
    r2 = leds[2];
    r3 = leds[3];
    r4 = leds[4];
    r5 = leds[5];
    r6 = leds[6];
    r7 = leds[7];
    r8 = leds[8];
    
    leds[51] = leds[15];
    leds[50] = leds[14];
    leds[45] = leds[9];
    leds[42] = t6;
    leds[41] = t5;
    leds[36] = t0;
    leds[33] = b6;
    leds[32] = b5;
    leds[27] = b0;
    leds[15] = d6;
    leds[14] = d5;
    leds[9] = d0;
    leds[26] = leds[24];
    leds[21] = leds[25];
    leds[20] = l8;
    leds[19] = l3;
    leds[18] = l2;
    leds[23] = l1;
    leds[24] = l0;
    leds[25] = l5;
    
    delay(wait);
  }
  



  
  if(b[1] == LOW){
    //rotate right face CW
   
    t0 = leds[45];
    t1 = leds[46];
    t2 = leds[47];
    t3 = leds[48];
    t4 = leds[49];
    t5 = leds[50];
    t6 = leds[51];
    t7 = leds[52];
    t8 = leds[53];
    
    b0 = leds[36];
    b1 = leds[37];
    b2 = leds[38];
    b3 = leds[39];
    b4 = leds[40];
    b5 = leds[41];
    b6 = leds[42];
    b7 = leds[43];
    b8 = leds[44];
    
    d0 = leds[27];
    d1 = leds[28];
    d2 = leds[29];
    d3 = leds[30];
    d4 = leds[31];
    d5 = leds[32];
    d6 = leds[33];
    d7 = leds[34];
    d8 = leds[35];
    
    l0 = leds[18];
    l1 = leds[19];
    l2 = leds[20];
    l3 = leds[21];
    l4 = leds[22];
    l5 = leds[23];
    l6 = leds[24];
    l7 = leds[25];
    l8 = leds[26];
    
    f0 = leds[9];
    f1 = leds[10];
    f2 = leds[11];
    f3 = leds[12];
    f4 = leds[13];
    f5 = leds[14];
    f6 = leds[15];
    f7 = leds[16];
    f8 = leds[17];
    
    r0 = leds[0];
    r1 = leds[1];
    r2 = leds[2];
    r3 = leds[3];
    r4 = leds[4];
    r5 = leds[5];
    r6 = leds[6];
    r7 = leds[7];
    r8 = leds[8];
   
    leds[53] = leds[17];
    leds[48] = leds[12];
    leds[47] = leds[11];
    leds[44] = t8;
    leds[39] = t3;
    leds[38] = t2;
    leds[35] = b8;
    leds[30] = b3;
    leds[29] = b2;
    leds[17] = d8;
    leds[12] = d3;
    leds[11] = d2;
    leds[0]  = leds[6];
    leds[1]  = leds[5];
    leds[2]  = r0;
    leds[3]  = r1;
    leds[8]  = r2;
    leds[7]  = r3;
    leds[6]  = r8;
    leds[5]  = r7;
    
    delay(wait);
  }

  
  if(b[3] == LOW){
    //rotate right face CCW
    
    t0 = leds[45];
    t1 = leds[46];
    t2 = leds[47];
    t3 = leds[48];
    t4 = leds[49];
    t5 = leds[50];
    t6 = leds[51];
    t7 = leds[52];
    t8 = leds[53];
    
    b0 = leds[36];
    b1 = leds[37];
    b2 = leds[38];
    b3 = leds[39];
    b4 = leds[40];
    b5 = leds[41];
    b6 = leds[42];
    b7 = leds[43];
    b8 = leds[44];
    
    d0 = leds[27];
    d1 = leds[28];
    d2 = leds[29];
    d3 = leds[30];
    d4 = leds[31];
    d5 = leds[32];
    d6 = leds[33];
    d7 = leds[34];
    d8 = leds[35];
    
    l0 = leds[18];
    l1 = leds[19];
    l2 = leds[20];
    l3 = leds[21];
    l4 = leds[22];
    l5 = leds[23];
    l6 = leds[24];
    l7 = leds[25];
    l8 = leds[26];
    
    f0 = leds[9];
    f1 = leds[10];
    f2 = leds[11];
    f3 = leds[12];
    f4 = leds[13];
    f5 = leds[14];
    f6 = leds[15];
    f7 = leds[16];
    f8 = leds[17];
    
    r0 = leds[0];
    r1 = leds[1];
    r2 = leds[2];
    r3 = leds[3];
    r4 = leds[4];
    r5 = leds[5];
    r6 = leds[6];
    r7 = leds[7];
    r8 = leds[8];
    
    leds[53] = leds[17];
    leds[48] = leds[12];
    leds[47] = leds[11];
    leds[44] = t8;
    leds[39] = t3;
    leds[38] = t2;
    leds[35] = b8;
    leds[30] = b3;
    leds[29] = b2;
    leds[17] = d8;
    leds[12] = d3;
    leds[11] = d2;
    leds[0]  = leds[6];
    leds[1]  = leds[5];
    leds[2]  = r0;
    leds[3]  = r1;
    leds[8]  = r2;
    leds[7]  = r3;
    leds[6]  = r8;
    leds[5]  = r7;
    
    t0 = leds[45];
    t1 = leds[46];
    t2 = leds[47];
    t3 = leds[48];
    t4 = leds[49];
    t5 = leds[50];
    t6 = leds[51];
    t7 = leds[52];
    t8 = leds[53];
    
    b0 = leds[36];
    b1 = leds[37];
    b2 = leds[38];
    b3 = leds[39];
    b4 = leds[40];
    b5 = leds[41];
    b6 = leds[42];
    b7 = leds[43];
    b8 = leds[44];
    
    d0 = leds[27];
    d1 = leds[28];
    d2 = leds[29];
    d3 = leds[30];
    d4 = leds[31];
    d5 = leds[32];
    d6 = leds[33];
    d7 = leds[34];
    d8 = leds[35];
    
    l0 = leds[18];
    l1 = leds[19];
    l2 = leds[20];
    l3 = leds[21];
    l4 = leds[22];
    l5 = leds[23];
    l6 = leds[24];
    l7 = leds[25];
    l8 = leds[26];
    
    f0 = leds[9];
    f1 = leds[10];
    f2 = leds[11];
    f3 = leds[12];
    f4 = leds[13];
    f5 = leds[14];
    f6 = leds[15];
    f7 = leds[16];
    f8 = leds[17];
    
    r0 = leds[0];
    r1 = leds[1];
    r2 = leds[2];
    r3 = leds[3];
    r4 = leds[4];
    r5 = leds[5];
    r6 = leds[6];
    r7 = leds[7];
    r8 = leds[8];
    
    leds[53] = leds[17];
    leds[48] = leds[12];
    leds[47] = leds[11];
    leds[44] = t8;
    leds[39] = t3;
    leds[38] = t2;
    leds[35] = b8;
    leds[30] = b3;
    leds[29] = b2;
    leds[17] = d8;
    leds[12] = d3;
    leds[11] = d2;
    leds[0]  = leds[6];
    leds[1]  = leds[5];
    leds[2]  = r0;
    leds[3]  = r1;
    leds[8]  = r2;
    leds[7]  = r3;
    leds[6]  = r8;
    leds[5]  = r7;
    
    t0 = leds[45];
    t1 = leds[46];
    t2 = leds[47];
    t3 = leds[48];
    t4 = leds[49];
    t5 = leds[50];
    t6 = leds[51];
    t7 = leds[52];
    t8 = leds[53];
    
    b0 = leds[36];
    b1 = leds[37];
    b2 = leds[38];
    b3 = leds[39];
    b4 = leds[40];
    b5 = leds[41];
    b6 = leds[42];
    b7 = leds[43];
    b8 = leds[44];
    
    d0 = leds[27];
    d1 = leds[28];
    d2 = leds[29];
    d3 = leds[30];
    d4 = leds[31];
    d5 = leds[32];
    d6 = leds[33];
    d7 = leds[34];
    d8 = leds[35];
    
    l0 = leds[18];
    l1 = leds[19];
    l2 = leds[20];
    l3 = leds[21];
    l4 = leds[22];
    l5 = leds[23];
    l6 = leds[24];
    l7 = leds[25];
    l8 = leds[26];
    
    f0 = leds[9];
    f1 = leds[10];
    f2 = leds[11];
    f3 = leds[12];
    f4 = leds[13];
    f5 = leds[14];
    f6 = leds[15];
    f7 = leds[16];
    f8 = leds[17];
    
    r0 = leds[0];
    r1 = leds[1];
    r2 = leds[2];
    r3 = leds[3];
    r4 = leds[4];
    r5 = leds[5];
    r6 = leds[6];
    r7 = leds[7];
    r8 = leds[8];
    
    leds[53] = leds[17];
    leds[48] = leds[12];
    leds[47] = leds[11];
    leds[44] = t8;
    leds[39] = t3;
    leds[38] = t2;
    leds[35] = b8;
    leds[30] = b3;
    leds[29] = b2;
    leds[17] = d8;
    leds[12] = d3;
    leds[11] = d2;
    leds[0]  = leds[6];
    leds[1]  = leds[5];
    leds[2]  = r0;
    leds[3]  = r1;
    leds[8]  = r2;
    leds[7]  = r3;
    leds[6]  = r8;
    leds[5]  = r7;
    
    delay(wait);
  }
  



  
  if(b[5] == LOW){
    //rotate front face CW
    
    t0 = leds[45];
    t1 = leds[46];
    t2 = leds[47];
    t3 = leds[48];
    t4 = leds[49];
    t5 = leds[50];
    t6 = leds[51];
    t7 = leds[52];
    t8 = leds[53];
    
    b0 = leds[36];
    b1 = leds[37];
    b2 = leds[38];
    b3 = leds[39];
    b4 = leds[40];
    b5 = leds[41];
    b6 = leds[42];
    b7 = leds[43];
    b8 = leds[44];
    
    d0 = leds[27];
    d1 = leds[28];
    d2 = leds[29];
    d3 = leds[30];
    d4 = leds[31];
    d5 = leds[32];
    d6 = leds[33];
    d7 = leds[34];
    d8 = leds[35];
    
    l0 = leds[18];
    l1 = leds[19];
    l2 = leds[20];
    l3 = leds[21];
    l4 = leds[22];
    l5 = leds[23];
    l6 = leds[24];
    l7 = leds[25];
    l8 = leds[26];
    
    f0 = leds[9];
    f1 = leds[10];
    f2 = leds[11];
    f3 = leds[12];
    f4 = leds[13];
    f5 = leds[14];
    f6 = leds[15];
    f7 = leds[16];
    f8 = leds[17];
    
    r0 = leds[0];
    r1 = leds[1];
    r2 = leds[2];
    r3 = leds[3];
    r4 = leds[4];
    r5 = leds[5];
    r6 = leds[6];
    r7 = leds[7];
    r8 = leds[8];
    
    leds[51] = leds[20];
    leds[52] = leds[19];
    leds[53] = leds[18];
    leds[2]  = t6;
    leds[1]  = t7;
    leds[0]  = t8;
    leds[29] = r2;
    leds[28] = r1;
    leds[27] = r0;
    leds[20] = d2;
    leds[19] = d1;
    leds[18] = d0;
    leds[9]  = leds[15];
    leds[10] = leds[14];
    leds[11] = f0;
    leds[12] = f1;
    leds[17] = f2;
    leds[16] = f3;
    leds[15] = f8;
    leds[14] = f7;
    
    delay(wait);
  }

  
  if(b[4] == LOW){
    //rotate front face CCW
    
    t0 = leds[45];
    t1 = leds[46];
    t2 = leds[47];
    t3 = leds[48];
    t4 = leds[49];
    t5 = leds[50];
    t6 = leds[51];
    t7 = leds[52];
    t8 = leds[53];
    
    b0 = leds[36];
    b1 = leds[37];
    b2 = leds[38];
    b3 = leds[39];
    b4 = leds[40];
    b5 = leds[41];
    b6 = leds[42];
    b7 = leds[43];
    b8 = leds[44];
    
    d0 = leds[27];
    d1 = leds[28];
    d2 = leds[29];
    d3 = leds[30];
    d4 = leds[31];
    d5 = leds[32];
    d6 = leds[33];
    d7 = leds[34];
    d8 = leds[35];
    
    l0 = leds[18];
    l1 = leds[19];
    l2 = leds[20];
    l3 = leds[21];
    l4 = leds[22];
    l5 = leds[23];
    l6 = leds[24];
    l7 = leds[25];
    l8 = leds[26];
    
    f0 = leds[9];
    f1 = leds[10];
    f2 = leds[11];
    f3 = leds[12];
    f4 = leds[13];
    f5 = leds[14];
    f6 = leds[15];
    f7 = leds[16];
    f8 = leds[17];
    
    r0 = leds[0];
    r1 = leds[1];
    r2 = leds[2];
    r3 = leds[3];
    r4 = leds[4];
    r5 = leds[5];
    r6 = leds[6];
    r7 = leds[7];
    r8 = leds[8];
    
    leds[51] = leds[20];
    leds[52] = leds[19];
    leds[53] = leds[18];
    leds[2]  = t6;
    leds[1]  = t7;
    leds[0]  = t8;
    leds[29] = r2;
    leds[28] = r1;
    leds[27] = r0;
    leds[20] = d2;
    leds[19] = d1;
    leds[18] = d0;
    leds[9]  = leds[15];
    leds[10] = leds[14];
    leds[11] = f0;
    leds[12] = f1;
    leds[17] = f2;
    leds[16] = f3;
    leds[15] = f8;
    leds[14] = f7;
    
    t0 = leds[45];
    t1 = leds[46];
    t2 = leds[47];
    t3 = leds[48];
    t4 = leds[49];
    t5 = leds[50];
    t6 = leds[51];
    t7 = leds[52];
    t8 = leds[53];
    
    b0 = leds[36];
    b1 = leds[37];
    b2 = leds[38];
    b3 = leds[39];
    b4 = leds[40];
    b5 = leds[41];
    b6 = leds[42];
    b7 = leds[43];
    b8 = leds[44];
    
    d0 = leds[27];
    d1 = leds[28];
    d2 = leds[29];
    d3 = leds[30];
    d4 = leds[31];
    d5 = leds[32];
    d6 = leds[33];
    d7 = leds[34];
    d8 = leds[35];
    
    l0 = leds[18];
    l1 = leds[19];
    l2 = leds[20];
    l3 = leds[21];
    l4 = leds[22];
    l5 = leds[23];
    l6 = leds[24];
    l7 = leds[25];
    l8 = leds[26];
    
    f0 = leds[9];
    f1 = leds[10];
    f2 = leds[11];
    f3 = leds[12];
    f4 = leds[13];
    f5 = leds[14];
    f6 = leds[15];
    f7 = leds[16];
    f8 = leds[17];
    
    r0 = leds[0];
    r1 = leds[1];
    r2 = leds[2];
    r3 = leds[3];
    r4 = leds[4];
    r5 = leds[5];
    r6 = leds[6];
    r7 = leds[7];
    r8 = leds[8];
    
    leds[51] = leds[20];
    leds[52] = leds[19];
    leds[53] = leds[18];
    leds[2]  = t6;
    leds[1]  = t7;
    leds[0]  = t8;
    leds[29] = r2;
    leds[28] = r1;
    leds[27] = r0;
    leds[20] = d2;
    leds[19] = d1;
    leds[18] = d0;
    leds[9]  = leds[15];
    leds[10] = leds[14];
    leds[11] = f0;
    leds[12] = f1;
    leds[17] = f2;
    leds[16] = f3;
    leds[15] = f8;
    leds[14] = f7;
    
    t0 = leds[45];
    t1 = leds[46];
    t2 = leds[47];
    t3 = leds[48];
    t4 = leds[49];
    t5 = leds[50];
    t6 = leds[51];
    t7 = leds[52];
    t8 = leds[53];
    
    b0 = leds[36];
    b1 = leds[37];
    b2 = leds[38];
    b3 = leds[39];
    b4 = leds[40];
    b5 = leds[41];
    b6 = leds[42];
    b7 = leds[43];
    b8 = leds[44];
    
    d0 = leds[27];
    d1 = leds[28];
    d2 = leds[29];
    d3 = leds[30];
    d4 = leds[31];
    d5 = leds[32];
    d6 = leds[33];
    d7 = leds[34];
    d8 = leds[35];
    
    l0 = leds[18];
    l1 = leds[19];
    l2 = leds[20];
    l3 = leds[21];
    l4 = leds[22];
    l5 = leds[23];
    l6 = leds[24];
    l7 = leds[25];
    l8 = leds[26];
    
    f0 = leds[9];
    f1 = leds[10];
    f2 = leds[11];
    f3 = leds[12];
    f4 = leds[13];
    f5 = leds[14];
    f6 = leds[15];
    f7 = leds[16];
    f8 = leds[17];
    
    r0 = leds[0];
    r1 = leds[1];
    r2 = leds[2];
    r3 = leds[3];
    r4 = leds[4];
    r5 = leds[5];
    r6 = leds[6];
    r7 = leds[7];
    r8 = leds[8];
    
    leds[51] = leds[20];
    leds[52] = leds[19];
    leds[53] = leds[18];
    leds[2]  = t6;
    leds[1]  = t7;
    leds[0]  = t8;
    leds[29] = r2;
    leds[28] = r1;
    leds[27] = r0;
    leds[20] = d2;
    leds[19] = d1;
    leds[18] = d0;
    leds[9]  = leds[15];
    leds[10] = leds[14];
    leds[11] = f0;
    leds[12] = f1;
    leds[17] = f2;
    leds[16] = f3;
    leds[15] = f8;
    leds[14] = f7;
    
    delay(wait);
  }
  
  
  if(b[7]==LOW){
    
    //rotate back face CCW
    t0 = leds[45];
    t1 = leds[46];
    t2 = leds[47];
    t3 = leds[48];
    t4 = leds[49];
    t5 = leds[50];
    t6 = leds[51];
    t7 = leds[52];
    t8 = leds[53];
    
    b0 = leds[36];
    b1 = leds[37];
    b2 = leds[38];
    b3 = leds[39];
    b4 = leds[40];
    b5 = leds[41];
    b6 = leds[42];
    b7 = leds[43];
    b8 = leds[44];
    
    d0 = leds[27];
    d1 = leds[28];
    d2 = leds[29];
    d3 = leds[30];
    d4 = leds[31];
    d5 = leds[32];
    d6 = leds[33];
    d7 = leds[34];
    d8 = leds[35];
    
    l0 = leds[18];
    l1 = leds[19];
    l2 = leds[20];
    l3 = leds[21];
    l4 = leds[22];
    l5 = leds[23];
    l6 = leds[24];
    l7 = leds[25];
    l8 = leds[26];
    
    f0 = leds[9];
    f1 = leds[10];
    f2 = leds[11];
    f3 = leds[12];
    f4 = leds[13];
    f5 = leds[14];
    f6 = leds[15];
    f7 = leds[16];
    f8 = leds[17];
    
    r0 = leds[0];
    r1 = leds[1];
    r2 = leds[2];
    r3 = leds[3];
    r4 = leds[4];
    r5 = leds[5];
    r6 = leds[6];
    r7 = leds[7];
    r8 = leds[8];
    
    leds[47] = leds[24];
    leds[8]  = leds[45];
    leds[7]  = leds[46];
    leds[6]  = t2;
    leds[35] = r8;
    leds[34] = r7;
    leds[33] = r6;
    leds[26] = d8;
    leds[25] = d7;
    leds[24] = d6;
    leds[45] = l8;
    leds[46] = l7;
    leds[42] = leds[36];
    leds[43] = leds[41];
    leds[44] = b6;
    leds[39] = b7;
    leds[38] = b8;
    leds[37] = b3;
    leds[36] = b2;
    leds[41] = b1;
  
    delay(wait);
  }

  
  if(b[6] == LOW){
    //rotate back face CCW
    
    t0 = leds[45];
    t1 = leds[46];
    t2 = leds[47];
    t3 = leds[48];
    t4 = leds[49];
    t5 = leds[50];
    t6 = leds[51];
    t7 = leds[52];
    t8 = leds[53];
    
    b0 = leds[36];
    b1 = leds[37];
    b2 = leds[38];
    b3 = leds[39];
    b4 = leds[40];
    b5 = leds[41];
    b6 = leds[42];
    b7 = leds[43];
    b8 = leds[44];
    
    d0 = leds[27];
    d1 = leds[28];
    d2 = leds[29];
    d3 = leds[30];
    d4 = leds[31];
    d5 = leds[32];
    d6 = leds[33];
    d7 = leds[34];
    d8 = leds[35];
    
    l0 = leds[18];
    l1 = leds[19];
    l2 = leds[20];
    l3 = leds[21];
    l4 = leds[22];
    l5 = leds[23];
    l6 = leds[24];
    l7 = leds[25];
    l8 = leds[26];
    
    f0 = leds[9];
    f1 = leds[10];
    f2 = leds[11];
    f3 = leds[12];
    f4 = leds[13];
    f5 = leds[14];
    f6 = leds[15];
    f7 = leds[16];
    f8 = leds[17];
    
    r0 = leds[0];
    r1 = leds[1];
    r2 = leds[2];
    r3 = leds[3];
    r4 = leds[4];
    r5 = leds[5];
    r6 = leds[6];
    r7 = leds[7];
    r8 = leds[8];
    
    leds[47] = leds[24];
    leds[8]  = leds[45];
    leds[7]  = leds[46];
    leds[6]  = t2;
    leds[35] = r8;
    leds[34] = r7;
    leds[33] = r6;
    leds[26] = d8;
    leds[25] = d7;
    leds[24] = d6;
    leds[45] = l8;
    leds[46] = l7;
    leds[42] = leds[36];
    leds[43] = leds[41];
    leds[44] = b6;
    leds[39] = b7;
    leds[38] = b8;
    leds[37] = b3;
    leds[36] = b2;
    leds[41] = b1;
    
    t0 = leds[45];
    t1 = leds[46];
    t2 = leds[47];
    t3 = leds[48];
    t4 = leds[49];
    t5 = leds[50];
    t6 = leds[51];
    t7 = leds[52];
    t8 = leds[53];
    
    b0 = leds[36];
    b1 = leds[37];
    b2 = leds[38];
    b3 = leds[39];
    b4 = leds[40];
    b5 = leds[41];
    b6 = leds[42];
    b7 = leds[43];
    b8 = leds[44];
    
    d0 = leds[27];
    d1 = leds[28];
    d2 = leds[29];
    d3 = leds[30];
    d4 = leds[31];
    d5 = leds[32];
    d6 = leds[33];
    d7 = leds[34];
    d8 = leds[35];
    
    l0 = leds[18];
    l1 = leds[19];
    l2 = leds[20];
    l3 = leds[21];
    l4 = leds[22];
    l5 = leds[23];
    l6 = leds[24];
    l7 = leds[25];
    l8 = leds[26];
    
    f0 = leds[9];
    f1 = leds[10];
    f2 = leds[11];
    f3 = leds[12];
    f4 = leds[13];
    f5 = leds[14];
    f6 = leds[15];
    f7 = leds[16];
    f8 = leds[17];
    
    r0 = leds[0];
    r1 = leds[1];
    r2 = leds[2];
    r3 = leds[3];
    r4 = leds[4];
    r5 = leds[5];
    r6 = leds[6];
    r7 = leds[7];
    r8 = leds[8];
    
    leds[47] = leds[24];
    leds[8]  = leds[45];
    leds[7]  = leds[46];
    leds[6]  = t2;
    leds[35] = r8;
    leds[34] = r7;
    leds[33] = r6;
    leds[26] = d8;
    leds[25] = d7;
    leds[24] = d6;
    leds[45] = l8;
    leds[46] = l7;
    leds[42] = leds[36];
    leds[43] = leds[41];
    leds[44] = b6;
    leds[39] = b7;
    leds[38] = b8;
    leds[37] = b3;
    leds[36] = b2;
    leds[41] = b1;

    
    t0 = leds[45];
    t1 = leds[46];
    t2 = leds[47];
    t3 = leds[48];
    t4 = leds[49];
    t5 = leds[50];
    t6 = leds[51];
    t7 = leds[52];
    t8 = leds[53];
    
    b0 = leds[36];
    b1 = leds[37];
    b2 = leds[38];
    b3 = leds[39];
    b4 = leds[40];
    b5 = leds[41];
    b6 = leds[42];
    b7 = leds[43];
    b8 = leds[44];
    
    d0 = leds[27];
    d1 = leds[28];
    d2 = leds[29];
    d3 = leds[30];
    d4 = leds[31];
    d5 = leds[32];
    d6 = leds[33];
    d7 = leds[34];
    d8 = leds[35];
    
    l0 = leds[18];
    l1 = leds[19];
    l2 = leds[20];
    l3 = leds[21];
    l4 = leds[22];
    l5 = leds[23];
    l6 = leds[24];
    l7 = leds[25];
    l8 = leds[26];
    
    f0 = leds[9];
    f1 = leds[10];
    f2 = leds[11];
    f3 = leds[12];
    f4 = leds[13];
    f5 = leds[14];
    f6 = leds[15];
    f7 = leds[16];
    f8 = leds[17];
    
    r0 = leds[0];
    r1 = leds[1];
    r2 = leds[2];
    r3 = leds[3];
    r4 = leds[4];
    r5 = leds[5];
    r6 = leds[6];
    r7 = leds[7];
    r8 = leds[8];
     
    leds[47] = leds[24];
    leds[8]  = leds[45];
    leds[7]  = leds[46];
    leds[6]  = t2;
    leds[35] = r8;
    leds[34] = r7;
    leds[33] = r6;
    leds[26] = d8;
    leds[25] = d7;
    leds[24] = d6;
    leds[45] = l8;
    leds[46] = l7;
    leds[42] = leds[36];
    leds[43] = leds[41];
    leds[44] = b6;
    leds[39] = b7;
    leds[38] = b8;
    leds[37] = b3;
    leds[36] = b2;
    leds[41] = b1;
    
    delay(wait);
  }
  
  
  
  if(b[11]==LOW){
  
    //rotate bottom CW
    t0 = leds[45];
    t1 = leds[46];
    t2 = leds[47];
    t3 = leds[48];
    t4 = leds[49];
    t5 = leds[50];
    t6 = leds[51];
    t7 = leds[52];
    t8 = leds[53];
    
    b0 = leds[36];
    b1 = leds[37];
    b2 = leds[38];
    b3 = leds[39];
    b4 = leds[40];
    b5 = leds[41];
    b6 = leds[42];
    b7 = leds[43];
    b8 = leds[44];
    
    d0 = leds[27];
    d1 = leds[28];
    d2 = leds[29];
    d3 = leds[30];
    d4 = leds[31];
    d5 = leds[32];
    d6 = leds[33];
    d7 = leds[34];
    d8 = leds[35];
    
    l0 = leds[18];
    l1 = leds[19];
    l2 = leds[20];
    l3 = leds[21];
    l4 = leds[22];
    l5 = leds[23];
    l6 = leds[24];
    l7 = leds[25];
    l8 = leds[26];
    
    f0 = leds[9];
    f1 = leds[10];
    f2 = leds[11];
    f3 = leds[12];
    f4 = leds[13];
    f5 = leds[14];
    f6 = leds[15];
    f7 = leds[16];
    f8 = leds[17];
    
    r0 = leds[0];
    r1 = leds[1];
    r2 = leds[2];
    r3 = leds[3];
    r4 = leds[4];
    r5 = leds[5];
    r6 = leds[6];
    r7 = leds[7];
    r8 = leds[8];
    
    leds[17] = leds[20];
    leds[0]  = leds[15];
    leds[5]  = leds[16];
    leds[6]  = f8;
    leds[38] = r0;
    leds[37] = r5;
    leds[36] = r6;
    leds[26] = b2;
    leds[21] = b1;
    leds[20] = b0;
    leds[15] = l8;
    leds[16] = l3;
    leds[27] = leds[33];
    leds[28] = leds[32];
    leds[29] = d0;
    leds[30] = d1;
    leds[35] = d2;
    leds[34] = d3;
    leds[33] = d8;
    leds[32] = d7;
    
    delay(wait);
  }


  
  if(b[10] == LOW){
    
      //rotate bottom CCW
      t0 = leds[45];
      t1 = leds[46];
      t2 = leds[47];
      t3 = leds[48];
      t4 = leds[49];
      t5 = leds[50];
      t6 = leds[51];
      t7 = leds[52];
      t8 = leds[53];
      
      b0 = leds[36];
      b1 = leds[37];
      b2 = leds[38];
      b3 = leds[39];
      b4 = leds[40];
      b5 = leds[41];
      b6 = leds[42];
      b7 = leds[43];
      b8 = leds[44];
      
      d0 = leds[27];
      d1 = leds[28];
      d2 = leds[29];
      d3 = leds[30];
      d4 = leds[31];
      d5 = leds[32];
      d6 = leds[33];
      d7 = leds[34];
      d8 = leds[35];
      
      l0 = leds[18];
      l1 = leds[19];
      l2 = leds[20];
      l3 = leds[21];
      l4 = leds[22];
      l5 = leds[23];
      l6 = leds[24];
      l7 = leds[25];
      l8 = leds[26];
      
      f0 = leds[9];
      f1 = leds[10];
      f2 = leds[11];
      f3 = leds[12];
      f4 = leds[13];
      f5 = leds[14];
      f6 = leds[15];
      f7 = leds[16];
      f8 = leds[17];
      
      r0 = leds[0];
      r1 = leds[1];
      r2 = leds[2];
      r3 = leds[3];
      r4 = leds[4];
      r5 = leds[5];
      r6 = leds[6];
      r7 = leds[7];
      r8 = leds[8];
      
      leds[17] = leds[20];
      leds[0]  = leds[15];
      leds[5]  = leds[16];
      leds[6]  = f8;
      leds[38] = r0;
      leds[37] = r5;
      leds[36] = r6;
      leds[26] = b2;
      leds[21] = b1;
      leds[20] = b0;
      leds[15] = l8;
      leds[16] = l3;
      leds[27] = leds[33];
      leds[28] = leds[32];
      leds[29] = d0;
      leds[30] = d1;
      leds[35] = d2;
      leds[34] = d3;
      leds[33] = d8;
      leds[32] = d7;
      
      t0 = leds[45];
      t1 = leds[46];
      t2 = leds[47];
      t3 = leds[48];
      t4 = leds[49];
      t5 = leds[50];
      t6 = leds[51];
      t7 = leds[52];
      t8 = leds[53];
      
      b0 = leds[36];
      b1 = leds[37];
      b2 = leds[38];
      b3 = leds[39];
      b4 = leds[40];
      b5 = leds[41];
      b6 = leds[42];
      b7 = leds[43];
      b8 = leds[44];
      
      d0 = leds[27];
      d1 = leds[28];
      d2 = leds[29];
      d3 = leds[30];
      d4 = leds[31];
      d5 = leds[32];
      d6 = leds[33];
      d7 = leds[34];
      d8 = leds[35];
      
      l0 = leds[18];
      l1 = leds[19];
      l2 = leds[20];
      l3 = leds[21];
      l4 = leds[22];
      l5 = leds[23];
      l6 = leds[24];
      l7 = leds[25];
      l8 = leds[26];
      
      f0 = leds[9];
      f1 = leds[10];
      f2 = leds[11];
      f3 = leds[12];
      f4 = leds[13];
      f5 = leds[14];
      f6 = leds[15];
      f7 = leds[16];
      f8 = leds[17];
      
      r0 = leds[0];
      r1 = leds[1];
      r2 = leds[2];
      r3 = leds[3];
      r4 = leds[4];
      r5 = leds[5];
      r6 = leds[6];
      r7 = leds[7];
      r8 = leds[8];
      
      leds[17] = leds[20];
      leds[0]  = leds[15];
      leds[5]  = leds[16];
      leds[6]  = f8;
      leds[38] = r0;
      leds[37] = r5;
      leds[36] = r6;
      leds[26] = b2;
      leds[21] = b1;
      leds[20] = b0;
      leds[15] = l8;
      leds[16] = l3;
      leds[27] = leds[33];
      leds[28] = leds[32];
      leds[29] = d0;
      leds[30] = d1;
      leds[35] = d2;
      leds[34] = d3;
      leds[33] = d8;
      leds[32] = d7;
      
      t0 = leds[45];
      t1 = leds[46];
      t2 = leds[47];
      t3 = leds[48];
      t4 = leds[49];
      t5 = leds[50];
      t6 = leds[51];
      t7 = leds[52];
      t8 = leds[53];
      
      b0 = leds[36];
      b1 = leds[37];
      b2 = leds[38];
      b3 = leds[39];
      b4 = leds[40];
      b5 = leds[41];
      b6 = leds[42];
      b7 = leds[43];
      b8 = leds[44];
      
      d0 = leds[27];
      d1 = leds[28];
      d2 = leds[29];
      d3 = leds[30];
      d4 = leds[31];
      d5 = leds[32];
      d6 = leds[33];
      d7 = leds[34];
      d8 = leds[35];
      
      l0 = leds[18];
      l1 = leds[19];
      l2 = leds[20];
      l3 = leds[21];
      l4 = leds[22];
      l5 = leds[23];
      l6 = leds[24];
      l7 = leds[25];
      l8 = leds[26];
      
      f0 = leds[9];
      f1 = leds[10];
      f2 = leds[11];
      f3 = leds[12];
      f4 = leds[13];
      f5 = leds[14];
      f6 = leds[15];
      f7 = leds[16];
      f8 = leds[17];
      
      r0 = leds[0];
      r1 = leds[1];
      r2 = leds[2];
      r3 = leds[3];
      r4 = leds[4];
      r5 = leds[5];
      r6 = leds[6];
      r7 = leds[7];
      r8 = leds[8];
      
      leds[17] = leds[20];
      leds[0]  = leds[15];
      leds[5]  = leds[16];
      leds[6]  = f8;
      leds[38] = r0;
      leds[37] = r5;
      leds[36] = r6;
      leds[26] = b2;
      leds[21] = b1;
      leds[20] = b0;
      leds[15] = l8;
      leds[16] = l3;
      leds[27] = leds[33];
      leds[28] = leds[32];
      leds[29] = d0;
      leds[30] = d1;
      leds[35] = d2;
      leds[34] = d3;
      leds[33] = d8;
      leds[32] = d7;
      
      delay(wait);
  }
  
  
  if(b[9] == LOW){
      //rotate top CCW
      t0 = leds[45];
      t1 = leds[46];
      t2 = leds[47];
      t3 = leds[48];
      t4 = leds[49];
      t5 = leds[50];
      t6 = leds[51];
      t7 = leds[52];
      t8 = leds[53];
      
      b0 = leds[36];
      b1 = leds[37];
      b2 = leds[38];
      b3 = leds[39];
      b4 = leds[40];
      b5 = leds[41];
      b6 = leds[42];
      b7 = leds[43];
      b8 = leds[44];
      
      d0 = leds[27];
      d1 = leds[28];
      d2 = leds[29];
      d3 = leds[30];
      d4 = leds[31];
      d5 = leds[32];
      d6 = leds[33];
      d7 = leds[34];
      d8 = leds[35];
      
      l0 = leds[18];
      l1 = leds[19];
      l2 = leds[20];
      l3 = leds[21];
      l4 = leds[22];
      l5 = leds[23];
      l6 = leds[24];
      l7 = leds[25];
      l8 = leds[26];
      
      f0 = leds[9];
      f1 = leds[10];
      f2 = leds[11];
      f3 = leds[12];
      f4 = leds[13];
      f5 = leds[14];
      f6 = leds[15];
      f7 = leds[16];
      f8 = leds[17];
      
      r0 = leds[0];
      r1 = leds[1];
      r2 = leds[2];
      r3 = leds[3];
      r4 = leds[4];
      r5 = leds[5];
      r6 = leds[6];
      r7 = leds[7];
      r8 = leds[8];
      
      leds[11] = leds[18];
      leds[2]  = leds[9];
      leds[3]  = leds[10];
      leds[8]  = f2;
      leds[44] = r2;
      leds[43] = r3;
      leds[42] = r8;
      leds[24] = b8;
      leds[23] = b7;
      leds[18] = b6;
      leds[9]  = l6;
      leds[10] = l5;
      leds[53] = leds[51];
      leds[48] = leds[52];
      leds[47] = t8;
      leds[46] = t3;
      leds[45] = t2;
      leds[50] = t1;
      leds[51] = t0;
      leds[52] = t5;
      
      delay(wait);
  }


  
  if(b[8] == LOW){
    //rotate top CW
    
    t0 = leds[45];
    t1 = leds[46];
    t2 = leds[47];
    t3 = leds[48];
    t4 = leds[49];
    t5 = leds[50];
    t6 = leds[51];
    t7= leds[52];
    t8 = leds[53];
    
    b0 = leds[36];
    b1 = leds[37];
    b2 = leds[38];
    b3 = leds[39];
    b4 = leds[40];
    b5 = leds[41];
    b6 = leds[42];
    b7 = leds[43];
    b8 = leds[44];
    
    d0 = leds[27];
    d1 = leds[28];
    d2 = leds[29];
    d3 = leds[30];
    d4 = leds[31];
    d5 = leds[32];
    d6 = leds[33]; 
    d7 = leds[34];
    d8 = leds[35];
    
    l0 = leds[18];
    l1 = leds[19];
    l2 = leds[20];
    l3 = leds[21];
    l4 = leds[22];
    l5 = leds[23];
    l6 = leds[24];
    l7 = leds[25];
    l8 = leds[26];
    
    f0 = leds[9];
    f1 = leds[10];
    f2 = leds[11];
    f3 = leds[12];
    f4 = leds[13];
    f5 = leds[14];
    f6 = leds[15];
    f7 = leds[16];
    f8 = leds[17];
    
    r0 = leds[0];
    r1 = leds[1];
    r2 = leds[2];
    r3 = leds[3];
    r4 = leds[4];
    r5 = leds[5];
    r6 = leds[6];
    r7 = leds[7];
    r8 = leds[8];
    
    leds[11] = leds[18];
    leds[2]  = leds[9];
    leds[3]  = leds[10];
    leds[8]  = f2;
    leds[44] = r2;
    leds[43] = r3;
    leds[42] = r8;
    leds[24] = b8;
    leds[23] = b7;
    leds[18] = b6;
    leds[9]  = l6;
    leds[10] = l5;
    leds[53] = leds[51];
    leds[48] = leds[52];
    leds[47] = t8;
    leds[46] = t3;
    leds[45] = t2;
    leds[50] = t1;
    leds[51] = t0;
    leds[52] = t5;
    
    t0 = leds[45];
    t1 = leds[46];
    t2 = leds[47];
    t3 = leds[48];
    t4 = leds[49];
    t5 = leds[50];
    t6 = leds[51];
    t7 = leds[52];
    t8 = leds[53];
    
    b0 = leds[36];
    b1 = leds[37];
    b2 = leds[38];
    b3 = leds[39];
    b4 = leds[40];
    b5 = leds[41];
    b6 = leds[42];
    b7 = leds[43];
    b8 = leds[44];
    
    d0 = leds[27];
    d1 = leds[28];
    d2 = leds[29];
    d3 = leds[30];
    d4 = leds[31];
    d5 = leds[32];
    d6 = leds[33];
    d7 = leds[34];
    d8 = leds[35];
    
    l0 = leds[18];
    l1 = leds[19];
    l2 = leds[20];
    l3 = leds[21];
    l4 = leds[22];
    l5 = leds[23];
    l6 = leds[24];
    l7 = leds[25];
    l8 = leds[26];
    
    f0 = leds[9];
    f1 = leds[10];
    f2 = leds[11];
    f3 = leds[12];
    f4 = leds[13];
    f5 = leds[14];
    f6 = leds[15];
    f7 = leds[16];
    f8 = leds[17];
    
    r0 = leds[0];
    r1 = leds[1];
    r2 = leds[2];
    r3 = leds[3];
    r4 = leds[4];
    r5 = leds[5];
    r6 = leds[6];
    r7 = leds[7];
    r8 = leds[8];
    
    leds[11] = leds[18];
    leds[2]  = leds[9];
    leds[3]  = leds[10];
    leds[8]  = f2;
    leds[44] = r2;
    leds[43] = r3;
    leds[42] = r8;
    leds[24] = b8;
    leds[23] = b7;
    leds[18] = b6;
    leds[9]  = l6;
    leds[10] = l5;
    leds[53] = leds[51];
    leds[48] = leds[52];
    leds[47] = t8;
    leds[46] = t3;
    leds[45] = t2;
    leds[50] = t1;
    leds[51] = t0;
    leds[52] = t5;
    
    t0 = leds[45];
    t1 = leds[46];
    t2 = leds[47];
    t3 = leds[48];
    t4 = leds[49];
    t5 = leds[50];
    t6 = leds[51];
    t7 = leds[52];
    t8 = leds[53];
    
    b0 = leds[36];
    b1 = leds[37];
    b2 = leds[38];
    b3 = leds[39];
    b4 = leds[40];
    b5 = leds[41];
    b6 = leds[42];
    b7 = leds[43];
    b8 = leds[44];
    
    d0 = leds[27];
    d1 = leds[28];
    d2 = leds[29];
    d3 = leds[30];
    d4 = leds[31];
    d5 = leds[32];
    d6 = leds[33];
    d7 = leds[34];
    d8 = leds[35];
    
    l0 = leds[18];
    l1 = leds[19];
    l2 = leds[20];
    l3 = leds[21];
    l4 = leds[22];
    l5 = leds[23];
    l6 = leds[24];
    l7 = leds[25];
    l8 = leds[26];
    
    f0 = leds[9];
    f1 = leds[10];
    f2 = leds[11];
    f3 = leds[12];
    f4 = leds[13];
    f5 = leds[14];
    f6 = leds[15];
    f7 = leds[16];
    f8 = leds[17];
    
    r0 = leds[0];
    r1 = leds[1];
    r2 = leds[2];
    r3 = leds[3];
    r4 = leds[4];
    r5 = leds[5];
    r6 = leds[6];
    r7 = leds[7];
    r8 = leds[8];
    
    leds[11] = leds[18];
    leds[2]  = leds[9];
    leds[3]  = leds[10];
    leds[8]  = f2;
    leds[44] = r2;
    leds[43] = r3;
    leds[42] = r8;
    leds[24] = b8;
    leds[23] = b7;
    leds[18] = b6;
    leds[9]  = l6;
    leds[10] = l5;
    leds[53] = leds[51];
    leds[48] = leds[52];
    leds[47] = t8;
    leds[46] = t3;
    leds[45] = t2;
    leds[50] = t1;
    leds[51] = t0;
    leds[52] = t5;
    
    delay(wait);
  }
}
