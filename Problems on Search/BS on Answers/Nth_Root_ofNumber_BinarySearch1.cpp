#include <iostream>
using namespace std;

// Returns the Nth root of m if it exists, otherwise -1
int NthRoot(int n, int m) {
    int low = 1, high = m;

    while (low <= high) {
        int mid = (low + high) / 2;

        long long power = 1;
        for (int i = 0; i < n; i++) {
            power *= mid;
            if (power > m) break;   // avoid overflow
        }

        if (power == m)
            return mid;
        else if (power < m)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;   // Nth root does not exist
}

int main() {
    int n, m;

    cout << "Enter value of n (root): ";
    cin >> n;

    cout << "Enter number: ";
    cin >> m;

    int ans = NthRoot(n, m);

    if (ans != -1)
        cout << n << "th root of " << m << " is: " << ans << endl;
    else
        cout << n << "th root of " << m << " does not exist." << endl;

    return 0;
}

// ================= ADDITIONAL EXPLANATION =================
//
// WHAT IS Nth ROOT:
// - Nth root of a number m is a number x such that
//   x^n = m
//
// EXAMPLE:
// 3rd root of 27 = 3   (3^3 = 27)
// 2nd root of 16 = 4   (4^2 = 16)
//
// WHY BINARY SEARCH IS USED:
// - Answer lies between 1 and m
// - We can reduce search space efficiently
//
// HOW THE ALGORITHM WORKS:
// 1. Take mid
// 2. Compute mid^n safely
// 3. Compare mid^n with m
// 4. Adjust search space accordingly
//
// ================= EXAMPLE SOLUTION =================
//
// INPUT:
// n = 3
// m = 27
//
// STEP-BY-STEP:
//
// low = 1, high = 27
//
// mid = 14 → 14^3 > 27
// → move left
//
// mid = 7 → 7^3 > 27
// → move left
//
// mid = 3 → 3^3 = 27
// → FOUND
//
// OUTPUT:
// 3rd root of 27 is: 3
//
// ================= EDGE CASES =================
//
// n = 1 → root = m
// m = 1 → root = 1
// If no integer x exists such that x^n = m → return -1
//
// ================= COMPLEXITY =================
//
// Time Complexity: O(log m * n)
// Space Complexity: O(1)
//
// =========================================================
