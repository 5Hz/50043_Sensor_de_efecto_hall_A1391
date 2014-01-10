#include <SoftwareSerial.h>
SoftwareSerial mySerial(3, 2);
#define SLEEP 8

const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to

int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)
int opcion = 0;
int barras;

int entrada;
void setup(){
  pinMode(SLEEP,OUTPUT);
 
  Serial.begin(9600);

//  do{
//  }while(Serial.available()==0);
//  if(Serial.available()>0){
    menu();
//  }
}

void loop(){
  if (opcion == 1)  // indica que se seleccionó una opción válida
    leer_sensor();
  else
    menu();
  if (Serial.available()){
    entrada=Serial.read();
    if(entrada=='*'){
      menu();
    }
    
  }
}


void menu(){
  int entradaMenu;
  Serial.println("-------------------5HZ ELECTRONICA---------------------------");
  Serial.println("");
  Serial.println("                     PRESENTA");
  Serial.println("");
  Serial.println("*************************************************************");
  Serial.println("");
  Serial.println("      BIEVENIDO AL PROGRAMA DE PRUEBAS DEL A1391");
  Serial.println("");
  Serial.println("            YA TIENES UN IMAN A LA MANO????");
Serial.println("");
    Serial.println("*************************************************************");
  Serial.println("");
  Serial.println("MENU PRINCIPAL");
  Serial.println("1-Activar SLEEP");
  Serial.println("2-Desactivar SLEEP");
  do{
  }while(Serial.available()==0);
      entradaMenu=Serial.read();
    switch(entradaMenu){
   
    case '1':
      digitalWrite(SLEEP,LOW);
       Serial.println("");
      Serial.println("SLEEP Activado");
      Serial.println("EL SENSOR NO FUNCIONARA YA QUE ESTA DORMIDITO.....");
      delay(3000);
      opcion = 1;
      break;
      
    case '2':
       digitalWrite(SLEEP,HIGH);
        Serial.println("");
      Serial.println("SLEEP Desactivado");
      Serial.println("LA SALIDA SERA 127 SIN PRESENCIA DE CAMPO MAGNETICO");
      Serial.println("CAMPO POSITIVO: AUMENTARA .....VARIARA ENTRE 511 Y 1023 DE ACUERDO A LA INTENSIDAD");
      Serial.println("CAMPO NEGATIVO: DISMINUIRA..... VARIARA ENTRE 511 A 0 DE ACUERDO A LA INTENSIDAD");
      delay(3000);
      opcion = 1;
      break;
      
    default:
      Serial.println("Solo hay dos opciones... 1..y 2... =) ");
      opcion = 0;
      break;
    }
    
    if (opcion == 1)
    Serial.println("Hola soy la TERMINAL DE 5Hz (teclea * para ir al menu) ");

}

  
  
void leer_sensor() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin);            
  // map it to the range of the analog out:
//  outputValue = map(sensorValue, 0, 1023, 0, 255);  
  // change the analog out value:


  barras = sensorValue / 15;
  
  for (int i=0; i <= barras; i++)
     Serial.print("-");
  Serial.print(" ");
//  Serial.print("sensor = " );                       
  Serial.println(sensorValue);      
//  Serial.print("output = ");      
//  Serial.println(outputValue);   

  // wait 10 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(100);   
}
