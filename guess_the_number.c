#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int secret_number, guess, attempts = 0;
    
    // Seed the random number generator using the current time
    srand(time(NULL));
    
    // Generate a random number between 1 and 100
    secret_number = (rand() % 100) + 1;
    
    printf("Welcome to the Number Guessing Game!\n");
    printf("I have picked a number between 1 and 100. Try to guess it!\n");
    
    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;
        
        if (guess < secret_number) {
            printf("Too low! Try again.\n");
        } else if (guess > secret_number) {
            printf("Too high! Try again.\n");
        } else {
            printf("Congratulations! You guessed the number %d in %d attempts!\n", secret_number, attempts);
        }
    } while (guess != secret_number);
    
    return 0;
}
