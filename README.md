# battery_voltage
Measures battery voltage as a function of time and reports results to the serial monitor using a LaunchPad and Energia.

battery_voltage - measures voltage of 3.3V or less with a
TI LaunchPad.  Prints time (minutes) since the test started,
voltage (volts), current (milli Amps), and power (milli Watts)
to the serial terminal.  The test starts when the load is
connected.  Do not connect the battery until prompted.

         o___________________o A_PIN
       __|__      |       
       | + |      o       
       |   |    Load    
       | - |      o      
       -----      |  
         o        | 
         |        |
         /________|__________o GND

 Tested on CR2032 battery with TI MSP-EXP430FR6989 LaunchPad
 using Energia V17.  Released into the public domain
 
 See writeup at:  http://forum.43oh.com/topic/10098-msp430-infrared-controlled-wearable/?p=75756
