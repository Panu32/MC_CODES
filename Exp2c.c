#include <reg51.h>

void msdelay(unsigned int time);

void main(){
    unsigned int z;
    for(z= 'A';z<='Z';z++){
        msdelay(5000);
        P1=z;
    }
}

void msdelay(unsigned time){
    unsigned int i,j;
    for(i=0;i<1275;i++){
        
    }
}