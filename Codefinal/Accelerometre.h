#ifndef ACCELROMETRE_h
#define ACCELROMETRE_h

#include <vector> // Inclusion de la bibliothèque vector pour utiliser des tableaux dynamiques
#include <ADXL345.h> // Inclusion de la bibliothèque ADXL345 pour l'accéléromètre

using namespace std; // Utilisation de l'espace de noms std

class Accelerometre : public ADXL345 // Définition de la classe Accelerometre qui hérite de la classe ADXL345
{
  private:
    vector<double> m_data; // Vecteur pour stocker les données de l'accéléromètre
    double m_filteredValue; // Valeur filtrée de l'accéléromètre
    double m_alpha; // Paramètre du filtre passe-bas

  public:
    Accelerometre(double alpha); // Constructeur de la classe Accelerometre avec le paramètre alpha
    void addData(); // Méthode pour ajouter une valeur à m_data
    double getFilteredValue(); // Méthode pour obtenir la valeur filtrée de l'accéléromètre
};

#endif
