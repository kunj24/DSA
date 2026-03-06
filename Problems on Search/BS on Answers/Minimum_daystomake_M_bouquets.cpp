#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Check if it is possible to make m bouquets on a given day
bool isPossible(vector<int>& arr, int day, int m, int k) {
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

// Brute force to find minimum day
int minimumDay(vector<int>& arr, int m, int k) {
    int n = arr.size();

    // Not enough flowers
    if (m * k > n) return -1;

    int low = *min_element(arr.begin(), arr.end());
    int high = *max_element(arr.begin(), arr.end());

    for (int day = low; day <= high; day++) {
        if (isPossible(arr, day, m, k)) {
            return day;   // first possible day
        }
    }
    return -1;
}

int main() {
    int n, m, k;

    cout << "Enter number of flowers: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter bloom days of flowers: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter number of bouquets: ";
    cin >> m;

    cout << "Enter flowers per bouquet: ";
    cin >> k;

    int result = minimumDay(arr, m, k);

    cout << "Minimum day to make bouquets: " << result << endl;

    return 0;
}

// ================= ADDITIONAL EXPLANATION =================
//
// PROBLEM:
// - arr[i] represents the day the ith flower blooms
// - Each bouquet needs k CONSECUTIVE flowers
// - Need to make m bouquets
// - Find the minimum day to achieve this
//
// BRUTE FORCE IDEA:
// - Try each possible day from minimum bloom day to maximum bloom day
// - For each day, check if we can form m bouquets
// - First day that satisfies the condition is the answer
//
// HOW isPossible() WORKS:
// - Traverse the array
// - Count consecutive flowers that bloomed on or before the given day
// - When count reaches k, one bouquet is formed
// - Reset flower count after each bouquet
//
// ================= EXAMPLE SOLUTION =================
//
// INPUT:
// arr = {1, 10, 3, 10, 2}
// m = 3
// k = 1
//
// Bloom days range:
// min = 1, max = 10
//
// Day = 1:
// Flowers bloomed → {1}
// Bouquets formed = 1 ❌
//
// Day = 2:
// Flowers bloomed → {1,2}
// Bouquets formed = 2 ❌
//
// Day = 3:
// Flowers bloomed → {1,3,2}
// Bouquets formed = 3 ✅
//
// ANSWER = 3
//
// ================= EDGE CASE =================
//
// If m * k > total flowers
// → Impossible to form bouquets
// → Return -1
//
// ================= COMPLEXITY =================
//
// Time Complexity:
// O((max(arr) - min(arr)) * n)
//
// Space Complexity:
// O(1)
//
// NOTE:
// - This approach is slow for large inputs
// - Binary Search is the optimized solution
//
// =========================================================
