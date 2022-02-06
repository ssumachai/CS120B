/*         Your Name & E-mail:  Sumachai Suksanguan (ssuks001@ucr.edu)
*          Lab Section:    021 
 *         Assignment:    Lab 5  Exercise 3
 *         Exercise Description: Photoresistor Light Display
 *        
 *         I acknowledge all content contained herein, excluding template or example code, is my own original work.
 *
 *         Demo Link: https://youtu.be/GWMBw14H4nE
 */
#include <Servo.h>

const int b0 = 2;
const int b1 = 3;
const int b2 = 4;
const int b3 = 5;
const int b4 = 6;
const int b5 = 7;
const int b6 = 8;
const int b7 = 9;
const int PR = 14;

int readValue = 0;
int ledValue = 0;
int mappedValue = 0;
int lightArray[9] = {0, 1, 3, 7, 15, 31, 63, 127, 255};

const int min_adc = 20;
const int max_adc = 800;


enum States {start, PLAY} state;

void setup()
{
  pinMode(PR, INPUT);
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

void resetB()
{
  digitalWrite(b0,LOW);
  digitalWrite(b1,LOW);
  digitalWrite(b2,LOW);
  digitalWrite(b3,LOW);
  digitalWrite(b4,LOW);
  digitalWrite(b5,LOW);
  digitalWrite(b6,LOW);
  digitalWrite(b7,LOW);
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

void Tick(){
    readValue = analogRead(PR);
    ledValue = map(readValue, min_adc, max_adc, 0, 255);
    mappedValue = map(ledValue, 0, 255, 0, 9);

    switch(state){
        case start:
            state = PLAY;
            break;
        case PLAY:
            state = PLAY;
            break;
        default:
            state = start;
    }

    switch(state){
        default:
            break;
    }
}

void loop(){
    resetB();
    writeToB(lightArray[mappedValue]);
    delay(100);
    Tick();
    Serial.println(analogRead(PR));
}