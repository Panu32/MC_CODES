#include #p184550.h>


extern void  _startup (void);
#pragma code I_R_C 1000
void reset(){
    _asm
     goto _startup
     _endasm
}
#pragma code 1008
void high_ISR(){
    _asm
     goto timer_isr
     _endasm

}

void timer_isr(){
    TMR0H = 0x6D;
    TMR0L= 0x82;
    PORTDbits.RD0= ~PORTDbits.RD0;
    INTCONbits.TMR0IF= 0;

}

void main(){
   ADCON1 = 0x0f;
   TRISD= 0x00;
   PORTD=0;

   TMR0H= 0X00;
   TMR0L= 0X00;
   T0CON = 0x03;
   INTCONbits.GIE=1

   T0CONbits.TMR0ON=1;

   while(1);


}

void msdelay(unsigned int time){
    unsigned int i,j;
    for(i=0;i<time;i++){
        for(j=0;j<710;j++){

        }
    }

}