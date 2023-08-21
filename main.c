#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRIES 5

int main() {
    while(1){

        // generating random number
        srand(time(NULL));
        rand();

        // game variables
        int guess = 0; int game = 0; int number;
        double points = 1000;
        double lostPoints = 0;

        // choosing difficulty
        int difficulty;
        int cap;
        printf("Choose difficulty: [1 - Easy (1-25)] [2 - Normal (1-50)] [3- Hard(1-100)]: ");
        scanf("%d", &difficulty);
        if(difficulty == 1) {
            cap = 25;
            number = rand() % 25 + 1;
        }
        else if(difficulty == 2) {
            cap = 50;
            number = rand() % 50 + 1;
        }
        else {
            cap = 100;
            number = rand() % 100 + 1;
        }

        // game
        for(int c = 1; c <= TRIES; c++){
            printf("----------------------------------------\n");
            printf("Try number %d of %d, what's your guess? ", c, TRIES);
            scanf("\n%d", &guess);
            printf("Your guess was %d\n", guess);
            // checking miss input
            if(guess < 0 || guess > cap){
                printf("You cannot input negative numbers or above cap!\n");
                c--;
                continue;
            }
            // checking win
            int correct = (guess == number);
            if(correct){
                printf("You completed the challenge!\n");
                break;
            }
            // checking guess
            else{
                if(guess > number){
                    printf("It's higher than the number...\n");
                }
                else {             
                    printf("It's lower than the number...\n");
                }
            // punctuation
            double lostPoints = (guess - number);
            points = points - abs(lostPoints);
            continue;
            }
        }
        // end game inputs
        printf("----------------------------------------\n");
        printf("The number was %d!\n", number);
        printf("You scored %.2f points! \n", points);
        printf("Do you want to continue? [1 - Yes] [2 - No]: ");
        scanf("\n%d", &game);
        if (game != 1) {
            printf("----------------------------------------\n");
            printf("See you next time!\n");
            printf("----------------------------------------\n");
            break;
        }
    }       
}
