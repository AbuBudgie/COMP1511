#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main(void) {
    
    int numbers[MAX_SIZE]; 
    int i = 0;
    int j = 0;
    while (scanf("%d ", &numbers[i]) == 1 && numbers[i] != 0) {
        i++;
    }
    while (j < i) {
        if (j % 2 == 0) {
            printf("%d ", numbers[j]);
        }
        j++;
    }	

	// print out the odd numbers
	j = 0;
    while (j < i) {
        if (j % 2 == 1) {
            printf("%d ", numbers[j]);
        }
        j++;
    }
    
    printf("\n");
    
    return 0;
    
    
}
