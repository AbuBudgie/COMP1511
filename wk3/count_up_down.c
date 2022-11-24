// this program reads one integer n and prints all integers from 0 to n inclusive one per line.
// Y.A MARCH 2022

#include <stdio.h>

int main(void) {
    int counter, finish;
    
    printf("Enter number: ");
    scanf("%d", &finish);
    
    counter = 0;
    if (finish > 0){
        while (counter <= finish) {
        printf("%d\n", counter);
        counter++;
        
        }          
    } 
    if (finish < 0) {
        while (counter >= finish) {
        printf("%d\n", counter);
        counter--;
        }  
    }
    return 0;
}
