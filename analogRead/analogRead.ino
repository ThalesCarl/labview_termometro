#include <Stream.h>
int input0 = 0;
int input1 = 0;
const int pin0 = 0;
const int pin1 = 1;
int dif = 0;
long int run_mode = 0;
long int run_mode_old = 0;
long int exit_mode = 0;
long int time_start = 0;
int led = 13;
String input;



void readPrintDDP(long int);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.setTimeout(1);
  Serial.flush();
  pinMode(pin0, INPUT);
  pinMode(pin1, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  //   put your main code here, to run repeatedly:
  if (run_mode == 0)
  {
    run_mode_old = run_mode;
    run_mode = Serial.parseInt();
    
  }

  if (run_mode == 1111)
  {
    if ((run_mode - run_mode_old) == 1111)
    {
      time_start = micros();
      
    }
    readPrintDDP(time_start);

    exit_mode = Serial.parseInt();
    if (exit_mode == 6666)
      run_mode = 0;
     
  } 
  else
  {
    run_mode = 0;
  }
  run_mode_old = run_mode;
  Serial.flush();
  delayMicroseconds(1e3);
  

}


void readPrintDDP(long int time_start)
{
  input0 = analogRead(pin0);
  input1 = analogRead(pin1);
  dif = input0 - input1;
  Serial.print(dif);
  Serial.print(",");
  Serial.println(micros()-time_start);

}


