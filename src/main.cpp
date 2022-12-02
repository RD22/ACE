#include <Arduino.h>
#include "TOF.h"

void setup(){
    TOF_setup();
}

void loop(){
    uint32_t distance;
    char report[64];
    distance = TOF_read();
    snprintf(report, sizeof(report), "| Distance [mm]: %ld |", distance);
    Serial.println(report);

}