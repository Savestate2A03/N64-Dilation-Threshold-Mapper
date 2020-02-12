# N64 Dilation Threshold Mapper
Designed to dilate your N64 control stick after a certain threshold to a certain radius / distance.

Programmed for the Arduino Nano. 

## Modifications
Modify `THRESHOLD` to change when the dilation kicks in.

Modify `EXPAND` to set the radius the coordinates dilate to from the center.

## Pins
By default, PIN 8 is your N64 console data line, and PIN 10 is is your N64 controller data line. 

Hook ground for both the controller and console up to ground on the Nano.

N64 controller power can go into 3.3v, or take power from the N64, however you wish (I use the Nano's 3.3v line)

N64 console power can either go into the controller, or be left loose. 

Use a logic level shifter so you're not sending 5v logic back to the N64/Controller from the Nano. 

## 8MHz + 3.3v option

If you have the capabilities to flash the bootloader (ex by ISP or another Ardiuno), there's a [branch of this repo](https://github.com/Savestate2A03/N64-Dilation-Threshold-Mapper/tree/8mhz-3.3v) by [Jademalo](https://github.com/Jademalo) that works at 8MHz which allows for an operating voltage of 3.3v which gets around having to step up the voltage to 5v and having to set up a logic level shifter. 

## Credits

Arduino N64 Controller Library by Kai Luke: https://github.com/pothos/arduino-n64-controller-library

N64 Console Communication from Andrew Brown: https://github.com/brownan/Gamecube-N64-Controller

