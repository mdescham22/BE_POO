#ifndef DEF_CAPTEURCARDIAQUE
#define DEF_CAPTEURCARDIAQUE


class CapteurCardiaque{

    private:
    unsigned char counter;
    unsigned long temp[21];
    unsigned long sub; //temps entre 2 impulsion
    bool data_effect;
    bool state;
    unsigned int heart_rate;//the measurement result of heart rate
    int pinEntree;
    int pinSortie;
    const int max_heartpluse_duty = 2000;//intervalle max de 2 sec entre les battements

    public:
    //constructeur
    CapteurCardiaque(int pinIn,int pinOut);
    //assesseurs
    int getPinEntree();
    int getPinSortie();
    int getHeartbeat();
    bool getState();
    //methodes
    void sendHeartbeat();
    void arrayInit();
    void sum();
    void interrupt();
    
};

static void handler();

#endif