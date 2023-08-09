#include <NewPing.h>

int a1=0, d1=3, a2=10, d2=4, a3=25, d3=4, a4=50, d4=8, a5=70; 
int s1=100, s2=0, s3=50, s4=80, s5=180;

int Distancia_cm=0, val=0;
double con1,con2,con3,con4, con5;
double pwm=2;
 
/*Aqui se configuran los pines donde debemos conectar el sensor*/
#define TRIGGER_PIN  12
#define ECHO_PIN     11
#define MAX_DISTANCE 400
 
/*Crear el objeto de la clase NewPing*/
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
 
void setup() 
{
  //Serial.begin(9600);
}
 
void loop() {
  // Esperar 1 segundo entre mediciones
  delay(200);
  // Obtener medicion de tiempo de viaje del sonido y guardar en variable uS
  int Distancia_uS = sonar.ping_median();
  int Distancia_cm = Distancia_uS/US_ROUNDTRIP_CM;//calcula la distancia en cm

  con1=exp((-(Distancia_cm-a1)^2)/(2*(d1^2)));
  con2=exp((-(Distancia_cm-a2)^2)/(2*(d2^2)));
  con3=exp((-(Distancia_cm-a3)^2)/(2*(d3^2)));
  con4=exp((-(Distancia_cm-a4)^2)/(2*(d4^2)));
  con5=1/(1+exp(-0.3*(Distancia_cm-a5)));
    

  if (Distancia_cm<=7)//Reversa
  { 
    //Giro hacia atrás
    digitalWrite(7,LOW); //Enable 1
    digitalWrite(8,HIGH); //Enable 2
  }

  else
  {
    //Giro hacia adelante
    digitalWrite(8,LOW); //Enable 1
    digitalWrite(7,HIGH); //Enable 2
  }


//******************STOP IMPORTANTE******************
  if (Distancia_cm>7 & Distancia_cm<15)
  {
    con1=0;
    con2=exp((-(Distancia_cm-a2)^2)/(2*(d2^2)));
    con3=0;
    con4=0;
    con5=0;
  }

  pwm=((con1*s1)+(con2*s2)+(con3*s3)+(con4*s4)+(con5*s5))/(con1+con2+con3+con4+con5);
  analogWrite(9,pwm); 
  // Imprimir la distancia medida a la consola serial
//  Serial.print("Distancia: ");
//  Serial.print(Distancia_cm);//uS / US_ROUNDTRIP_CM);
//  Serial.println("cm");
//  Serial.print("%C.U.: ");
//  Serial.print(pwm);
//  Serial.println("%");
  
}
