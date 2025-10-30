/*
 * Program: 0/1 Knapsack Problem
 * Problem statement:
 *   Given weights and values of n items, put these items in a knapsack of 
 *   capacity W to get the maximum total value in the knapsack. 
 *   You cannot break items (0/1 property).
 *
 * Example:
 *   Number of items: 4
 *   Weights: 2 3 4 5
 *   Values: 3 4 5 6
 *   Capacity: 5
 *   Output: Maximum value = 7
 *
 * Compile:
 *   gcc -std=c11 -O2 -Wall Knapsack_0_1.c -o knapsack
 *
 * Run:
 *   ./knapsack
 *
 * Time Complexity: O(n*W)
 * Space Complexity: O(n*W)
 */

#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) { return (a > b) ? a : b; }

int knapsack(int W, int wt[], int val[], int n) {
    int i, w;
    int K[n+1][W+1];

    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i-1] <= w)
                K[i][w] = max(val[i-1] + K[i-1][w - wt[i-1]], K[i-1][w]);
            else
                K[i][w] = K[i-1][w];
        }
    }

    return K[n][W];
}

int main() {
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int wt[n], val[n];
    printf("Enter the weights of items:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &wt[i]);

    printf("Enter the values of items:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &val[i]);

    int W;
    printf("Enter the maximum capacity of knapsack: ");
    scanf("%d", &W);

    int max_value = knapsack(W, wt, val, n);
    printf("Maximum value = %d\n", max_value);

    return 0;
}
