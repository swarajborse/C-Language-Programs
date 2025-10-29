/*
 * =====================================================================================
 *
 * Program:  Factorial Calculator (Reusable Version)
 *
 * Description:
 * Accepts multiple integers from the user, computes their factorials, 
 * and displays the results. 
 * Includes input validation and modular structure for reusability.
 *
 * Author: <Your Name> (Hacktoberfest Contribution)
 * Complexity: O(n * m) where m = each number's value
 *
 * Example Run:
 * How many numbers do you want to enter? 3
 * Enter number 1: 5
 * Enter number 2: -2
 * Enter number 3: 3
 *
 * Factorials:
 * Factorial of 5 is 120
 * Factorial of -2 is not defined
 * Factorial of 3 is 6
 *
 * =====================================================================================
 */

#include <stdio.h>

// Function to calculate factorial of a single number
unsigned long long calculate_factorial(int num) {
    if (num < 0)
        return 0; // Return 0 to indicate undefined factorial

    unsigned long long result = 1;
    for (int i = 1; i <= num; i++) {
        result *= i;
    }
    return result;
}

// Function to get numbers from user
void get_numbers(int *arr, int count) {
    for (int i = 0; i < count; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

// Function to display results
void display_results(int *numbers, unsigned long long *factorials, int count) {
    printf("\nFactorials:\n");
    for (int i = 0; i < count; i++) {
        if (numbers[i] < 0)
            printf("Factorial of %d is not defined\n", numbers[i]);
        else
            printf("Factorial of %d is %llu\n", numbers[i], factorials[i]);
    }
}

int main(void) {
    int n;

    printf("How many numbers do you want to enter? ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid input. Please enter a positive count.\n");
        return 1; // Exit early
    }

    int numbers[n];
    unsigned long long factorials[n];

    // --- Input Phase ---
    get_numbers(numbers, n);

    // --- Calculation Phase ---
    for (int i = 0; i < n; i++) {
        factorials[i] = calculate_factorial(numbers[i]);
    }

    // --- Output Phase ---
    display_results(numbers, factorials, n);

    return 0;
}
