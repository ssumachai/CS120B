/*         Your Name & E-mail:  Sumachai Suksanguan (ssuks001@ucr.edu)
*          Lab Section:    021 
 *         Assignment:    Lab 4  Exercise 2
 *         Exercise Description: Simple Light Game
 *        
 *         I acknowledge all content contained herein, excluding template or example code, is my own original work.
 *
 *         Demo Link: https://youtu.be/zN6ZUek1P_0
 */

enum States {start, light1, light2, light3, win_wait, win_release, reset} state;

const int b2 = 4;
const int b3 = 5;
const int b4 = 6;
const int a0 = 14;

void setup(){
    pinMode(b2, OUTPUT);
    pinMode(b3, OUTPUT);
    pinMode(b4, OUTPUT);
    pinMode(a0, INPUT);
}

void Tick(){
    int button = digitalRead(a0);

    switch(state){
        case start:
            digitalWrite(b2, LOW);
            digitalWrite(b3, LOW);
            digitalWrite(b4, LOW);
            state = light1;
            break;
        case light1:
            state = light2;
            digitalWrite(b2, LOW);
            break;
        case light2:
            if(button == HIGH){
                state = win_wait;
            }
            else{
                state = light3;
                digitalWrite(b3, LOW);
            }
            break;
        case light3:
            state = light1;
            digitalWrite(b4, LOW);
            break;
        case win_wait:
            state = (button == HIGH) ? win_wait : win_release;
            break;
        case win_release:
            state = (button == HIGH) ? reset : win_release;
            break;
        case reset:
            state = (button == HIGH) ? reset : light1;
            break;
        default:
            state = start;
            break;
    }

    switch(state){
        case light1:
            digitalWrite(b2, HIGH);
            break;
        case light2:
            digitalWrite(b3, HIGH);
            break;
        case light3:
            digitalWrite(b4, HIGH);
            break;
        case reset:
            digitalWrite(b2, LOW);
            digitalWrite(b3, LOW);
            digitalWrite(b4, LOW);
            break;
        default:
            break;
    }
}
void loop(){
    Tick();
    delay(300);
}