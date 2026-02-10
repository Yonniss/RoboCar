#include <analogWrite.h>

#include <ABLocks_TimerFreeTone.h>
#include "BluetoothSerial.h"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

double numero;
double tiempo;
String s_numero_text;
String s_message;
String s_pantallaoled;
BluetoothSerial bt_serial;
Adafruit_SSD1306 oled_1(128,64, &Wire,-1);
bool oled_1_autoshow=true;

void avanzar() {
	digitalWrite(14, HIGH);
	digitalWrite(12, LOW);
	digitalWrite(19, HIGH);
	digitalWrite(18, LOW);
}
void convertir_segons() {
	if ((String(s_message).length() >= 7)) {
		s_numero_text = String(s_message).substring((7)-1,(String(s_message).length()));
		numero = String(s_numero_text).toFloat();
		tiempo = (numero * 1000);
	}
	else {
		numero = 0;
	}

}
void retroceder() {
	digitalWrite(14, LOW);
	digitalWrite(12, HIGH);
	digitalWrite(19, LOW);
	digitalWrite(18, HIGH);
}
void temps_parar() {
	delay(tiempo);
	stop2();
}
void stop2() {
	digitalWrite(14, LOW);
	digitalWrite(12, LOW);
	digitalWrite(19, LOW);
	digitalWrite(18, LOW);
	analogWrite(13,(uint16_t)(0));
	analogWrite(5,(uint16_t)(0));
}

void setup()
{
  	pinMode(13, OUTPUT);
	pinMode(5, OUTPUT);
	pinMode(2, OUTPUT);
	pinMode(14, OUTPUT);
	pinMode(12, OUTPUT);
	pinMode(19, OUTPUT);
	pinMode(18, OUTPUT);

	//bluetooth classic slave
	bt_serial.begin(String("coxterobot").c_str());
	if(String("1234").length()>0)bt_serial.setPin(String("1234").c_str());

	oled_1.begin(SSD1306_SWITCHCAPVCC,0x3C);
	oled_1.clearDisplay();
	if(oled_1_autoshow)oled_1.display();

}


void loop()
{
	yield();

  	if ((bt_serial.available()>0)) {
  		oled_1.clearDisplay();
  		if(oled_1_autoshow)oled_1.display();
  		s_message = bt_serial.readString();
  		convertir_segons();
  		if ((String(s_message).indexOf(String("CMD"))!=-1)) {
  			if (((String(s_message).indexOf(String("CMD:w:"))!=-1) && (numero > 0))) {
  				avanzar();
  				analogWrite(13,(uint16_t)(255));
  				analogWrite(5,(uint16_t)(255));
  				temps_parar();
  			}
  			else if (String(s_message).equals(String("CMD:w"))) {
  				avanzar();
  				analogWrite(13,(uint16_t)(255));
  				analogWrite(5,(uint16_t)(255));
  			}
  			else if (((String(s_message).indexOf(String("CMD:a:"))!=-1) && (numero > 0))) {
  				avanzar();
  				analogWrite(13,(uint16_t)(255));
  				analogWrite(5,(uint16_t)(0));
  				temps_parar();
  			}
  			else if (String(s_message).equals(String("CMD:a"))) {
  				avanzar();
  				analogWrite(13,(uint16_t)(255));
  				analogWrite(5,(uint16_t)(0));
  			}
  			else if (((String(s_message).indexOf(String("CMD:s:"))!=-1) && (numero > 0))) {
  				retroceder();
  				analogWrite(13,(uint16_t)(255));
  				analogWrite(5,(uint16_t)(255));
  				temps_parar();
  			}
  			else if (String(s_message).equals(String("CMD:s"))) {
  				retroceder();
  				analogWrite(13,(uint16_t)(255));
  				analogWrite(5,(uint16_t)(255));
  			}
  			else if (((String(s_message).indexOf(String("CMD:d:"))!=-1) && (numero > 0))) {
  				avanzar();
  				analogWrite(13,(uint16_t)(0));
  				analogWrite(5,(uint16_t)(255));
  				temps_parar();
  			}
  			else if (String(s_message).equals(String("CMD:d"))) {
  				avanzar();
  				analogWrite(13,(uint16_t)(0));
  				analogWrite(5,(uint16_t)(255));
  			}
  			else if ((String(s_message).equals(String("CMD:r")) || String(s_message).equals(String("")))) {
  				stop2();
  			}

  		}
  		else if ((String(s_message).indexOf(String("TXT:"))!=-1)) {
  			s_pantallaoled = String(s_message).substring((4)-1,(String(s_message).length()));
  			oled_1.setTextSize(2);
  			oled_1.setTextColor(WHITE);
  			oled_1.setCursor(0,0);
  			oled_1.print(s_pantallaoled);
  			if(oled_1_autoshow)oled_1.display();
  		}
  		else if ((String(s_message).indexOf(String("BRD"))!=-1)) {
  			TimerFreeTone(2,1000,100);
  		}

  	}

}