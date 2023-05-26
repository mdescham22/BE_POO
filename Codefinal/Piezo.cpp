#include <iostream>
#include <Arduino.h>
#include "Piezo.h"

using namespace std;

Piezo::Piezo()
{

}

Piezo::~Piezo()
{

}

void Piezo::setup(int Pin)
{
  // Configure la broche du piezo
  m_pin = Pin;
  pinMode(m_pin, OUTPUT);
}

void Piezo::Start(int p)
{ 
  if (m_cpt == p / 2) {
    // Réinitialise le compteur lorsque la moitié de la fréquence est atteinte
    m_cpt = 0;
  }
  else if (m_cpt < p / 2) {
    // Active la sortie pour produire un bip
    digitalWrite(m_pin, HIGH);
  }
  else if (m_cpt >= p / 2) {
    // Désactive la sortie pour interrompre le bip
    digitalWrite(m_pin, LOW);
  }
  m_cpt++;
}

void Piezo::Stop(void)
{
  // Désactive la sortie pour arrêter le bip
  digitalWrite(m_pin, LOW);
}
