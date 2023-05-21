#include "CapteurCardiaque.h"

void setup() {
  int a;
  // put your setup code here, to run once:
  CapteurCardiaque Capt_C(D7,D3); //entree sur D7 et sortie sur D3
  Capt_C.calculateHeartbeat();//calcul de la frequence
  a=Capt_C.getHeartbeat();
  Capt_C.sendHeartbeat();
  

}

void loop() {
  // put your main code here, to run repeatedly:

}
