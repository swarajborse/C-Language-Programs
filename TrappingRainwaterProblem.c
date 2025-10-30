#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

void trap(int heights[], int n) {
    int leftMax[20000], rightMax[20000];
    int i, waterTrapped = 0;

    // Initialize boundary values
    leftMax[0] = heights[0];
    rightMax[n - 1] = heights[n - 1];

    // Fill leftMax array
    for (i = 1; i < n; i++) {
        leftMax[i] = max(leftMax[i - 1], heights[i - 1]);
    }

    // Fill rightMax array
    for (i = n - 2; i >= 0; i--) {
        rightMax[i] = max(rightMax[i + 1], heights[i + 1]);
    }

    // Calculate trapped water
    for (i = 0; i < n; i++) {
        int currWater = min(leftMax[i], rightMax[i]) - heights[i];
        if (currWater > 0) {
            waterTrapped += currWater;
        }
    }

    printf("Water Trapped = %d\n", waterTrapped);
}

int main() {
    int heights[] = {4, 2, 0, 6, 3, 2, 5};
    int n = sizeof(heights) / sizeof(heights[0]);

    trap(heights, n);

    return 0;
}
