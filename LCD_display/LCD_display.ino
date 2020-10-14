// import LCD library
#include <LiquidCrystal_I2C.h>

// initialize the library
LiquidCrystal_I2C lcd(0x27, 20, 4);

// enums for states
enum open_close_state { OPEN, CLOSE, OC_CLEAR };
enum start_stop_state { START, STOP, NONE, SS_CLEAR }; 
enum emergency_state { EMERGENCY, NOT_EMERGENCY };
enum curr_state { C_EAST, C_WEST, C_CLEAR };
enum next_state { N_EAST, N_WEST, N_CLEAR };

open_close_state op_cl_state = OC_CLEAR;
start_stop_state st_sp_state = SS_CLEAR;
emergency_state em_state = NOT_EMERGENCY;
curr_state c_state = C_CLEAR;
next_state n_state = N_CLEAR;

char line1[16] = "S:    >     B: ";
char line2[16] = "D:   M:        ";

/*
 * Layout will be as follows on 16x2 lcd
 * "S:    >     B: "
 * "D:   M:        "
*/

/*
   S : Is used to indicate the current and next stations:
   CURR and NEXT will be replaced by EAST/WEST corresponding to the current and next stations
   
   D : Is used to indicate the state of the door, this will either be:
   OP = Open or CL = Close
   
   M : Indicates the movement, this will be either:
   ST = Start or SP = Stop
   
   B : Will be used to indicate the most recent accepted button press.
   eg ST = Start, SP = Stop, E = East, W =  West, O = Open, C = Closed, EM = Emergency
*/

void setup() {
  // Set baud rate
  Serial.begin(9600);

  // initialize the lcd
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
}

void loop() {
  display_open_close(op_cl_state);
  display_start_stop(st_sp_state);
  display_emergency(em_state);
  display_curr(c_state);
  display_next(n_state);

  // write lines to display
  lcd.setCursor(0, 0);
  lcd.print(line1);
  lcd.setCursor(0, 1);
  lcd.print(line2);
  
  delay(500);
}

void insert_chars(char insert, char *line, int index){
   char msg[10];
   char buffer[10];
   strcpy(msg, line);
   strcpy(buffer, msg);
   buffer[index] = insert;
   strcpy(&buffer[index + 1], &msg[index]);
}

// topleft state display - line2, index 14

void display_open_close(open_close_state s) {
  switch (s) {
    case OPEN:
      // line2, index 2: OP
      break;
    case CLOSE:
      // line2, index 2: CL
      break;
    default:
      break;
  }
}

void display_start_stop(start_stop_state s) {
  switch (s) {
    case START:
      // line2, index 7: ST
      break;
    case STOP:
      // line2, index 7: SP
      break;
    default:
      break;
  }
}

void display_emergency(emergency_state s) {
  switch (s) {
    case EMERGENCY:
      strcpy(line1, "Emergrency stop");
      strcpy(line2, "Please Reset   ");
      break;
    case NOT_EMERGENCY:
      // Do nothing when there is no emergency state
      break;
    default:
      break;
  }
}

void display_curr(curr_state s) {
    switch (s) {
    case C_EAST:
      // line1, index 2: EAST
      break;
    case C_WEST:
      // line1, index 2: WEST
      break;
    default:
      break;
  }
}

void display_next(next_state s) {
    switch (s) {
    case N_EAST:
      // line1, index 7: EAST
      break;
    case N_WEST:
      // line1, index 7: WEST
      break;
    default:
      break;
  }
}
