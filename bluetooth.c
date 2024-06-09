#include<reg51.h>
#include<string.h>
#include "components.h"
char val[20]=""; // Global variable to store received data (buffer)
void serial_init()
{
SCON = 0x50; // 8 bit UART mode 1, REN = 1
TMOD = 0x20; // TMOD: timer 1, mode 2, 8-bit reload
TH1 = 0xFD; // load divisor to Timer 1 High Byte (TH1)
TR1 = 1; // TR1: timer 1 run
}
void tx_data(char ch)
{
SBUF = ch; // Load character into serial buffer
while(TI == 0); // Wait until transmission is complete
TI = 0; // Clear transmission flag
}
// Function to receive data over UART
// Basically, Phone --> UART --> LCD
void rx_data(void)
{
int i = 0; // Index variable
char ch,lcd[20]=""; // Temporary character & string to be passed to LCD
lcd_cmd(0x01);
lcd_cmd(0x80);
lcd_str("Receiving....");
lcd_cmd(0xc0);
while(1)
{
while(RI==0); // Wait until data is received
RI = 0; // Clear receive interrupt flag
ch = SBUF; // Read received character
val[i]=ch; // Store character in buffer
if(ch == '\n') // Check for newline character to terminate reception.
{
break;
}
i++; // increment buffer
}
// Copy received data to LCD string, excluding newline character
strncpy(lcd,val,strlen(val)-2);
lcd_str(lcd); // Display received data on LCD.
delay_s(20);
}
// Function to transmit a string over UART
// Basically, UART --> Phone
void uart_str(char *str)
{
char lcd[16]=""; // Temporary LCD display string
int i;
lcd_cmd(0x01);
lcd_cmd(0x80);
lcd_str("Transmitting...");
lcd_cmd(0xc0);
// Loop through the string characters and transmit them one by one
for(i=0;str[i]!=0;i++)
{
tx_data(str[i]);
}
// Pass transmitted data to lcd_str(), excluding newline character
strncpy(lcd,str,strlen(str)-2);
lcd_str(lcd); // Display transmitted data on LCD
delay_s(30);
}
void bluetooth(void)
{
char val1[16]=""; // Temporary buffer for received data from the user phone
lcd_init(); // Initialize LCD display
serial_init(); // Initialize serial communication.
while(1)
{
rx_data(); // Call function to receive data over UART
// Copy received data (input from phone) to temporary buffer, excluding \n
strncpy(val1,val,strlen(val)-2);
// If input == LED1 -> Toggle LED1
if(strcmp(val1,"LED1")==0)
{
if(LED1 != 0)
{
uart_str("LED1 ON\r\n");
LED1 = ~LED1;
}
else
{
uart_str("LED1 OFF\r\n");
LED1 = ~LED1;
}
}
// If input == LED2 -> Toggle LED2
else if(strcmp(val1,"LED2")==0)
{
if(LED2 != 0)
{
uart_str("LED2 ON\r\n"); // Transmit this to the user phone and LCD
// Lets call whatever we transmit
'Modified string'
LED2 = ~LED2;
}
else
{
uart_str("LED2 OFF\r\n"); // Modified String
LED2 = ~LED2;
}
}
// If input == LED3 -> Toggle LED3
else if(strcmp(val1,"LED3")==0)
{
if(LED3 != 0)
{
uart_str("LED3 ON\r\n"); // Modified String
LED3 = ~LED3;
}
else
{
uart_str("LED3 OFF\r\n"); // Modified String
LED3 = ~LED3;
}
}
// If input == LED4 -> Toggle LED4
else if(strcmp(val1,"LED4")==0)
{
if(LED4 != 0)
{
uart_str("LED4 ON\r\n"); // Modified String
LED4 = ~LED4;
}
else
{
uart_str("LED4 OFF\r\n"); // Modified String
LED4 = ~LED4;
}
}
// If input is a string write it to LCD using lcd_str()
else if(val[0]=='1')
{
lcd_cmd(0x01); // Clear LCD display
lcd_cmd(0x80); // Move cursor to the beginning of the first line
strcpy(val1,val+1); // Copy received string to temporary buffer
memset(val,0,20); // Clear the main buffer
// Copy modified string back to main buffer, excluding \n
strncpy(val,val1,strlen(val1)-2);
lcd_str(val); // Display modified string on LCD
delay_s(8);
}
// Clear main and temporary buffers for next iteration
memset(val,0,20);
memset(val1,0,16);
}
}
