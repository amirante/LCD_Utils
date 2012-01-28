#ifndef LCD_UTILS_H
#define LCD_UTILS_H

#include <Arduino.h>
#include "/Applications/Arduino 11.09.18 PM.app/Contents/Resources/Java/libraries/SoftwareSerial/SoftwareSerial.h"

class LCD_Display
{
  public:
    LCD_Display();
    ~LCD_Display() {};
    void attach(uint8_t txPin);
    void clear();
    void position(int row, int col);
    void backlightOn();
    void backlightOff();
    void selectLineOne();
    void selectLineTwo();
    void shiftRight();
    void shiftLeft();
    void print(char *s);
    void print(int i);
    
  private:
  	void serCommand();
    uint8_t _pin;
    SoftwareSerial *_LCD;    
};


#endif //LCD_UTILS_H
