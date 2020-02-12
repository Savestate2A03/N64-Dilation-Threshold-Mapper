// N64 Communication Libraries by Andrew Brown
// Check files for their respective licenses.

// Adapter math by Savestate aka Joseph El-Khouri
// Retiming for an 8MHz arduino by Jademalo
// Non-library portions of code are Public Domain

#include "pins_arduino.h"
#include "N64Controller.h"
#include "N64Communication.cpp"
#include <math.h>

#define THRESHOLD 67 // What radius the dilation kicks in
#define EXPAND 163   // What radius to dilate to

N64Controller n64c (10); // This controller for player one is on PIN 10
                         // N64Communication.h has N64 pin on PIN 8
                         
void setup()
{
  n64c.begin(); // Initialisation
  //Serial.begin(57600);
  n64_init();

}

void expando(signed char* x_axis, signed char* y_axis) {
  if (sqrt(pow(*x_axis, 2) + pow(*y_axis, 2)) < THRESHOLD)
    // don't apply dialation if distance from center < THRESHOLD
    return;
  // Get the angle of the input then apply the dialation to it so that the
  // input is mapped to the desired radius / distance from the reset point. 
  double angle = atan2((double)(*y_axis), (double)(*x_axis));
  double temp_x = min(max(-128.0, (round(EXPAND * cos(angle)))),127.0);
  double temp_y = min(max(-128.0, (round(EXPAND * sin(angle)))),127.0);
  *x_axis = ((signed char)temp_x);
  *y_axis = ((signed char)temp_y);
  return;
}

// Prepare the data to send to the N64
// n64_buffer is defined in N64Communication.h
void buffer_setup() {
  char x = n64c.axis_x();
  char y = n64c.axis_y();
  expando(&x, &y);
  n64_buffer[0] =    n64c.A() << 7 |      n64c.B() << 6 |      n64c.Z() << 5 | n64c.Start() << 4 |
                  n64c.D_up() << 3 | n64c.D_down() << 2 | n64c.D_left() << 1 | n64c.D_right();
  n64_buffer[1] =                                                    n64c.L() << 5 |     n64c.R() << 4 | 
                  n64c.C_up() << 3 | n64c.C_down() << 2 | n64c.C_left() << 1 | n64c.C_right();
  n64_buffer[2] = x;
  n64_buffer[3] = y;
}

void loop() {
    n64c.update();      // get controller inputs
    buffer_setup();     // process controller inputs 
    //n64c.print_N64_status_alt();
    n64_command_wait(); // block for N64 to send controller inputs
}
