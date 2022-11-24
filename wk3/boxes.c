#include <stdio.h>

int main (void) {

    int boxes = 0;
    printf("How many boxes: ");
    scanf("%d", &boxes);
    int size = ((boxes * 3) + (boxes - 1));
    int row = 1; // Row counter i
    int column = 1; // Column counter j
    int mid_row = boxes * 2;

    // For printing each row
    while (row <= size) {
        column = 1;
        if (row < mid_row) {
            // For printing each column
            while (column <= size) {

                // If the current row is odd
                if ((row % 2) != 0) {

                    // If the current column is odd
                    if ((column % 2) != 0) {
                        printf("*");
                    } else {
                        // If the current column is even
                        if ((column < row) || ((size - column) < row)) {
                            printf("-");
                        } else {
                            printf("*");
                        }
                    }
                } else {
                    // If the current row is even

                    // If the current column is odd
                    if ((column % 2) != 0) {
                        if ((column < row) || ((size - column) < row)) {
                            printf("*");
                        } else {
                            printf("-");
                        }
                    } else {
                        // If the current column is even
                        printf("-");
                    }
                }
                column++;
            }
        } else if (row == mid_row) {
            while (column <= size) {
                if ((column % 2) != 0) {
                    printf("*");
                } else {
                    printf("-");
                };
                column++;
            }
        } else {
            // For printing each column
            while (column <= size) {

                // If the current row is odd
                if ((row % 2) != 0) {

                    // If the current column is odd
                    if ((column % 2) != 0) {
                        printf("*");
                    } else {
                        // If the current column is even
                        if ((column > row) || ((size - column) >= row)) {
                            printf("-");
                        } else {
                            printf("*");
                        }
                    }
                } else {
                    // If the current row is even

                    // If the current column is odd
                    if ((column % 2) != 0) {
                        if ((column > row) || ((size - column) >= row)) {
                            printf("*");
                        } else {
                            printf("-");
                        }
                    } else {
                        // If the current column is even
                        printf("-");
                    }
                }
                column++;
            }
        }

        printf("\n");
        row++;
    }

    return 0;
}
