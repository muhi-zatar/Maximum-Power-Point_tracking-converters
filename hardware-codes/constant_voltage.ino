
#include <TimerOne.h>

double V = 0;
int Next=0;
float D = 0.5;
float Vmax;
float Vmin;
float voltage;
float I;

void setup() {
 Serial.begin(9600);
 pinMode(A0,INPUT);
 pinMode(A1,INPUT);
 Timer1.initialize(100);
Timer1.pwm(9, D*1023);

}
void loop() {
  
 V = 0.0048828125 * analogRead(A0) *5.0; // (5 V / 1024 = 0.0049) which converter Measured analog input voltage to 5 V Range
 for(int i = 0; i < 1000; i++) {
 voltage = (voltage + (.0048828125 * analogRead(A1))); // (5 V / 1024 = 0.0049) which converter Measured analog input voltage to 5 V Range
delay(1);
}
voltage = voltage/1000;
I = -1 * (voltage - 2.509)/ 0.186;
 Serial.println("\n Voltage Sensed (V) = "); // shows the measured voltage
 Serial.print(V,4); // the '2' after voltage allows you to display 2 digits after decimal point
 Serial.println("\n Duty cycle");
 Serial.print(D,3);
 Serial.println("\n Current sensed (A) = ");
 Serial.print(I,4);
 //Next = 0;
 //if (Next==0)
 //{
 Vmax=0.85*19.8;
 Vmin=0.7*19.8;

 if (V>Vmax)
 D = D+0.02;
 else
 D = D-0.02;
 // }
 //analogWrite(9,D*255);
 Timer1.pwm(9, D*1023); 
 
delay(2000);
}
