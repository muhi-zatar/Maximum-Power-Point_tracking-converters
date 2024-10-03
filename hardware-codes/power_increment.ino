
#include <TimerOne.h>

const int voltagePin = A0; // Pin for PV voltage
const int currentPin = A1; // Pin for PV current
const int pwmPin = 9; // PWM output pin (for most Arduinos, pins 3, 5, 6, 9, 10, and 11 have PWM capability)

float voltage, current, power, lastVoltage, lastPower, V, I, maxpower, maxduty;
float deltaVoltage = 0.075; // Small perturbation in voltage
double duty = 0.89; // Start with a 50% duty cycle
int flag = 0;
void setup() {
 Serial.begin(9600);
 Timer1.initialize(100);
 pinMode(A0, INPUT);
 pinMode(A1, INPUT);
Timer1.pwm(9, duty*1023);
 
 lastVoltage = analogRead(A1) * (5.0 / 1023.0); // Initial voltage measurement
 lastPower = lastVoltage * (analogRead(A0) * (5.0 / 1023.0)); // Initial power calculation
  maxpower = 0;
 maxduty = duty;
}

void loop() {
 for(int i = 0; i < 1000; i++) {
 voltage = (voltage + (.0048828125 * analogRead(A1))); // (5 V / 1024 = 0.0049) which converter Measured analog input voltage to 5 V Range
delay(1);
}

 voltage = voltage/1000;
 I = -1 * (voltage - 2.509)/ 0.186;
 V = ( (.0048828125 * analogRead(A0)));

 current = analogRead(A1) * (5.0 / 1023.0);
 power = V * I;


if (flag == 1){
  duty = maxduty;
  }
else{
if (power > maxpower){
  maxpower = power;
  maxduty = duty;} 

if (duty >= 0.95 or duty <=0.15){
  duty = maxduty;
  flag = 1;
  }
  else{
    duty=duty-0.01;}
}

 // Update the PWM output
Timer1.pwm(9, duty*1023);

 lastPower = power;
lastVoltage = V;
 Serial.print("\t Duty cycle = "); // shows the voltage measured
 Serial.println(duty);
 Serial.print("\n Voltage Sensed (V) = "); 
 Serial.println(V);
 Serial.print("\t Current (A) = "); // shows the voltage measured
 Serial.println(I);
 Serial.print("\t Power (W) = ");
 Serial.println(power);
 Serial.println("\n maximum power sensed:");
 Serial.println(maxpower);
 delay(500); // Adjust this delay based on how frequently you want to run the MPPT algorithm
}
