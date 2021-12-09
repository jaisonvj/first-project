#include<LiquidCrystal.h>
#define rs 10
#define enable 9
#define trigpin A0
#define echopin A1
double duration,distance,meter,volume1,volume,leftfuel,percentage;
int radius = 10;
LiquidCrystal lcd(rs,enable,7,6,5,4);
void setup() 
{
  lcd.begin(16,2);
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
  Serial.begin(9600);
}

void loop() 
{
  
 digitalWrite(trigpin,LOW);
 delayMicroseconds(2);
 digitalWrite(trigpin,HIGH);
 delayMicroseconds(10);
 digitalWrite(trigpin,LOW);
 duration=pulseIn(echopin,HIGH);
 distance=(duration*0.0343)/2;
 volume1=3.14*(radius*radius)*distance;
 volume=volume1/1000;
 leftfuel=93.04-volume;
 percentage=(leftfuel/80.00)*100; 
 lcd.setCursor(0,0);
 lcd.print("FUEL LEFT:");
 lcd.setCursor(10,0);
 lcd.print(leftfuel);
 lcd.setCursor(0,16);
 lcd.print("L");
 lcd.setCursor(0,1);
 lcd.print( "% OF FUEL:");
 Serial.println(percentage);
 delay(100);

}
