#include "CapteurCardiaque.h"

//declaration du capteur en global
CapteurCardiaque Capt_C(D7,LED_BUILTIN); //entree en D7 et sortie sur led-builtin

void setup() {
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(Capt_C.getPinEntree()), handler, RISING);//association des interruptions
}

void loop() {
 Serial.println("heart rate is:");
 Serial.println(Capt_C.getHeartbeat());
 delay(5000);
}
 IRAM_ATTR void handler(){
  Capt_C.interrupt();
}

