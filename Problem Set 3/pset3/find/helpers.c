/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <math.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    
    int startIndex = 0; 
    int endIndex = n-1;   
    
    while(startIndex <= endIndex){
        
        int midIndex = round((startIndex + endIndex)/2.0);
        
        if(values[midIndex] == value) {
            
            return true;
        }
        
        else if (values[midIndex] > value) {
            
            
            endIndex = midIndex-1;
            
        }
        
        else {
            
            startIndex = midIndex+1;
        } 
        
       
        
    }
    
     return false;
    
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    for(int i=0; i<n-1; i++){
        
        int min = i;
        int tempt = 0;
        
        for(int j=i+1; j<n; j++){
            
            if (values[j] < values[min]){
                
               min = j;
            }
            
        } // iterate from i+1 to n, if j < min; swapt j with min;
            
            if (i != min){
            tempt = values[i];
            values[i] = values[min];
            values[min] = tempt;
            }
            
    }
    
    return;

}