/* main.c

   This file written 2024 by Artur Podobas and Pedro Antunes

   For copyright and licensing, see file COPYING */


/* Below functions are external and found in other files. */
extern void print(const char*);
extern void print_dec(unsigned int);
extern void display_string(char*);
extern void time2string(char*,int);
extern void tick(int*);
extern void delay(int);
extern int nextprime( int );

int mytime = 0x5957;
char textstring[] = "text, more text, and even more text!";

const int segment_map[10] = {
  0x3F, // 0 00111111
  0x06, // 1 00000110
  0x5B, // 2 01011011
  0x4F, // 3 01001111
  0x66, // 4 01100110
  0x6D, // 5 01101101
  0x7D, // 6 01111101
  0x07, // 7 00000111
  0x7F, // 8 01111111
  0x6F, // 9 01101111
};

/* Function to turn LED's on or off*/
void set_leds(int led_mask) {
  volatile int *leds = (int *)0x04000000; // address of the LED's
  *leds = led_mask & 0x3FF; // 0x3FF = 001111111111, only care about the 10 lsb
}
/* Function to increment the 4 first LED's */
void increment_leds() {
  int led_value = 0;
  set_leds(led_value); 

  while (led_value < 0xF) { // run until led_value = 1111 (0xF)
    delay (1000); // change value to get accurate seconds
    led_value++;
    set_leds(led_value);
  }
}
/* Function to set a value to a desired display */
void set_displays (int display_number, int value) {
  volatile int *display = (int *)0x04000050 + (display_number * 0x10);
  *display = ~segment_map[value] & 0x7F; // 0x7F = 01111111, 7 lsb
}

int get_sw(void) {
  volatile int *switches = (int *)0x04000010;
  return *switches & 0x3FF; // 0x3FF = 001111111111, 10 lsb
}

int get_btn (void) {
  volatile int *button = (int *)0x040000d0;
  return *button & 0x1; // 0x1 = 0001, 1 lsb
}

/* Below is the function that will be called when an interrupt is triggered. */
void handle_interrupt(unsigned cause) 
{}

/* Add your code here for initializing interrupts. */
void labinit(void)
{}

/* Your code goes into main as well as any needed functions. */
int main() {
  // Call labinit()
  labinit();

  // Enter a forever loop
  while (1) {
    time2string( textstring, mytime ); // Converts mytime to string
    display_string( textstring ); //Print out the string 'textstring'
    delay( 1000 );          // Delays 1 sec (adjust this value)
    tick( &mytime );     // Ticks the clock once
  }
}


