#include <stdio.h>

int main() {
    int r, c, i, j;
    int matrix[10][10], rowSum;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &r, &c);
    printf("Enter elements of the matrix:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("Sum of each row:\n");
    for (i = 0; i < r; i++) {
        rowSum = 0;
        for (j = 0; j < c; j++) {
            rowSum += matrix[i][j];
        }
        printf("Row %d sum = %d\n", i + 1, rowSum);
    }
    return 0;
}
