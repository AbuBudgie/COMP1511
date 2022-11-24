#include <stdio.h>
#include <stdlib.h>


struct coordinate {
    int x;
    int y;
};


// Return the sum of all negative x coordinates 
// and all positive y coordinates as a struct 
struct coordinate sum_coords(int size, struct coordinate array[size]){

    struct coordinate total;
    total.x = 0; 
    total.y = 0; 
    int i = 0; 
    
    while (i < size) {                                           
        if (array[i].x < 0) { 
            total.x = total.x + array[i].x;   
        } 
        if (array[i].y > 0) {
            total.y = total.y + array[i].y;
        } 
        i++;
    }
   
    return total;   
}

// This is a simple main function which could be used
// to test your sum_cood function.
// It will not be marked.
// Only your sum_cood function will be marked.

#define TEST_ARRAY_SIZE 4

int main(void) {
    struct coordinate test_array[TEST_ARRAY_SIZE] = {
        { .x = -10, .y = 10},
        { .x = 10, .y = -10},
        { .x = 10, .y = 10}, 
        { .x = -10, .y = -10}
    };
    struct coordinate result = sum_coords(TEST_ARRAY_SIZE, test_array);
    printf("(%d, %d)\n", result.x, result.y);

    return 0;
}
