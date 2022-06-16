#include <Wire.h>

#include <LiquidCrystal_I2C.h>

 

LiquidCrystal_I2C lcd(0x27,16,2);

int buzzerPin = 13;

int Sensor_pin = A1;

int LED_R = 3;

int LED_G = 4;

 

void setup() {

  Serial.begin(9600);

  lcd.init();

  lcd.backlight();

  lcd.clear();

 

  pinMode(LED_R,OUTPUT);

 

  pinMode(LED_G,OUTPUT);

 

}

 

void loop() {

  int nsoil = analogRead(Sensor_pin);

  int nsoilper = map(nsoil,0,1023,100,0);

  

  if(nsoilper < 30)

    {

    tone(13,2500,100);

    }

  Serial.print("sensor : ");

  Serial.println(nsoil);

  

//  Serial.print(analogRead(nsoilper));

Serial.print(nsoilper);

  Serial.println("%");

  

 

  if((nsoilper < 30)) {

    lcd.clear();

    digitalWrite(LED_R,HIGH);

 

    digitalWrite(LED_G,LOW);

    lcd.setCursor(0,0);

    lcd.print("Water, please");

    

  }else{

    lcd.clear();

    digitalWrite(LED_G,HIGH);

 

    digitalWrite(LED_R,LOW);

    lcd.setCursor(0,1);

    lcd.print("Enough");

  }

  delay(100);

}
