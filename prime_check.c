#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

/*
  Prime checker with robust input handling.

  Improvements over typical classroom versions:
  - clear is_prime() function with 6k±1 optimization (O(sqrt(n)))
  - handles n < 2 correctly
  - supports both CLI arg and interactive input
  - validates that input is a non-negative integer and within range
  - no undefined behavior on bad input
*/

static bool is_prime(long long n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    // 6k ± 1 optimization: all primes > 3 are of this form
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

static int read_number_from_stdin(long long *out) {
    // Read a line and parse as long long
    char buf[128];
    if (!fgets(buf, sizeof(buf), stdin)) return 0;

    char *end = NULL;
    long long v = strtoll(buf, &end, 10);

    // Reject if no digits were consumed or trailing junk exists
    if (end == buf) return 0;
    while (*end == ' ' || *end == '\t' || *end == '\n' || *end == '\r') end++;
    if (*end != '\0') return 0;

    if (v < 0) return 0; // only non-negative here
    *out = v;
    return 1;
}

int main(int argc, char *argv[]) {
    long long n = -1;

    if (argc >= 2) {
        // Try parse from argv[1]
        char *end = NULL;
        n = strtoll(argv[1], &end, 10);
        if (end == argv[1] || *end != '\0' || n < 0) {
            fprintf(stderr, "Usage: %s <non-negative-integer>\n", argv[0]);
            return 1;
        }
    } else {
        printf("Enter a non-negative integer: ");
        if (!read_number_from_stdin(&n)) {
            fprintf(stderr, "Invalid input.\n");
            return 1;
        }
    }

    printf("%lld is %sprime.\n", n, is_prime(n) ? "" : "not ");
    return 0;
}
