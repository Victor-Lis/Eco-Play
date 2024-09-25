# Eco-Play 
Esse é o lado de IOT do projeto Eco-Play

<br>

## Configurando placar 
```c++
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
  Serial.println("Tampas"+String(alcancado));
  Display.print("Tampas"+String(alcancado));
}
```

<br>

## Configurando sensor
```c++
// Explicação Sensor

//   Sensor  | Arduino
//   Marrom  |   5v
//   Azul    |   GND
//   Preto   |   Data
const int sensor = A0;

boolean hasMoviment(){
  //return (digitalRead(sensor) == LOW);
  return (analogRead(sensor) < 550);
}
```

<br>

## Configurando manipulações e funções voltadas ao software
```c++
int meta = 10000;
int alcancado = 0;

void increment(){
  if(hasMoviment()){
    alcancado++;    
    Serial.println("https://ecoplay-landingpage.vercel.app/api/tampinha");
    verifyGoal();
    delay(100);
  }  
}

void verifyGoal(){
  if(alcancado >= meta){
    alcancado = 0; 
  }
}
```

<br>

## Conteúdo "Main" do código
```c++
void setup() {
  Serial.begin(9600);
  pinMode(sensor, INPUT);
  initDisplay();
}

void loop() {
  setPlacar(meta, alcancado);  
  increment();
}
```

# Resultado Final
![Imagem do WhatsApp de 2024-09-21 à(s) 17 20 45_02f7daca](https://github.com/user-attachments/assets/d6fc0b30-fbf3-4d29-a79d-9973350efed4)
![Imagem do WhatsApp de 2024-09-21 à(s) 17 20 46_0789af37](https://github.com/user-attachments/assets/596fe6e2-0a10-4436-b61d-029d15983568)
![Imagem do WhatsApp de 2024-09-21 à(s) 17 20 46_fd277280](https://github.com/user-attachments/assets/5cadffe1-800e-47b2-bda4-b8c97042b01b)
![Imagem do WhatsApp de 2024-09-21 à(s) 17 20 46_a8211abf](https://github.com/user-attachments/assets/0c96e54b-919f-4213-aa68-fa8311cec71e)
![Imagem do WhatsApp de 2024-09-21 à(s) 17 20 45_0ff63c51](https://github.com/user-attachments/assets/d897ed9e-49d4-464f-97ff-3b1350fda707)
![Imagem do WhatsApp de 2024-09-21 à(s) 17 20 44_dcabe56f](https://github.com/user-attachments/assets/c7f84163-efa4-4c70-b348-aa54c4bce18a)
![Imagem do WhatsApp de 2024-09-21 à(s) 17 20 44_170bde19](https://github.com/user-attachments/assets/423e0eca-b6f0-489d-8be0-54534eb14e92)

<br>

# Autores

### Orientadores
- [@Márcio-Yugi](https://www.linkedin.com/in/marcio-yuji-tokunaga-3aba8016/)
- [@Kátia-Maria](https://www.linkedin.com/in/katia-fushita-180522160/)

### Alunos
- [@Karlos-Eduardo](https://www.linkedin.com/in/karlos-eduardo-marques-araujo-de-moraes-2b531b293/)
- [@Miguel-Rosillo](https://www.linkedin.com/in/miguel-rosillo-8534a8294/)
- [@Pedro-Henrique](https://www.linkedin.com/in/pedro-henrique-moraes-samsonas-4a0b3a29a/)
- [@Victor-Lis](https://www.linkedin.com/in/victor-lis-bronzo/)
