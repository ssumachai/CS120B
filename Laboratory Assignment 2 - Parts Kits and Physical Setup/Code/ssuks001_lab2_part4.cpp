/*         Your Name & E-mail:  Sumachai Suksanguan (ssuks001@ucr.edu)

*          Lab Section:		021	

 *         Assignment: 		Lab 2  Exercise 4

 *         Exercise Description: Button Press LED

 *        

 *         I acknowledge all content contained herein, excluding template or example code, is my own original work.

 *

 *         Demo Link: https://youtu.be/gR2j9fwdkwk

 */


// C++ code
//
const int ledPin = 2;
const int button = 3;
int value = 0;
void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(button, INPUT);
}

void loop()
{
  value = digitalRead(button);
  digitalWrite(ledPin, value);
}
