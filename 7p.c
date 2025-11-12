#include <p184550.h>
#include "vector_relocate.h"


#define  LCD_Output PORTD
#define  ctrl PORTE
#define rs PORTEbits.RE0
#define rw PORTEbits.RE1
#define en PORTEbits.RE2

void init_LCD(void){

    LCD_cmd(0X38); // 8 bit lcd
    msdelay();

    LCD_cmd(0x01); // clear lcd
    msdelay();
    

    LCD_cmd(0x0E);// cursor off
    msdelay();

    LCD_cmd(0x80);// move cursor to first pos
    msdelay();

}

void lcd_cmd(unsigned char cmd){
    LCD_data= cmd;
    rs=0;
    rw=0;
    en=1;
    msdelay(15);
    en=0;
    msdelay(15);
}

void lcd_write(unsigned char data){
     LCD_DATA= data;
     rs=1;
     rw=0;
     en=1;
     msdelay(15);
     en=0;msdelay(15);

}

void main(){
    unsigned int val[4],ADC_Result=0,var;
    unsigned char i;
    str[]= "Result";

    TRISD= 0X00;
    TRISDE=0;

    TRISA= 0xff;
    init_LCD();

    ADCON1= 0x0c;
    


}
