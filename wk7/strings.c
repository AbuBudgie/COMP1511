// This program looks at strings


#include <stdio.h>

#define SIZE 50

int main (void) {

   // '\0' NULL terminator
   // char word[] = {'H','e', 'l', 'l','o', '\0'};
   // printf("%s", word);
   // char word[SIZE] = "Hello";
   
   
    char word[SIZE];
    /*
    fgets(word, SIZE, stdin); //scanf
    fputs(word, stdout); //printf
    */
    while (scanf("%s \n", word) != EOF) {
        fputs(word, stdout);
    } 
    
    
    return 0; 
}
/*
int secret_function(char word[SIZE]) {
    int i = 0;
    int result = 0;
    while (word[i] != '\0') {
        if (word[i] >= 'a' && word[i] <= 'z') {
            result++;
        }
        i++;
    }
    return result;
}
*/
