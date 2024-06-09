#include<reg51.h>
#include<intrins.h>
#include "components.h"
// The delay function used in all files
// But defined under LCD.c
void delay_s(int itime)
{
int i,j;
for(i=0;i<itime;i++)
for(j=0;j<1275;j++);
}
// Function to write commands to LCD
// Commands like to clear display, Line 1 or 2 etc...
void lcd_cmd(unsigned char cmd)
{
rs=0; // Register Select
rw=0; // Read-Write Select
lcd=cmd;
en=1; // Chip Enable
delay_s(2);
en=0;
}
// Function to initialize the LCD
// Uses lcd_cmd to send commands to LCD
void lcd_init(void)
{
lcd_cmd(0x38); //38 for 8 bit mode .... 28 for 4 bit mode
lcd_cmd(0x10); // move cursor to right
lcd_cmd(0x01); // to clear display
lcd_cmd(0x06); // entry mode
lcd_cmd(0x0c); // display on and cursor on
}
// Function to write data to the LCD
void lcd_data(unsigned char ch)
{
rs=1;
rw=0;
lcd=ch;
en=1;
delay_s(10);
en=0;
}
// Function to write a string to the LCD
// Uses lcd_data() defined previously
void lcd_str(unsigned char *v)
{
unsigned char s=0;
while(v[s]!='\0')
{
lcd_data(v[s]);
s++;
delay_s(15);
}
}
