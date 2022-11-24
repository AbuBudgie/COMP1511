//



#include <stdio.h>

#define SIZE 3

struct plot {
    int seed;
    int water;
};


int main (void) {

    struct plot land[SIZE][SIZE] = {0}
   

    int row, col;
    
    row = 0;
    
    while (row < SIZE) {
    
    col = 0;
        while (col < SIZE) {
            if (col % 2 != 0) {
                 land[row][col].seed = 5;
                    land[row][col].water = 5;
            }
        }
        }
    return 0;
}
