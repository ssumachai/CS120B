/*         Your Name & E-mail:  Sumachai Suksanguan (ssuks001@ucr.edu)
*          Lab Section:    021 
 *         Assignment:    Lab 7  Exercise 2
 *         Exercise Description: LCD Racer Screen
 *        
 *         I acknowledge all content contained herein, excluding template or example code, is my own original work.
 *
 *         Demo Link: https://youtu.be/_sWbnxnIKbw
 */

#include <LiquidCrystal.h>

typedef struct task {
  int state;
  unsigned long period;
  unsigned long elapsedTime;
  int (*TickFct)(int);
    
} task;

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int button1 = 9;
const int button2 = 8;
const int button3 = 7;

byte car_column, car_row = 0;
int obstacle_x, obstacle_y = 0;
byte increment_value, movement = 0;

long up_or_down = 0;

int score = 0;
bool is_obstacle = false;
bool is_crash = false;
int timer;

const unsigned short tasksNum = 2;
task tasks[tasksNum];

enum car_states {car_start, car_input, car_move, car_crash};
int Tick_car(int state){
    int up = digitalRead(button1);
    int down = digitalRead(button2);
    int reset = digitalRead(button3);

    switch(state){
      case car_start:
        lcd.clear();
        lcd.setCursor(0, 0);
        car_column = car_row = 0;
        state = car_input;
        is_crash = is_obstacle = false;
        timer = 0;
        increment_value = movement = 0;
        score = 0;
        break;
      case car_input:
        if(is_crash){
          state = car_crash;
          lcd.clear();
        }
        else{
          if(reset){
            state = car_start;
          }
          else{
            if(up && !down){
              car_row = 0;
              state = car_move;
            }
            else if(!up && down){
              car_row = 1;
              state = car_move;
            }
            else if(!up && !down){
              state = car_input;
            }
          }
        }
        break;
      case car_move:
        state = car_input;
        break;
      case car_crash:
        state = (reset) ? car_start : car_crash;
        break;
      default:
        state = car_start;
        break;
    }

    switch(state){
      case car_input:
        lcd.clear();
        lcd.setCursor(0, car_row);
        lcd.write('A');
        break;
      case car_crash:
        lcd.setCursor(0, 0);
        lcd.print("Game Over!");
        lcd.setCursor(0, 1);
        lcd.print("Score: ");
        lcd.print(score);
        break;
      default:
        break;
    }

  return state;
}

enum obs_states {obs_start, obs_play};
int Tick_obs(int state){
  
  switch(state){
    case obs_start:
      state = obs_play;
      break;
    case obs_play:
      state = obs_play;
      break;
    default:
      state = obs_start;
      break;
  }

  switch(state){
    case obs_play:
      if(timer % 20 == 0){
        if(timer < 60){
          ++increment_value;
          ++movement;
        }
      }
      if(!is_crash){
        score += increment_value;
        if(!is_obstacle){
            up_or_down = random(0, 2);
            obstacle_x = 15;
            obstacle_y = up_or_down;
            lcd.setCursor(obstacle_x, obstacle_y);
            lcd.write('O');
            is_obstacle = true;
        }
        else{
          lcd.setCursor(obstacle_x, obstacle_y);
          lcd.write(' ');
          obstacle_x -= movement;
          if(obstacle_x <= 0 && (obstacle_y == car_row)){
              obstacle_x = 1;
              is_crash = true;
          }
          lcd.setCursor(obstacle_x, obstacle_y);
          lcd.write('O');


          if((obstacle_x <= 0) && (obstacle_y == car_row) && !is_crash){
            is_crash = true;
          }
          else if((obstacle_x <= 0) && (obstacle_y != car_row) && !is_crash){
            is_obstacle = false;
          }
        }
        ++timer;
      }
      break;
    default:
      break;
  }
  return state;
}

void setup() {
  lcd.begin(16, 2);
  randomSeed(analogRead(0));
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);

  unsigned char i = 0;
  tasks[i].state = car_start;
  tasks[i].period = 100;
  tasks[i].elapsedTime = 0;
  tasks[i].TickFct = &Tick_car;
  ++i;
  tasks[i].state = obs_start;
  tasks[i].period = 500;
  tasks[i].elapsedTime = 0;
  tasks[i].TickFct = &Tick_obs;
}

void loop() {
    unsigned char i;
    for(i = 0; i < tasksNum; ++i){
        if( (millis() - tasks[i].elapsedTime) >= tasks[i].period){
            tasks[i].state = tasks[i].TickFct(tasks[i].state);
            tasks[i].elapsedTime = millis();
        }
    }
    delay(100);
}