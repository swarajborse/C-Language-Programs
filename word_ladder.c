#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000   // Maximum words in dictionary
#define MAX_LEN   20     // Maximum word length

// Check if two words differ by exactly one letter
int oneLetterDiff(const char *a, const char *b) {
    int diff = 0;
    for (int i = 0; a[i] && b[i]; i++) {
        if (a[i] != b[i]) diff++;
        if (diff > 1) return 0;
    }
    return diff == 1;
}

// Queue structures for BFS
typedef struct {
    int wordIndex;
    int steps;
} Node;

typedef struct {
    Node data[2000];
    int front, rear;
} Queue;

void initQueue(Queue *q) { q->front = q->rear = 0; }
int isEmpty(Queue *q) { return q->front == q->rear; }

void enqueue(Queue *q, int index, int steps) {
    q->data[q->rear].wordIndex = index;
    q->data[q->rear].steps = steps;
    q->rear++;
}

Node dequeue(Queue *q) { return q->data[q->front++]; }

// BFS to find shortest transformation length
int ladderLength(char *beginWord, char *endWord, char wordList[][MAX_LEN], int wordCount) {
    int endIndex = -1;

    // Check if endWord exists in dictionary
    for (int i = 0; i < wordCount; i++) {
        if (strcmp(wordList[i], endWord) == 0) {
            endIndex = i;
            break;
        }
    }
    if (endIndex == -1) return 0;  // endWord not in wordList

    int visited[MAX_WORDS] = {0};
    Queue q;
    initQueue(&q);

    // Start BFS
    enqueue(&q, -1, 1); // -1 represents beginWord

    while (!isEmpty(&q)) {
        Node curr = dequeue(&q);
        char *word = (curr.wordIndex == -1) ? beginWord : wordList[curr.wordIndex];

        for (int i = 0; i < wordCount; i++) {
            if (!visited[i] && oneLetterDiff(word, wordList[i])) {
                if (strcmp(wordList[i], endWord) == 0)
                    return curr.steps + 1;
                visited[i] = 1;
                enqueue(&q, i, curr.steps + 1);
            }
        }
    }
    return 0;
}

// ------------------ TEST CASES ------------------

int main() {
    // Test Case 1: Classic example
    char wordList1[][MAX_LEN] = {"hot", "dot", "dog", "lot", "log", "cog"};
    int wordCount1 = 6;
    printf("Test Case 1:\n");
    printf("Begin: hit, End: cog\n");
    printf("Dictionary: {hot, dot, dog, lot, log, cog}\n");
    printf("Shortest transformation length = %d (Expected: 5)\n\n",
           ladderLength("hit", "cog", wordList1, wordCount1));

    // Test Case 2: End word not in dictionary
    char wordList2[][MAX_LEN] = {"hot", "dot", "dog", "lot", "log"};
    int wordCount2 = 5;
    printf("Test Case 2:\n");
    printf("Begin: hit, End: cog\n");
    printf("Dictionary: {hot, dot, dog, lot, log}\n");
    printf("Shortest transformation length = %d (Expected: 0)\n\n",
           ladderLength("hit", "cog", wordList2, wordCount2));

    // Test Case 3: Begin equals end
    char wordList3[][MAX_LEN] = {"aaa", "aab", "abb", "bbb"};
    int wordCount3 = 4;
    printf("Test Case 3:\n");
    printf("Begin: aaa, End: aaa\n");
    printf("Dictionary: {aaa, aab, abb, bbb}\n");
    printf("Shortest transformation length = %d (Expected: 0 or 1 depending on spec)\n\n",
           ladderLength("aaa", "aaa", wordList3, wordCount3));

    // Test Case 4: Longer chain
    char wordList4[][MAX_LEN] = {"most", "fist", "lost", "cost", "fish", "miss", "moss", "mist"};
    int wordCount4 = 8;
    printf("Test Case 4:\n");
    printf("Begin: lost, End: miss\n");
    printf("Dictionary: {most, fist, lost, cost, fish, miss, moss, mist}\n");
    printf("Shortest transformation length = %d (Expected: 5)\n\n",
           ladderLength("lost", "miss", wordList4, wordCount4));

    // Test Case 5: No possible path
    char wordList5[][MAX_LEN] = {"aaa", "aab", "abb", "abc"};
    int wordCount5 = 4;
    printf("Test Case 5:\n");
    printf("Begin: xyz, End: abc\n");
    printf("Dictionary: {aaa, aab, abb, abc}\n");
    printf("Shortest transformation length = %d (Expected: 0)\n",
           ladderLength("xyz", "abc", wordList5, wordCount5));

    return 0;
}
