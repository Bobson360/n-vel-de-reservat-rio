#define bomba   8                        // atribui nome a porta 8

const int trigPin = 9;                   // define uma constante do trigger no pino 12

const int echoPin = 10;                  // define uma constante do echo no pino 13

int distancia;                           // variavel que receberá a distancia entre o sensor e o nivel do liquido





void setup(){

   Serial.begin(9600);                  // inicia o serial monitor

   pinMode(trigPin, OUTPUT);            // define a porta 12 trigger como sa�da

   pinMode(echoPin, INPUT);             // defina a porta 13 echo como entrada

   pinMode(bomba,    OUTPUT); // define o pino 8 como saida
}

void loop(){


  

   

   /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

   /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

   /* *                  CALCULOS DO SENSOR HC-SR04                                                     * * 

   /* *                                                                                                 * *

   /* *                                                                                                 * *

   /* */  digitalWrite(trigPin, LOW);   // define a porta 12 com estado logico 0                        * *

   /* */  delayMicroseconds(2);         // delay de 2 microsegundos                                     * *

   /* */  digitalWrite(trigPin, HIGH);  // define a porta 12 com estado logico 1                        * *

   /* */  delayMicroseconds(10);        // delay de 10 microsegundos                                    * *

   /* */  digitalWrite(trigPin, LOW);   // define a porta 12 com estado logico 0                        * *

   /* *                                 //                                                              * *

   /* */  unsigned long duracao = pulseIn(echoPin, HIGH); // verifica o tempo de retorno no pino echo   * * 

   /* */  distancia = duracao / 58; // divide o tempo do echo por 58 para transformar em centimetros    
                                                                               

 for(int i = 0; i < 50; i++){
      distancia = distancia + distancia;
  }

   distancia = distancia / 50;
   
     if ( distancia <= 4 ) {                                 

                 digitalWrite(bomba, LOW);                                              

                  delay(50);         

      }                                    

                                                  

      if ( distancia >= 8  ){               

                   digitalWrite(bomba, HIGH);                         

                   delay(50); 

                 

   }                                    


 

   Serial.print("Distancia em CM: ");     // imprime o texto "Distancia em CM: " no serial monitor

   Serial.println(distancia);             // imprime o valor da variavel distancia no serial nonitor

   delay(250);                            // espera 250 milisegundos para continuar a execu��o

}