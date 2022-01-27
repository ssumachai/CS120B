/*         Your Name & E-mail:  Sumachai Suksanguan (ssuks001@ucr.edu)
*          Lab Section:    021 
 *         Assignment:    Lab 4  Exercise 4
 *         Exercise Description: Random LED Game
 *        
 *         I acknowledge all content contained herein, excluding template or example code, is my own original work.
 *
 *         Demo Link: https://youtu.be/7u9LPISHgnw
 */
 

#include <stdlib.h>
#include <time.h>

 const int a0 = 14;
 const int a1 = 15;
 const int a2 = 16;
 const int a3 = 17;
 const int b0 = 2;
 const int b1 = 3;
 const int b2 = 4;
 const int b3 = 5;
 const int b4 = 6;

 int timer, starter;

 enum States {start, RANDOM, START0, START1, START2, START3, LIGHT0, LIGHT1, LIGHT2, LIGHT3, LOSE} state;
void setup(){
    pinMode(a0, INPUT);
    pinMode(a1, INPUT);
    pinMode(a2, INPUT);
    pinMode(a3, INPUT);
    pinMode(b0, OUTPUT);
    pinMode(b1, OUTPUT);
    pinMode(b2, OUTPUT);
    pinMode(b3, OUTPUT);
    pinMode(b4, OUTPUT);
}

void Tick(){
    int button1 = digitalRead(a0);
    int button2 = digitalRead(a1);
    int button3 = digitalRead(a2);
    int button4 = digitalRead(a3);

    switch(state){
        case start:
            srand(time(NULL));
            timer = 0;
            starter = rand() % 4;
            state = RANDOM;
            break;
        case RANDOM:
            if(starter == 0){state = START0;}
            else if(starter == 1){state = START1;}
            else if(starter == 2){state = START2;}
            else if(starter == 3){state = START3;}
            break;
        case START0:
            if(timer <= 5 && (button1 == HIGH)){
                digitalWrite(b0, LOW);
                state = LIGHT1;
                timer = 0;
            }
            else if(timer <= 5 && (button1 == LOW)){
                state = START0;
            }
            else if(timer > 5){
                digitalWrite(b0, LOW);
                state = RANDOM;
                timer = 0;
            }
            break;
        case START1:
            if(timer <= 5 && (button2 == HIGH)){
                digitalWrite(b1, LOW);
                state = LIGHT2;
                timer = 0;
            }
            else if(timer <= 5 && (button1 == LOW)){
                state = START1;
            }
            else if(timer > 5){
                digitalWrite(b1, LOW);
                state = RANDOM;
                timer = 0;
            }
            break;
        case START2:
            if(timer <= 5 && (button3 == HIGH)){
                digitalWrite(b2, LOW);
                state = LIGHT3;
                timer = 0;
            }
            else if(timer <= 5 && (button3 == LOW)){
                state = START2;
            }
            else if(timer > 5){
                digitalWrite(b2, LOW);
                state = RANDOM;
                timer = 0;
            }
            break;
        case START3:
            if(timer <= 5 && (button4 == HIGH)){
                digitalWrite(b3, LOW);
                state = LIGHT0;
                timer = 0;
            }
            else if(timer <= 5 && (button4 == LOW)){
                state = START3;
            }
            else if(timer > 5){
                digitalWrite(b3, LOW);
                state = RANDOM;
                timer = 0;
            }
            break;
        case LIGHT0:
            if(timer <= 5 && (button1 == LOW)){
                state = LIGHT0;
            }
            else if(timer <= 5 && (button1 == HIGH)){
                digitalWrite(b0, LOW);
                state = LIGHT1;
                timer = 0;
            }
            else if(timer > 5){
                digitalWrite(b0, LOW);
                state = LOSE;
            }
            break;
        case LIGHT1:
            if(timer <= 5 && (button2 == LOW)){
                state = LIGHT1;
            }
            else if(timer <= 5 && (button2 == HIGH)){
                digitalWrite(b1, LOW);
                state = LIGHT2;
                timer = 0;
            }
            else if(timer > 5){
                digitalWrite(b1, LOW);
                state = LOSE;
            }
            break;
        case LIGHT2:
            if(timer <= 5 && (button3 == LOW)){
                state = LIGHT2;
            }
            else if(timer <= 5 && (button3 == HIGH)){
                digitalWrite(b2, LOW);
                state = LIGHT3;
                timer = 0;
            }
            else if(timer > 5){
                digitalWrite(b2, LOW);
                state = LOSE;
            }
            break;
        case LIGHT3:
            if(timer <= 5 && (button4 == LOW)){
                state = LIGHT3;
            }
            else if(timer <= 5 && (button4 == HIGH)){
                digitalWrite(b3, LOW);
                state = LIGHT0;
                timer = 0;
            }
            else if(timer > 5){
                digitalWrite(b3, LOW);
                state = LOSE;
            }
            break;
        case LOSE:
            state = LOSE;
            break;
        default:
            state = start;
            break;    
    }

    switch(state){
        case RANDOM:
            if(timer % 10 == 0){
                starter = rand() % 4;
            }
            timer++;
            break;
        case START0:
        case LIGHT0:
            digitalWrite(b0, HIGH);
            timer++;
            break;
        case START1:
        case LIGHT1:
            digitalWrite(b1, HIGH);
            timer++;
            break;
        case START2:
        case LIGHT2:
            digitalWrite(b2, HIGH);
            timer++;
            break;
        case START3:
        case LIGHT3:
            digitalWrite(b3, HIGH);
            timer++;
            break;
        case LOSE:
            digitalWrite(b4, HIGH);
            break;
        default:
            break;
    }

}

void loop(){
    Tick();
    delay(100);
}