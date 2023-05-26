#include <iostream>
#include <Arduino.h>
#include "Accelerometre.h"

using namespace std;

// Constructeur de la classe Accelerometre
Accelerometre::Accelerometre(double alpha) : m_alpha(alpha)
{
  m_filteredValue = 0.0;
}
// Méthode pour ajouter une valeur à m_data
void Accelerometre::addData() 
{
  // Obtenir les valeurs de l'accéléromètre
  double xyz[3];
  getAcceleration(xyz);

  m_data.push_back(sqrt(sqrt(xyz[0]*xyz[0]+xyz[1]*xyz[1])+xyz[2]*xyz[2]));
}

// Méthode pour obtenir la valeur filtrée de l'accéléromètre
double Accelerometre::getFilteredValue()
{
  // Appliquer le filtre passe-bas sur la dernière valeur de m_data
  m_filteredValue = m_alpha * m_data.back() + (1 - m_alpha) * m_filteredValue;
  return m_filteredValue;
}
