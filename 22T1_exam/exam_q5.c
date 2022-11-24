#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1024
#define YES 1
#define NO 0
void remove_newline(char *string);
// my function(s)
void match_checker(char *pattern, char *test);
    
int main(void) {

    char pattern[MAX_LENGTH];
    printf("Enter the pattern string: ");
    fgets(pattern, MAX_LENGTH, stdin);
    remove_newline(pattern);
    

    char test[MAX_LENGTH];
    printf("Enter the test strings:\n");
    
    // Your solution should go here.
    // You can create and use your own functions if you would like.
    while (fgets(test, MAX_LENGTH, stdin) != NULL) {
        remove_newline(test);
        match_checker(pattern, test);
    }

    return 0;
}

// Given a null-terminated string, removes
// the trailing newline (if one exists).
void remove_newline(char *string) {
    int i = 0;
    while (string[i] != '\0') {
        if (string[i] == '\n') {
            string[i] = '\0';
        }
        i++;
    }
}

void match_checker(char *pattern, char *test) {
    int i = 0;
    int has_match_occured = NO;
    
    while (pattern[i] != '\0' && has_match_occured == NO) {
        if (test[i] == pattern[i]) {
            printf("%d %s\n", i, test);
            has_match_occured = YES;  
        }
        i++;
    }
}
