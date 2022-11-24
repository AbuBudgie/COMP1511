#include <stdio.h>
#include <assert.h>

#define BOARD_LENGTH 8
#define PIECE_RED 'R'
#define PIECE_BLACK 'B'
#define PIECE_EMPTY ' '
#define TYPE_KING 1
#define TYPE_NORMAL 0
struct board_square {
    int type;
    char piece_color;
};

// Prints out a checkerboard using the provided 2D array as reference.
void print_checkerboard(struct board_square board[BOARD_LENGTH][BOARD_LENGTH]);

int main(void) {
    // Declare and Initialize a 2D array representing your checkerboard, 
    // using the given struct board_square defined above as the array element 
    // type. Your checkerboard array size should be 8x8; BOARD_LENGTH has been      
    // defined above for you to accomplish this.
    struct board_square board[BOARD_LENGTH][BOARD_LENGTH];
    
   
    // Initialize checkerboard squares with:
    // 1. A value of PIECE_EMPTY for piece_color (i.e. it is empty)
    // 2. A value of TYPE_NORMAL for type (no piece starts the game as a king!)
    // HINT: How do you change elements of a 2D array? What about structs?
    int row = 0;
    int col = 0;
    while (row < BOARD_LENGTH) {
        //col = 0; 
       while (col < BOARD_LENGTH) { 
            board[row][col].type = TYPE_NORMAL;
            board[row][col].piece_color = PIECE_EMPTY;
            col++;
        } 
        row++;
    }
    // Scan in instructions from the user for filling the checkerboard
    // until EOF given (Ctrl+D)
    // HINT: How do you continuously scan for user input?
    int type = 0; 
    char color; 
    printf("Please enter pieces: ");
    printf("\n");
    while (scanf(" %d %d %c %d", &row, &col, &color, &type) != EOF) {
        if ((row >= 0 && row <= 7) && (col >= 0 && col <= 7)) {
            board[row][col].type = type;
            if (type == 1) {
                board[row][col].type = TYPE_KING;
            }
            if (type == 0) {
                board[row][col].type = TYPE_NORMAL;
            }
            board[row][col].piece_color = color; 
            if (color == 'R') {
                board[row][col].piece_color = PIECE_RED;
            }
            if (color == 'B') {
                board[row][col].piece_color = PIECE_BLACK;
            }  
        }
    }

    // TODO: Pass your checkerboard 2D array to this function call!
    //       Refer to how the function is implemented below for more information
    //       on how the checkerboard is printed.
    // HINT: You need to change REPLACE_ME to your checkerboard 2D array.
    print_checkerboard(board);

    return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT EDIT THE CODE BELOW THIS LINE! ////////////////////
///////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// print_checkerboard(): Prints out a checkerboard using the provided 2D array
//                       as reference.
//
// Takes in:
// - `board[BOARD_LENGTH][BOARD_LENGTH]` -- The 2D array containing a
//                                          representation of the checkerboard
//
// Returns: nothing.
void print_checkerboard(struct board_square board[BOARD_LENGTH][BOARD_LENGTH]) {
    int row_index = 0;
    while (row_index < BOARD_LENGTH) {

        // NOTE: Print row dividers of checkerboard
        printf("+-----+-----+-----+-----+-----+-----+-----+-----+\n");
        printf("|");
        
        int column_index = 0;
        while (column_index < BOARD_LENGTH) {
            
            // NOTE: Check that all struct values contain valid input.
            assert(
                board[row_index][column_index].piece_color == PIECE_RED ||
                board[row_index][column_index].piece_color == PIECE_BLACK ||
                board[row_index][column_index].piece_color == PIECE_EMPTY
            );
   
            assert(
                board[row_index][column_index].type == TYPE_KING || 
                board[row_index][column_index].type == TYPE_NORMAL
            );
            
            // NOTE: Print column dividers of checkerboard
            if (board[row_index][column_index].type == TYPE_KING) {
                printf(" %c-K |", board[row_index][column_index].piece_color);
            } else {
                printf("  %c  |", board[row_index][column_index].piece_color);

            }
            
            column_index++;
        }
        
        printf("\n");
        row_index++;
    }
    // NOTE: Print final row divider of checkerboard
    printf("+-----+-----+-----+-----+-----+-----+-----+-----+\n");

    return;
}
