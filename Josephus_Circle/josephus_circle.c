/**
 * =============================================================================
 *  Josephus Circle - INTERACTIVE VISUAL EDITION
 *  File: simulation/josephus_circle_interactive.c
 *
 *  Features:
 *  - Animated circle: O (alive), X (eliminated)
 *  - Press Enter to continue after each elimination
 *  - Color-coded output (Green/Red/Yellow)
 *  - Input validation + retry loop
 *  - Replay menu
 *  - Math formula for k==2
 *
 *  Compile: gcc -o josephus simulation/josephus_circle_interactive.c
 *  Run: ./josephus
 *
 *  Hacktoberfest 2025 - The Ultimate Learning Experience
 * =============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

// ANSI Colors
#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define BOLD    "\033[1m"

// Clear screen (cross-platform)
void clear_screen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Print circle with visual status
void print_circle(int *circle, int n, int current_pos) {
    printf(YELLOW "   Circle: " RESET);
    for (int i = 1; i <= n; i++) {
        if (i == current_pos) printf(BOLD "→" RESET);
        if (circle[i]) {
            printf(GREEN "O " RESET);  // alive
        } else {
            printf(RED "X " RESET);    // eliminated
        }
    }
    printf("\n           ");
    for (int i = 1; i <= n; i++) {
        printf("%2d ", i);
    }
    printf("\n\n");
}

// Safe input with retry
int safe_input(const char* prompt, int min_val) {
    int value;
    while (1) {
        printf(YELLOW "%s" RESET, prompt);
        if (scanf("%d", &value) == 1 && value >= min_val) {
            while (getchar() != '\n'); // clear buffer
            return value;
        }
        while (getchar() != '\n');
        printf(RED "Invalid! Enter >= %d\n" RESET, min_val);
    }
}

int josephus_interactive(int n, int k) {
    int *circle = (int *)malloc((n + 1) * sizeof(int));
    for (int i = 1; i <= n; i++) circle[i] = 1;

    int alive = n;
    int pos = 1;
    int count = 0;

    clear_screen();
    printf(BOLD GREEN "JOSEPHUS CIRCLE - VISUAL MODE\n" RESET);
    printf("Every %d%s person will be eliminated.\n\n", k, k==1?"st":k==2?"nd":k==3?"rd":"th");

    while (alive > 1) {
        print_circle(circle, n, pos);
        if (circle[pos]) {
            count++;
            if (count == k) {
                circle[pos] = 0;
                alive--;
                printf(RED "ELIMINATED: Person %d\n" RESET, pos);
                printf(YELLOW "Press Enter to continue..." RESET);
                getchar();
                count = 0;
            }
        }
        pos = (pos % n) + 1;
    }

    // Find survivor
    for (int i = 1; i <= n; i++) {
        if (circle[i]) {
            clear_screen();
            print_circle(circle, n, i);
            printf(BOLD GREEN "SURVIVOR: PERSON %d!\n" RESET, i);
            free(circle);
            return i;
        }
    }
    free(circle);
    return -1;
}

int main() {
    while (1) {
        clear_screen();
        printf(BOLD GREEN "JOSEPHUS CIRCLE - INTERACTIVE\n" RESET);
        printf("Watch the circle shrink step by step!\n\n");

        int n = safe_input("Enter number of people (n >= 1): ", 1);
        int k = safe_input("Enter counting step (k >= 1): ", 1);

        int survivor = josephus_interactive(n, k);

        // FIXED: One single printf, no broken string
        if (k == 2) {
            int m = 1;
            while ((1 << m) <= n) m++;
            m--;
            int l = n - (1 << m);
            int formula = 2 * l + 1;
            printf(YELLOW "\n(Math: for k=2, f(%d) = %d)\n" RESET, n, formula);
        }

        printf(YELLOW "\nPlay again? (y/n): " RESET);
        char choice;
        scanf(" %c", &choice);
        if (choice != 'y' && choice != 'Y') break;
    }

    printf(BOLD "Thanks for playing! Hacktoberfest 2025\n" RESET);
    return 0;
}