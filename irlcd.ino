#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// DEFINIÇÕES
#define endereco  0x27 // Endereços comuns: 0x27, 0x3F
#define colunas   16
#define linhas    2
const int pinoSensor = 5;


LiquidCrystal_I2C lcd(endereco, colunas, linhas);

void setup() {
  lcd.init(); 
   
  lcd.clear(); 
  pinMode(pinoSensor, INPUT);

}

void loop() {

if(digitalRead(pinoSensor) == LOW){ 
    
    lcd.backlight();
     lcd.print("PERTO");
  lcd.setCursor(0, 1); 

delay(2000);
lcd.clear();
delay(200);
  
  }else{ //SENÃO, FAZ
  lcd.backlight();
    lcd.print("LONGE");
  lcd.setCursor(0, 1); //
delay(2000);
lcd.clear();
delay(200);
  }
}
