#include <MD_MAX72xx.h>
#include <MD_Parola.h>
#include <SPI.h>

// Define hardware type, size, and output pins:
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW

// Explicação Display
// Display | Arduino
//   VCC   |   5v
//   GND   |   GND
//   DIN   |   11
//   CS    |   10
//   CLK   |   13
#define MAX_DEVICES 8  
#define CLK_PIN   13   
#define DATA_PIN  11   
#define CS_PIN    10   

// Criando Objeto "Display" usando a Class MD_PAROLA da própria lib
MD_Parola Display = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

// Função responsável por inicializar display
void initDisplay(){
  Display.begin();
  Display.setIntensity(5);
  Display.displayClear();  
}

// Setando placar no display
void setPlacar(int meta, int alcancado) {
  Display.setTextEffect(1, PA_SCROLL_LEFT, PA_SCROLL_LEFT);
  Display.setTextAlignment(PA_LEFT);
  //Serial.println("Tampas"+String(alcancado));
  Display.print("Tampas"+String(alcancado));
}

// -------------------------------------------------------------------------------- Display ^
// -------------------------------------------------------------------------------- Sensor v

// Explicação Sensor

//   Sensor  | Arduino
//   Marrom  |   5v
//   Azul    |   GND
//   Preto   |   Data

const int sensor = A0;
//const int sensor = 2;

boolean hasMoviment(){
  //return (digitalRead(sensor) == LOW);
  return (analogRead(sensor) < 550);
  Serial.println(analogRead(sensor));
}

// -------------------------------------------------------------------------------- Variáveis de "Software" v

int meta = 10000;
int alcancado = 0;

void increment(){
  if(hasMoviment()){
    alcancado++;    
    
    //Serial.println("https://ecoplay-landingpage.vercel.app/api/tampinha");
    verifyGoal();
    delay(100);
  }  
}

void verifyGoal(){
  if(alcancado >= meta){
    alcancado = 0; 
  }
}

// -------------------------------------------------------------------------------- Main v

void setup() {
  Serial.begin(9600);
  pinMode(sensor, INPUT);
  initDisplay();
}

void loop() {
  setPlacar(meta, alcancado);
  increment();
}
