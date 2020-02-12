# 8MHz Arduino Nano Bootloader

This file is a replacement arduino nano bootloader that clock divides to 8mhz, meaning it should run better at 3.3v  
https://www.ba0sh1.com/blog/2013/03/30/tutorial-3-3v-hacking-for-arduino-nano/  
https://www.arduino.cc/en/tutorial/arduinoISP  

`"C:\Program Files (x86)\Arduino\hardware\tools\avr/bin/avrdude" -C"C:\Program Files (x86)\Arduino\hardware\tools\avr/etc/avrdude.conf" -v -patmega328p -cstk500v1 -PCOM4 -b19200 -Uflash:w:"ATmegaBOOT_168_atmega328_pro_16MHzDiv2.hex":i -Ulock:w:0x0F:m`  

File->Examples->ArduinoISP in the arduino ide  
Load that onto a second arduino you're using to flash the nano  
edit the above command for the correct com port of the arduino you're using to flash and the right path to the hex file and to where the arduino ide is installed, that was mine  

Or if you have a proper isp just use that  


Aim of this is to be able to run it from the 3.3v of the N64 controller port without the CPU being overclocked. This means no additional hardware is needed.  
