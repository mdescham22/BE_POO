/*****************************************************************************/
//	Function:    Get the accelemeter of the x/y/z axis.
//  Hardware:    Grove - 3-Axis Digital Accelerometer(±1.5g)
//	Arduino IDE: Arduino-1.0
//	Author:	 Frankie.Chu
//	Date: 	 Jan 10,2013
//	Version: v0.9b
//	by www.seeedstudio.com
//
//  This library is free software; you can redistribute it and/or
//  modify it under the terms of the GNU Lesser General Public
//  License as published by the Free Software Foundation; either
//  version 2.1 of the License, or (at your option) any later version.
//
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public
//  License along with this library; if not, write to the Free Software
//  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
//
/*******************************************************************************/

#include <Wire.h>
#include "MMA7660.h"
MMA7660 accelemeter;

int cmpt = 0,etape = 1;

void setup() {
    accelemeter.init();
    Serial.begin(9600);
}
void loop() {
    float ax, ay, az;

    
    switch(etape)
    {
      case 1 : accelemeter.getAcceleration(&ax, &ay, &az);
        if (ax > 1.2 || ay > 1.2 || az > 1.2)
        {
          Serial.print("Chute potencielle de mamie\n");
          delay(5000);
          etape = 2;
        }
        break;
      
      case 2 : accelemeter.getAcceleration(&ax, &ay, &az);
        cmpt++;
        if (ax > 1 || ay > 1 || az > 1)
        {
          Serial.print("Mamie n'a pas chutée\n");
          etape = 1;
          cmpt = 0;
        }
        else if(cmpt >= 100)
        {
          Serial.print("Mamie a chutée");
          etape = 3;
          cmpt = 0;
        }
        break;
      
      case 3 : Serial.print("Piezzo");
        break;
    }
    Serial.println("accleration of X/Y/Z: ");
    Serial.print(ax);
    Serial.println(" g");
    Serial.print(ay);
    Serial.println(" g");
    Serial.print(az);
    Serial.println(" g");
    Serial.println("*************");
    Serial.println(etape);
    delay(500);
}


