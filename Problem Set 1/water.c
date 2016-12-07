#include <cs50.h>
#include <stdio.h>

int main(void){
    
    printf("Please state how many minutes you take shower:");
    int n=GetInt()*12;
    printf("You use %i bottles of water to shower.\n", n);
    
}