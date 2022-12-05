// Includes

#include <Arduino.h>
#include "RP2040_PWM.h"
#include "TOF.h"
#include "commands.h"

// pin 25 is the built in LED for the Pi Pico (NOT for the Pi Pico W)
#define PWM0_pin 25

//creates pwm instance
RP2040_PWM* PWM_Instance;
float LED_frequency;
uint16_t LED_intensity;

unsigned long interval, last_cycle;
unsigned long loop_micros;


commands_t serial_commands;

void process_command(char command, float value)
{
  if (command == 'L') {  // The 'L' command sets the LED_intensity to the value that follows
    LED_intensity = value;
    if (LED_intensity > 100) LED_intensity = 100;  // Avoid "impossible" values for LED_intensity

  } else if (command == 'o') { // The 'o' command sets the LED_intensity to zero
    LED_intensity = 0;

  } // Put here more commands...
}


// creates variable to receive ditance from TOF and string to print it
uint32_t distance;
char report[64];



void setup(){
  //serial_commands.init(process_command);

  // Start the serial port with 115200 baudrate
  // Serial.begin(115200);


  //assigns pin 25 (built in LED), with frequency of [LED_frequency] Hz and a duty cycle of [LED_intensity]%
  //LED_frequency = 20000;
  //PWM_Instance = new RP2040_PWM(PWM0_pin, LED_frequency, LED_intensity);

  //interval = 10;

  TOF_setup();
}    

void loop(){    
    distance = TOF_read();
    snprintf(report, sizeof(report), "| Distance [mm]: %ld |", distance);
    Serial.println(report);

}