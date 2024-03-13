//***************************************** Definições *******************************************//

#define BLYNK_PRINT Serial
#define pino A0

//***************************************** Blibiotecas ******************************************//

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


//***************************************** Variáveis Globais ************************************//

char auth[] = "bWZIZac0ulLlcy0NNP2BmKdNtW_e6tez";
char ssid[] = "Claro";
char pass[] = "+++12345+++";

int leitura = 0;
byte temperatura = 0;
byte angulo = 0;

//**************************************** objetos ***********************************************//

BlynkTimer timerLM35;


//*********************************** obejetos instanciados ******************************************************

WidgetLED led (V2); 
WidgetLCD lcd (V6);

//****************************************** Setup ***********************************************//

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  lcd.clear();
  lcd.print(5,0,"Centro");
  lcd.print(2,1,"Universitario");
  delay(2000);
  lcd.clear();
  lcd.print(5,0,"ENIAC");
  delay(2000);
  lcd.clear();
  lcd.print(4,0,"Projeto");
  lcd.print(3,1,"Integrador");
  delay(2000);
  lcd.clear();
  lcd.print(5,0,"Forno");
  lcd.print(6,1,"IOT");
  delay(2000);
  lcd.clear();
  lcd.print(2,0,"Desenvolvido");
  lcd.print(6,1,"Por");
  delay(2000);
  lcd.clear();
  lcd.print(0,0,"Luiz Augusto R.");
  lcd.print(4,1,"Da Silva");
  delay(2000);
  lcd.clear();
  lcd.print(0,0,"Inicializando");
  lcd.print(0,1,"..............");
  delay(1500);
  lcd.clear();
  lcd.print(3,0,"Sistema");
  lcd.print(3,1,"Iniciado");
  delay(1500);
  pinMode(14,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
 
}

//****************************************** Loop **********************************************//

void loop()
{
  
  //--------------sensor temperatura------------------
  
  Blynk.run();
  leitura = analogRead (A0);
  temperatura = (analogRead(pino)*(3.0/1023))/0.01;
  Serial.println(temperatura);
  delay(100);
  Blynk.virtualWrite(V1,temperatura);
  timerLM35.setInterval(2000L, LM35);
   
   //-------------temperatura miníma--------------------   
  
  if (temperatura <=27)
      { 
        lcd.clear();
        lcd.print(3,0,"Temperatura");
        lcd.print(5,1,"Minima");
        delay(2000);
        Blynk.virtualWrite(V3,255);
        digitalWrite(5,HIGH);
        lcd.clear();
      }
  else 
      { 
        lcd.clear();
        Blynk.virtualWrite(V3,0);
        digitalWrite(5,LOW);
      }
  //-------------------temperatura máxima------------------
  
  if (temperatura >= 38)
      { 
        lcd.clear();
        lcd.print(3,0,"Temperatura");
        lcd.print(5,1,"Maxima");
        delay(2000);
        Blynk.virtualWrite(V4,255);
        digitalWrite(4,HIGH);
        lcd.clear();
  
      }
  else 
      { 
        lcd.clear();
        Blynk.virtualWrite(V4,0);
        digitalWrite(4,LOW);
      }
      
      //-------------------temperatura ideal-----------------------------
      
      switch (temperatura) 
      {
        
        //---------------mensagem para aumentar a temperatura---------------
        
        case 25:
        digitalWrite(14,0);
        led.off();
        lcd.print(3,0,"Aumente a");
        lcd.print(3,1,"Temperatura");
        delay(2000);
    break;
        case 26:
        digitalWrite(14,0);
        led.off();
        lcd.print(3,0,"Aumente a");
        lcd.print(3,1,"Temperatura");
        delay(2000);
    break;
        case 27:
        digitalWrite(14,0);
        led.off();
        lcd.print(3,0,"Aumente a");
        lcd.print(3,1,"Temperatura");
        delay(2000);
    break;

  //---------------mensagem temperatura ideal---------------
       
       case 28:
        digitalWrite(14,255);
        led.on();
        lcd.print(3,0,"Temperatura");
        lcd.print(5,1,"Ideal");
        delay(2000);
    break;
       case 29:
        digitalWrite(14,255);
        led.on();
        lcd.print(3,0,"Temperatura");
        lcd.print(5,1,"Ideal");
        delay(2000);
    break;
       case 30:
        digitalWrite(14,255);
        led.on();
        lcd.print(3,0,"Temperatura");
        lcd.print(5,1,"Ideal");
        delay(2000);
    break;
      case 31:
        digitalWrite(14,255);
        led.on();
        lcd.print(3,0,"Temperatura");
        lcd.print(5,1,"Ideal");
        delay(2000);
    break;
       case 32:
        digitalWrite(14,255);
        led.on();
        lcd.print(3,0,"Temperatura");
        lcd.print(5,1,"Ideal");
        delay(2000);
    break;
       case 33:
        digitalWrite(14,255);
        led.on();
        lcd.print(3,0,"Temperatura");
        lcd.print(5,1,"Ideal");
        delay(2000);
    break;
       case 34:
        digitalWrite(14,255);
        led.on();
        lcd.print(3,0,"Temperatura");
        lcd.print(5,1,"Ideal");
        delay(2000);
    break;
       case 35:
        digitalWrite(14,255);
        led.on();
        lcd.print(3,0,"Temperatura");
        lcd.print(5,1,"Ideal");
        delay(2000);
    break;
    
    //---------------mensagem para abaixar a temperatura---------------
       
       case 36:
        digitalWrite(14,0);
        led.off();
        lcd.print(3,0,"Abaixe a");
        lcd.print(3,1,"Temperatura");
        delay(2000);
    break;
       case 37:
        digitalWrite(14,0);
        led.off();
        lcd.print(3,0,"Abaixe a");
        lcd.print(3,1,"Temperatura");
        delay(2000);
    break;
}
       //---------------------controle de lcd--------------------------------
  
  if (temperatura >= 38)
      { 
         digitalWrite(12,LOW);
         lcd.clear();
         lcd.print(3,0,"Abaixando a");
         lcd.print(3,1,"Temperatura");
         delay(2000);
         lcd.clear();
        
       }
      else
      {
        lcd.clear();
                      
      }  
  if (temperatura <= 24 )
      { 
         digitalWrite(12,HIGH);
         lcd.clear();
         lcd.print(3,0,"Aumentando a");
         lcd.print(3,1,"Temperatura");
         delay(2000);
         lcd.clear();
        
      }
      else
      {
        lcd.clear();
                        
      }
}

//****************************************** Void temperatura **********************************************//

void LM35()
{
 int temp=0,ultimatemp=0;
 temp= map (leitura,0,1023,0,150);
 Blynk.virtualWrite(V1, ultimatemp);
  if(isnan(ultimatemp))
  {
   return;
  }
}
