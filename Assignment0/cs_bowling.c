// cs_bowling
// This program will calculate and record a full bowling game (10 frames). 
// written by Yahya Al-Faraj (z5417171)
// on 21/02/2022

#include <stdio.h>

#define FULL_GAME 10 //the limit for the while loop to make a full game

int main(void) {

    int score_1 = 0;
    int score_2 = 0;
    int score_sum = 0;
    int frame = 1;
    int total_score = 0;
    int spare = 0;
    int strike = 0;
    int score_spare = 0;
    int score_strike = 0;
    int bonus_bowl = 0;
          
    printf("Welcome to CS Bowling!\n");

    while (frame <= FULL_GAME) {
        score_sum = 0;
        score_1 = 0;
        score_2 = 0;
        score_spare = 0;
        score_strike = 0;
        printf("Frame %d, Bowl 1: ", frame); //bowl 1
        scanf("%d", & score_1);
            

        if (score_1 < 0 || score_1 > 10) { 
            printf("Bowl 1 invalid! \n");
            score_1 = 0;
        }

        if (score_1 != 10) {
            printf("Frame %d, Bowl 2: ", frame); //bowl 2
            scanf("%d", & score_2);
            if (score_2 < 0 || score_2 > 10) {
                printf("Bowl 2 invalid! \n");
                score_2 = 0;
            }

            if (score_1 + score_2 > 10) {
                printf("Bowl 2 invalid! \n");
                score_2 = 0;
            }
        }

        //spare bonus will be calculated here
        if (spare == 1 && frame != 1) {
            score_spare = score_1;
            spare = 0;
        }
        //strike bonus will be calculated here
        if (strike == 1 && frame != 1) {
            score_strike = score_1 + score_2;
            strike = 0;
        }
        if ((score_1 + score_2 == 10) && score_2 != 0) {
            spare = 1;
        }
        if (score_1 == 10) {
            strike = 1;
        }
        score_sum = score_1 + score_2;
        printf("Score for Frame: %d \n", score_sum);
        if ((score_1 + score_2 == 10) && score_2 != 0) {
            printf("Spare! Bonus for this frame is next roll. \n");
        }
        if (score_1 == 10 && score_2 == 0) {
            printf("Strike! Bonus for this frame is next two rolls. \n");
        }
        //bonus bowl
        if (frame == 10 && (spare == 1 || strike == 1)) {
            printf("Bonus Bowl 1: ");
            scanf("%d", & bonus_bowl);
            if (bonus_bowl < 0 || bonus_bowl > 10) {
                printf("Bonus Bowl Invalid! \n");
                bonus_bowl = 0;
            }
            bonus_bowl = bonus_bowl * 2;
        }
        //total score is added up here
        total_score = total_score + score_sum + score_spare + score_strike + bonus_bowl;
        frame++;
    }

    printf("Total Score: %d \n", total_score);

    return 0;
}

 
