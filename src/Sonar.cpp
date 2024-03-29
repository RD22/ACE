/*
 Copyright (c) 2020-2021 Alan Yorinks All rights reserved.

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU AFFERO GENERAL PUBLIC LICENSE
 Version 3 as published by the Free Software Foundation; either
 or (at your option) any later version.
 This library is distributed in the hope that it will be useful,f
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 General Public License for more details.

 You should have received a copy of the GNU AFFERO GENERAL PUBLIC LICENSE
 along with this library; if not, write to the Free Software
 Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

// Constantly read and print the distance measured by an HC-SR04 Ultrasonic
// distance sensor.


#include "NanoConnectHcSr04.h"
#include "Sonar.h"

// D11 (7) == trigger, D12 (4) == echo
// Using pio0 and sm 0
NanoConnectHcSr04 sonar_esq(3,4, pio0, 0);
NanoConnectHcSr04 sonar_dir(7,8,pio0,0);
NanoConnectHcSr04 sonar_mid(11,12,pio0,0);

// distance value returned
float value = 0.0;

void Sonar_setup() {
    Serial.begin(115200);

}

void Sonar_read(float *dist) {
    // put your main code here, to run repeatedly:
    dist[0] = sonar_esq.readSonar();
    dist[1] = sonar_dir.readSonar();
    dist[2] = sonar_mid.readSonar();
    Serial.println(value);
}
