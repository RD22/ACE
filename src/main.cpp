#include <Arduino.h>
#include "TOF.h"

uint32_t distance;
    char report[64];

void setup(){
    TOF_setup();
}    

void loop(){    
    distance = TOF_read();
    snprintf(report, sizeof(report), "| Distance [mm]: %ld |", distance);
    Serial.println(report);

}