/* battery_voltage - measures voltage of 3.3V or less with a
 * TI LaunchPad.  Prints time (minutes) since the test started,
 * voltage (volts), current (milli Amps), and power (milli Watts)
 * to the serial terminal.  The test starts when the load is
 * connected.  Do not connect the battery until prompted.
 *
 *         o___________________o A_PIN
 *       __|__      |       
 *       | + |      o       
 *       |   |    Load    
 *       | - |      o      
 *       -----      |  
 *         o        | 
 *         |        |
 *         /________|__________o GND
 *
 * Tested on CR2032 battery with TI MSP-EXP430FR6989 LaunchPad
 * using Energia V17.  Released into the public domain
 * F Milburn    January 2017
 */

//const int R_LOAD = 149.9;         // resistance (ohms) under test
const int R_LOAD = 219.2;
const int A_PIN = 6;               // voltage analog input pin
const int A_RES = 4095;            // analog resolution
const float V_REF = 3.304;         // reference voltage for LaunchPad

unsigned long startTime = 0;       // variables to track time...
unsigned long thisTime = 0;
unsigned long nextTime = 0;
const unsigned long T_INT = 60000; // interval between readings (millis)

void printData();

void setup(){
  Serial.begin(115200);
  Serial.println("Connect battery to start test...");
  while (analogRead(A_PIN) < (A_RES / 2)){
    // wait for load to be inserted
  }
  printData();
  thisTime = millis();
  startTime = millis();
  nextTime = startTime + T_INT;
}

void loop(){
  thisTime = millis();
  if (thisTime >= nextTime){
    printData();
    nextTime = thisTime + T_INT;
  }
}

void printData(){
  float minutes = ((float)thisTime - float(startTime))/60000;
  Serial.print(minutes,1);
  Serial.print(" ");
  float voltage = ((float)analogRead(A_PIN)) / A_RES;
  voltage = voltage * V_REF;
  Serial.print(voltage);
  Serial.print(" ");
  float current = (voltage * 1000) / R_LOAD;
  Serial.print(current);
  Serial.print(" ");
  float power = voltage * current;
  Serial.println(power);
}
