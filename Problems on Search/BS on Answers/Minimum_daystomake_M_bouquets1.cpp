#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Check if it's possible to make m bouquets in given days
bool isPossible(const vector<int>& arr, int day, int m, int k) {
    int bouquets = 0;
    int flowers = 0;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] <= day) {
            flowers++;
            if (flowers == k) {
                bouquets++;
                flowers = 0;
            }
        } else {
            flowers = 0;
        }
    }
    return bouquets >= m;
}

// Binary search to find minimum day
int minimumDay(vector<int>& arr, int m, int k) {
    long long n = arr.size();

    // Not enough flowers
    if ((long long)m * k > n) return -1;

    int low = *min_element(arr.begin(), arr.end());
    int high = *max_element(arr.begin(), arr.end());
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(arr, mid, m, k)) {
            ans = mid;
            high = mid - 1;   // try earlier day
        } else {
            low = mid + 1;    // need more days
        }
    }
    return ans;
}

int main() {
    int n, m, k;

    cout << "Enter number of flowers: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter bloom days of flowers: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter number of bouquets (m): ";
    cin >> m;

    cout << "Enter flowers per bouquet (k): ";
    cin >> k;

    int result = minimumDay(arr, m, k);

    cout << "Minimum day to make bouquets: " << result << endl;

    return 0;
}

// ================= ADDITIONAL EXPLANATION =================
//
// PROBLEM SUMMARY:
// - arr[i] = day when ith flower blooms
// - Each bouquet needs k CONSECUTIVE flowers
// - Need to make m bouquets
// - Find MINIMUM day to do this
//
// KEY OBSERVATION:
// - If we can make bouquets on day D,
//   then we can also make them on any day > D
// - This forms a MONOTONIC pattern → Binary Search
//
// HOW isPossible() WORKS:
// - Traverse flowers
// - Count consecutive bloomed flowers (arr[i] <= day)
// - Every time we get k flowers → one bouquet
// - Reset count after bouquet
//
// ================= EXAMPLE SOLUTION =================
//
// INPUT:
// arr = {1, 10, 3, 10, 2}
// m = 3
// k = 1
//
// Bloom days range:
// low = 1, high = 10
//
// mid = 5
// Blooms ≤ 5 → {1,3,2}
// Bouquets = 3 → possible
//
// Try earlier day
//
// mid = 3
// Blooms ≤ 3 → {1,3,2}
// Bouquets = 3 → possible
//
// mid = 2
// Blooms ≤ 2 → {1,2}
// Bouquets = 2 → not possible
//
// ANSWER = 3
//
// ================= EDGE CASE =================
//
// If m*k > n
// → Not enough flowers
// → Return -1
//
// ================= COMPLEXITY =================
//
// Time Complexity:
// O(n log(max(arr)))
//
// Space Complexity:
// O(1)
//
// =========================================================
