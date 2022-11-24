/* This program will read the number of sides on a set of dice and how many of them are being rolled
it then outputs the range of possible totals that these dice can produce as well as the average value. 
created by Y.A z5417171 on 28/02/2022
*/

#include <stdio.h>

int main (void) {

    int sides;
    int dice;
    int lower_range;
    int higher_range;
    double limit;
    double sum = 0;
    double avg;
    
    printf("Enter the number of sides on your dice: ");
    scanf("%d", &sides);
    
    printf("Enter the number of dice being rolled: ");
    scanf("%d", &dice);
    
        if (sides <= 0 || dice <= 0) {
            printf("These dice will not produce a range.\n");
        return 1;
        }
        
        lower_range = dice;
        higher_range = dice * sides;
    
    printf("Your dice range is %d to %d. \n", lower_range, higher_range);
    
        while (lower_range <= higher_range)
        {
            sum = sum + lower_range;
            lower_range++;
        }
        limit = higher_range - (dice - 1); 
        avg = (sum / limit); 
        printf("The average value is %lf \n", avg);

    return 0;
}
