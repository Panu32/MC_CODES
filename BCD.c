#include <reg51.h>

void msdelay(unsigned int time);

void main(){
    unsigned int x,y;

    for(x=0;x<9;x++){
        for(y=0;y<9;y++){
            msdelay(5000);
            P1= x<<4|y;
        }
    }
}

void msdelay(unsigned int time){
   unsigned int i,j;
   for(i=0;i<time;i++){
    for(j=0;j,1275;j++){

    }
   }
}

