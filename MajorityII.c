// package _5_arrays.hard;
// Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times
// eg:- [1,1,1,3,3,2,2,2] , n=8
// O/P -> [1,2]
// n/3 = 2
// therefore the occurrence should be more than n/3 -> therefore in this case minimum should be 3 times 
// 1 appears -> 3 times 
// 2 appears -> 3 times
// and 3+3 = 6, remaining is 2
// and 2 <= n/3
// therefore in majority II question there will be at most 2 majority integers  

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// extreme brute force -> check every element in the array and traverse the entire array and check the appearance 
// TC -> O(n^2)
// SC -> O(1)
void majorityElement_bruteforce(int arr[], int n) {
    int ans[2];  // stores at most 2 majority elements
    int ans_size = 0;

    for (int i = 0; i < n; i++) {
        int already_present = 0;
        for (int k = 0; k < ans_size; k++) {
            if (ans[k] == arr[i]) {
                already_present = 1;
                break;
            }
        }
        if (already_present) continue;

        int count = 0;
        for (int j = 0; j < n; j++) {
            if (arr[j] == arr[i]) count++;
        }
        if (count > n / 3) {
            ans[ans_size++] = arr[i];
        }
        if (ans_size == 2) break;
    }

    printf("Brute Force Result: ");
    for (int i = 0; i < ans_size; i++) printf("%d ", ans[i]);
    printf("\n");
}

// better solution -> find the frequency and store it in hashmap or in an array
// for 1st case: TC -> O(n) + O(n) + O(1) -> avg or best case in unordered map
// for 2nd case: TC -> O(n) + O(1) -> avg or best case in unordered map 
// SC -> O(n) + O(1)
void majorityElement_better(int arr[], int n) {
    // Since C does not have a HashMap by default, we'll simulate one using arrays
    int unique[1000];
    int freq[1000];
    int unique_count = 0;

    int ans[2];
    int ans_size = 0;

    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < unique_count; j++) {
            if (unique[j] == arr[i]) {
                freq[j]++;
                found = 1;

                // if we don't want two O(n) loops to run -> we want to do code in one loop
                if (freq[j] > n / 3) {
                    int already_in_ans = 0;
                    for (int k = 0; k < ans_size; k++) {
                        if (ans[k] == arr[i]) already_in_ans = 1;
                    }
                    if (!already_in_ans) ans[ans_size++] = arr[i];
                }
                break;
            }
        }
        if (!found) {
            unique[unique_count] = arr[i];
            freq[unique_count] = 1;
            unique_count++;
        }
        if (ans_size == 2) break;
    }

    printf("Better Solution Result: ");
    for (int i = 0; i < ans_size; i++) printf("%d ", ans[i]);
    printf("\n");
}

// Optimal solution 
// TC -> O(N) + O(N)
// SC -> O(1)
void majorityElement_optimal(int arr[], int n) {
    int cnt1 = 0;
    int cnt2 = 0;
    int el1 = INT_MIN;
    int el2 = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (cnt1 == 0 && el2 != arr[i]) {
            cnt1 = 1;
            el1 = arr[i];
        }
        else if (cnt2 == 0 && el1 != arr[i]) {
            cnt2 = 1;
            el2 = arr[i];
        }
        else if (el1 == arr[i]) cnt1++;
        else if (el2 == arr[i]) cnt2++;
        else {
            cnt1--;
            cnt2--;
        }
    }

    // Reset counts
    cnt1 = 0;
    cnt2 = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == el1) cnt1++;
        if (arr[i] == el2) cnt2++;
    }

    printf("Optimal Solution Result: ");
    if (cnt1 > n / 3) printf("%d ", el1);
    if (cnt2 > n / 3 && el2 != el1) printf("%d ", el2);
    printf("\n");
}

int main() {
    // List<Integer> arr = new ArrayList<>();
    // arr.addAll(Arrays.asList(1,1,1,3,3,2,2,2));

    int arr[] = {1, 1, 1, 3, 3, 2, 2, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    // List<Integer> arr = List.of(1,1,1,3,3,2,2,2);

    // Call all three versions
    majorityElement_bruteforce(arr, n);
    majorityElement_better(arr, n);
    majorityElement_optimal(arr, n);

    return 0;
}
