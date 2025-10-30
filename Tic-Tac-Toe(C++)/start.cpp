#include <iostream>
#include <vector>
using namespace std;

int main() {
    int rounds = 3; // Total rounds
    cout << "=== Factorial Challenge (Best of 3) ===\n";

    for (int round = 1; round <= rounds; round++) {
        int n;
        cout << "\n--- Round " << round << " ---\n";
        cout << "How many numbers do you want to enter? ";
        cin >> n;

        if (n <= 0) {
            cout << "Invalid input! Number of entries must be positive.\n";
            continue; // Skip invalid round
        }

        vector<int> numbers(n);
        vector<unsigned long long> factorials(n);

        // Input numbers
        for (int i = 0; i < n; i++) {
            cout << "Enter number " << i + 1 << ": ";
            cin >> numbers[i];
        }

        // Calculate factorials
        for (int i = 0; i < n; i++) {
            if (numbers[i] < 0) {
                factorials[i] = 0; // Not defined
            } else {
                factorials[i] = 1;
                for (int j = 1; j <= numbers[i]; j++) {
                    factorials[i] *= j;
                }
            }
        }

        // Display results
        cout << "\nResults for Round " << round << ":\n";
        unsigned long long highest = 0;
        int winnerIndex = -1;

        for (int i = 0; i < n; i++) {
            if (numbers[i] < 0)
                cout << "Factorial of " << numbers[i] << " is not defined.\n";
            else {
                cout << "Factorial of " << numbers[i] << " = " << factorials[i] << "\n";
                if (factorials[i] > highest) {
                    highest = factorials[i];
                    winnerIndex = i;
                }
            }
        }

        // Announce round winner
        if (winnerIndex != -1)
            cout << "\nWinner of Round " << round << ": Number " 
                 << numbers[winnerIndex] << " with factorial " << highest << "!\n";
        else
            cout << "\nNo valid numbers entered this round.\n";
    }

    cout << "\n=== Game Over! All 3 rounds completed! ===\n";
    cout << "Thanks for playing the Factorial Challenge \n";
    return 0;
}