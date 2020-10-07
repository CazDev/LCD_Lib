#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//typedef enum { OPEN, CLOSE } open_close_state;
//typedef enum { EAST, WEST } east_west_state;
//typedef enum { START, STOP } start_stop_state;
//typedef enum { EMERGENCY, NOT_EMERGENCY } emergency_state;

// State enum
typedef enum {
  NONE,
  EAST,
  WEST,
  START,
  STOP,
  OPEN,
  CLOSE,
  EMERGENCY,
} message;

// include the library code:
#include "LiquidCrystal_I2C.h"

// initialize the library
LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup() {

  // Set baud
  Serial.begin(9600);
  
  // initialize the lcd
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();

  // Template for display
  lcd.setCursor(0, 0);
  lcd.print("S:    >     B: ");
  lcd.setCursor(0, 1);
  lcd.print("D:   M:        ");

  //Run tests
  message msg = NONE;

  // East West states
  delay(1000);
  Serial.println("EAST");
  msg = EAST;
  display_message(msg);
  delay(1000);
  Serial.println("WEST");
  msg = WEST;
  display_message(msg);

  // Start Stop states
  delay(1000);
  Serial.println("START");
  msg = START;
  display_message(msg);
  delay(1000);
  Serial.println("STOP");
  msg = STOP;
  display_message(msg);

  // Open Close states
  delay(1000);
  Serial.println("OPEN");
  msg = OPEN;
  display_message(msg);
  delay(1000);
  Serial.println("CLOSE");
  msg = CLOSE;
  display_message(msg);

  // Emergency state
  delay(1000);
  Serial.println("EMERGENCY");
  msg = EMERGENCY;
  display_message(msg);

}

void loop() {

}

//  "S:    >     B: "
//  "D:   M:        "

//S : Is used to indicate the current and next stations, CURR and NEXT will be replaced by EAST/WEST corresponding to the current and next stations

//D : Is used to indicate the state of the door, this will either be OP = Open or CL = Close

//M : Indicates the movement, this will be either ST = Start or SP = Stop

//B : Will be used to indicate the most recent accepted button press, eg ST = Start, SP = Stop, E = East, W =  West, O = Open, C = Closed, EM = Emergency

void display_message(message msg) {
  switch (msg) {
    case NONE:
      break;
    case EAST:
      lcd.setCursor(2, 0);
      lcd.print("EAST");
      lcd.setCursor(14, 0);
      lcd.print("E");
      break;
    case WEST:
      lcd.setCursor(2, 0);
      lcd.print("WEST");
      lcd.setCursor(14, 0);
      lcd.print("W");
      break;
    case START:
      lcd.setCursor(7, 1);
      lcd.print("ST");
      lcd.setCursor(14, 0);
      lcd.print("ST");
      break;
    case STOP:
      lcd.setCursor(7, 1);
      lcd.print("SP");
      lcd.setCursor(14, 0);
      lcd.print("SP");
      break;
    case OPEN:
      lcd.setCursor(2, 1);
      lcd.print("OP");
      lcd.setCursor(14, 0);
      lcd.print("OP");
      break;
    case CLOSE:
      lcd.setCursor(2, 1);
      lcd.print("CL");
      lcd.setCursor(14, 0);
      lcd.print("CL");
      break;
    case EMERGENCY:
      lcd.setCursor(14, 0);
      lcd.print("EM");
      lcd.setCursor(0, 0);
      lcd.print("Emergrency stop ");
      lcd.setCursor(0, 1);
      lcd.print("Please Reset");
      break;
    default:
      break;
  }
}

//void set_door(open_close_state oc_state) {
//  lcd.setCursor(7,1);
//  switch (oc_state) {
//    case OPEN: lcd.print("OP"); break;
//    case CLOSE: lcd.print("CL"); break;
//    default: break;
//  }
//}
//
//void set_dir(east_west_state s1) {
//  lcd.setCursor(0,2);
//  switch (s1) {
//    case EAST: lcd.print("E"); break;
//    case WEST: lcd.print("W"); break;
//    default: break;
//  }
//}
//
//void set_emergency() {
//  lcd.setCursor(0,0);
//  lcd.print("Emergrency stop");
//  lcd.setCursor(0,1);
//  lcd.print("Please Reset");
//}
