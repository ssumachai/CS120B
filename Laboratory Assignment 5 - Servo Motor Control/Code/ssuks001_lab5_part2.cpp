/*         Your Name & E-mail:  Sumachai Suksanguan (ssuks001@ucr.edu)
*          Lab Section:    021 
 *         Assignment:    Lab 5  Exercise 2
 *         Exercise Description: Potentiometer Servo Motor
 *        
 *         I acknowledge all content contained herein, excluding template or example code, is my own original work.
 *
 *         Demo Link: https://youtu.be/WRPtMIhux-k
 */

#include <Servo.h>

enum States {start, MOVE} state;

Servo my_boy;

const int knob = 14;
int readValue, moveValue = 0;

void setup()
{
    my_boy.attach(3);
    pinMode(knob, INPUT);
}

void Tick(){
    readValue = analogRead(knob);
    moveValue = map(readValue, 0, 1023, 0, 180);
    
    switch(state){
        case start:
            state = MOVE;
            break;
        case MOVE:
            state = MOVE;
            break;
        default:
            state = start;
            break;
    }
    switch(state){
        default:
            break;
    }
}

void loop(){
    my_boy.write(moveValue);
    delay(100);
    Tick();
}