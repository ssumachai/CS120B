/*         Your Name & E-mail:  Sumachai Suksanguan (ssuks001@ucr.edu)
*          Lab Section:    021 
 *         Assignment:    Lab 6  Exercise 2
 *         Exercise Description: Concurrent Light Show
 *        
 *         I acknowledge all content contained herein, excluding template or example code, is my own original work.
 *
 *         Demo Link: https://youtu.be/hANJL1DDa2s
 */
typedef struct task {
  int state;
  unsigned long period;
  unsigned long elapsedTime;
  int (*TickFct)(int);
    
} task;

const int red1 = 5;
const int yellow1 = 6;
const int green1 = 7;
const int blue1 = 8;
const int blue2 = 10;
const int green2 = 11;
const int yellow2 = 12;
const int red2 = 13;

const unsigned short tasksNum = 2;
task tasks[tasksNum];

enum S1_States {S1_start, S1_LED1, S1_LED2, S1_LED3, S1_LED4};
int Tick_Show1(int state){
    switch(state){
        case S1_start:
            resetLights();
            state = S1_LED1;
            break;
        case S1_LED1:
            state = S1_LED2;
            digitalWrite(red1, LOW);
            break;
        case S1_LED2:
            state = S1_LED3;
            digitalWrite(yellow1, LOW);
            break;
        case S1_LED3:
            state = S1_LED4;
            digitalWrite(green1, LOW);
            break;
        case S1_LED4:
            state = S1_LED1;
            digitalWrite(blue1, LOW);
            break;
        default:
            break;
    }
    switch(state){
        case S1_LED1:
            digitalWrite(red1, HIGH);
            break;
        case S1_LED2:
            digitalWrite(yellow1, HIGH);
            break;
        case S1_LED3:
            digitalWrite(green1, HIGH);
            break;
        case S1_LED4:
            digitalWrite(blue1, HIGH);
            break;
        default:
            break;
    }
    return state;
}

enum S2_States {S2_start, S2_LED1, S2_LED2, S2_LED3, S2_LED4};
int Tick_Show2(int state){
    switch(state){
        case S2_start:
            resetLights();
            state = S2_LED1;
            break;
        case S2_LED1:
            state = S2_LED2;
            digitalWrite(blue2, LOW);
            break;
        case S2_LED2:
            state = S2_LED3;
            digitalWrite(green2, LOW);
            break;
        case S2_LED3:
            state = S2_LED4;
            digitalWrite(yellow2, LOW);
            break;
        case S2_LED4:
            state = S2_LED1;
            digitalWrite(red2, LOW);
            break;
        default:
            break;
    }
    switch(state){
        case S2_LED1:
            digitalWrite(blue2, HIGH);
            break;
        case S2_LED2:
            digitalWrite(green2, HIGH);
            break;
        case S2_LED3:
            digitalWrite(yellow2, HIGH);
            break;
        case S2_LED4:
            digitalWrite(red2, HIGH);
            break;
        default:
            break;
    }
    return state;
}

void setup(){
    pinMode(red1, OUTPUT);
    pinMode(yellow1, OUTPUT);
    pinMode(green1, OUTPUT);
    pinMode(blue1, OUTPUT);
    pinMode(blue2, OUTPUT);
    pinMode(green2, OUTPUT);
    pinMode(yellow2, OUTPUT);
    pinMode(red2, OUTPUT);
    
    unsigned char i = 0;
    tasks[i].state = S1_start;
    tasks[i].period = 1000;
    tasks[i].elapsedTime = 0;
    tasks[i].TickFct = &Tick_Show1;
    ++i;
    tasks[i].state = S2_start;
    tasks[i].period = 500;
    tasks[i].elapsedTime = 0;
    tasks[i].TickFct = &Tick_Show2;

}

void resetLights(){
    digitalWrite(red1, LOW);
    digitalWrite(red2, LOW);
    digitalWrite(yellow1, LOW);
    digitalWrite(yellow2, LOW);
    digitalWrite(blue1, LOW);
    digitalWrite(blue2, LOW);
    digitalWrite(green1, LOW);
    digitalWrite(green2, LOW);
}

void loop(){
    unsigned char i;
    for(i = 0; i < tasksNum; ++i){
        if( (millis() - tasks[i].elapsedTime) >= tasks[i].period){
            tasks[i].state = tasks[i].TickFct(tasks[i].state);
            tasks[i].elapsedTime = millis();
        }
    }
    delay(500);
}