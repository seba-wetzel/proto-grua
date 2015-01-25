
//escrito por Sebastian Wetzel

#include <Button.h>

// declarando las entradas
const int derPin = 2;
const int izqPin = 3;

const int arribaPin = 4;
const int abajoPin =5;
const int velocidadPin = A0;

//declarando las salidas
const int panStep = 12;
const int panDir = 13;
const int tiltStep = 9;
const int tiltDir = 10;

//declarando variables de sentido
boolean sentidoPan = true;
boolean sentidoTilt = true;


//tiempo del pulso de step
int pulso = 500;

int velocidadSensor;

//iniciando los botones en forma global (no volver a meter en un void() que sino no anda gil
Button derecha = Button(derPin,PULLDOWN);
Button izquierda = Button(izqPin,PULLDOWN);

Button arriba = Button(arribaPin,PULLDOWN);
Button abajo = Button(abajoPin,PULLDOWN);

void setup(){

  for(int salida = 7; salida >= 13; salida++){   //bucle for para configurar las salidas de una sola vez
    pinMode(salida, OUTPUT);
  }
  Serial.begin(9600);
} 

void loop(){
  velocidadSensor = analogRead(velocidadPin); 
  pulso = ((velocidadSensor/6)+1);
  Serial.println(pulso);
  if(derecha.isPressed()){
    moverDerecha();

  }

  if(izquierda.isPressed()){
    moverIzquierda();
  }
  if(arriba.isPressed()){
    moverArriba();
  }
  if(abajo.isPressed()){
    moverAbajo();
  }
}

// funciones de movimiento 

void moverDerecha(){
  if(!sentidoPan){
    digitalWrite(panDir, HIGH);
    //digitalWrite(13,HIGH);
    sentidoPan = true;
  }
  digitalWrite(panStep,HIGH);
  //digitalWrite(13,HIGH);
  delay(pulso);
  digitalWrite(panStep,LOW);
  //digitalWrite(13,LOW);
  delay(pulso);
}

void moverIzquierda(){
  if(sentidoPan){
    digitalWrite(panDir, LOW);
    digitalWrite(13,LOW);
    sentidoPan = false;
  }
  digitalWrite(panStep,HIGH);
  //digitalWrite(13,HIGH);
  delay(pulso);
  digitalWrite(panStep,LOW);
  //digitalWrite(13,LOW);
  delay(pulso);
}

void moverArriba(){
  if(sentidoTilt){
    digitalWrite(tiltDir, LOW);
    sentidoTilt = false;
  }
  digitalWrite(tiltStep,HIGH);
  //digitalWrite(13,HIGH);
  delay(pulso);
  digitalWrite(tiltStep,LOW);
  //digitalWrite(13,LOW);
  delay(pulso);
}

void moverAbajo(){
  if(!sentidoTilt){
    digitalWrite(tiltDir, HIGH);
    sentidoTilt = true;
  }
  digitalWrite(tiltStep,HIGH);
  //digitalWrite(13,HIGH);
  delay(pulso);
  digitalWrite(tiltStep,LOW);
  //digitalWrite(13,LOW);
  delay(pulso);
}
