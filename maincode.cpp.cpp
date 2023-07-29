#include <DS3231.h>
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 5, en = 6, d4 = 7, d5 = 8, d6 = 9, d7 = 10;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int Relay = 4;

DS3231  rtc(SDA, SCL);
Time t;

const int OnHour = 10;
const int OnMin =57;
const int OffHour =10;
const int OffMin =58;

void setup() {
  Serial.begin(9600);
  rtc.begin();
  pinMode(Relay, OUTPUT);
  digitalWrite(Relay, LOW);
  pinMode(2,OUTPUT);
}

void loop() {lcd.clear();
  lcd.setCursor(1,2);
  lcd.print("Motor's are OFF ");
  t = rtc.getTime();
  Serial.print(t.hour);
  Serial.print(" hour(s), ");
  Serial.print(t.min);
  Serial.print(" minute(s)");
  Serial.println(" ");
  
  
  if(t.hour == OnHour && t.min == OnMin){
    digitalWrite(Relay,HIGH);
    digitalWrite(2,HIGH);
    Serial.println("LIGHT ON");
    lcd.clear();
  lcd.setCursor(1,2);
  lcd.print("Motor's are ON ");
delay(60000);
    }
    
    else if(t.hour == OffHour && t.min == OffMin){


      digitalWrite(Relay,LOW);
      digitalWrite(2,LOW);
      Serial.println("LIGHT OFF");

    }
}