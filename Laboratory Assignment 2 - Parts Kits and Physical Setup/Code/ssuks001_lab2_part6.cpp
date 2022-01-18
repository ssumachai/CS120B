/*         Your Name & E-mail:  Sumachai Suksanguan (ssuks001@ucr.edu)

*          Lab Section:    021 

 *         Assignment:    Lab 2  Exercise 6

 *         Exercise Description: Gas Meter

 *        

 *         I acknowledge all content contained herein, excluding template or example code, is my own original work.

 *

 *         Demo Link: https://youtu.be/v8NvGKm1X7U

 */


// C++ code
//

const int b0 = 2;
const int b1 = 3;
const int b2 = 4;
const int b3 = 5;
const int b4 = 6;
const int b5 = 7;
const int b6 = 8;
const int b7 = 9;
int a = 0x00;
int a0, a1, a2, a3, a4, a5, a6, a7;
void setup()
{
  pinMode(b0, OUTPUT);
  pinMode(b1, OUTPUT);
  pinMode(b2, OUTPUT);
  pinMode(b3, OUTPUT);
  pinMode(b4, OUTPUT);
  pinMode(b5, OUTPUT);
  pinMode(b6, OUTPUT);
  pinMode(b7, OUTPUT);
  Serial.begin(9600);
}

void readData()
{
  if(Serial.available()){
    a = Serial.parseInt();
  }
  a7 = a >> 7;
  a6 = (a >> 6) & 0x01;
  a5 = (a >> 5) & 0x01;
  a4 = (a >> 4) & 0x01;
  a3 = (a >> 3) & 0x01;
  a2 = (a >> 2) & 0x01;
  a1 = (a >> 1) & 0x01;
  a0 = (a >> 0) & 0x01;
}

void resetB()
{
  digitalWrite(b7,LOW);
  digitalWrite(b6,LOW);
  digitalWrite(b5,LOW);
  digitalWrite(b4,LOW);
  digitalWrite(b3,LOW);
  digitalWrite(b2,LOW);
  digitalWrite(b1,LOW);
  digitalWrite(b0,LOW);
}

void writeToB(unsigned char temp)
{
  if ((temp>>7) & 0x01){digitalWrite(b7,HIGH);}
  if ((temp>>6) & 0x01){digitalWrite(b6,HIGH);}
  if ((temp>>5) & 0x01){digitalWrite(b5,HIGH);}
  if ((temp>>4) & 0x01){digitalWrite(b4,HIGH);}
  if ((temp>>3) & 0x01){digitalWrite(b3,HIGH);}
  if ((temp>>2) & 0x01){digitalWrite(b2,HIGH);}
  if ((temp>>1) & 0x01){digitalWrite(b1,HIGH);}
  if (temp & 0x01){digitalWrite(b0,HIGH);}
}

void loop()
{
  readData();
  resetB();
  if(a == 0){
      writeToB(64);
  }
  else if(a >= 1 && a <= 2){
      writeToB(96);                 //Light Port 7 + Fuel, 0x0110 0000 = 96
  }
  else if(a >= 3 && a <= 4){
      writeToB(112);                 //Light Port 7 and 6 + Fuel, 0x0111 0000 = 112
  }
  else if(a >= 5 && a <= 6){        //Light Port 7 through 5, 0x0011 1000 = 56
      writeToB(56);
  }
  else if(a >= 7 && a <= 9){        //Light Port 7 through 4, 0x0011 1100 = 60 
      writeToB(60);
  }
  else if(a >= 10 && a <= 12){      //Light Port 7 through 3, 0x0011 1110 = 62
        writeToB(62);
  }
  else if(a >= 13 && a <= 15){      //Light Port 7 through 2, 0x0011 1111 = 63
        writeToB(63);
  }
  delay(200);
}