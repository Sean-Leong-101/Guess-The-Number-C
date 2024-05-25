#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ATTEMPTS 10

int getRandomNumber(int max) {
    srand(time(NULL));
    return rand() % max;
}

int promptGuess(int max) {
    int guess;
    printf("Guess a number between 1 and %d: ", max);
    scanf("%d", &guess);
    return guess;
}

void playGame(int max) {
    int number = getRandomNumber(max);
    int attempts = 0;
    int guess;

    do {
        guess = promptGuess(max);
        attempts++;

        if (guess < number) {
            printf("Higher number please!\n");
        } else if (guess > number) {
            printf("Lower number please!\n");
        } else {
            printf("You guessed the number in %d attempts!\n", attempts);
            return;
        }
    } while (attempts < MAX_ATTEMPTS);

    printf("You Lose!\n");
}

int main() {
    int max = 100;
    playGame(max);
    return 0;
}