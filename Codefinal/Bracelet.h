
#ifndef BRACELET_h
#define BRACELET_h

#include "Bouton.h"
#include "Piezo.h"

class Bracelet
{
    private:
    Bouton m_bouton; // Objet Bouton pour le bouton du bracelet
    Piezo m_piezo; // Objet Piezo pour le buzzer du bracelet

    public:
        Bracelet(); // Constructeur
        ~Bracelet(); // Destructeur
        bool chute(double x, double y, double z); // Méthode pour détecter une chute
        bool verificationChute(int time); // Méthode pour vérifier une chute pendant une période donnée
        bool getStateButton(void); // Méthode pour obtenir l'état du bouton du bracelet
        void bipStart(int p); // Méthode pour démarrer le buzzer du bracelet
        void bipStop(void); // Méthode pour arrêter le buzzer du bracelet
};

#endif
