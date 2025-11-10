// LCD EXPERIMENT
#include <p18f4550.h>
#include "vector_relocate.h"

#define LCD_DATA PORD
#define ctrl PORTE
#define rs PORTEbits.RE0
#define rw PORTbits.RE1
#define en PORTbits.RE2

void init_LCD(void);
void LCD_command(unsigned char cmd);
void LCD_data(unsigned char data);
void LCD_write_string(static char* str);
void msdelay(unsigned int time);

void main(void){
    char var1[]= "PICT";
    char var2[]= "COLLEGE";

    ADCON1= 0X0F;
    TRISD= 0X00;
    TRISE= 0X00;


    init_LCD();
    msdelay(50);

    LCD_write_string(var1);
    msdelay(15);


    LCD_command(0xc0);
    LCD_write_string(var2);
    
    while(1);

}

void init_LCD(){
    LCD_command(0x38);

    msdelay(15);

    LCD_command(0x0c);
    msdelay(15);

    LCD_command(0x0c);
    msdelay(15);

    LCD_command(0x80);
    msdelay(15);
}