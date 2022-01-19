/*         Your Name & E-mail:  Sumachai Suksanguan (ssuks001@ucr.edu)

*          Lab Section:		021	

 *         Assignment: 		Lab 3  Exercise 4

 *         Exercise Description: Door Lock State Machine

 *        

 *         I acknowledge all content contained herein, excluding template or example code, is my own original work.

 *

 *         Demo Link: https://youtu.be/tz_dbJUgJmE

 */


// C++ code
//

enum States {start, LOCK, POUND_PRESS, POUND_RELEASE, Y_UNLOCK, INSIDE_LOCK} state;

const int a0 = 14;
const int a1 = 15;
const int a2 = 16;
const int a4 = 18;
const int b2 = 4;

void setup(){
    pinMode(a0, INPUT);
    pinMode(a1, INPUT);
    pinMode(a2, INPUT);
    pinMode(a4, INPUT);
    pinMode(b2, OUTPUT);
}

void Tick(){
    int x = digitalRead(a0);
    int y = digitalRead(a1);
    int pound = digitalRead(a2);
    int inside = digitalRead(a4);

    switch(state){
        case start:
            digitalWrite(b2, LOW);
            state = LOCK;
            break;
        case LOCK:
            if((x == LOW) && (y == LOW) && (pound == HIGH) && (inside == LOW)){
                state = POUND_PRESS;
            }
            else if(inside == LOW){
                state = INSIDE_LOCK;
            }
            else{
                state = LOCK;
            }
            break;
        case POUND_PRESS:
            if((x == LOW) && (y == LOW) && (pound == LOW) && (inside == LOW)){
                state = POUND_RELEASE;
            }
            else if((x == LOW) && (y == LOW) && (pound == HIGH) && (inside == LOW)){
                state = POUND_PRESS;
            }
            else if(inside == HIGH){
                state = INSIDE_LOCK;
            }
            else{
                state = LOCK;
            }
            break;
        case POUND_RELEASE:
            if((x == LOW) && (y == LOW) && (pound == LOW) && (inside == LOW)){
                state = POUND_RELEASE;
            }
            else if((x == LOW) && (y == HIGH) && (pound == LOW) && (inside == LOW)){
                state = Y_UNLOCK;
            }
            else if(inside == HIGH){
                state = INSIDE_LOCK;
            }
            else{
                state = LOCK;
            }
            break;
        case Y_UNLOCK:
            if(inside == HIGH){
                state = INSIDE_LOCK;
            }
            else{
                state = Y_UNLOCK;
            }
            break;
        case INSIDE_LOCK:
            state = LOCK;
            break;
        default:
            state = start;
            break;
    }

    switch(state){
        case Y_UNLOCK:
            digitalWrite(b2, HIGH);
            break;
        case INSIDE_LOCK:
            digitalWrite(b2, LOW);
            break;
        default:
            break;
    }
}

void loop(){
    Tick();
}