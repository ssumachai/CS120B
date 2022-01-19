/*         Your Name & E-mail:  Sumachai Suksanguan (ssuks001@ucr.edu)

*          Lab Section:    021 

 *         Assignment:    Lab 3  Exercise 2

 *         Exercise Description: State Machine Light Show

 *        

 *         I acknowledge all content contained herein, excluding template or example code, is my own original work.

 *

 *         Demo Link: https://youtu.be/meUPZzYGsmE

 */


// C++ code
//

enum States {start, RED, RED_WAIT, YELLOW, YELLOW_WAIT, GREEN, GREEN_WAIT, BLUE, BLUE_WAIT, ALL, ALL_WAIT} state;

const int a0 = 14;
const int red1 = 5;
const int yellow1 = 6;
const int green1 = 7;
const int blue1 = 8;
const int white = 9;
const int blue2 = 10;
const int green2 = 11;
const int yellow2 = 12;
const int red2 = 13;

void setup(){
    pinMode(a0, INPUT);
    pinMode(red1, OUTPUT);
    pinMode(yellow1, OUTPUT);
    pinMode(green1, OUTPUT);
    pinMode(blue1, OUTPUT);
    pinMode(white, OUTPUT);
    pinMode(blue2, OUTPUT);
    pinMode(green2, OUTPUT);
    pinMode(yellow2, OUTPUT);
    pinMode(red2, OUTPUT);
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


void Tick(){
    int button = digitalRead(a0);
    
    switch(state){
        case start: 
            resetLights();
            state = RED;
            break;
        case RED:
            state = (button == HIGH) ? RED_WAIT : RED;
            break;
        case RED_WAIT:
            state = (button == HIGH) ? RED_WAIT : YELLOW;
            break;
        case YELLOW:
            state = (button == HIGH) ? YELLOW_WAIT : YELLOW;
            break;
        case YELLOW_WAIT:
            state = (button == HIGH) ? YELLOW_WAIT : GREEN;
            break;
        case GREEN:
            state = (button == HIGH) ? GREEN_WAIT : GREEN;
            break;
        case GREEN_WAIT:
            state = (button == HIGH) ? GREEN_WAIT : BLUE;
            break;
        case BLUE:
            state = (button == HIGH) ? BLUE_WAIT : BLUE;
            break;
        case BLUE_WAIT:
            state = (button == HIGH) ? BLUE_WAIT : ALL;
            break;
        case ALL:
            state = (button == HIGH) ? ALL_WAIT : ALL;
            break;
        case ALL_WAIT:
            state = (button == HIGH) ? ALL_WAIT : RED;
            break;
        default:
            state = start;
            break;
    }

    switch(state){
        case RED:
        case RED_WAIT:
            setRed();
            break;
        case YELLOW:
        case YELLOW_WAIT:
            setYellow();
            break;
        case GREEN:
        case GREEN_WAIT:
            setGreen();
            break;
        case BLUE:
        case BLUE_WAIT:
            setBlue();
            break;
        case ALL:
        case ALL_WAIT:
            AllOn();
            break;
        default:
            break;
    }
}

void loop(){
    Tick();
}