/*
  LCD_Utils.cpp - Library for talking to the serial LCD display
  Released into the public domain.
*/


#include <LCD_Utils.h>

const int LCDdelay = 10;	// conservative, 2 actually works


LCD_Display::LCD_Display()
{
}

void
LCD_Display::attach(uint8_t txPin)
{
	_pin = txPin;
	pinMode(_pin, OUTPUT);
	_LCD = new SoftwareSerial(0, txPin);	// since the LCD does not send data back to the Arduino, we should only define the txPin
	_LCD->begin(9600);
	clear();
}

void LCD_Display::position(int row, int col) 
{
  serCommand();   //command flag
  _LCD->write(0x80);	// set cursor position command
  if (row == 2)
    col = col + 16;
    
  _LCD->write(col);
  //LCD.write((col + row*64 + 128));    //position 
  delay(LCDdelay);
}

void LCD_Display::clear() 
{
  serCommand();   //command flag
  _LCD->write(0x01);   //clear command.
  delay(LCDdelay);
}

void LCD_Display::backlightOn() {  //turns on the backlight
  _LCD->write(0x80);   // command flag for backlight stuff
  _LCD->write(128);    // light level (0 = off to 255 = full on
  delay(LCDdelay);
}

void LCD_Display::backlightOff() {  //turns off the backlight
  _LCD->write(0x80);   //command flag for backlight stuff
  _LCD->write((uint8_t)0);     //light level for off.
  delay(LCDdelay);
}

void LCD_Display::serCommand(){   //a general function to call the command flag for issuing all other commands   
  _LCD->write(0xFE);
}

void LCD_Display::selectLineOne(){  //puts the cursor at line 0 char 0.
   position(1,0);    //position
}

void LCD_Display::selectLineTwo(){  //puts the cursor at line 2 char 0.
   position(2,0);    //position
}

void LCD_Display::shiftRight() {
  serCommand();
  _LCD->write(0x1c);
  delay(LCDdelay);
}

void LCD_Display::shiftLeft() {
  serCommand();
  _LCD->write(0x18);
  delay(LCDdelay);
}

void LCD_Display::print(char *s)
{
	_LCD->print(s);
}

void LCD_Display::print(int i)
{
	_LCD->print(i);
}

