//Programa q simula semaforo de veículos e de pedestres
//Acacia Calegari
//11/11/2019
//biblio: https://www.youtube.com/watch?v=uwYPkrrHGjY

int pinVermelho = 10; //Led Vermelho do semaforo principal
int pinAmarelo = 9; //Led Amarelo do semaforo principal
int pinVerde = 8; //Led Verde do semaforo principal
int pinBotao = 7; //botao q controla o semaforo
int pinPedestreVermelho = 3; //Led vermelho do semaforo de Pedestre
int pinPedestreVerde = 2; //Led verde do semaforo de pedestre


int faseSemaforo; //qual fase o semaforo principal esta

int estadoBotao; //estado atual do botao
int estadoAnteriorBotao; //estado anterior do botao

void setup() {
  
 pinMode(pinVerde, OUTPUT); //led verde semaforo principal
 pinMode(pinAmarelo, OUTPUT); //led amarelo semaforo principal
 pinMode(pinVermelho,OUTPUT); //led vermelho semaforo principal
 pinMode(pinBotao, INPUT); // botao de controle do semaforo
 pinMode(pinPedestreVerde, OUTPUT); //led verde do semaforo de pedestre
 pinMode(pinPedestreVermelho, OUTPUT); //led vermelho do semaforo de pedestre

 faseSemaforo = 1;
 estadoAnteriorBotao = digitalRead(pinBotao);

}

void loop() {

  estadoBotao = digitalRead(pinBotao);

  if((estadoBotao == HIGH) && (estadoAnteriorBotao == LOW)) { //Testando 2 coisas
    if(faseSemaforo < 3){
      faseSemaforo = faseSemaforo +1;
    }else{
      faseSemaforo = 1;
    }
  }

  estadoAnteriorBotao = estadoBotao; //nao fica trocando de fase se pressionar o botao

  if (faseSemaforo == 1){ //Semaforo Verde

    digitalWrite(pinVerde, HIGH);
    digitalWrite(pinAmarelo, LOW);
    digitalWrite(pinVermelho, LOW);

    digitalWrite(pinPedestreVerde, LOW);
    digitalWrite(pinPedestreVermelho, HIGH);

  }
  
  if (faseSemaforo == 2){ //Semaforo Amarelo

    digitalWrite(pinVerde, LOW);
    digitalWrite(pinAmarelo, HIGH);
    digitalWrite(pinVermelho, LOW);

    digitalWrite(pinPedestreVerde, LOW);
    digitalWrite(pinPedestreVermelho, HIGH);

  }

  if (faseSemaforo == 3){ //Semaforo Vermelho

    digitalWrite(pinVerde, LOW);
    digitalWrite(pinAmarelo, LOW);
    digitalWrite(pinVermelho, HIGH);

    digitalWrite(pinPedestreVerde, HIGH);
    digitalWrite(pinPedestreVermelho, LOW);

  }
  delay(100);
  }