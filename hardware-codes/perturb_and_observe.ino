#include <TimerOne.h>

const int voltagePin = A0; // Pin for PV voltage
const int currentPin = A1; // Pin for PV current
const int pwmPin = 9; // PWM output pin (for most Arduinos, pins 3, 5, 6, 9, 10, and 11 have PWM capability)

float voltage, current, power, lastVoltage, lastPower, V, I;
float deltaVoltage = 0.075; // Small perturbation in voltage
double duty = 0.3; // Start with a 50% duty cycle

void setup() {
 Serial.begin(9600);
 Timer1.initialize(100);
 pinMode(A0, INPUT);
 pinMode(A1, INPUT);
Timer1.pwm(9, duty*1023);
 
 lastVoltage = analogRead(A1) * (5.0 / 1023.0); // Initial voltage measurement
 lastPower = lastVoltage * (analogRead(A0) * (5.0 / 1023.0)); // Initial power calculation
}

void loop() {
 for(int i = 0; i < 1000; i++) {
 voltage = (voltage + (.0048828125 * analogRead(A1))); // (5 V / 1024 = 0.0049) which converter Measured analog input voltage to 5 V Range
delay(1);
}

 voltage = voltage/1000;
 I = (voltage - 2.509)/ 0.186;
 V = ( (.0048828125 * analogRead(A0)));
 current = analogRead(A1) * (5.0 / 1023.0);
 power = V * I;

 // Perturb and Observe Algorithm
 if (power > lastPower) {
 if (voltage > lastVoltage) {
duty=(duty+0.01);
 lastVoltage = voltage + deltaVoltage; // Increase voltage
 } else {
 duty=(duty-0.01); // Decrease duty cycle
 lastVoltage = voltage - deltaVoltage; // Decrease voltage
 }
 } else {
 if (voltage > lastVoltage) {
 duty=(duty-0.01); // Decrease duty cycle
 lastVoltage = voltage - deltaVoltage; // Decrease voltage
 } else {
 duty=(duty+0.01); // Increase duty cycle
 lastVoltage = voltage + deltaVoltage; // Increase voltage
 }
 }

 // Ensure PWM values are within bounds
 duty = constrain(duty, 0.05, 0.95);

 // Update the PWM output
Timer1.pwm(9, duty*1023);

 lastPower = power;
 Serial.print("\t Duty cycle = "); // shows the voltage measured

 Serial.println(duty);
 Serial.print("\n Voltage Sensed (V) = "); 
 Serial.println(V);
 Serial.print("\t Current (A) = "); // shows the voltage measured
 Serial.println(I);
 delay(500); // Adjust this delay based on how frequently you want to run the MPPT algorithm
}

