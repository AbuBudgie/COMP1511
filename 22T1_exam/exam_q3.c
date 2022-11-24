// I attempted q3 to the best of my ability and i spent atleast 30 minutes on it
// i did not pass any of the autotests as one of the values kept being 
// uninitialised for some reason that i couldnt figure out. 
// But the logic of my code made sense to me atleast...


#include <stdio.h>

#define SIZE 10000


int main(void) {
    // write your code for exam_q3 here!
    int array[SIZE];
    int i = 0; 
    //scanning into array
    while (scanf("%d \n", &array[i]) != EOF) {
        i++;
    }
    
    i = 0;
    int j = 0; 
    // an attempt at replacing multiples of another number with -1
    // and then printing it out again
    while (array[i] != '\0') {
        j = 0;   
        while (array[j] != '\0') {
            if (array[i] % array[j] == 0 && array[i] != array[j]) {
                array[i] = -1; 
                
            } else {
                j++;
            } 
        }
        printf("%d \n", array[i]);
        i++;
    }
    
    return 0;
}

