#include<reg51.h>
#include<intrins.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "components.h"
// Define global variables used in this file
char pass[4],i=0; // Array to store password characters and index variable
// Function to display strings on LCD when the password is correct
void accept()
{
lcd_cmd(0x01);
lcd_cmd(0x80);
lcd_str("Welcome");
lcd_cmd(0xc0);
lcd_str("Password Accept");
delay_s(5);
}
// Function to display strings on LCD when the password is incorrect
void wrong()
{
lcd_cmd(0x80); //first line
lcd_str("Wrong Passkey");
lcd_cmd(0xc0); //second line
lcd_str("Please Try Again");
delay_s(5);
}
// Function to scan the 4*4 keypad
void keypad()
{
int cursor=0xc0,flag=0; // Variables for cursor position and flag
lcd_cmd(0x80);
lcd_str("Enter Ur Passkey");
lcd_cmd(0xc0);
i=0; // Initialize index variable for scanning keys
while(i<4)
{
flag=cursor; // Store cursor position
// Scanning the FIRST column
col1=0; // Pass 0 to column 1
col2=col3=col4=1; // Pass 1 to other columns
if(!row1) // Check if row 1 is pressed
{
lcd_data('1'); // Display '1' on LCD
pass[i++]='1'; // Store '1' in password array
cursor++; // Move cursor to the next position
while(!row1); // Wait for key release
}
else if(!row2) // Check if row 2 is pressed
{
lcd_data('4');
pass[i++]='4';
cursor++;
while(!row2);
}
else if(!row3) // Check if row 3 is pressed
{
lcd_data('7');
pass[i++]='7';
cursor++;
while(!row3);
}
else if(!row4) // Check if row 4 is pressed
{
lcd_data('*');
pass[i++]='*';
cursor++;
while(!row4);
}
// Scanning the SECOND column
col2=0; // Pass 0 to column 2
col1=col3=col4=1; // Pass 1 to other columns
if(!row1) // Check if row 1 is pressed
{
lcd_data('2');
pass[i++]='2';
cursor++;
while(!row1);
}
else if(!row2) // Check if row 2 is pressed
{
lcd_data('5');
pass[i++]='5';
cursor++;
while(!row2);
}
else if(!row3) // Check if row 3 is pressed
{
lcd_data('8');
pass[i++]='8';
cursor++;
while(!row3);
}
else if(!row4) // Check if row 4 is pressed
{
lcd_data('0');
pass[i++]='0';
cursor++;
while(!row4);
}
// Scanning the THIRD column
col3=0; // Pass 0 to column 3
col1=col2=col4=1; // Pass 1 to other columns
if(!row1) // Check if row 1 is pressed
{
lcd_data('3');
pass[i++]='3';
cursor++;
while(!row1);
}
else if(!row2) // Check if row 2 is pressed
{
lcd_data('6');
pass[i++]='6';
cursor++;
while(!row2);
}
else if(!row3) // Check if row 3 is pressed
{
lcd_data('9');
pass[i++]='9';
cursor++;
while(!row3);
}
else if(!row4) // Check if row 4 is pressed
{
lcd_data('#');
pass[i++]='#';
cursor++;
while(!row4);
}
// Scanning the FOURTH column
col4=0; // Pass 0 to column 4
col1=col3=col2=1; // Pass 1 to other columns
if(!row1) // Check if row 1 is pressed
{
lcd_data('A');
pass[i++]='A';
cursor++;
while(!row1);
}
else if(!row2) // Check if row 2 is pressed
{
lcd_data('B');
pass[i++]='B';
cursor++;
while(!row2);
}
else if(!row3) // Check if row 3 is pressed
{
lcd_data('C');
pass[i++]='C';
cursor++;
while(!row3);
}
else if(!row4) // Check if row 4 is pressed
{
lcd_data('D');
pass[i++]='D';
cursor++;
while(!row4);
}
// Displaying '*' in place of the passkey characters
if(i>0)
{
if(flag!=cursor) // Check if cursor moved
delay_s(5);
lcd_cmd(cursor-1); // Move cursor back one position
lcd_data('*'); // Display '*' instead of the character
}
}
}
