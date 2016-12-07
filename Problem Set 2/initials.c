#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void){
    
    
    
    string gName=GetString();
    
    char firstInitial = gName[0];
    printf("%c", toupper(firstInitial));
    
    int i, n;
    for(i=0, n=strlen(gName); i<n; i++){
        
        if(gName[i] == 32 ){
            
            char c=gName[i+1];
            printf("%c", toupper(c));
            i++;
        }
    }
    
    printf("\n");
    
    
    
}