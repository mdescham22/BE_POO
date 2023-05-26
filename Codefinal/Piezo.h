#ifndef PIEZO_h
#define PIEZO_h

class Piezo
{
    private:
      int m_pin;  // Numéro de la broche du piezo
      int m_cpt;  // Compteur utilisé pour le bip

    public:
        Piezo();
        ~Piezo();
        void setup(int Pin);  // Méthode pour configurer le piezo
        void Start(int p);  // Méthode pour démarrer le bip du piezo
        void Stop(void);  // Méthode pour arrêter le bip du piezo
};

#endif
