#include <LCD_Utils.h>
#include <SoftwareSerial.h>

const uint8_t txPin = 2;

LCD_Display LCD;

void setup()
{
  Serial.begin(9600);

  LCD.attach(txPin);
  LCD.clear();
  LCD.backlightOn();
  LCD.selectLineTwo();
  LCD.print("Hello worldy!");
  delay(5000);
  LCD.clear();

  LCD.print("Turning backlight off");
  LCD.backlightOff();
  delay(5000);
  LCD.selectLineOne();
  LCD.clear();
  LCD.print("Turning backlight on");
  LCD.backlightOn();
  delay(5000);

  for (int i=0; i < 32; i++) {
    LCD.clear();
    if (i < 16) {
      LCD.position(1, i);
    }
    else {
      LCD.position(2, i-16);
    }
    LCD.print(i%10);
    delay(200);
  }
  LCD.clear();
  LCD.selectLineOne();
  LCD.print("Line one.......!");
  delay(5000);
  LCD.clear();
  LCD.selectLineTwo();
  LCD.print("Line two.......!");
  delay(5000);
}



void loop()
{
  int line=0;
  LCD.clear();
  LCD.position(line%2+1, 0);
  line++;
  LCD.print("Move me...");
  delay(1000);
  for (int j=0; j < 5; j++) {
    LCD.shiftRight();
    delay(1000);
  }
  for (int k=0; k < 5; k++) {
    LCD.shiftLeft();
    delay(1000);
  }
}




