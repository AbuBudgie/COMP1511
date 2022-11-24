// Program to demonstrate why an array is useful

// Example is tracking ice-cream consumption for a week
// Y.A Week 3, Lecture 6


#include <stdio.h>

#define WEEK 7 

int main(void){

    //declare an array
    int ice_cream[WEEK];
    int total_ice_cream = 0;
    //declare and initialise
    //int ice_cream[7] = {1, 2, 3, 5, 6, 2, 3}; 
    
    //printf("I had %d ice cream\n", ice_cream[1]);
    int i = 0; // ready to access ice_cream[0]
    
    while (i < WEEK) {
        printf("How many scoops did u have today?");
        scanf("%d", &ice_cream[i]);
        total_ice_cream = total_ice_cream + ice_cream[i];
        i++;
    }
    
    i = 0;
    while(i < WEEK) {
        printf("On day %d you had %d scoops of ice-cream\n", i + 1, ice_cream[i]);
        i++;
    } 
    
    printf("The total ice cream for the week: %d\n", total_ice_cream);
    
    return 0;   
}
