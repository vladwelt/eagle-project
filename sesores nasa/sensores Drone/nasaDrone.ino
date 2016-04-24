/*  UMSS 24/04/2016   NASAEVENT
    Alexander Fidel Marquez ing INFORMATICA
    Neidy   Patricia Tapia Sillerico  ing ELECTRONICA
 --------------------><-------------------------------
 PINES USADOS  
 MOTORES      3 - 5 - 6 - 9
 ULTRASONICO  8 -12 
 RELE         7
 SHOCK        10
 DHT          4  
*/
#include <DHT.h>
#define DHTPIN 4 //dato 
#define DHTTYPE DHT11 
#define PIN_TRIG 8  //ultrasonico
#define PIN_ECO  12  //ultrsonico
#define RELE     7    
#define SHOCK    10
#define INI_1 3  
#define INI_2 5 
#define INI_3 6  
#define INI_4 9 
DHT dht(DHTPIN, DHTTYPE);
float temperatura,humedad,volumen_Gas;

const int xPin  = A1;
const int yPin  = A2;
const int zPin  = A3;

int x = 0, y = 0, z = 0,velocidad, tiempo;
char direccion,separador;

void setup()
{
    Serial.begin(9600);
    dht.begin();
    pinMode(PIN_TRIG, OUTPUT);  // pines de mi ultrasonico
    pinMode(PIN_ECO, INPUT);
    pinMode(RELE, OUTPUT);
    pinMode(INI_1,OUTPUT); 
    pinMode(INI_2,OUTPUT);
    pinMode(INI_3,OUTPUT);
    pinMode(INI_4,OUTPUT);
    Serial.println("conectado");
    digitalWrite(PIN_TRIG,LOW);
    digitalWrite(RELE,LOW);
    digitalWrite(INI_1,LOW); 
    digitalWrite(INI_2,LOW); 
    digitalWrite(INI_3,LOW); 
    digitalWrite(INI_4,LOW); 

}

void loop()
{
    humedad = dht.readHumidity();//Lee humedad
    temperatura = dht.readTemperature(); // lee temperatura
    volumen_Gas = detector_gas(); // detecta gas 
    x = analogRead(xPin);
    y = analogRead(yPin);
    z = analogRead(zPin);//lectura acelerometro
    x = constrain(map(x,349,281,0,90),0,90);
    y = constrain(map(y,341,345,0,90),0,90);
    z = constrain(map(z,425,357,0,90),0,90);
    if(ultrasonico_f () == 1 )
    {
       digitalWrite(RELE, HIGH);
    }
    else
    {
       digitalWrite(RELE, LOW); 
    }
    leer();
    
}

float detector_gas()
{
    float vol;
    int sensorValue = analogRead(A0);
    vol=(float)sensorValue/1024*5.0;
    return vol;
}
int ultrasonico_f()
{
  int respuesta = 0;
  long duracion, distancia;  // Variables
  
  /* Hacer el disparo */
  digitalWrite(PIN_TRIG, LOW);  
  delayMicroseconds(2); 
  digitalWrite(PIN_TRIG, HIGH);  // Flanco ascendente
  delayMicroseconds(10);        // Duracion del pulso
  digitalWrite(PIN_TRIG, LOW);  // Flanco descendente
  /* Recepcion del eco de respuesta */
  duracion = pulseIn(PIN_ECO, HIGH);
  /* Calculo de la distancia efectiva */
  distancia = (duracion/2) / 29; 
  if(distancia > 20)
  { 
    respuesta = 1;
  }
  return   respuesta;
}

void adelante(int vel, int time)
{
  analogWrite(INI_1,vel);
  analogWrite(INI_2,0);
  analogWrite(INI_3,vel);
  analogWrite(INI_4,0);
  //analogWrite(enA,vel);
  //analogWrite(enB,vel);
  delay(time);
  detenido();
}
void reversa(int vel, int time)
{  //atras
  analogWrite(INI_1,0);
  analogWrite(INI_2,vel);
  analogWrite(INI_3,0);
  analogWrite(INI_4,vel);
  delay(time);
  detenido();
}
void derecha(int vel, int time)
{
  analogWrite(INI_1,0);
  analogWrite(INI_2,vel);
  analogWrite(INI_3,vel);
  analogWrite(INI_4,0);
  delay(time);
  detenido();
}
void izquierda(int vel, int time)
{
  analogWrite(INI_1,vel);
  analogWrite(INI_2,0);
  analogWrite(INI_3,0);
  analogWrite(INI_4,vel);
  delay(time);
  detenido();
}
void detenido()
{
  analogWrite(INI_1,0);
  analogWrite(INI_2,0);
  analogWrite(INI_3,0);
  analogWrite(INI_4,0);
}
void leer()
{
  if(Serial.available()>0) //
    {
      direccion = Serial.read();
      velocidad = Serial.parseInt();
      separador = Serial.read();
      tiempo = Serial.parseInt();
      if(direccion == 'a')// adelante
      { 
        adelante(velocidad,tiempo);
      }
      if(direccion == 'r')//retro
      { 
        reversa(velocidad,tiempo);
      }
      if(direccion == 'i')//izquierda
      { 
        izquierda(velocidad,tiempo);
      }
      if(direccion == 'd')//derecha
      { 
         derecha(velocidad,tiempo);
      }
    }
}