#include <iostream>
#include <vector>
using namespace std;

// Brute force function to find minimum k
int minEatingSpeed(vector<int>& a, int h) {
    int n = a.size();

    // Find maximum pile (upper bound for k)
    int maxi = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > maxi)
            maxi = a[i];
    }

    // Try all possible values of k from 1 to max pile
    for (int k = 1; k <= maxi; k++) {
        long long hours = 0;

        // Calculate total hours needed with speed k
        for (int i = 0; i < n; i++) {
            hours += (a[i] + k - 1) / k; // ceil(a[i]/k)
        }

        // If total hours is within limit, return k
        if (hours <= h)
            return k;
    }

    return maxi;
}

int main() {
    int n, h;

    cout << "Enter number of piles: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter bananas in each pile: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "Enter total hours h: ";
    cin >> h;

    int ans = minEatingSpeed(a, h);
    cout << "Minimum bananas per hour: " << ans << endl;

    return 0;
}

// ================= ADDITIONAL EXPLANATION =================
//
// BRUTE FORCE IDEA:
// - Koko can eat between 1 to max(a[]) bananas per hour
// - Try each possible speed k
// - For each k, calculate total hours required
// - First k that satisfies hours <= h is the answer
//
// HOW HOURS ARE CALCULATED:
// For a pile with a[i] bananas:
// hours = ceil(a[i] / k)
//
// We use:
// (a[i] + k - 1) / k
//
// ================= EXAMPLE SOLUTION =================
//
// Input:
// a = {7, 15, 6, 3}
// h = 8
//
// Try k = 4:
// 7/4 = 2 hours
// 15/4 = 4 hours
// 6/4 = 2 hours
// 3/4 = 1 hour
// Total = 9 hours ❌
//
// Try k = 5:
// 7/5 = 2 hours
// 15/5 = 3 hours
// 6/5 = 2 hours
// 3/5 = 1 hour
// Total = 8 hours ✅
//
// Answer = 5
//
// ================= COMPLEXITY =================
//
// Time Complexity:
// O(max(a[]) * n)
//
// Space Complexity:
// O(1)
//
// LIMITATION:
// - Too slow for large inputs
// - Optimized solution uses Binary Search
//
// =========================================================    
