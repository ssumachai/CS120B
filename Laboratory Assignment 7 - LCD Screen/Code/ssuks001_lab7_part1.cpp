/*         Your Name & E-mail:  Sumachai Suksanguan (ssuks001@ucr.edu)
*          Lab Section:    021 
 *         Assignment:    Lab 7  Exercise 1
 *         Exercise Description: LCD Text Editor
 *        
 *         I acknowledge all content contained herein, excluding template or example code, is my own original work.
 *
 *         Demo Link: https://youtu.be/XTT_JSCDTj8
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

const int button1 = 13;
const int button2 = 10;
const int button3 = 9;
const int button4 = 8;
const int button5 = 7;

char to_write;
char lower_array[] = {'a', 'b', 'c', 'd'};
char upper_array[] = {'A', 'B', 'C', 'D'};
int array_index;
byte cursor_x, cursor_y = 0;
bool i_write = false;
int count;

const unsigned short tasksNum = 2;
task tasks[tasksNum];

enum keyboard_states {kb_start, KB_INPUT, SHIFT, ONE_PRESS, SHIFT_HOLD, RESET};
int Tick_KB(int state){
    int a = digitalRead(button1);
    int b = digitalRead(button2);
    int c = digitalRead(button3);
    int d = digitalRead(button4);
    int shift_key = digitalRead(button5);

    switch(state){
        case kb_start:
            if(cursor_x != 16 && cursor_y != 1){
                lcd.cursor();
                lcd.blink();
            }
            count = 0;
        case KB_INPUT:
            if(shift_key){
                state = SHIFT;
            }
            else if(!a && !b && !c &&!d){
                state = KB_INPUT;
            }
            else{
                if(a && !b && !c && !d){
                    array_index = 0;
                    i_write = true;
                }
                else if(!a && b && !c && !d){
                    array_index = 1;
                    i_write = true;
                }
                else if(!a && !b && c && !d){
                    array_index = 2;
                    i_write = true;
                }
                else if(!a && !b && !c && d){
                    array_index = 3;
                    i_write = true;
                }
                to_write = lower_array[array_index];
                state = ONE_PRESS;
            }
            break;
        case SHIFT:
            if(!shift_key || (!a && !b && !c && !d)){
                state = KB_INPUT;
            }
            else{
                if(a && !b && !c && !d){
                    array_index = 0;
                    i_write = true;
                }
                else if(!a && b && !c && !d){
                    array_index = 1;
                    i_write = true;
                }
                else if(!a && !b && c && !d){
                    array_index = 2;
                    i_write = true;
                }
                else if(!a && !b && !c && d){
                    array_index = 3;
                    i_write = true;
                }
                to_write = upper_array[array_index];
                state = SHIFT_HOLD;
            }
            break;
        case SHIFT_HOLD:
            state = (shift_key && (a || b || c || d)) ? SHIFT_HOLD : KB_INPUT;
            break;
        case ONE_PRESS:
            if(a || b || c || d){
                state = ONE_PRESS;
            }
            
            if(!a && !b && !c && !d){
                state = KB_INPUT;
            }
            else if(a && b && !c && !d){
                state = RESET;
            }
            else if(a && !b && c && !d){
                state = RESET;
            }
            else if(a && !b && !c && d){
                state = RESET;
            }
            else if(!a && b && c && !d){
                state = RESET;
            }
            else if(!a && b && !c && d){
                state = RESET;
            }
            else if(!a && !b && c && d){
                state = RESET;
            }
            count = 0;
            break;
        case RESET:
            if(!a && !b && !c && !d){
                state = KB_INPUT;
            }
            if(count < 10){
                if(a && b && !c && !d){
                    state = RESET;
                }
                else if(a && !b && c && !d){
                    state = RESET;
                }
                else if(a && !b && !c && d){
                    state = RESET;
                }
                else if(!a && b && c && !d){
                    state = RESET;
                }
                else if(!a && b && !c && d){
                    state = RESET;
                }
                else if(!a && !b && c && d){
                    state = RESET;
                }
            }
            else if(count >= 10){
                state = KB_INPUT;
            }
            break;
        default:
            state = kb_start;
            break;
    }

    switch(state){
        case RESET:
            ++count;
            if(count == 10){
                lcd.clear();
                cursor_x = cursor_y = 0;
                lcd.setCursor(cursor_x, cursor_y);
            }
            break;
        default:
            break;
    }
    return state;
}

enum led_states {led_start, LED_DISPLAY};
int Tick_LED(int state){
    
    switch(state){
        case led_start:
            state = LED_DISPLAY;
            break;
        case LED_DISPLAY:
            state = LED_DISPLAY;
            break;
        default:
            state = led_start;
            break;
    }

    switch(state){
        case led_start:
            lcd.clear();
            lcd.setCursor(0, 0);
            break;
        case LED_DISPLAY:
            if(cursor_x > 15 && cursor_y == 1 || !i_write){
                //do nothing really lol
            }
            else{
                lcd.write(to_write);
                i_write = false;
                if(cursor_x < 15){
                    ++cursor_x;
                }
                else if(cursor_x == 15){
                    if(cursor_y == 0){
                        cursor_x = 0;
                        cursor_y = 1;
                    }
                    else{
                        cursor_x = 16;
                    }
                }
                lcd.setCursor(cursor_x, cursor_y);
            }
            break;
        default:
            break;
    }
    return state;
}


void setup() {
  lcd.begin(16, 2);

  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);
  pinMode(button5, INPUT);

  unsigned char i = 0;
  tasks[i].state = kb_start;
  tasks[i].period = 100;
  tasks[i].elapsedTime = 0;
  tasks[i].TickFct = &Tick_KB;
  ++i;
  tasks[i].state = led_start;
  tasks[i].period = 100;
  tasks[i].elapsedTime = 0;
  tasks[i].TickFct = &Tick_LED;
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