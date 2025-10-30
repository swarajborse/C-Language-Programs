#include <stdio.h>

int main() {
    int r, c, i, j;
    int matrix[10][10];
    int max;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &r, &c);
    printf("Enter elements of the matrix:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    max = matrix[0][0];
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            if (matrix[i][j] > max) {
                max = matrix[i][j];
            }
        }
    }
    printf("Maximum element in the matrix: %d\n", max);
    return 0;
}
