/*
 *PAUL RUDOLF MARCUS CAMARGO.
*/

#include <Wire.h>
#include "RTClib.h"
#include <LiquidCrystal_I2C.h>
#define RV_1  12
#define RV_2  11
#define RV_3  10
//#define RV_4  9
//#define RV_5  8

int n_dia;
int r_dia;
int n_mes;
int t_mes;
int n_anno;
int d_anno;
int t_siglo=6;

LiquidCrystal_I2C lcd(0x27,16,2); 
RTC_DS1307 rtc;


void setup() {
 pinMode(RV_1, OUTPUT);
 pinMode(RV_2, OUTPUT);
 pinMode(RV_3, OUTPUT);
 //pinMode(RV_4, OUTPUT);
 //pinMode(RV_5, OUTPUT);
 Wire.begin();
 rtc.begin();
 //RTC.adjust(DateTime(__DATE__, __TIME__));
Serial.begin (9600);
  {

   Serial.println("RTC is NOT running!");
  }
lcd.init();
lcd.backlight();                            // Coloca luz de fondo al LCD
lcd.clear(); 
}

void loop() {


   DateTime now = rtc.now();
   int contacto1 = analogRead(A0);    //Lee el valor de los contactos para escoger el horario
   int contacto2 = analogRead(A1);

   Serial.print(now.year(), DEC);
   Serial.print('/');
   Serial.print(now.month(), DEC);
   Serial.print('/');
   Serial.print(now.day(), DEC);
   Serial.print('/');
   Serial.print(now.hour(), DEC);
   Serial.print('/');
   Serial.print(now.minute(), DEC);
   Serial.print('/');
   Serial.print(now.second(), DEC);
   Serial.println();
   Serial.println();
    delay(1000);
 lcd.setCursor(0,0);
 lcd.print("Fecha:");
 lcd.print(now.year(), DEC);
 lcd.print("/");
 lcd.print(now.month(), DEC);
 lcd.print("/");
 lcd.print(now.day(), DEC);
 lcd.print(" ");
 lcd.setCursor(0,1);
 lcd.print("Hr: ");
 lcd.print(now.hour(), DEC);
 lcd.print(":");
 lcd.print(now.minute(), DEC);
 lcd.print(":");
 lcd.print(now.second(), DEC);
 lcd.setCursor(13,1);
/*
if (contacto1 <= 1000){     // si el contacto 1 esta desactivado, despliega -S- entre semana funciona el timbre
    lcd.setCursor(12,0);
    lcd.print("S");
    Serial.print("-S-"); 
}
 else {                      // si el contacto 1 esta activado, despliega -F- el Fin de semana funciona el timbre
   lcd.setCursor(15,0);
   lcd.print("F");
   Serial.print("-F-");
 }/*
 int r_diaSemana=dia_de_semana();   // llama a la funcion que calcula el dia de la semana y lo almacena en r_diaSemana
 
 if ((r_diaSemana == 6 || r_diaSemana == 0)&&(contacto4 <= 1000)){  // si el contacto4 de Fin de semana esta apagado y es fin de semana no hace nada
 }
 else {
   if (contacto1 >= 1000)   // Si el contacto 1 esta activo (Horario 1)    
     horario_1();           // llama a la funcion que activa el horario 1

   if (contacto2 >= 1000)  // Si el contacto 2 esta activo (Horario 2)
     horario_2();          // llama a la funcion que activa el horario2
}
 digitalWrite(timbre, LOW);     
 digitalWrite(val1, LOW); 
 digitalWrite(val2, LOW); 
 // digitalWrite(val3, LOW); 
 delay(500);                    // La informaci¢n se actualiza cada 1/2 seg.
 lcd.setCursor(9,0);            // Borra parte de la pantalla del LCD
 lcd.print("                ");
 lcd.setCursor(8,1);
 lcd.print("                ");
 
void activar_Valvulas(){
    digitalWrite(timbre, HIGH); 
    digitalWrite(val1, HIGH);
    digitalWrite(val2, HIGH);
   // digitalWrite(val3, HIGH);
    lcd.setCursor(0,0);
    lcd.print("Valvula ON  ");
    Serial.println("Valvula Activa");
    delay(else if (now.hour() == 12 & now.minute() == 56
& now.second() == 0)); 
}
 */
 n_anno=(now.year()-2000);
 d_anno=n_anno/4;
 n_dia=now.day();
 n_mes=now.month();
 switch (n_mes) {
    case 1:
      t_mes=0;
      break;
    case 2:
      t_mes=3;
      break;
    case 3:
      t_mes=3;
      break;
    case 4:
      t_mes=6;
      break;
    case 5:
      t_mes=1;
      break;
    case 6:
      t_mes=4;
      break;
    case 7:
      t_mes=6;
      break;
    case 8:
      t_mes=2;
      break;
    case 9:
      t_mes=5;
      break;
    case 10:
      t_mes=0;
      break;
    case 11:
      t_mes=3;
      break;
    case 12:
      t_mes=5;
      break;
    default: 
      t_mes=t_mes;
    break;
 }

 r_dia=n_dia+t_mes+n_anno+d_anno+t_siglo;
 r_dia = r_dia % 7;

switch (r_dia) {
    case 1:
       lcd.print("Lu");
        Serial.print(" Lun ");
      break;
      case 2:
       lcd.print("Mar");
       Serial.println(" Ma ");
      break;
      case 3:
       lcd.print("Mie");
       Serial.print(" Mi ");
      break;
      case 4:
       lcd.print("Jue");
       Serial.print(" Ju ");
      break;
      case 5:
       lcd.print("Vie");
       Serial.print(" Vi ");
      break;
      case 6:
       lcd.print("Sab");
       Serial.print(" Sa ");
      break;
      case 0:
       lcd.print("Dom");
       Serial.print(" Do ");
      break;
      default: 
       lcd.print("---");
       Serial.print(" ---");
      break;

  
 } 


   
//VALVULA 1
//HORA 1
//ENCENDIDO 1
 if (now.hour() == 10 & now.minute() == 52& now.second() == 0)
 {
    digitalWrite(RV_1, HIGH);
     

      lcd.setCursor(0,0);
    lcd.print("Timbre ON  ");
    Serial.println("Timbre Activo");
    }
    //APAGADO 1
  else if (now.hour() == 10 & now.minute() == 53& now.second() == 0)
  {
digitalWrite(RV_1, LOW);
    }

 
 //HORA 2
 //ENCENDIDO 2
 if (now.hour() == 14 & now.minute() == 50& now.second() == 0)

    {
    digitalWrite(RV_1, HIGH);
    } 
  //APAGADO 2
   else if (now.hour() == 14 & now.minute() == 53& now.second() == 0)
   {
digitalWrite(RV_1, LOW);
    }



 
//VALVULA 2

//HORA 1
//ENCENDIDO 1
 if (now.hour() == 14& now.minute() == 50& now.second() == 0)
    {
    digitalWrite(RV_2, HIGH);
    } 
   
//APAGADO 1

    else if (now.hour() == 14 & now.minute() == 53& now.second() == 0)
    {
digitalWrite(RV_2, LOW);
    }




    
//VALVULA 3

//ENCENDIDO 1
if (now.hour() == 14& now.minute() == 56& now.second() == 0)
    {
    digitalWrite(RV_3, HIGH);
    } 
//APAGADO 1

   else if (now.hour() == 14 & now.minute() == 53& now.second() == 0)
    {
digitalWrite(RV_2, LOW);
    }



 /*
//VALVULA 4

//ENCENDIDO 1
 if (now.hour() == 14& now.minute() == 33& now.second() == 0)

    {
    digitalWrite(RV_4, HIGH);
    } 
 //APAGADO 1

  else  if (now.hour() == 14& now.minute() == 35& now.second() == 0)
    {
digitalWrite(RV_4, LOW);
    }

*/



/*
//VALVULA 5

 
//ENCENDIDO 1
if (now.hour() == 16 & now.minute() == 1 & now.second() == 30)

    {
    digitalWrite(RV_5, HIGH);
    } 
//APAGADO 1

  else  if (now.hour() == 14 & now.minute() == 0 & now.second() == 0)
    {
digitalWrite(RV_5, LOW);
    }

    */
}



