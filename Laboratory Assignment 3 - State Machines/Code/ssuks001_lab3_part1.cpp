/*         Your Name & E-mail:  Sumachai Suksanguan (ssuks001@ucr.edu)

*          Lab Section:		021	

 *         Assignment: 		Lab 3  Exercise 1

 *         Exercise Description: State Machine Button Switch

 *        

 *         I acknowledge all content contained herein, excluding template or example code, is my own original work.

 *

 *         Demo Link: https://youtu.be/zEqGlgngHXA

 */


// C++ code
//

enum States {start, off_release, on_press, on_release, off_press} state;

const int b0 = 2;
const int b1 = 3;
const int b2 = 4;
const int b3 = 5;
const int b4 = 6;
const int b5 = 7;
const int b6 = 8;
const int b7 = 9;
const int a0 = 14;

void setup()
{
  pinMode(a0, INPUT);
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

void light1(){
    digitalWrite(b0, HIGH);
    digitalWrite(b1, LOW);
}

void light2(){
    digitalWrite(b0, LOW);
    digitalWrite(b1, HIGH);
}

void Tick(){
    int button = digitalRead(a0);
    
    switch(state){
        case start:
            light1();
            state = off_release;
        case off_release:
            if(button == HIGH){
                state = on_press;
                light2();
            }
            else{
                state = off_release;
            }
            break;
        case on_press:
            state = (button == HIGH) ? on_press : on_release;
            break;
        case on_release:
            if(button == HIGH){
                state = off_press;
                light1();
            }
            break;
        case off_press:
            state = (button  == HIGH) ? off_press : off_release;
            break;
        default:
            state = start;
    }
}

void loop(){
    Tick();
}