#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

byte kapali_agiz[8] = { B01110, B11111, B11111, B11111, B11111, B11111, B01110, B00000 };
byte acik_agiz[8]   = { B01110, B11101, B11000, B11100, B11000, B11111, B01110, B00000 };

#define SAG   0
#define UST   1
#define ALT   2
#define SOL   3
#define YOK   4

int px = 0;
int skor = 0;
bool agiz_durumu = false;
char alt_satir[16];

unsigned long sonHareket = 0;

int tus_oku() {
  int deger = analogRead(0);
  if (deger > 1000) return YOK;
  if (deger < 50)   return SAG;
  if (deger < 250)  return UST;
  if (deger < 450)  return ALT;
  if (deger < 650)  return SOL;
  return YOK;
}

void setup() {
  lcd.begin(16, 2);
  
  lcd.createChar(0, kapali_agiz);
  lcd.createChar(1, acik_agiz);
  
  for(int x = 0; x < 16; x++) {
    alt_satir[x] = '*';
  }
  alt_satir[px] = ' ';
}

void loop() {
  int tus = tus_oku();
  
  if(millis() - sonHareket > 200) {
    if(tus == SOL) {
      px--;
      if(px < 0) px = 0;
    }
    else if(tus == SAG) {
      px++;
      if(px > 15) px = 15;
    }
    
    if(alt_satir[px] == '*') {
      skor++;
      alt_satir[px] = ' ';
    }
    
    agiz_durumu = !agiz_durumu;
    sonHareket = millis();
  }

  lcd.setCursor(0, 0);
  lcd.print("Skor: ");
  lcd.print(skor);
  lcd.print("       ");

  lcd.setCursor(0, 1);
  for(int x = 0; x < 16; x++) {
    if(x == px) {
      lcd.write(agiz_durumu ? byte(1) : byte(0));
    } else {
      lcd.print(alt_satir[x]);
    }
  }
  
  if (skor >= 15) {
    lcd.clear();
    lcd.setCursor(3, 0); lcd.print("TEBRIKLER!");
    lcd.setCursor(4, 1); lcd.print("Skor: 15");
    while(1);
  }
}
