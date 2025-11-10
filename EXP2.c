#include <reg51.h>

void msdelay(unsigned time);

void main(){
   while(1){
     P1= 0X55;
     msdelay(50000);
     P2= 0xAA;
     msdelay(50000);
   }
}

void msdelay(time){
    unsigned int i,j;
    for( i=0;i<time;i++){
        for(j=0;j<1275;j++){

        }
    }

}