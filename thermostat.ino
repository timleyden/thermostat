
// include the library code:
#include <LiquidCrystal.h>
#define compRelayPin 2 //this is pin D2 on the board
#define tempPropePin 1 //this is pin A1 on the board
float temp = 0.0;
float compOffTemp = 19.0;
float compOnTemp = 24.0;


// initialize the library with the numbers of the interface pins
//LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Awesome Thermostat!");
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  temp = analogRead(tempPropePin)*5/1024.0;
  temp = temp - 0.5;
  temp = temp / 0.01;
  lcd.print(temp);
  lcd.setCursor (5,1);//shift lcd cursor 5 spaces to print compressor state
  //if the temp is below set temp turn off compressor
  if(temp < compOffTemp){
    digitalWrite(compRelayPin, LOW);
    lcd.print("comp:off");
  }
  //if the temp is too high turn on the compressor
  else if(temp > compOnTemp){
    digitalWrite(compRelayPin, HIGH);
    lcd.print("comp:on");
  }
  delay(2000); //sleep for 2 secods
  // print the number of seconds since reset:
  //lcd.print(millis() / 1000);
}

