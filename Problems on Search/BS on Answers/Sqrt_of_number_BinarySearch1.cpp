#include <iostream>
using namespace std;

// Returns floor value of square root of n
int sqrtofnumber(int n) {
    int low = 0, high = n;
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if ((long long)mid * mid <= n) { // avoid overflow
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    int n;

    cout << "Enter number that you need to sqrt: ";
    cin >> n;

    int ans = sqrtofnumber(n);

    cout << "The sqrt of " << n << " (floor value) is: " << ans << endl;
    return 0;
}

// ================= ADDITIONAL EXPLANATION =================
//
// WHAT THIS PROGRAM DOES:
// - Finds the square root of a number
// - Returns only the FLOOR value (integer part)
//
// WHY BINARY SEARCH IS USED:
// - Square root lies between 0 and n
// - We can eliminate half the range each time
// - Much faster than linear checking
//
// KEY IDEA:
// - If mid * mid <= n → mid can be a possible answer
// - If mid * mid > n → discard right half
//
// ================= EXAMPLE SOLUTION =================
//
// INPUT:
// n = 27
//
// STEP-BY-STEP DRY RUN:
//
// low = 0, high = 27
//
// mid = 13 → 13*13 = 169 > 27
// → move left → high = 12
//
// mid = 6 → 6*6 = 36 > 27
// → move left → high = 5
//
// mid = 2 → 2*2 = 4 <= 27
// → ans = 2 → move right
//
// mid = 4 → 4*4 = 16 <= 27
// → ans = 4 → move right
//
// mid = 5 → 5*5 = 25 <= 27
// → ans = 5 → move right
//
// low > high → stop
//
// OUTPUT:
// Floor sqrt of 27 = 5
//
// ================= EDGE CASES =================
//
// n = 0 → sqrt = 0
// n = 1 → sqrt = 1
// n = 16 → sqrt = 4
//
// ================= COMPLEXITY =================
//
// Time Complexity: O(log n)
// Space Complexity: O(1)
//
// =========================================================
