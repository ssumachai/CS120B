/*         Your Name & E-mail:  Sumachai Suksanguan (ssuks001@ucr.edu)
*          Lab Section:    021 
 *         Assignment:    Lab 4  Exercise 1
 *         Exercise Description: Three LED Blink
 *        
 *         I acknowledge all content contained herein, excluding template or example code, is my own original work.
 *
 *         Demo Link: https://youtu.be/SqzxJ1wHKzs
 */
 
enum States {start, light1, light2, light3} state;

const int b0 = 2;
const int b1 = 3;
const int b2 = 4;



void setup()
{
    pinMode(b0, OUTPUT);
    pinMode(b1, OUTPUT);
    pinMode(b2, OUTPUT);
}

void Tick(){
    switch(state){
        case start:
            digitalWrite(b0, LOW);
            digitalWrite(b1, LOW);
            digitalWrite(b2, LOW);
            state = light1;
            break;
        case light1:
            state = light2;
            digitalWrite(b0, LOW);
            break;
        case light2:
            state = light3;
            digitalWrite(b1, LOW);
            break;
        case light3:
            state = light1;
            digitalWrite(b2, LOW);
            break;
        default:
            state = start;
            break;
    }

    switch(state){
        case light1:
            digitalWrite(b0, HIGH);
            break;
        case light2:
            digitalWrite(b1, HIGH);
            break;
        case light3:
            digitalWrite(b2, HIGH);
            break;
        default:
            break;
    }
}

void loop(){
    Tick();
    delay(1000);
}