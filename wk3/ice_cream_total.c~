// Program to demonstrate basic input/output into an array
// Sasha Vassar Week 3, Lecture 6

/*
Tom am writing a piece of code and each day that code gets longer everyday he finds a different number of bugs in his code and he records that number (for a week)
Tammy is writing a better peice of code and each day counts how many bugs her code has also (for a week).



whos got more bugs

Solution steps:
1. Toms bugs
2. tammy's bugs
 
*/

#include <stdio.h>

int main(void){

    int tom_bugs[7];
    int tammy_bugs[7];
    int total_tom_bugs = 0;
    int total_tammy_bugs = 0;
    
    int i = 0;
    while (i < 7){
        printf("How many bugs today Tom? ");
        scanf("%d", &tom_bugs[i]);
        printf("How many bugs today tammy? ");
        scanf("%d", &tammy_bugs[i]);
        total_tom_bugs = total_tom_bugs + tom_bugs[i];
        total_tammy_bugs = total_tammy_bugs + tammy_bugs[i]; 
        i++;
    }
    if(total_tammy_bugs < total_tom_bugs){
        printf("Tom has more bugs than Tammy: %d\n", total_tom_bugs - total_tammy_bugs);
    } else if (total_tammy_bugs > total_tom_bugs) {
        printf("Tammy has more bugs than Tom: %d\n", total_tammy_bugs - total_tom_bugs);
    } else {
        printf("Tom and Tammy have same amount of bugs\n");
    }



    
    return 0;
}
