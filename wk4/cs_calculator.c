// Calculator.c 
// written by Yahya.A
// 11/03/2022
// this program will print out the value of either the square of a number 
// or a powerof specific number


#include <stdio.h>


int main (void) {

    char instruction; 
    int number;
    int power; 
    
    printf("Enter Instruction: ");
    
    while (scanf(" %c", &instruction) == 1) { 
    int result = 1;
        if (instruction == 's') {
            scanf("%d", &number);
            number = number * number;
            printf("%d\n", number);
        }  if (instruction == 'p') {
            scanf("%d %d", &number, &power);
            int i = 0; 
                while (i < power) {
                result = result * number;
                i++;    
                }
                printf("%d\n", result);
            }
    printf("Enter Instruction: ");
    }




    return 0; 
}
