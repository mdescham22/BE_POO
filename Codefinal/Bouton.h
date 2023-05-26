#ifndef BOUTON_h
#define BOUTON_h

class Bouton
{
    private:
      int m_pin; // Numéro de la broche du bouton

    public:
      Bouton(); // Constructeur
      ~Bouton(); // Destructeur
      void setup(int Pin); // Configuration du bouton
      bool state(void); // Lecture de l'état du bouton
};

#endif
