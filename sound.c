#include<reg51.h>
#include "components.h"
void delay(unsigned char p,unsigned char q)
{
TMOD=0x01; //timer0 mode1(16 bit)
TL0=q; //load TL0
TH0=p; //load TH0
TR0=1; //turn on T0
while(TF0==0); // wait for flag generation
TR0=0; // turn off T0
TF0=0; // clear TF0
}
void play(unsigned char j,unsigned char k)
{
int i;
for(i=0;i<1000;i++) //to play sound
{
out=1;
delay(j,k);
out=0;
delay(j,k);
}
}
int l;
void correct_sound(void)
{
play(0xff,0xa3); //playing sound of frequency of 5000 hertz with a delay between two frequencies if
entered password is correct
for(l=0;l<5;l++)
{
delay(0x00,0x00);
}
play(0xff,0xd1); //playing sound of frequency of about 10000 hertz with a delay between two frequencies as
a cont. of correct password entered sound
for(l=0;l<5;l++)
{
delay(0x00,0x00);
}
}
void incorrect_sound(void)
{
play(0xfe,0x33); //playing sound of frequency of about 1000 hertz with a delay between two
frequencies if entered password is incorrect
for(l=0;l<5;l++)
{
delay(0x00,0x00);
}
}
