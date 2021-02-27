/*******************************************************************************************************************************************************************
                                                                                DEBOUNCE


 Obs:Exercício do livro: Explorando o ARDUINO - Autor: Jeremy Blum

 Aluno: Jailson Correia Data: 27/02/2021.



********************************************************************************************************************************************************************/
/*********************************************************************** DEFINIÇÃO DE HARDWARE *********************************************************************/

#define LED 9
#define BUTTON 2

/************************************************************************* VARIÁVEIS GLOBAIS ***********************************************************************/


boolean lastButton = LOW;
boolean currentButton = LOW;
boolean ledOn = false;


/************************************************************************** CÓDIGO PRINCIPAL ***********************************************************************/

void setup() {

  pinMode (LED, OUTPUT);
  pinMode (BUTTON, INPUT);

}

boolean debounce (boolean last) {

  boolean current = digitalRead (BUTTON);
  if (last != current) {
    delay (5);
    current = digitalRead (BUTTON);

  }

  return current;

}

void loop() {

  currentButton = debounce (lastButton);
  if (lastButton == LOW && currentButton == HIGH) {

    ledOn = !ledOn;

  }

  lastButton = currentButton;
  digitalWrite (LED, ledOn);

}
