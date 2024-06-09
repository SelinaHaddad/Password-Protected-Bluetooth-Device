#ifndef _COMPONENTS_H_
#define _COMPONENTS_H_
// Pin Definition for LCD
sbit rs=P2^6;
sbit rw=P2^5;
sbit en=P2^7;
#define lcd P0
// Pin Definintion for keypad
sbit col1=P1^3;
sbit col2=P1^2;
sbit col3=P1^1;
sbit col4=P1^0;
sbit row1=P1^7;
sbit row2=P1^6;
sbit row3=P1^5;
sbit row4=P1^4;
// Pin Definition for Buzzer
sbit out=P2^5;
// Pin Definition for 4 LEDs
sbit LED1 = P2^0;
sbit LED2 = P2^1;
sbit LED3 = P2^2;
sbit LED4 = P2^3;
// Functions for LCD
void lcd_cmd(unsigned char);
void lcd_init(void);
void lcd_data(unsigned char);
void delay_s(int itime);
void lcd_str(unsigned char *);
// Functions for keypad
void accept(void);
void wrong(void);
void keypad(void);
extern char pass[4];
extern char i;
// Functions for sound
void delay(unsigned char p,unsigned char q);
void play(unsigned char j,unsigned char k);
void correct_sound(void);
void incorrect_sound(void);
// Functions for bluetooth
void serial_init(void);
void tx_data(char ch);
void rx_data(void);
void uart_str(char *str);
void bluetooth(void);
#endif
