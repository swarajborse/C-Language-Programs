/*
 * Program: Matrix Chain Multiplication (MCM)
 * Problem statement:
 *   Given a sequence of matrices, find the minimum number of scalar 
 *   multiplications needed to multiply the chain.
 *
 * Example:
 *   Input dimensions: 40 20 30 10 30
 *   Output: Minimum number of multiplications = 26000
 *
 * Compile:
 *   gcc -std=c11 -O2 -Wall "Matrix_Chain_Multiplication.c" -o mcm
 *
 * Run:
 *   ./mcm
 *
 * Time Complexity: O(n^3)
 * Space Complexity: O(n^2)
 */

#include <stdio.h>
#include <limits.h>

#define MAX 100

int min(int a, int b) {
    return (a < b) ? a : b;
}

int matrixChainOrder(int p[], int n) {
    int m[MAX][MAX] = {0}; // m[i][j] = min number of multiplications for Ai..Aj

    // cost is zero when multiplying one matrix
    for (int i = 1; i < n; i++)
        m[i][i] = 0;

    // l = chain length
    for (int l = 2; l < n; l++) {
        for (int i = 1; i <= n - l; i++) {
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1]*p[k]*p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }
    return m[1][n - 1];
}

int main() {
    int n;
    printf("Enter the number of matrices: ");
    scanf("%d", &n);

    int p[n+1];
    printf("Enter the dimensions of matrices (n+1 numbers):\n");
    for (int i = 0; i <= n; i++)
        scanf("%d", &p[i]);

    int min_cost = matrixChainOrder(p, n);
    printf("Minimum number of multiplications = %d\n", min_cost);

    return 0;
}
