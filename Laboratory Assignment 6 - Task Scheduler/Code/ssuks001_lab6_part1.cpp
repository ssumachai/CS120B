/*         Your Name & E-mail:  Sumachai Suksanguan (ssuks001@ucr.edu)
*          Lab Section:    021 
 *         Assignment:    Lab 6  Exercise 1
 *         Exercise Description: Task Scheduling LED
 *        
 *         I acknowledge all content contained herein, excluding template or example code, is my own original work.
 *
 *         Demo Link: https://youtu.be/4kyDyztsxXc
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
const int white = 9;
const int blue2 = 10;
const int green2 = 11;
const int yellow2 = 12;
const int red2 = 13;

const unsigned short tasksNum = 1;
task tasks[tasksNum];

enum light_states {start, RED, YELLOW, GREEN, BLUE, ALL};
int Tick_lightStates(int state){
    
    switch(state){
        case start: 
            resetLights();
            state = RED;
            break;
        case RED:
            state = YELLOW;
            break;
        case YELLOW:
            state = GREEN;
            break;
        case GREEN:
            state = BLUE;
            break;
        case BLUE:
            state = ALL;
            break;
        case ALL:
            state = RED;
            break;
        default:
            state = start;
            break;
    }

    switch(state){
        case RED:
            setRed();
            break;
        case YELLOW:
            setYellow();
            break;
        case GREEN:
            setGreen();
            break;
        case BLUE:
            setBlue();
            break;
        case ALL:
            AllOn();
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
    pinMode(white, OUTPUT);
    pinMode(blue2, OUTPUT);
    pinMode(green2, OUTPUT);
    pinMode(yellow2, OUTPUT);
    pinMode(red2, OUTPUT);
    
    unsigned char i = 0;
    tasks[i].state = start;
    tasks[i].period = 500;
    tasks[i].elapsedTime = 0;
    tasks[i].TickFct = &Tick_lightStates;
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
    digitalWrite(white, LOW);
}

void setRed(){
    digitalWrite(red1, HIGH);
    digitalWrite(red2, HIGH);
    digitalWrite(yellow1, LOW);
    digitalWrite(yellow2, LOW);
    digitalWrite(blue1, LOW);
    digitalWrite(blue2, LOW);
    digitalWrite(green1, LOW);
    digitalWrite(green2, LOW);
    digitalWrite(white, LOW);
}

void setBlue(){
    digitalWrite(red1, LOW);
    digitalWrite(red2, LOW);
    digitalWrite(yellow1, LOW);
    digitalWrite(yellow2, LOW);
    digitalWrite(blue1, HIGH);
    digitalWrite(blue2, HIGH);
    digitalWrite(green1, LOW);
    digitalWrite(green2, LOW);
    digitalWrite(white, LOW);
}

void setGreen(){
    digitalWrite(red1, LOW);
    digitalWrite(red2, LOW);
    digitalWrite(yellow1, LOW);
    digitalWrite(yellow2, LOW);
    digitalWrite(blue1, LOW);
    digitalWrite(blue2, LOW);
    digitalWrite(green1, HIGH);
    digitalWrite(green2, HIGH);
    digitalWrite(white, LOW);
}

void setYellow(){
    digitalWrite(red1, LOW);
    digitalWrite(red2, LOW);
    digitalWrite(yellow1, HIGH);
    digitalWrite(yellow2, HIGH);
    digitalWrite(blue1, LOW);
    digitalWrite(blue2, LOW);
    digitalWrite(green1, LOW);
    digitalWrite(green2, LOW);
    digitalWrite(white, LOW);
}

void AllOn(){
    digitalWrite(red1, HIGH);
    digitalWrite(red2, HIGH);
    digitalWrite(yellow1, HIGH);
    digitalWrite(yellow2, HIGH);
    digitalWrite(blue1, HIGH);
    digitalWrite(blue2, HIGH);
    digitalWrite(green1, HIGH);
    digitalWrite(green2, HIGH);
    digitalWrite(white, HIGH);
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