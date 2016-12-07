#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, string argv[]){
    
    if(argc != 2) {
        
        printf("Invalid Input!\n");
    
        return 1; 
    
    } // check if argc is valid
        
    else {
        

            int k = atoi(argv[1]); 
            
                
    if (k<0) {
        
        printf("Invalid Input!\n");
        return 2;
    }
    
    else {
    
    string s = GetString(); //get the message
    int i, n;
    int a_Order; //alphabetical order
    int c_Order; //ascii order

    for(i=0, n=strlen(s); i<n; i++ ){
        
        if(s[i]>='a' && s[i]<='z'){
            
        a_Order=(s[i]-'a'+k)%26; 
        c_Order=a_Order+'a';
        
        printf("%c", c_Order);
        }
        
        else if(s[i]>='A' && s[i]<='Z'){
            
        a_Order=(s[i]-'A'+k)%26; 
        c_Order=a_Order+'A';
        
        printf("%c", c_Order);
        }
        
        else {
            printf("%c", s[i]);
        }
        
    } // scan all s[i]
    
printf("\n");

return 0; } // if k> 0, decipher and print result
            
            
            

    } // else when argc == 2
        
    
} // main function