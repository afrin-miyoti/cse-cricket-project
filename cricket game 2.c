#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


void showLoading(const char *message, int dots) {
    printf("%s", message);
    for (int i = 0; i < dots; i++) {
        printf(".");
        fflush(stdout);
        usleep(500000);
    }
    printf("\n");
}

void playCricketGame() {
    int balls = 6;
    int userScore = 0, computerScore = 0;
    int userRun, computerRun;
    int tossChoice, tossResult, userDecision;
    int isUserBattingFirst;

    printf("Welcome to the Cricket Game!\n");
    showLoading("Loading", 4);

    printf("You will play one over (6 balls).\n");

    srand(time(0));

    printf("\nLet's toss the coin!\n");
    printf("Choose Heads (1) or Tails (2): ");
    scanf("%d", &tossChoice);

    if (tossChoice != 1 && tossChoice != 2) {
        printf("Invalid choice! Defaulting to Heads (1).\n");
        tossChoice = 1;
    }

    showLoading("Tossing the coin", 4);

    tossResult = (rand() % 2) + 1;
    printf("Toss result: %s\n", tossResult == 1 ? "Heads" : "Tails");

    if (tossChoice == tossResult) {
        printf("You won the toss!\n");
        printf("Enter 1 to Bat first or 2 to Bowl first: ");
        scanf("%d", &userDecision);

        if (userDecision == 1) {
            isUserBattingFirst = 1;
            printf("You chose to bat first.\n");
        } else {
            isUserBattingFirst = 0;
            printf("You chose to bowl first.\n");
        }
    } else {
        printf("Computer won the toss!\n");
        isUserBattingFirst = rand() % 2;

        if (isUserBattingFirst) {
            printf("Computer chose to bowl first. You will bat first.\n");
        } else {
            printf("Computer chose to bat first. You will bowl first.\n");
        }
    }

    showLoading("Starting the game", 4);

    if (isUserBattingFirst) {

        printf("\nYour Batting:\n");
        for (int i = 1; i <= balls; i++) {
            printf("Ball %d: Enter your runs (0-6): ", i);
            scanf("%d", &userRun);

            if (userRun < 0 || userRun > 6) {
                printf("Invalid input! Enter a number between 0 and 6.\n");
                i--;
                continue;
            }

            computerRun = rand() % 7;
            printf("Computer bowled: %d\n", computerRun);

            if (userRun == computerRun) {
                printf("You are OUT!\n");
                break;
            } else {
                userScore += userRun;
                printf("Your total score: %d\n", userScore);
            }
        }

        printf("\nYour final score: %d\n", userScore);


        printf("\nNow it's Computer's turn to bat!\n");
        for (int i = 1; i <= balls; i++) {
            printf("Ball %d: Enter your delivery (0-6): ", i);
            scanf("%d", &userRun);

            if (userRun < 0 || userRun > 6) {
                printf("Invalid input! Enter a number between 0 and 6.\n");
                i--;
                continue;
            }

            computerRun = rand() % 7;
            printf("Computer scored: %d\n", computerRun);

            if (userRun == computerRun) {
                printf("Computer is OUT!\n");
                break;
            } else {
                computerScore += computerRun;
                printf("Computer's total score: %d\n", computerScore);
            }

            if (computerScore > userScore) {
                printf("Computer won the match!\n");
                return;
            }
        }
    } else {

        printf("\nComputer's Batting:\n");
        for (int i = 1; i <= balls; i++) {
            printf("Ball %d: Enter your delivery (0-6): ", i);
            scanf("%d", &userRun);

            if (userRun < 0 || userRun > 6) {
                printf("Invalid input! Enter a number between 0 and 6.\n");
                i--;
                continue;
            }

            computerRun = rand() % 7;
            printf("Computer scored: %d\n", computerRun);

            if (userRun == computerRun) {
                printf("Computer is OUT!\n");
                break;
            } else {
                computerScore += computerRun;
                printf("Computer's total score: %d\n", computerScore);
            }
        }

        printf("\nComputer's final score: %d\n", computerScore);


        printf("\nYour turn to bat!\n");
        for (int i = 1; i <= balls; i++) {
            printf("Ball %d: Enter your runs (0-6): ", i);
            scanf("%d", &userRun);

            if (userRun < 0 || userRun > 6) {
                printf("Invalid input! Enter a number between 0 and 6.\n");
                i--;
                continue;
            }

            computerRun = rand() % 7;
            printf("Computer bowled: %d\n", computerRun);

            if (userRun == computerRun) {
                printf("You are OUT!\n");
                break;
            } else {
                userScore += userRun;
                printf("Your total score: %d\n", userScore);
            }

            if (userScore > computerScore) {
                printf("Congratulations! You won the match!\n");
                return;
            }
        }
    }


    printf("\nFinal Scores: You: %d | Computer: %d\n", userScore, computerScore);
    if (userScore > computerScore) {
        printf("Congratulations! You won the match!\n");
    } else if (userScore < computerScore) {
        printf("Computer won the match!\n");
    } else {
        printf("The match is a TIE!\n");
    }
}

int main() {
    playCricketGame();
    return 0;
}
