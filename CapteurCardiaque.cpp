#include <Arduino.h>
#include "CapteurCardiaque.h"

////////////////////////////////  constructeur de CapteurCardiaque  ////////////////////////////////////////////

CapteurCardiaque::CapteurCardiaque(int pinIn,int pinOut){
  DEAD=false;
  pinEntree=pinIn;
  pinSortie=pinOut;

  //Configuration du pin
  pinMode(pinSortie, OUTPUT);
  data_effect=true;
  Serial.println("Capteur OK!");

}
////////////////////////////////////  Assesseurs ///////////////////////////////////////////////////////////////

int CapteurCardiaque::getPinEntree(){
  return pinEntree;
}

int CapteurCardiaque::getPinSortie(){
  return pinSortie;
}

int CapteurCardiaque::getHeartbeat(){
  return heart_rate;
}
bool CapteurCardiaque::getState(){
  return DEAD;
}
//////////////////////////////////  Methodes ////////////////////////////////////////////////////////////

void CapteurCardiaque::sendHeartbeat(){
  Serial.println("the heart rate is "+heart_rate);
}

void CapteurCardiaque::sum()
    {
     if(data_effect)
        {
          heart_rate=1200000/(temp[20]-temp[0]);//60*20*1000/20_total_time 
          //Serial.print("Heart_rate_is:\t");
          //Serial.println(heart_rate);
        }
       data_effect=1;//sign bit
    }

void CapteurCardiaque::arrayInit()
{
    for(unsigned char i=0;i < 20;i ++)
    {
        temp[i]=0;
    }
    temp[20]=millis();
}

void CapteurCardiaque::interrupt(){
  temp[counter]=millis();
  
  //Serial.println(counter,DEC);
 // Serial.println(temp[counter]);

  switch(counter)
  {
    case 0:
      sub=temp[counter]-temp[20];
      //Serial.println(sub);
      break;
    default:
      sub=temp[counter]-temp[counter-1];
      //Serial.println(sub);
      break;
  }
  if(sub>max_heartpluse_duty)//set 2 seconds as max heart pluse duty
  {
    data_effect=0;//sign bit
    counter=0;
    Serial.println("No heart rate detected,test will restart!" );
    DEAD=true;
    arrayInit();
    digitalWrite(pinSortie, HIGH);
  }
  else
  {
    DEAD=false;
    digitalWrite(pinSortie, LOW);
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

 
