#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void){
    
    float n;
    
    do{
        printf("How much changes:");
        n=GetFloat();
    }
    while(n<0); // get a positive float 
    
    int m=roundf(n*100); //
    
    int i=0;
    
    while(m>=25){
        
        m=m-25;
        i++;
    }
    
   while(m>=10 && m<25){
       
       m=m-10;
       i++;
   }
   
   while(m<10 && m>=5){
       
       m=m-5;
       i++;
   }
   
   while(m<5 && m>=1){
       
       m=m-1;
       i++;
   }
    
    printf("%d\n", i);
    
}


