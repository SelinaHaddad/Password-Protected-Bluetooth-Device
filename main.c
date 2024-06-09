#include<reg51.h>
#include<intrins.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "components.h"
void main(void)
{
lcd_init(); // initialize the LCD
lcd_cmd(0x80); // First line on LCD
lcd_str(" Bluetooth "); // String on the first line
delay_s(5);
lcd_cmd(0xc0); // Second line on LCD
lcd_str("Lock System"); // String on the second line
delay_s(5);
lcd_cmd(0x01); // Clear LCD
while(1)
{
keypad(); // Scanning the 4*4 key array
if(strncmp(pass,"C420",4)==0) // Comparing for correct passkey
{
accept(); // Display passkey correct message
correct_sound(); // Play Sound to indicate correct passkey
lcd_cmd(0x01);
lcd_cmd(0x80);
lcd_str("Access Granted ");
delay_s(30);
lcd_cmd(0x01);
bluetooth(); // Access granted to bluetooth to send messages and control LEDs
break;
}
else
{
lcd_cmd(0x01);
lcd_cmd(0x80);
lcd_str("Access Denied");
incorrect_sound(); // Play Sound to indicate correct passkey
wrong(); // Display passkey correct message
delay_s(5);
lcd_cmd(0x01);
}
}
}
