#ifndef TRIG_PIN
#define TRIG_PIN
#endif
#ifndef ECHO_PIN
#define ECHO_PIN
#endif

#include <iostream>

void Sonar_setup();
void Sonar_read(float * dist);
