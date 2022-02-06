/*         Your Name & E-mail:  Sumachai Suksanguan (ssuks001@ucr.edu)
*          Lab Section:    021 
 *         Assignment:    Lab 5  Exercise 4
 *         Exercise Description: Photoresistor ON/OFF
 *        
 *         I acknowledge all content contained herein, excluding template or example code, is my own original work.
 *
 *         Demo Link: https://youtu.be/cz0iiohh_Lc
 */
#include <Servo.h>

const int LED = 2;
const int PR = 14;

int readValue = 0;

//ADC calculated from ambient lighting in room
const int min_adc = 20;
const int max_adc = 700;



enum States {start, PLAY} state;

void setup()
{
    pinMode(LED, OUTPUT);
    pinMode(PR, INPUT);
    Serial.begin(9600);
}

void Tick(){
    readValue = analogRead(PR);


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
        case PLAY:
            if(readValue >= max_adc/2){
                digitalWrite(LED, HIGH);
            }
            else{
                digitalWrite(LED, LOW);
            }
            break;
        default:
            break;
    }
}

void loop(){
    delay(100);
    Tick();
    Serial.println(analogRead(PR));
}