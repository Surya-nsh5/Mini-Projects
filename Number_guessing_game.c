/*
     PROJECT 1: NUMBER GUESSING GAME

We will write a program that generates a random number and asks the player to guess
it. If the player’s guess is higher than the actual number, the program displays “Lower
number please”. Similarly, if the user’s guess is too low, the program prints “Higher
number please”.

When the user guesses the correct number, the program displays the number of
guesses the player used to arrive at the number.

Hint: Use loop & use a random number generator
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int randomNumber;
    int no_of_guesses = 0;
    int guessed;

    // Initialize random seed using current time
    srand(time(NULL));

    // Generate random number between 1 and 100
    randomNumber = rand() % 100 + 1; // Generates a number in the range 0 to 99, so add 1

    // printf("Random number between 1 and 100: %d\n", randomNumber);

    do
    {
        printf("Guess the Number : ");
        scanf("%d", &guessed);
        if (guessed > randomNumber)
        {
            printf("Lower number please! \n");
        }
        else if (guessed < randomNumber)
        {
            printf("Higher number please! \n");
        }
        else
        {
            printf("Congrats!! \n");
        }

        no_of_guesses++;

    } while (guessed != randomNumber);

    printf("You guessed the number in %d guesses", no_of_guesses);

    return 0;
}

/*

### Explanation:

1. **Headers Included:**
   - `stdio.h` for standard input/output functions like `printf`.
   - `stdlib.h` for functions like `rand` and `srand`.
   - `time.h` for getting current time, used to seed the random number generator.

2. **Seeding the Random Number Generator:**
   - `srand(time(NULL));` initializes the random number generator with the current time. This is done once at the beginning of the program to ensure that `rand()` produces different sequences of pseudo-random numbers on each program run.

3. **Generating the Random Number:**
   - `rand() % 100 + 1;` generates a random number between 0 and 99 (`rand() % 100`). Adding 1 (`+ 1`) adjusts the range to be between 1 and 100.

4. **Printing the Random Number:**
   - `printf("Random number between 1 and 100: %d\n", randomNumber);` prints the generated random number.

This program will output a different random number between 1 and 100 each time it is executed due to the use of `srand(time(NULL));` to seed the random number generator based on the current time.

*/