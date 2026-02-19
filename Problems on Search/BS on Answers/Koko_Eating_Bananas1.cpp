#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Calculate total hours needed for given eating speed
long long calculateTotalHours(const vector<int>& arr, int speed) {
    long long totalHours = 0;

    for (int i = 0; i < arr.size(); i++) {
        totalHours += (arr[i] + speed - 1) / speed; // ceil(arr[i]/speed)
    }
    return totalHours;
}

// Binary Search to find minimum eating speed
int minEatingSpeed(vector<int>& arr, int h) {
    int n = arr.size();

    int low = 1;
    int high = *max_element(arr.begin(), arr.end());
    int ans = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        long long totalHours = calculateTotalHours(arr, mid);

        if (totalHours <= h) {
            ans = mid;          // possible answer
            high = mid - 1;     // try smaller speed
        } else {
            low = mid + 1;      // need higher speed
        }
    }
    return ans;
}

int main() {
    int n, h;

    cout << "Enter number of piles: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter bananas in each pile: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter total hours h: ";
    cin >> h;

    int ans = minEatingSpeed(arr, h);
    cout << "Minimum bananas per hour: " << ans << endl;

    return 0;
}

// ================= ADDITIONAL EXPLANATION =================
//
// PROBLEM SUMMARY:
// - Koko eats k bananas per hour
// - One pile per hour
// - Must finish all piles within h hours
// - Find MINIMUM possible k
//
// WHY BINARY SEARCH WORKS:
// - Eating speed k lies between 1 and max(a[i])
// - If Koko can eat with speed k,
//   then she can also eat with any speed > k
// - This gives a MONOTONIC function
//
// HOW TOTAL HOURS ARE CALCULATED:
// For each pile:
// hours = ceil(a[i] / k)
//
// We compute ceil using:
// (a[i] + k - 1) / k
//
// ================= EXAMPLE SOLUTION =================
//
// Input:
// a = {7, 15, 6, 3}
// h = 8
//
// max pile = 15
// low = 1, high = 15
//
// mid = 8
// hours = 1 + 2 + 1 + 1 = 5 <= 8
// → possible answer → try smaller
//
// mid = 4
// hours = 2 + 4 + 2 + 1 = 9 > 8
// → too slow → increase speed
//
// mid = 5
// hours = 2 + 3 + 2 + 1 = 8 <= 8
// → answer = 5
//
// OUTPUT:
// Minimum bananas per hour: 5
//
// ================= COMPLEXITY =================
//
// Time Complexity:
// O(n log(max(a)))
//
// Space Complexity:
// O(1)
//
// =========================================================
