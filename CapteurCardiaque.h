#ifndef DEF_CAPTEURCARDIAQUE
#define DEF_CAPTEURCARDIAQUE


class CapteurCardiaque{
    private:
    unsigned char counter;
    unsigned long temp[21];
    unsigned long sub; //temps entre 2 impulsion
    bool data_effect;
    bool DEAD;
    unsigned int heart_rate;//the measurement result of heart rate

    const int max_heartpluse_duty = 2000;//you can change it follow your system's request.
                            //2000 meams 2 seconds. System return error 
                            //if the duty overtrip 2 second.

    public:
    void CapteurCardiaque(int pinIn,pinOut);
    void sendHeartbeat();
    void calculateHeartbeat();
    int getHeartbeat();
    IRAM_ATTR void interrupt();
}