/*         Your Name & E-mail:  Sumachai Suksanguan (ssuks001@ucr.edu)
*          Lab Section:    021 
 *         Assignment:    Lab 4  Exercise 3
 *         Exercise Description: Button Increment with Time
 *        
 *         I acknowledge all content contained herein, excluding template or example code, is my own original work.
 *
 *         Demo Link: https://youtu.be/Vn-O9oIebEM
 */
 
const int b0 = 2;
const int b1 = 3;
const int b2 = 4;
const int b3 = 5;
const int b4 = 6;
const int b5 = 7;
const int b6 = 8;
const int b7 = 9;
const int a0 = 14;
const int a1 = 15;
char count;
char sum;

enum States {start, WAIT, INCREMENT, DECREMENT, RESET} state;

void setup()
{
  pinMode(b0, OUTPUT);
  pinMode(b1, OUTPUT);
  pinMode(b2, OUTPUT);
  pinMode(b3, OUTPUT);
  pinMode(b4, OUTPUT);
  pinMode(b5, OUTPUT);
  pinMode(b6, OUTPUT);
  pinMode(b7, OUTPUT);
  pinMode(a0, INPUT);
  pinMode(a1, INPUT);
}

void resetB()
{
  digitalWrite(b0,LOW);
  digitalWrite(b1,LOW);
  digitalWrite(b2,LOW);
  digitalWrite(b3,LOW);
  digitalWrite(b4,LOW);
  digitalWrite(b5,LOW);
  digitalWrite(b6,LOW);
  digitalWrite(b7,LOW);
}

void writeToB(unsigned char temp)
{
  if ((temp>>7) & 0x01){digitalWrite(b7,HIGH);}
  if ((temp>>6) & 0x01){digitalWrite(b6,HIGH);}
  if ((temp>>5) & 0x01){digitalWrite(b5,HIGH);}
  if ((temp>>4) & 0x01){digitalWrite(b4,HIGH);}
  if ((temp>>3) & 0x01){digitalWrite(b3,HIGH);}
  if ((temp>>2) & 0x01){digitalWrite(b2,HIGH);}
  if ((temp>>1) & 0x01){digitalWrite(b1,HIGH);}
  if (temp & 0x01){digitalWrite(b0,HIGH);}
}

void Tick(){
    int up = digitalRead(a0);
    int down = digitalRead(a1);

    switch(state){
        case start:
            count = 0;
            sum = 7;
            state = WAIT;
            break;
        case WAIT:
            if((up == LOW) && (down == LOW)){
                state = WAIT;
            }
            else if((up == HIGH) && (down == LOW)){
                if(sum < 9){
                    state = INCREMENT;
                    count = 0;
                }
                else{
                    state = WAIT;
                }
            }
            else if((up == LOW) && (down == HIGH)){
                if(sum > 0){
                    state = DECREMENT;
                    count = 0;
                }
                else{
                    state = WAIT;
                }
            }
            else if((up == HIGH) && (down == HIGH)){
                state = RESET;
            }
            break;
        case INCREMENT:
            if((up == HIGH) && (down == LOW)){
                if(sum == 9){
                    state = WAIT;
                    count = 0;
                }
                else{
                    state = INCREMENT;
                }
            }
            else if((up == LOW) && (down == LOW)){
                state = WAIT;
                count = 0;
            }
            else if((up == HIGH) && (down == HIGH)){
                state = RESET;
            }
            break;
        case DECREMENT:
            if((up == LOW) && (down == HIGH)){
                if(sum == 0){
                    state = WAIT;
                    count = 1;
                }
                else{
                    state = DECREMENT;
                }
            }
            else if((up == LOW) && (down == LOW)){
                state = WAIT;
                count = 0;
            }
            else if((up == HIGH) && (down == HIGH)){
                state = RESET;
            }
            break;
        case RESET:
            state = WAIT;
            break;
        default:
            state = start;
    }

    switch(state){
        case INCREMENT:
            if(count % 10 == 0){
                ++sum;
            }
            ++count;
            break;
        case DECREMENT:
            if(count % 10 == 0){
                --sum;
            }
            ++count;
            break;
        case RESET:
            sum = 0;
            break;
        default:
          break;
        
    }

}

void loop(){
    resetB();
    writeToB(sum);
    delay(100);
    Tick();
}