// Word square program
// This program will prompt the user to enter a word, and afterwards, prints out 
// that word n amount of times,where n = length of the word.
// Y.A (z5417171)
// 04/04/2022



#include <stdio.h>
#include <strings.h>

#define SIZE 1024

void print_word_square(char word[SIZE]) {
    int i = 0;
    int j = 0;
    while (word[i] != '\0') {
    
        i++;
    }
    while (j <= i - 2) {
        fputs(word, stdout);
        j++;
    }
}


int main (void) {


    printf("Input word: ");
    printf("\n");
    char word[SIZE];
    fgets(word, SIZE, stdin);
    
    printf("Word square is: \n");
   // printf("\n");
    print_word_square(word);
   

    return 0;
}










