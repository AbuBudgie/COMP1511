// CS Explorer
// cs_explorer.c
//
// This program was written by Yahya Al-Faraj (z5417171)
// on 09/03/2022
//
// Version 1.0.0 (2022-03-08): Assignment Released.
//
// Description of your program.
// This program will simulate a game using a 2D array map where a player will 
// drink potions to defeat monsters while simulatneously trying to avoid boulders. 

#include <stdio.h>

// Additional libraries here

// Provided constants 
#define SIZE 8
#define PLAYER_STARTING_ROW (SIZE - 1)
#define PLAYER_STARTING_COL 0
#define EMPTY_POINTS 0
#define EMPTY_TYPE 'E'
#define PLAYER_TYPE 'P'
#define MONSTER_TYPE 'M'
#define HEALING_TYPE 'H'
#define BOULDER_TYPE 'B'

// Your constants here
#define MOVE 'm'
#define RIGHT 'r'
#define LEFT 'l'
#define UP 'u'
#define DOWN 'd'
#define CHEAT 'c'
#define QUIT 'q'
#define HEALTH 'h'
#define SQUARE 's'
#define RECTANGLE 'r'
#define BOULDER 'b'

// Provided struct
struct location {
    char occupier;
    int points;
};

// Your structs here

// Provided functions use for game setup
// You do not need to use these functions yourself.
void init_map(struct location map[SIZE][SIZE]);
void place_player_on_starting_location(struct location map[SIZE][SIZE]);

// You will need to use these functions for stage 1.
void print_cheat_map(struct location map[SIZE][SIZE]);
void print_game_play_map(struct location map[SIZE][SIZE]);

// Your functions prototypes here
void print_square(int row, int col, int size, char type, struct location map[SIZE][SIZE]);
int print_win(int row, int col, struct location map[SIZE][SIZE]);
void print_rectangle(int start_row, int start_col, int end_row, int end_col, char type, struct location map[SIZE][SIZE]);
int trap(int row, int col, struct location map[SIZE][SIZE]);

int main(void) {

    struct location map[SIZE][SIZE];
    init_map(map);

    printf("Welcome Explorer!!\n");
    printf("How many game pieces are on the map?\n");

    // code to scan in the number of game pieces here.
    int piece_num;
    scanf("%d", & piece_num);
    // code to scan in the details of each game piece and place them
    // on the map
    printf("Enter the details of game pieces: ");
    printf("\n");
    int i = 0;

    while (i < piece_num) {
        int points, row, col;
        scanf("%d %d %d", & points, & row, & col);
        if ((row >= 0 && row <= 7) &&
            (col >= 0 && col <= 7) &&
            (map[row][col].occupier !=
                map[PLAYER_STARTING_ROW][PLAYER_STARTING_COL].occupier)) {
            map[row][col].points = points;
            if (points < -9 || points > 9) {
                map[row][col].occupier = EMPTY_TYPE;
            } else if (points > 0) {
                map[row][col].occupier = HEALING_TYPE;
            } else if (points == 0) {
                map[row][col].occupier = BOULDER_TYPE;
            } else if (points < 0) {
                map[row][col].occupier = MONSTER_TYPE;
            }
        }
        i++;
    }
    // game pieces have been added to the map to print out the map.

    print_game_play_map(map);
    printf("\nEXPLORE!\n");
    printf("Enter command: ");

    // scanning in commands from the user until the user presses
    // ctrl + d    
    char command, type;
    int size;
    int row = PLAYER_STARTING_ROW;
    int col = PLAYER_STARTING_COL;
    int player_health = 10;
    map[row][col].points = player_health;
    while (scanf(" %c", & command) != EOF) {
        if (command == CHEAT) {
            print_cheat_map(map);
        }
        if (command == QUIT) {
            printf("Exiting Program!\n");
            return 0;
        }
        if (command == HEALTH) {
            printf("Your player is at (%d, %d) with a health of %d.\n", row,
                col, player_health);
        }
        if (command == SQUARE) {
            scanf(" %d %d %d %c", & row, & col, & size, & type);
            print_square(row, col, size, type, map);
        }
        if (command == BOULDER) {
            int row_b;
            int col_b;
            scanf(" %d %d", & row_b, & col_b);
            if (row_b > 7) {
                row_b = 7;
            } else if (row_b < 0) {
                row_b = 0;
            } 

            if (col_b < 0) {
                col_b = 0;
            } else if (col_b > 7) {
                col_b = 7;
            }
            
        
         if (map[row_b][col_b].occupier == PLAYER_TYPE) {
            player_health = 0;
        } else {
            map[row_b][col_b].occupier = BOULDER_TYPE;
            map[row_b][col_b].points = EMPTY_POINTS;
        }
           
        /* 
        if (trap(row,col,map) == 1) {
            player_health = 0;
        } 
        an attempt at trying to code for a player trapped by boulders
        using the function called trap.
        */    
        }
        if (command == RECTANGLE) {
            int start_row;
            int start_col;
            int end_row;
            int end_col;
            scanf(" %d %d %d %d %c", & start_row, & start_col, & end_row, & end_col, & type);
            print_rectangle(start_row, start_col, end_row, end_col, type, map);
        }
        // Movement. 
        if (command == MOVE) {
            char direction;
            scanf(" %c", & direction);
            int next_col = col;
            int next_row = row;
            if (direction == LEFT) {
                next_col = col - 1;
                if (next_col < 0) {
                    next_col = 0;
                }
            } else if (direction == RIGHT) {
                next_col = col + 1;
                if (next_col > 7) {
                    next_col = 7;
                }
            } else if (direction == UP) {
                next_row = row - 1;
                if (next_row < 0) {
                    next_row = 0;
                }
            } else if (direction == DOWN) {
                next_row = row + 1;
                if (next_row > 7) {
                    next_row = 7;
                }

            }
            // drinking potions and fighting monsters.
            if (map[next_row][next_col].occupier != BOULDER_TYPE) {

                int damageORhealth = map[next_row][next_col].points;
                player_health = player_health + damageORhealth;
                map[row][col].points = player_health;
                map[row][col].occupier = EMPTY_TYPE;
                map[row][col].points = EMPTY_POINTS;
                row = next_row;
                col = next_col;
                map[row][col].occupier = PLAYER_TYPE;
            }
        }
        print_game_play_map(map);
        // Determining whether the game is lost or won.
        if (player_health == 0) {
            printf("GAME LOST!\n");
            return 0;
        }
        if (print_win(row, col, map) == 1 && player_health != 0) {
            return 0;
        }
        printf("Enter command: ");
    }
    return 0;

}

////////////////////////////////////////////////////////////////////////////////
///////////////////////////// ADDITIONAL FUNCTIONS /////////////////////////////
////////////////////////////////////////////////////////////////////////////////

// add additional functions here
void print_square(int row, int col, int size, char type, struct location map[SIZE][SIZE]) {
    if (row < 0) {
        row = 0;
    } else if (row > 7) {
        row = 7;
    }
    if (col < 0) {
        col = 0;
    } else if (col > 7) {
        col = 7;
    }

    int value = 0;
    int row_size = row + size;
    int col_size = col + size;

    while (row < row_size && row < SIZE) {
        int col_counter = col;
        while (col_counter < col_size && col_counter < SIZE) {
            if (map[row][col_counter].occupier == type) {
                value = map[row][col_counter].points + value;
            }
            col_counter++;
        }
        row++;
    }
    if (type == MONSTER_TYPE) {
        printf("Monsters in this section could apply %d health points.\n", value);
    } else if (type == HEALING_TYPE) {
        printf("Healing Potions in this section could apply %d health points.\n", value);
    }
};

void print_rectangle(int start_row, int start_col, int end_row, int end_col, char type, struct location map[SIZE][SIZE]) {
    
    if (start_row < 0) {
        start_row = 0;
    } else if (start_row > 7) {
        start_row = 7;
    }
    if (end_row < 0) {
        end_row = 0;
    } else if (end_row > 7) {
        end_row = 7;
    }

    if (start_col < 0) {
        start_col = 0;
    } else if (start_col > 7) {
        start_col = 7;
    }
    if (end_col < 0) {
        end_col = 0;
    } else if (end_col > 7) {
        end_col = 7;
    }
    // SR: "Start Row"
    int start_row_sub = 0;
    // ER: "End Row"
    int end_row_sub = 0;
    // SC: "Start Column"
    int start_col_sub = 0;
    // EC: "End Column"
    int end_col_sub = 0;

    if (start_row <= end_row) {
        start_row_sub = start_row;
        end_row_sub = end_row;
    } else {
        start_row_sub = end_row;
        end_row_sub = start_row;
    }

    if (start_col <= end_col) {
        start_col_sub = start_col;
        end_col_sub = end_col;
    } else {
        start_col_sub = end_col;
        end_col_sub = start_col;
    }

    int value = 0;
    
    while (start_row_sub <= end_row_sub && start_row_sub < SIZE) {
        int col_counter = start_col_sub;
        while (col_counter <= end_col_sub && col_counter < SIZE) {
            if (map[start_row_sub][col_counter].occupier == type) {
                value = map[start_row_sub][col_counter].points + value;
            }
            col_counter++;
        }
        start_row_sub++;
    }

    if (type == MONSTER_TYPE) {
        printf("Monsters in this section could apply %d health points.\n", value);
    } else if (type == HEALING_TYPE) {
        printf("Healing Potions in this section could apply %d health points.\n", value);
    }

};

int print_win(int row, int col, struct location map[SIZE][SIZE]) {
    row = 0;
    col = 0;
    int monster = 0;
    while (row < SIZE) {
        col = 0;
        while (col < SIZE) {
            if (map[row][col].occupier == MONSTER_TYPE) {
                monster++;
            }
            col++;
        }
        row++;
    }

    if (monster == 0) {
        printf("GAME WON!\n");
        return 1;
    }
    return 0;
};

int trap(int row, int col, struct location map[SIZE][SIZE]) {
    // This function was created to determine whether the player is trapped 
    // by boulders or not but could not figure out the issue in time.
    return map[row][col-1].occupier == BOULDER_TYPE && map[row][col+1].occupier == MONSTER_TYPE 
   && map[row-1][col].occupier == MONSTER_TYPE && map[row+1][col].occupier == MONSTER_TYPE;
}
////////////////////////////////////////////////////////////////////////////////
////////////////////////////// PROVIDED FUNCTIONS //////////////////////////////
/////////////////////////// (DO NOT EDIT BELOW HERE) ///////////////////////////
////////////////////////////////////////////////////////////////////////////////

// Provided Function
// Initalises all elements on the map to be empty to prevent access errors.
void init_map(struct location map[SIZE][SIZE]) {
    int row = 0;
    while (row < SIZE) {
        int col = 0;
        while (col < SIZE) {
            struct location curr_loc;
            curr_loc.occupier = EMPTY_TYPE;
            curr_loc.points = EMPTY_POINTS;
            map[row][col] = curr_loc;
            col++;
        }
        row++;
    }

    place_player_on_starting_location(map);
}

// Provided Function
// Places the player in the bottom left most location.
void place_player_on_starting_location(struct location map[SIZE][SIZE]) {
    map[PLAYER_STARTING_ROW][PLAYER_STARTING_COL].occupier = PLAYER_TYPE;
}

// Provided Function
// Prints out map with alphabetic values. Monsters are represented with 'M',
// healing potions in 'H', boulders with 'B' and the player with 'P'.
void print_game_play_map(struct location map[SIZE][SIZE]) {
    printf(" -----------------\n");
    int row = 0;
    while (row < SIZE) {
        printf("| ");
        int col = 0;
        while (col < SIZE) {
            if (map[row][col].occupier == EMPTY_TYPE) {
                printf("- ");
            } else {
                printf("%c ", map[row][col].occupier);
            }
            col++;
        }
        printf("|\n");
        row++;
    }
    printf(" -----------------\n");
}

// Provided Function
// Prints out map with numerical values. Monsters are represented in red,
// healing potions in blue, boulder in green and the player in yellow.
//
// We use some functionality you have not been taught to make sure that
// colours do not appear during testing.
void print_cheat_map(struct location map[SIZE][SIZE]) {

    printf(" -----------------\n");
    int row = 0;
    while (row < SIZE) {
        printf("| ");
        int col = 0;
        while (col < SIZE) {
            if (map[row][col].occupier == PLAYER_TYPE) {
                // print the player in purple
                // ----------------------------------------
                // YOU DO NOT NEED TO UNDERSTAND THIS CODE.
                #ifndef NO_COLORS
                printf("\033[1;35m");
                #endif
                // ----------------------------------------
                printf("%c ", PLAYER_TYPE);
            } else if (map[row][col].occupier == HEALING_TYPE) {
                // print healing potion in green
                // ----------------------------------------
                // YOU DO NOT NEED TO UNDERSTAND THIS CODE.
                #ifndef NO_COLORS
                printf("\033[1;32m");
                #endif
                // ----------------------------------------
                printf("%d ", map[row][col].points);
            } else if (map[row][col].occupier == MONSTER_TYPE) {
                // print monsters in red
                // ----------------------------------------
                // YOU DO NOT NEED TO UNDERSTAND THIS CODE.
                #ifndef NO_COLORS
                printf("\033[1;31m");
                #endif
                // ----------------------------------------
                printf("%d ", -map[row][col].points);
            } else if (map[row][col].occupier == BOULDER_TYPE) {
                // print boulder in blue
                // ----------------------------------------
                // YOU DO NOT NEED TO UNDERSTAND THIS CODE.
                #ifndef NO_COLORS
                printf("\033[1;34m");
                #endif
                // ----------------------------------------
                printf("%d ", map[row][col].points);
            } else {
                // print empty squares in the default colour
                printf("- ");
            }
            // ----------------------------------------
            // YOU DO NOT NEED TO UNDERSTAND THIS CODE.
            // reset the colour back to default
            #ifndef NO_COLORS
            printf("\033[0m");
            #endif
            // ----------------------------------------
            col++;
        }
        printf("|\n");
        row++;
    }
    printf(" -----------------\n");
}
