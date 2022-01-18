/*         Your Name & E-mail:  Sumachai Suksanguan (ssuks001@ucr.edu)

*          Lab Section:		021	

 *         Assignment: 		Lab 2  Exercise 5

 *         Exercise Description: Double IS nothing

 *        

 *         I acknowledge all content contained herein, excluding template or example code, is my own original work.

 *

 *         Demo Link: https://youtu.be/AkVZVqXd3Nw

 */


// C++ code
//
const int ledPin1 = 2;
const int ledPin2 = 3;
const int button1 = 14;
const int button2 = 15;
int val1, val2 = 0;

void setup()
{
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

void loop()
{
	val1 = digitalRead(button1);
  	val2 = digitalRead(button2);
	
    if(val1 == val2){
        digitalWrite(ledPin1, LOW);
        digitalWrite(ledPin2, LOW);
    }
    else{
        digitalWrite(ledPin1, val1);
        digitalWrite(ledPin2, val2);
    }
}
