#include <p184550.h>
#include "vector_relocate.h"


#define  LCD_Output PORTD
#define  ctrl PORTE
#define rs PORTEbits.RE0
#define rw PORTEbits.RE1
#define en PORTEbits.RE2

void init_LCD(void){

    LCD_cmd(0X38);
    msdelay();

    LCD_cmd(0x01);
    msdelay();
    

    LCD_cmd(0x0E);
    msdelay();

    LCD_cmd(0x80);
    msdelay();

}
