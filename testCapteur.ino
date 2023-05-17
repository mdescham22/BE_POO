#include CapteurCardiaque.h

void setup() {
  int a;
  // put your setup code here, to run once:
  CapteurCardiaque Capt_C(D7,D3); //entree sur D7 et sortie sur D3
  Capt_C.calculateHeartBeat();//calcul de la frequence
  a=Capt_C.getHeartBeat();
  Capt_C.sendHeartBeat();
  

}

void loop() {
  // put your main code here, to run repeatedly:

}
