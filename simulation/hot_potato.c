/*
---------------------------------------------------------
Program: Hot Potato Simulation
File: simulation/hot_potato.c
Category: Simulation / Algorithms
---------------------------------------------------------
Problem Statement:
------------------
N players stand in a circle, numbered 1 to N.
A "hot potato" is passed around the circle.
Every K-th pass eliminates the player holding the potato.
The game continues until only one player (the winner) remains.

Input:
N (number of players)
K (number of passes before elimination)

Output:
Elimination order and the final winner.

---------------------------------------------------------
Sample Input:
5
3

Sample Output:
Elimination order: 3 1 5 2
Winner: 4
---------------------------------------------------------
Algorithm:
----------
1. Initialize an array `players` from 1 to N (all active).
2. Maintain a counter for how many players remain.
3. Use a circular index and count K active players each round.
4. Eliminate the K-th player and mark them as 0.
5. Repeat until only one player remains.

Time Complexity:  O(N × K)
Space Complexity: O(N)
---------------------------------------------------------
*/
#include <stdio.h>

int main() {
    int n, k;
    printf("Enter number of players: ");
    scanf("%d", &n);
    printf("Enter pass count (K): ");
    scanf("%d", &k);

    int players[n];
    for (int i = 0; i < n; i++)
        players[i] = i + 1;  // Player numbers 1..N

    int remaining = n;
    int index = 0;

    printf("Elimination order: ");
    while (remaining > 1) {
        int count = 0;
        while (count < k - 1) {
            if (players[index] != 0)
                count++;
            index = (index + 1) % n;  // Move circularly
        }

        // Move to next active player for elimination
        while (players[index] == 0)
            index = (index + 1) % n;

        printf("%d ", players[index]);  // Eliminated player
        players[index] = 0;             // Mark as eliminated
        remaining--;

        // Move to next player for next round
        index = (index + 1) % n;
    }

    // Find the last remaining player
    int winner;
    for (int i = 0; i < n; i++) {
        if (players[i] != 0) {
            winner = players[i];
            break;
        }
    }
    printf("\nWinner: %d\n", winner);
    return 0;
}
