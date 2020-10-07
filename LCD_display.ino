#include <LiquidCrystal.h>

/*
  LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystal
 */

typedef enum {
  EAST,
  WEST,
//  NOP,
} buttonstate;

// T= Time
//[ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]
//[ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][T][T][T]

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);


void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("S:    >     B: ");
  lcd.setCursor(0,1);
  lcd.print("D:   M:        ");
  set_doorOpen(true);
  delay(1000);
  set_emergency();
  delay(1000);
  
}

void loop() {
  
}

  // Print a message to the LCD.
//  lcd.setCursor(0,0);
//  lcd_emergency.print("Emergrency stop");
//  lcd.setCursor(0,1);
//  lcd_emergency.print("Please Reset");

//S : Is used to indicate the current and next stations, CURR and NEXT will be replaced by EAST/WEST corresponding to the current and next stations

//D : Is used to indicate the state of the door, this will either be OP = Open or CL = Close 

//M : Indicates the movement, this will be either ST = Start or SP = Stop

//B : Will be used to indicate the most recent accepted button press, eg ST = Start, SP = Stop, E = East, W =  West, O = Open, C = Closed, EM = Emergency


  
  
  //lce.setCursor(0,0);
  //lcd_display.print("S:CURR>NEXT B:XX");
  //lcd_display.print("D:XX M:XX DDDDDD");

  //WHEN PRESSED DOOR OPEN

  //lcd_display.print("D:OP M:ST STOP");

  //WHEN PRESSED DOOR CLOSE
  //lcd_display.print("S:CURR>NEXT B:C");
  //lcd_display.print("D:ST M:ST START");

  //WHEN PRESSED TARIN STARTS
  //lcd_display.print("S:CURR>NEXT B:ST");      //M INICTE THE MOVEMENT when stop button is pressed train is moving 
  //lcd_display.print("D:CL M:ST START");
  

  //WHEN PRESSED TRAIN STOPS
  //lcd_display.print("S:CURR>NEXT B:ST");
  //lcd_display.print("D:CL M:SP START");

  //WHEN EMERGENCY IS PRESSED
  //lcd_display.print("S:CURR>NEXT B:EM");
  //lcd_display.print("D:CL M:SP START");


void set_doorOpen(bool open) {
  lcd.setCursor(7,1);
  
  if (open)  {
    lcd.print("OP");
  }
  if (!open) {
    lcd.print("CL");  
  }
}

void set_dir(buttonstate b) {
  lcd.setCursor(0,2);
  switch (b) {
    case EAST: lcd.print("E");
    case WEST: lcd.print("W");
    default: break;
  }
}

void set_emergency() {
  lcd.setCursor(0,0);
  lcd.print("Emergrency stop");
  lcd.setCursor(0,1);
  lcd.print("Please Reset");
}

//void lcdstate write_time(String time_str){
//  // This writes the time to the bottom right of the LCD and returns success if it works 
//  lcd.setCursor(13,1);
//  lcd.print(time_str);
//  return SUCCESS;
//};
