#include <LiquidCrystal_PCF8574.h>
#include <Wire.h>

LiquidCrystal_PCF8574 lcd(0x27); // set the LCD address to 0x27 for a 16 chars and 2 line display

uint8_t lastButtons;

void setup()
{
  int error;

  Serial.begin(115200);
  Serial.println("LCD...");

  // wait on Serial to be available on Leonardo
  while (!Serial)
    ;

  Serial.println("Dose: check for LCD");

  // See http://playground.arduino.cc/Main/I2cScanner how to test for a I2C device.
  Wire.begin();
  Wire.beginTransmission(0x27);
  error = Wire.endTransmission();
  Serial.print("Error: ");
  Serial.print(error);

  if (error == 0) {
    Serial.println(": LCD found.");

    lcd.begin(16, 2); // initialize the lcd
    lcd.clear();
    lcd.home();
    lcd.print ("buttons test");
    lcd.setBacklight(1);
  } else {
    Serial.println(": LCD not found.");
    while(1) {}
  } // if

} // setup()


void loop()
{
  uint8_t buttons = lcd.readKeys();
  if (buttons!=lastButtons) {
    lcd.setCursor(0,1);
    lcd.printf ("%02X", buttons);
    lastButtons = buttons;  
  }
  
} // loop()
