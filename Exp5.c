#include <p18f4550.h>
#include "vector_relocate.h"

#define lrbit PORTBbits.RB1 //SW0 interfaced to RB1
#define rlbit PORTBbits.RB0 //SW1 interfaced to RB0
#define buzzer PORTCbits.RC2
#define relay PORTDbits.RD7

void msdelay(unsigned int time);

//start of the program
void main(){
    unsigned char i,val=0;
    INTCON2bits.RBPU=0;  // to output internal pull up on portB
    ADCON1= 0X0F;  // to disable all the analog inputs


    TRISBbits.RB0 =1;  //INPUT SW1
    TRSIBbits.RB1=1;   //INPUT SW0

    TRISDbits.TRISD7=0; // OUTPUT RELAY
    TRISCbits.TRISC2=0; // OUTPUT BUZZER
    TRISA= 0X00;       //PORTA as OUTPUT

    PORTA= 0X00;
    buzzer=0;       // Intial values of all 3
    relay=0;

    while(1){
        if(lrbit == 0){
            val =1;
        }
        if(rlbit==0){
            val =2;
        }

        if(val == 1){
            buzzer=1;
            relay=1;

            PORTA= 0x20;
            msdelay(50);
            for(i=0;i<8;i++){
                PORTA= PORTA>>1; //shift right by 1
                msdelay(50);
                
            }
        }

        if(val==2){
            buzzer= 0;
            relay=0;
            PORTA= 0x01;

            msdelay(50);
            for(i=0;i<8;i++){
                msdelay(50);
                PORTA= PORTA<<1;
            }
        }
    }

}

void msdelay(unsigned int time){
     unsigned int i,j;
     for(i=0;i<time;i++){
        for(j=0;j<710;j++){
            
        }
     }
}