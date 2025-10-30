/*
 * Program: Longest Increasing Subsequence (LIS)
 * Problem statement:
 *   Given an array of integers, find the length of the longest strictly
 *   increasing subsequence and print one example subsequence.
 *
 * Input / Output examples:
 *   Input:  [10, 22, 9, 33, 21, 50, 41, 60]
 *   Output:
 *     Length of Longest Increasing Subsequence is 5
 *     One LIS: 10 22 33 50 60
 *
 * Compile:
 *   gcc -std=c11 -O2 -Wall "arrays/Longest Increasing Subsequence/Longest_Increasing_Subsequence.c" -o lis
 *
 * Run:
 *   ./lis
 *
 * Time Complexity: O(n^2)
 * Space Complexity: O(n)
 *
 * Beginner-friendly, well-commented, and easy to follow.
 */

#include <stdio.h>
#include <stdlib.h>

int max_int(int a, int b) { return (a > b) ? a : b; }

/* Print one LIS using parent pointers */
void print_LIS(int arr[], int parent[], int end_index) {
    int len = 0, i = end_index;
    while (i != -1) { len++; i = parent[i]; }

    int seq[len];
    i = end_index;
    for (int j = len - 1; j >= 0; --j) {
        seq[j] = arr[i];
        i = parent[i];
    }

    printf("One LIS: ");
    for (int j = 0; j < len; j++)
        printf("%d%c", seq[j], (j == len - 1) ? '\n' : ' ');
}

/* Return LIS length and print one sequence */
int LIS(int arr[], int n) {
    int lis[n], parent[n];
    for (int i = 0; i < n; i++) {
        lis[i] = 1;
        parent[i] = -1;
    }

    int max_len = 1, end_index = 0;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
                parent[i] = j;
            }
        }
        if (lis[i] > max_len) {
            max_len = lis[i];
            end_index = i;
        }
    }

    printf("Length of Longest Increasing Subsequence is %d\n", max_len);
    print_LIS(arr, parent, end_index);

    return max_len;
}

int main(void) {
    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60};
    int n = sizeof(arr) / sizeof(arr[0]);

    LIS(arr, n);
    return 0;
}
