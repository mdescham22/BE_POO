#include <iostream>
#include <Arduino.h>
#include "Bouton.h"

using namespace std;

Bouton::Bouton()
{

}

Bouton::~Bouton()
{

}

void Bouton::setup(int Pin)
{
  m_pin = Pin; // Affecte le numéro de broche passé en paramètre à la variable membre m_pin
  pinMode(m_pin, INPUT); // Configure la broche en entrée pour le bouton
}

bool Bouton::state(void)
{
    // Vérifie l'état du bouton
    // Si le bouton est enfoncé, la fonction digitalRead() retourne HIGH :
    if (digitalRead(m_pin) == HIGH) {
        return true; // Le bouton est enfoncé
    }
    else {
        return false; // Le bouton n'est pas enfoncé
    }
}
