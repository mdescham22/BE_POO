
#define arret 0
#define acq 1
#define verifchute 2
#define verifpouls 3
#define alarm 4
#define arretcardiaque 5

#include <Wire.h>
#include "Bracelet.h"
#include "Accelerometre.h"
#include "CapteurCardiaque.h"

int step = arret;
Accelerometre acc(0.0);
Bracelet bracelet;
CapteurCardiaque Capt_C(D7, LED_BUILTIN); // Entrée en D7 et sortie sur LED_BUILTIN

void setup() {
  Serial.begin(9600); // Initialise la communication série
  acc.powerOn(); // Active l'accéléromètre
  attachInterrupt(digitalPinToInterrupt(Capt_C.getPinEntree()), handler, RISING); // Associe l'interruption au pin d'entrée du capteur cardiaque
  Serial.println("setup ready"); // Affiche un message de configuration prêt
}

void loop() {
  switch (step) {
    case arret:
      Serial.println(Capt_C.getState()); // Affiche l'état du capteur cardiaque
      if (bracelet.getStateButton() == true && (Capt_C.getState() == 0)) {
        step = acq; // Passe à l'étape d'acquisition
        Serial.println("acq");
      }
      break;

    case acq:
      double xyz[3];
      acc.getAcceleration(xyz); // Récupère les valeurs d'accélération
      if (bracelet.chute(xyz[0], xyz[1], xyz[2])) { // Vérifie s'il y a une chute détectée
        step = verifchute; // Passe à l'étape de vérification de chute
        Serial.println("verif");
      }
      break;

    case verifchute:
      if (bracelet.verificationChute(5) == true && (Capt_C.getState() == 0)) {
        step = alarm; // Passe à l'étape d'alarme
        Serial.println("alarm");
      }
      else if (bracelet.verificationChute(5) == true && (Capt_C.getState() == 1)) {
        step = arretcardiaque; // Passe à l'étape d'arrêt cardiaque
        Serial.println("arretcardiaque");
      }
      else {
        step = acq; // Retourne à l'étape d'acquisition
        Serial.println("acq");
      }
      break;

    case alarm:
      bracelet.bipStart(100); // Active l'alarme du bracelet
      if (bracelet.getStateButton() == true) {
        bracelet.bipStop(); // Arrête l'alarme
        step = acq; // Retourne à l'étape d'acquisition
        Serial.println("acq");
      }
      break;

    case arretcardiaque:
      bracelet.bipStart(10); // Active l'alarme d'arrêt cardiaque
      if (bracelet.getStateButton() == true && (Capt_C.getState() == 0)) {
        bracelet.bipStop(); // Arrête l'alarme
        step = acq; // Retourne à l'étape d'acquisition
        Serial.println("acq");
      }
      break;

    default:
      step = arret; // Réinitialise l'étape à l'arrêt
  }

  delay(10);
}

IRAM_ATTR void handler(){
  Capt_C.interrupt();
}

