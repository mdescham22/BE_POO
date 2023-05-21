#include "CapteurCardiaque.h"

//using namespace std;
//constructeur de CapteurCardiaque
CapteurCardiaque::CapteurCardiaque(int pinIn,int pinOut){
  //Configuration du pin
  pinMode(pinOut, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(pinIn), interrupt, RISING);
  data_effect=true;
  Serial.println("Capteur OK!");

}

void CapteurCardiaque::sendHeartbeat(){
  Serial.println("the heart rate is "+heart_rate);
}

void CapteurCardiaque::calculateHeartbeat(){
  if(data_effect)
    {
      heart_rate=1200000/(temp[20]-temp[0]);//60*20*1000/20_total_time 
      Serial.print("Heart_rate_is:\t");
      Serial.println(heart_rate);
    }
    data_effect=1;//sign bit

/*Function: Interrupt service routine.Get the sigal from the external interrupt*/
}

int CapteurCardiaque::getHeartbeat(){
  return heart_rate;
}

void /*IRAM_ATTR*/ CapteurCardiaque::interrupt(){
  temp[counter]=millis();
  
  /*Serial.println(counter,DEC);
  Serial.println(temp[counter]);*/

  switch(counter)
  {
    case 0:
      sub=temp[counter]-temp[20];
      Serial.println(sub);
      break;
    default:
      sub=temp[counter]-temp[counter-1];
      Serial.println(sub);
      break;
  }
  if(sub>max_heartpluse_duty)//set 2 seconds as max heart pluse duty
  {
    data_effect=0;//sign bit
    counter=0;
    Serial.println("Heart rate measure error,test will restart!" );
    DEAD=true;
    arrayInit();
    digitalWrite(pinOut, HIGH);
  }
  else
  {
    DEAD=0;
    digitalWrite(pinOut, LOW);
  }
  if (counter==20&&data_effect)
  {
      counter=0;
      sum();
  }
  else if(counter!=20&&data_effect){
  counter++;
  }
  else 
  {
      counter=0;
      data_effect=1;
  }
}
