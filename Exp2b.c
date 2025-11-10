#include <reg51.h>

void msdelay(unsigned int);

void main(){
    unsigned int z;
    while(1){
        for(z=0;z<9;z++){
            msdelay(50000);
            P1= P1>>1;
        }
    }
}

void msdelay(unsigned int time){
    unsigned int i,j;
    for(i=0;i<time;i++){
        for(j=0;j<1275;j++){
            
        }
    }
}