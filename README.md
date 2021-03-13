# Arduino Library for LiquidCrystal displays with I2C PCF8574 adapter

A library for driving LiquidCrystal displays (LCD) by using the I2C bus and an PCF8574 I2C adapter.

There are modules that can be soldered or stacked to the display that offers a I2C interface for communication instead of the 8+ digital lines that are used to send data to the display.

Most of these modules used the internal wiring that is supported by this library. If you use a module with a different wiring you can adjust this in the code (see comments). 

Added schematic to read the state of four buttons using the unused R/W signal and the four data lines. Could probably support 5 buttons by also using the RS line. Should probably leave the E signal alone since it enables the LCD module.

See the web site for more details and pictures: <https://www.mathertel.de/Arduino/LiquidCrystal_PCF8574.aspx>

