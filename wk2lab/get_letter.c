// This program will read in a character and an integer 
// and will then print out some text
// created by Y.A z5417171 24/02/2022

#include <stdio.h> 

int main (void) {

    char uppercase;
    int index;
    char letter;
    
    printf("Uppercase: ");
    scanf("%c", &uppercase);
    if (uppercase != 'n' && uppercase != 'y')
    {
          printf("You need to enter 'y' or 'n'\n");               
          printf("Exiting the program with error code 1\n");
    
    return 1;
    }
          printf("index: ");
          scanf("%d", &index);
    if (index < 1 || index > 26)
        printf("You need to enter a number from 1 to 26 \n");
    if (index >= 1 && index <= 26) {
          letter = 64 + index;
          
          }     
        if (uppercase == 'y') {
            letter = ;
            }
        if (uppercase == 'n') {
          letter = ;    
            }
                
          
    }
       printf("the letter is %c\n", letter)
    return 0;
    }
