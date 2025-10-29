#include <stdio.h>

// Structure to represent an activity
typedef struct {
    int index;
    int start;
    int finish;
} Activity;

// Function to swap two activities
void swap(Activity *a, Activity *b) {
    Activity temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort activities by finish time using simple bubble sort
// (You can replace this with qsort if desired)
void sortActivities(Activity activities[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (activities[j].finish > activities[j + 1].finish) {
                swap(&activities[j], &activities[j + 1]);
            }
        }
    }
}

// Function to perform activity selection
void activitySelection(int start_times[], int finish_times[], int n) {
    Activity activities[n];
    
    // Combine start, finish, and index
    for (int i = 0; i < n; i++) {
        activities[i].index = i;
        activities[i].start = start_times[i];
        activities[i].finish = finish_times[i];
    }

    // Sort activities by finish time
    sortActivities(activities, n);

    printf("Selected activities (indices): ");

    // Select the first activity
    int last_finish_time = activities[0].finish;
    printf("%d ", activities[0].index);

    // Consider the rest of the activities
    for (int i = 1; i < n; i++) {
        if (activities[i].start >= last_finish_time) {
            printf("%d ", activities[i].index);
            last_finish_time = activities[i].finish;
        }
    }
    printf("\n");
}

// Main function with test cases
int main() {
    // Example 1
    int start_times1[] = {1, 3, 0, 5, 8, 5};
    int finish_times1[] = {2, 4, 6, 7, 9, 9};
    int n1 = sizeof(start_times1) / sizeof(start_times1[0]);
    printf("Example 1:\n");
    activitySelection(start_times1, finish_times1, n1);

    // Example 2
    int start_times2[] = {10, 12, 20};
    int finish_times2[] = {20, 25, 30};
    int n2 = sizeof(start_times2) / sizeof(start_times2[0]);
    printf("\nExample 2:\n");
    activitySelection(start_times2, finish_times2, n2);

    return 0;
}
