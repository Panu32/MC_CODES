//************************************************************
// EXPERIMENT 2: LCD INTERFACING WITH PIC18F4550
//************************************************************
// AIM: To interface a 16x2 LCD with PIC18F4550 and display
//      "PICT" on the first line and "COLLEGE" on the second line.
//************************************************************

//-----------------------------
// HEADER FILES
//-----------------------------
#include <p18f4550.h>           // PIC18F4550 definitions
#include "vector_relocate.h"    // Vector relocation file for MPLAB setup

//-----------------------------
// LCD CONNECTIONS
//-----------------------------
// LCD data lines (D0–D7) → PORTD
// LCD control lines (RS, RW, EN) → PORTE
#define LCD_DATA PORTD
#define ctrl PORTE
#define rs PORTEbits.RE0         // RS pin → RE0
#define rw PORTEbits.RE1         // RW pin → RE1
#define en PORTEbits.RE2         // EN pin → RE2

//-----------------------------
// FUNCTION DECLARATIONS
//-----------------------------
void init_LCD(void);                          // Initialize LCD
void LCD_command(unsigned char cmd);          // Send command to LCD
void LCD_data(unsigned char data);            // Send data (character) to LCD
void LCD_write_string(static char *str);      // Display string on LCD
void msdelay(unsigned int time);              // Delay function

//************************************************************
// MAIN PROGRAM
//************************************************************
void main(void)
{
    char var1[] = "PICT";       // Message for first line
    char var2[] = "COLLEGE";    // Message for second line

    ADCON1 = 0x0F;              // Configure all analog pins as digital I/O
    TRISD = 0x00;               // Set PORTD as output (LCD data lines)
    TRISE = 0x00;               // Set PORTE as output (LCD control lines)

    init_LCD();                 // Initialize the LCD
    msdelay(50);                // Small startup delay

    LCD_write_string(var1);     // Display "PICT" on first line
    msdelay(15);

    LCD_command(0xC0);          // Command: Move cursor to 2nd line (0xC0)
    msdelay(15);
    LCD_write_string(var2);     // Display "COLLEGE" on second line

    while(1);                   // Infinite loop (hold display)
}

//************************************************************
// FUNCTION DEFINITIONS
//************************************************************

//------------------------------------------------------------
// Function: init_LCD()
// Purpose : Initialize the 16x2 LCD in 8-bit mode
//------------------------------------------------------------
void init_LCD(void)
{
    LCD_command(0x38);   // Command: 8-bit mode, 2 lines, 5x7 font
    msdelay(15);

    LCD_command(0x01);   // Command: Clear display
    msdelay(15);

    LCD_command(0x0C);   // Command: Display ON, Cursor OFF
    msdelay(15);

    LCD_command(0x80);   // Command: Move cursor to first line, position 0
    msdelay(15);
}

//------------------------------------------------------------
// Function: LCD_command()
// Purpose : Send instruction/command to LCD
//------------------------------------------------------------
void LCD_command(unsigned char cmd)
{
    LCD_DATA = cmd;      // Put command on data lines (PORTD)
    rs = 0;              // RS = 0 → Command mode
    rw = 0;              // RW = 0 → Write operation
    en = 1;              // EN = 1 → Enable high
    msdelay(15);         // Short delay for LCD to read
    en = 0;              // EN = 0 → Falling edge latches command
}

//------------------------------------------------------------
// Function: LCD_data()
// Purpose : Send character data to LCD
//------------------------------------------------------------
void LCD_data(unsigned char data)
{
    LCD_DATA = data;     // Put character on data lines
    rs = 1;              // RS = 1 → Data mode
    rw = 0;              // RW = 0 → Write operation
    en = 1;              // EN = 1 → Enable high
    msdelay(15);         // Wait for LCD to latch data
    en = 0;              // EN = 0 → Data written
}

//------------------------------------------------------------
// Function: LCD_write_string()
// Purpose : Display an entire string on LCD
//------------------------------------------------------------
void LCD_write_string(static char *str)
{
    int i = 0;
    while (str[i] != 0)         // Loop until end of string
    {
        LCD_data(str[i]);       // Send each character to LCD
        msdelay(15);
        i++;
    }
}

//------------------------------------------------------------
// Function: msdelay()
// Purpose : Generate software delay
//------------------------------------------------------------
void msdelay(unsigned int time)
{
    unsigned int i, j;
    for (i = 0; i < time; i++)
        for (j = 0; j < 710; j++);  // Adjusted for approx. 1ms delay at 4MHz clock
}
