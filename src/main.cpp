#include <Arduino.h>
#define M1Adelante 51
#define M1Atras 49
#define M2Adelante 47
#define M2Atras 45
#define PWM1 6
#define PWM2 7
int velocidad = 400;
int TiempoEjecucion = 1000;
char dato;

void setup()
{
  Serial.begin(9600);
  pinMode(M1Adelante, OUTPUT);
  pinMode(M1Atras, OUTPUT);
  pinMode(M2Adelante, OUTPUT);
  pinMode(M2Atras, OUTPUT);
  pinMode(PWM1, OUTPUT);
  pinMode(PWM2, OUTPUT);
}

void Adelante()
{
  digitalWrite(M1Adelante, HIGH);
  digitalWrite(M1Atras, LOW);
  digitalWrite(M2Adelante, HIGH);
  digitalWrite(M2Atras, LOW);
}

void Atras()
{
  digitalWrite(M1Adelante, LOW);
  digitalWrite(M1Atras, HIGH);
  digitalWrite(M2Adelante, LOW);
  digitalWrite(M2Atras, HIGH);
}

void Derecha()
{
  digitalWrite(M1Adelante, HIGH);
  digitalWrite(M1Atras, LOW);
  digitalWrite(M2Adelante, LOW);
  digitalWrite(M2Atras, HIGH);
}

void Izquierda()
{
  digitalWrite(M1Adelante, LOW);
  digitalWrite(M1Atras, HIGH);
  digitalWrite(M2Adelante, HIGH);
  digitalWrite(M2Atras, LOW);
}

void loop()
{
  digitalWrite(M1Adelante, LOW);
  digitalWrite(M1Atras, LOW);
  digitalWrite(M2Adelante, LOW);
  digitalWrite(M2Atras, LOW);
  analogWrite(PWM1, velocidad);
  analogWrite(PWM2, velocidad);
  if (Serial.available() > 0)
  {
    dato = Serial.read();
    switch (dato)
    {
    case 'w':
      Serial.println("Posicion: w= Adelante");
      Adelante();
      delay(TiempoEjecucion);
      break;
    case 's':
      Serial.println("Posicion: s= Atras");
      Atras();
      delay(TiempoEjecucion);
      break;
    case 'd':
      Serial.println("Posicion: d= Derecha");
      Derecha();
      delay(TiempoEjecucion);
      break;
    case 'a':
      Serial.println("Posicion: a= Izquierda");
      Izquierda();
      delay(TiempoEjecucion);
      break;
    case 'q':
      Serial.println("Posicion: q= Parar");
      digitalWrite(M1Adelante, LOW);
      digitalWrite(M1Atras, LOW);
      digitalWrite(M2Adelante, LOW);
      digitalWrite(M2Atras, LOW);
      delay(500);
      break;
    case '1':
      Serial.println("Velociad: 1= 200");
      velocidad = 200;
      break;
    case '2':
      Serial.println("Velociad: 2= 300");
      velocidad = 300;
      break;
    case '3':
      Serial.println("Velociad: 3= 400");
      velocidad = 400;
      break;
    case '4':
      Serial.println("Velociad: 4= 500");
      velocidad = 500;
      break;
    case '5':
      Serial.println("Velociad: 5= 600");
      velocidad = 600;
      break;
    case '6':
      Serial.println("Velociad: 6= 700");
      velocidad = 700;
      break;
    case '7':
      Serial.println("Velociad: 7= 800");
      velocidad = 800;
      break;
    case '8':
      Serial.println("Velociad: 8= 900");
      velocidad = 900;
      break;
    case '9':
      Serial.println("Velociad: 9= 1000");
      velocidad = 1000;
      break;
    case 'z':
      Serial.println("TiempoDeEjecucion: z= 1s");
      TiempoEjecucion = 1000;
      break;
    case 'x':
      Serial.println("TiempoDeEjecucion: x= 2s");
      TiempoEjecucion = 2000;
      break;
    case 'c':
      Serial.println("TiempoDeEjecucion: c= 3s");
      TiempoEjecucion = 3000;
      break;
    case 'v':
      Serial.println("TiempoDeEjecucion: v= 4s");
      TiempoEjecucion = 4000;
      break;
    case 'b':
      Serial.println("TiempoDeEjecucion: b= 5s");
      TiempoEjecucion = 5000;
      break;
    case 'n':
      Serial.println("TiempoDeEjecucion: n= 6s");
      TiempoEjecucion = 6000;
      break;
    case 'm':
      Serial.println("TiempoDeEjecucion: m= 7s");
      TiempoEjecucion = 7000;
      break;
    default:
      Serial.println("Caracter no reconocido");
      break;
    }
  }
}