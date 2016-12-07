#include<cs50.h>
#include<stdio.h>


int main(void){
    
   int n;
   do{
       printf("Please give me the height of the half-pyramid:");
       n = GetInt();
   }
   while(n<0 || n>23); //prompt the user for the height of the half-pyramid

if(n!=0){

for(int i=0;i<n;i++){
    
    int s=i; //s=space; 
    
    while(s<n-1){
         printf(" ");
         s++;
    } //print spaces
    
    printf("#");
    
    int h=0; //h=hash;
    
    do{
        printf("#");
        h++;
    }
    while(h<=i); //print hashtags
    
    printf("\n");
    
    
} //loop the heights; when i=n, loop stop.

}

else {
    
    return 0;
}

  
  
  
  }
  