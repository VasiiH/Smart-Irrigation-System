//#include <LiquidCrystal.h>
//int carCount = 0;
//int storeCount = 0;
//
//int temp1 = A0;
//int temp2 = A1;
//int temp3 = A2;
//int temp4 = A3; 
//int tempRead1,tempRead2,tempRead3,tempRead4;
//float countTemp1,countTemp2,countTemp3,countTemp4;
//float finalTemp;
//
//int fan = 3;
//int heat = 2;
//int light = 1;
//
//int LDR = A4;
//int LDRRead;
//float LDRConvert;
//
//int carEnternce = 7;
//int carEnternceRead;
//int carOut = 6;
//int carOutRead;
//
//int storEnternce = 5;
//int storEnternceRead;
//int storOut = 4;
//int storOutRead;
//
//LiquidCrystal Lcd(13,12,11,10,9,8);
//
//int carLimit = 32;
//int storeLimit = 50;
//
//void IN_Read_CAR(){
//  carCount++;
//}
//
//void OUT_Read_CAR(){
//  carCount--;
//}
//
//void IN_Read_STORE(){
//  storeCount++;
//}
//
//void OUT_Read_STORE(){
//  storeCount--;
//}
//void setup() {
//  Lcd.begin(16,2);
//
//  pinMode(temp1,INPUT);
//  pinMode(temp2,INPUT);
//  pinMode(temp3,INPUT);
//  pinMode(temp4,INPUT);
//
//  pinMode(LDR,INPUT);
//
//  pinMode(carEnternce,INPUT);
//  pinMode(carOut,INPUT);
//
//  pinMode(storEnternce,INPUT);
//  pinMode(storOut,INPUT);
//
//  pinMode(fan,OUTPUT);
//  pinMode(heat,OUTPUT);
//  pinMode(light,OUTPUT);
//}
//
//void loop() {
//
//  
//  tempRead1 = analogRead(temp1);
//  tempRead2 = analogRead(temp2);
//  tempRead3 = analogRead(temp3);
//  tempRead4 = analogRead(temp4);
//
//  countTemp1 = ((tempRead1/1024.8)*5000)/10;
//  countTemp2 = ((tempRead2/1024.8)*5000)/10;
//  countTemp3 = ((tempRead3/1024.8)*5000)/10;
//  countTemp4 = ((tempRead4/1024.8)*5000)/10;
//  
//  finalTemp = (countTemp1+countTemp2+countTemp3+countTemp4)/4;
//  
//  LDRRead = analogRead(LDR);
//  //LDRConvert = map(LDRRead,0,1023,0.0,200.0);
//  
//  
//  carEnternceRead = digitalRead(carEnternce);
//  carOutRead = digitalRead(carOut);
//
//  storEnternceRead = digitalRead(storEnternce);
//  storOutRead = digitalRead(storOut);
//
//  Lcd.setCursor(0,0);
//  Lcd.print("Welcome to Store");
//  Lcd.setCursor(0,1);
//  Lcd.print(finalTemp);
//  Lcd.setCursor(1,0);
//  Lcd.print(LDRRead);
//  delay(1000);
//  Lcd.clear();
//  
//  if(carEnternceRead == HIGH){
//    IN_Read_CAR();
//  }
//  if(carOutRead == HIGH){
//    OUT_Read_CAR();
//  }
//
//  if(storEnternceRead == HIGH){
//    IN_Read_STORE();
//  }
//  if(storOutRead == HIGH){
//    OUT_Read_STORE();
//  }
//
//  if(finalTemp < 25){
//    digitalWrite(3,LOW);
//    digitalWrite(2,HIGH);
//  }else{
//    digitalWrite(3,HIGH);
//    digitalWrite(2,LOW);
//  }
//
//  if(LDRRead == HIGH){
//    digitalWrite(1,HIGH);
//  }else{
//    digitalWrite(1,LOW);
//  }
//
//    if(storeCount <= 50){
//    digitalWrite(0,LOW);
//  }else{
//    digitalWrite(0,HIGH);
//  }
//
//  
//  if(carCount <= 0){
//    Lcd.setCursor(0,0);
//    Lcd.print("No Car In Park");
//    delay(1000);
//    Lcd.clear();
//  }else{
//    Lcd.setCursor(0,0);
//    Lcd.print(carCount);
//    Lcd.setCursor(0,1);
//    Lcd.print("Car In Park"); 
//    delay(1000);
//    Lcd.clear(); 
//  }
//
//  
//  if(storeCount <= 0){
//    Lcd.setCursor(0,0);
//    Lcd.print("No Body In Store");
//    delay(1000);
//    Lcd.clear();
//  }else{
//    Lcd.setCursor(0,0);
//    Lcd.print(storeCount);
//    Lcd.setCursor(0,1);
//    Lcd.print("Peoples In Store"); 
//    delay(1000);
//    Lcd.clear(); 
//  }
//  
//
//
//  
//}




 
#include <LiquidCrystal.h> //LCD Library

#define NOTE_C4 262 
#define NOTE_D4 294 
#define NOTE_E4 330 
#define NOTE_F4 349 
#define NOTE_G4 392 
#define NOTE_A4 440 
#define NOTE_B4 494 
#define NOTE_C5 523 

int temp;
int T_Sensor = A4;
int M_Sensor = A0;
int W_led = 7;
int P_led = 13;
int Speaker = 9;
int val;
int cel;  

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
 {
    lcd.begin(16, 2);
    lcd.clear(); 
    pinMode(13,OUTPUT);
    pinMode(7,INPUT);
    pinMode(9,OUTPUT);
    
    val = analogRead(T_Sensor); //Read Temperature sensor value 
    int mv = ( val/1024.0)*5000; 
    cel = mv/10;

}

void loop()
{
  
  lcd.clear();
  int Moisture = analogRead(M_Sensor); //Read Moisture Sensor Value 

  lcd.setCursor(0,0);
  lcd.print("TEMP:");
  lcd.setCursor(5,0);
  lcd.print(cel);
  lcd.setCursor(7,0);
  lcd.print("*C");
 
 if (Moisture> 700)   // for dry soil
  { 
        lcd.setCursor(11,0);
        lcd.print("DRY");
        lcd.setCursor(11,1);
        lcd.print("SOIL");
       if (digitalRead(W_led)==1) //test the availability of water in storage
       {
         digitalWrite(13, HIGH);
         lcd.setCursor(0,1);
         lcd.print("PUMP:ON");
       }
       else
       {
         digitalWrite(13, LOW);
         lcd.setCursor(0,1);
         lcd.print("PUMP:OFF");
           
           tone(Speaker, NOTE_C4, 500); 
           delay(500); 
           tone(Speaker, NOTE_D4, 500);
           delay(500); 
           tone(Speaker, NOTE_E4, 500); 
           delay(500); 
           tone(Speaker, NOTE_F4, 500); 
           delay(500); 
           tone(Speaker, NOTE_G4, 500); 
           delay(500);
       }
    }
 
     if (Moisture>= 300 && Moisture<=700) //for Moist Soil
    { 
      lcd.setCursor(11,0);
     lcd.print("MOIST");
     lcd.setCursor(11,1);
     lcd.print("SOIL");
     digitalWrite(13,LOW);
     lcd.setCursor(0,1);
     lcd.print("PUMP:OFF");    
  }
 
  if (Moisture < 300)  // For Soggy soil
  { 
    lcd.setCursor(11,0);
     lcd.print("SOGGY");
     lcd.setCursor(11,1);
     lcd.print("SOIL");
     digitalWrite(13,LOW);
     lcd.setCursor(0,1);
     lcd.print("PUMP:OFF");
  }
 delay(1000);    
}  
