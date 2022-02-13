/*         Your Name & E-mail:  Sumachai Suksanguan (ssuks001@ucr.edu)
*          Lab Section:    021 
 *         Assignment:    Lab 6  Exercise 4
 *         Exercise Description: Deadbolt Lock with Servo and Photoresistor
 *        
 *         I acknowledge all content contained herein, excluding template or example code, is my own original work.
 *
 *         Demo Link: https://youtu.be/lc2d1SkoVnA
 */
#include <Servo.h>

typedef struct task {
  int state;
  unsigned long period;
  unsigned long elapsedTime;
  int (*TickFct)(int);
    
} task;

const int button1 = 2;
const int button2 = 3;
const int button3 = 4;
const int button4 = 5;
const int button5 = 6;
const int PR = 14;
const int LED = 7;

int readValue = 0;

const int ambient = 60;

Servo deadbolt;
bool locked = true;

const unsigned short tasksNum = 2;
task tasks[tasksNum];

enum SERVOLOCK {start, LOCK, CORRECT1_PRESS, CORRECT1_RELEASE, CORRECT2_PRESS, CORRECT2_RELEASE, CORRECT3_PRESS,
            CORRECT3_RELEASE, CORRECT4_PRESS, CORRECT4_RELEASE, CORRECT5_UNLOCK};
int Tick(int state){
    int a = digitalRead(button1);
    int b = digitalRead(button2);
    int c = digitalRead(button3);
    int d = digitalRead(button4);
    int e = digitalRead(button5);

    switch(state){
        case start:
            deadbolt.write(180);
            state = LOCK;
            break;
        case LOCK:
            if((a == LOW) && (b == LOW) && (c == HIGH) && (d == LOW) && (e == LOW)){
                state = CORRECT1_PRESS;
            }
            else{
                state = LOCK;
            }
            break;
        case CORRECT1_PRESS:
            if((a == LOW) && (b == LOW) && (c == LOW) && (d == LOW) && (e == LOW)){
                state = CORRECT1_RELEASE;
            }
            else if((a == LOW) && (b == LOW) && (c == HIGH) && (d == LOW) && (e == LOW)){
                state = CORRECT1_PRESS;
            }
            else{
                state = LOCK;
            }
            break;
        case CORRECT1_RELEASE:
            if((a == LOW) && (b == LOW) && (c == LOW) && (d == LOW) && (e == LOW)){
                state = CORRECT1_RELEASE;
            }
            else if((a == HIGH) && (b == LOW) && (c == LOW) && (d == LOW) && (e == LOW)){
                state = CORRECT2_PRESS;
            }
            else{
                state = LOCK;
            }
            break;
        case CORRECT2_PRESS:
            if((a == LOW) && (b == LOW) && (c == LOW) && (d == LOW) && (e == LOW)){
                state = CORRECT2_RELEASE;
            }
            else if((a == HIGH) && (b == LOW) && (c == LOW) && (d == LOW) && (e == LOW)){
                state = CORRECT2_PRESS;
            }
            else{
                state = LOCK;
            }
            break;
        case CORRECT2_RELEASE:
            if((a == LOW) && (b == LOW) && (c == LOW) && (d == LOW) && (e == LOW)){
                state = CORRECT2_RELEASE;
            }
            else if((a == LOW) && (b == HIGH) && (c == LOW) && (d == LOW) && (e == LOW)){
                state = CORRECT3_PRESS;
            }
            else{
                state = LOCK;
            }
            break;
        case CORRECT3_PRESS:
            if((a == LOW) && (b == LOW) && (c == LOW) && (d == LOW) && (e == LOW)){
                state = CORRECT3_RELEASE;
            }
            else if((a == LOW) && (b == HIGH) && (c == LOW) && (d == LOW) && (e == LOW)){
                state = CORRECT3_PRESS;
            }
            else{
                state = LOCK;
            }
            break;
        case CORRECT3_RELEASE:
            if((a == LOW) && (b == LOW) && (c == LOW) && (d == LOW) && (e == LOW)){
                state = CORRECT3_RELEASE;
            }
            else if((a == LOW) && (b == LOW) && (c == LOW) && (d == HIGH) && (e == LOW)){
                state = CORRECT4_PRESS;
            }
            else{
                state = LOCK;
            }
            break;
        case CORRECT4_PRESS:
            if((a == LOW) && (b == LOW) && (c == LOW) && (d == LOW) && (e == LOW)){
                state = CORRECT4_RELEASE;
            }
            else if((a == LOW) && (b == LOW) && (c == LOW) && (d == HIGH) && (e == LOW)){
                state = CORRECT4_PRESS;
            }
            else{
                state = LOCK;
            }
            break;
        case CORRECT4_RELEASE:
            if((a == LOW) && (b == LOW) && (c == LOW) && (d == LOW) && (e == LOW)){
                state = CORRECT4_RELEASE;
            }
            else if((a == LOW) && (b == LOW) && (c == LOW) && (d == LOW) && (e == HIGH)){
                state = CORRECT5_UNLOCK;
            }
            else{
                state = LOCK;
            }
            break;
        case CORRECT5_UNLOCK:
            state = LOCK;
            break;
        default:
            state = start;
            break;
    }

    switch(state){
        case CORRECT5_UNLOCK:
            if(locked){
                deadbolt.write(0);
                locked = false;
            }
            else{
                deadbolt.write(180);
                locked = true;
            }
            break;
        default:
            break;
    }
    return state;
}

enum PR_States {PR_start, LIGHT};
int Tick_PR(int state){
    readValue = analogRead(PR);

    switch(state){
        case PR_start:
            state = LIGHT;
            break;
        case LIGHT:
            state = LIGHT;
            break;
        default:
            state = start;
            break;
    }
    switch(state){
        case LIGHT:
            if(readValue < 30){
              digitalWrite(LED, HIGH);
            }
            else{
              digitalWrite(LED, LOW);
            }
            break;
        default:
            break;
    }
    return state;
}


void setup(){
    deadbolt.attach(12);
    pinMode(button1, INPUT);
    pinMode(button2, INPUT);
    pinMode(button3, INPUT);
    pinMode(button4, INPUT);
    pinMode(LED, OUTPUT);
    pinMode(PR, INPUT);
    Serial.begin(9600);

    unsigned char i = 0;
    tasks[i].state = start;
    tasks[i].period = 100;
    tasks[i].elapsedTime = 0;
    tasks[i].TickFct = &Tick;
    ++i;
    tasks[i].state = PR_start;
    tasks[i].period = 100;
    tasks[i].period = 0;
    tasks[i].TickFct = &Tick_PR;
}

void loop(){
    unsigned char i;
    for(i = 0; i < tasksNum; ++i){
        if( (millis() - tasks[i].elapsedTime) >= tasks[i].period){
            tasks[i].state = tasks[i].TickFct(tasks[i].state);
            tasks[i].elapsedTime = millis();
        }
    }
    delay(100);
    Serial.println(analogRead(PR));
}