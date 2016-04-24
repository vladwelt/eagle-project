/*
    UMSS 24/04/2016   NASAEVENT 
    Alexander Fidel Marquez ing INFORMATICA
    Neidy   Patricia Tapia Sillerico  ing ELECTRONICA
 --------------------><-------------------------------
*/

//**********DECLARAMOS SALIDAS************
int rightmotor1=9;  // 8 salidas al driver l298n
int rightmotor2=10; //  9
int leftmotor1=5;  //13
int leftmotor2=6;  //12
//int enA=10;
//int enB=11;
char direccion,separador;
int velocidad, tiempo;
// ************* funciones del motor *******
  void adelante(int vel, int time){
  analogWrite(rightmotor1,vel);
  analogWrite(rightmotor2,0);
  analogWrite(leftmotor1,vel);
  analogWrite(leftmotor2,0);
  //analogWrite(enA,vel);
  //analogWrite(enB,vel);
  delay(time);
  detenido();
  
  }
  void reversa(int vel, int time){  //atras
  analogWrite(rightmotor1,0);
  analogWrite(rightmotor2,vel);
  analogWrite(leftmotor1,0);
  analogWrite(leftmotor2,vel);
  //analogWrite(enA,vel);
  //analogWrite(enB,vel);
  delay(time);
  detenido();
  }
  void derecha(int vel, int time){
  analogWrite(rightmotor1,0);
  analogWrite(rightmotor2,vel);
  analogWrite(leftmotor1,vel);
  analogWrite(leftmotor2,0);
  //analogWrite(enA,vel);
  //analogWrite(enB,vel);
  delay(time);
  detenido();
  }
  void izquierda(int vel, int time){
  analogWrite(rightmotor1,vel);
  analogWrite(rightmotor2,0);
  analogWrite(leftmotor1,0);
  analogWrite(leftmotor2,vel);
  //analogWrite(enA,vel);
  //analogWrite(enB,vel);
  delay(time);
  detenido();
  }
  void detenido(){
  analogWrite(rightmotor1,0);
  analogWrite(rightmotor2,0);
  analogWrite(leftmotor1,0);
  analogWrite(leftmotor2,0);
  //analogWrite(enA,0);
  //analogWrite(enB,0);
    }
//*****************
 void setup()
 {
    pinMode(rightmotor1,OUTPUT); //es un pin de salida.
    pinMode(rightmotor2,OUTPUT);
    //pinMode(enA,OUTPUT);
    pinMode(leftmotor1,OUTPUT);
    pinMode(leftmotor2,OUTPUT);
    //pinMode(enB,OUTPUT);
    Serial.begin(9600);
    Serial.print("conectado");
}
//***************************
void loop()
{
 //0 = BLANCO (LOW) 1=NEGRO (HIGH)
   if(Serial.available()>0)
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
