#include <LiquidCrystal.h> //LCD EKRAN KÜTÜPHANE tanımlama işlemi


LiquidCrystal lcd(12,11,5,4,3,2); //Kart üzerinde bağlı olan lcd ekran pinleri

int trig = 9;
int echo = 10;
int buzzer = 13;
int led=7;

long sure; //sure isimli değişkeni tam sayı olamayacağı için long türünde 
int mesafe;


void setup() 
{
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(led,OUTPUT);

  lcd.begin(16,2);
  lcd.clear();
}

void loop() 
{

  digitalWrite(trig,LOW);
  delayMicroseconds(2); //2 milisaniye kadar bekle

  digitalWrite(trig, HIGH); //ses dalgası gönder
  delayMicroseconds(10); 
  digitalWrite(trig, LOW); //ses dalgası göndermeyi kapat

  sure = pulseIn(echo, HIGH); //gelen ses dalgasını  sure değişkenine aktar
  mesafe = (sure/2)/29.1; //mesafeyi bulmak için  uygulamamız gereken formül
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Mesafe : "); //lcd ekranda sabit yazı
  
  lcd.setCursor(7,0);
  lcd.print(mesafe);
 
  if (mesafe <=5) //eğer mesafe 5 ve altında ise 
  {
    digitalWrite(buzzer,HIGH);
    digitalWrite(led,HIGH);
    delay(20);
    digitalWrite(buzzer,LOW);
    digitalWrite(led,LOW);
    delay(20);
  }
else if (mesafe <=10) //eğer mesafe 10 ve altında ise 
  {
    digitalWrite(buzzer,HIGH);
    digitalWrite(led,HIGH);
    delay(50);
    digitalWrite(buzzer,LOW);
    digitalWrite(led,LOW);
    delay(50);
  }
  
else if (mesafe <=15) {
  digitalWrite(buzzer,HIGH);
    digitalWrite(led,HIGH);
    delay(70);
    digitalWrite(buzzer,LOW);
    digitalWrite(led,LOW);
    delay(70);

 }
 else if (mesafe <=20) {
  digitalWrite(buzzer,HIGH);
    digitalWrite(led,HIGH);
    delay(100);
    digitalWrite(buzzer,LOW);
    digitalWrite(led,LOW);
    delay(100);

 }
else if (mesafe <=25) {
  digitalWrite(buzzer,HIGH);
    digitalWrite(led,HIGH);
    delay(150);
    digitalWrite(buzzer,LOW);
    digitalWrite(led,LOW);
    delay(150);

  
 }
 else if (mesafe <=30) {
  digitalWrite(buzzer,HIGH);
    digitalWrite(led,HIGH);
    delay(250);
    digitalWrite(buzzer,LOW);
    digitalWrite(led,LOW);
    delay(250);
  
 }   
 
 delay(10);

} 
