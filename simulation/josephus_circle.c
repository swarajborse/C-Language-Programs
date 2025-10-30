/*
 * File: simulation/josephus_circle.c
 * -----------------------------------
 * Josephus Circle – Circular Elimination
 *
 * Problem:
 * n people stand in a circle, numbered 1 to n.
 * Starting from person 1, every k-th alive person is eliminated.
 * Continue until only one survivor remains.
 *
 * Input:
 * n (number of people)
 * k (step count)
 *
 * Output:
 * Elimination order and the final survivor.
 *
 * Sample I/O:
 * Input:
 * 7
 * 3
 * Output:
 * Elimination order: 3 6 2 7 5 1
 * Survivor: 4
 *
 * Input:
 * 10
 * 2
 * Output:
 * Elimination order: 2 4 6 8 10 3 7 1 5
 * Survivor: 9
 *
 * Algorithm:
 * - Represent people in an array (alive = 1).
 * - Use modulo indexing to move around the circle.
 * - Eliminate every k-th alive person.
 * - Print elimination order and final survivor.
 *
 * Complexity:
 * Time: O(n × k)
 * Space: O(n)
 */

#include <stdio.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int people[n];
    for (int i = 0; i < n; i++) people[i] = 1;  // alive = 1

    int eliminated = 0, index = 0, count = 0;

    printf("Elimination order: ");
    while (eliminated < n - 1) {
        if (people[index] == 1) {
            count++;
            if (count == k) {
                printf("%d ", index + 1);
                people[index] = 0;
                eliminated++;
                count = 0;
            }
        }
        index = (index + 1) % n;
    }

    for (int i = 0; i < n; i++) {
        if (people[i] == 1) {
            printf("\nSurvivor: %d\n", i + 1);
            break;
        }
    }
    return 0;
}
