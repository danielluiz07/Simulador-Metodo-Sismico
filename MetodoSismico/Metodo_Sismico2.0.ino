
// include the library code:
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Ultrasonic.h>
//Definimos o pino do Arduino que utilizaremos para conectar ao pin TRIGGER do sensor oHC-SR04
#define PINO_TRIGGER 4 
//Definimos o pino do Arduino que utilizaraemos para conectar ao pino ECHO do sensor HC-SR04
#define PINO_ECHO 5 
//Inicializamos nosso sensor ultrassonico HC-SR04 informando a ele
//os pinos atribuidos para TRIGGER e ECHO respectivamente
Ultrasonic ultrasonic(PINO_TRIGGER, PINO_ECHO); 
//Definimos os pinos do nosso Arduino que utilizaremos para conectar ao display LCD
LiquidCrystal_I2C lcd(0x3F, 16, 2); 


// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to


void setup() {
  
  lcd.init();       // Initialize the lcd
  lcd.backlight();  // turn on the backlight
 
}

void loop() {
  float cmMsec;
  //Le os dados do sensor, com o tempo de retorno do sinal
  long microsec = ultrasonic.timing();  
 
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
   // INCLUSAO PARA APRESENTAR VALOR SEM CASAS DECIMAS EM CENTIMETROS e METROS
  //-------------------------------------------------------------------------
  // (CÓDIGO ORIGINAL CRIADO POR RODRIGO COSTA em 01/04/17).
  //------------------------------------------------------------------------- 
    String cmMsecToMetersFinal = String(cmMsec *10); //transformamos nossa variavel "cmMsec" que está até aqui em "cm" para "metros"
  String cmMsecString = String(cmMsec, 0); //aqui pego a variavel que armazena os valores em centimetros e no segundo argumento ("0") serve para dizer que nao quero nenhuma casa decimal (ou seja, numero intero apenas). RCosta.
  String cmMsecStringFinal = cmMsecString + " cm"; // temos agora o valor numa STRING em CENTIMETROS
  String mMsecToMetersFinal = cmMsecToMetersFinal + " m";
  //Apresentamos os dados, em centimetros, no display LCD e no Monitor Serial
  lcd.setCursor(0, 0);
  lcd.print("Dist.REAL: ");
  lcd.print("        ");
  lcd.setCursor(11, 0);
  lcd.print(cmMsecStringFinal);
  //lcd.print("cm");

  Serial.print("Dist.REAL: ");
  Serial.print(cmMsecStringFinal);

  //Apresentamos os dados, em metros, no display LCD e no Monitor Serial
  lcd.setCursor(0, 1);
  lcd.print("Profund.: ");
  lcd.print("        ");
  lcd.setCursor(8, 1);
  lcd.print(mMsecToMetersFinal);

  Serial.print(", Profundidade: ");
  Serial.println(mMsecToMetersFinal);
 
  
 
  delay(1000);
  
 
}
