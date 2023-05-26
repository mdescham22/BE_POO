
#include <iostream> // Inclusion de la bibliothèque iostream pour l'affichage en console
#include <Arduino.h> // Inclusion de la bibliothèque Arduino pour les fonctions de base
#include "Bracelet.h" // Inclusion du fichier d'en-tête Bracelet.h

using namespace std; // Utilisation de l'espace de noms std

// Définition du constructeur de la classe Bracelet
Bracelet::Bracelet()
{
    m_bouton.setup(15); // Configuration du bouton avec le numéro de pin 15
    m_piezo.setup(D5); // Configuration du buzzer avec le numéro de pin D5
}

// Définition de la méthode chute de la classe Bracelet
bool Bracelet::chute(double x, double y, double z)
{
    if ((x >= 1.9) || (y >= 1.9) || (z >= 1.9)) {
        return true; // Retourne true si une chute est détectée (les valeurs d'accélération dépassent 1.9)
    }
    else {
        return false; // Retourne false si aucune chute n'est détectée
    }
}

// Définition de la méthode verificationChute de la classe Bracelet
bool Bracelet::verificationChute(int timeMax)
{
    int time = 0;
    cout << "Une chute a été détectée. Appuyez sur le bouton pour annuler." << endl;
    while (1)
    {
        if (m_bouton.state()) {
            time = 0;
            return false; // Retourne false si le bouton est appuyé pour annuler la chute
        }
        else if (time == 100 * timeMax) {
            return true; // Retourne true si le temps maximum est atteint sans annulation
        }
        time++;
        delay(10);
    }
}

// Définition de la méthode getStateButton de la classe Bracelet
bool Bracelet::getStateButton(void)
{
    return m_bouton.state(); // Retourne l'état du bouton
}

// Définition de la méthode bipStart de la classe Bracelet
void Bracelet::bipStart(int p)
{
    m_piezo.Start(p); // Démarre le buzzer
}

// Définition de la méthode bipStop de la classe Bracelet
void Bracelet::bipStop(void)
{
    m_piezo.Stop(); // Arrête le buzzer
}








