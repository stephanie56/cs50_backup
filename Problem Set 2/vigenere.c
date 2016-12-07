#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[]){
    
    if (argc!=2){
        
        printf("This input is not valid!\n");
        return 1;
    }
    
    string k = argv[1];
    int n=strlen(k);
    
    for(int i=0; i<n; i++){
        
        if(!isalpha(k[i])){
            
            printf("Invalid Input!\n");
            return 1;
        }
        
        else {
            
            k[i] = toupper(k[i])-'A';
        }
    } // if k has non-alphabetical char, return 1;
   
   string Msg = GetString();
   char p;
   
   
   for(int j=0, ind=0, m=strlen(Msg); j<m; j++){
       
      if (isalpha(Msg[j])==false){
          
          printf("%c", Msg[j]);
      }
      
     
      else {
          
           if (islower(Msg[j])){
               
            p = (Msg[j]-'a' + k[ind%n])%26 + 'a';
            ind = ind + 1;
          
            printf("%c", p);
          
                 }
      
            else {
               
            p = (Msg[j]-'A' + k[ind%n])%26 + 'A';
            ind = ind + 1;
          
            printf("%c", p);
          
                 }
      } 
     
       
   } // for loop ends
   
   printf("\n");
   return 0;
   
    
} /* main function */
