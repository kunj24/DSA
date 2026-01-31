#include <iostream>
#include <vector>
using namespace std;


// Returns index of any peak element
//any peak index there is lot of peak index in the array
int peakElement(const vector<int>& arr, int n) {

    // If only one element
    if (n == 1) return 0;

    // Check first element
    if (arr[0] > arr[1]) return 0;

    // Check last element
    if (arr[n - 1] > arr[n - 2]) return n - 1;

    // Check middle elements
    for (int i = 1; i <= n - 2; i++) {
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements: " << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int ans = peakElement(arr, n);
    cout << "Peak element index: " << ans << endl;

    return 0;
}

// ================= ADDITIONAL EXPLANATION =================
//
// WHAT IS A PEAK ELEMENT:
// - An element which is greater than its neighbors
// - For first element → compare only with next
// - For last element → compare only with previous
//
// WHY WE CHECK EDGES SEPARATELY:
// - arr[-1] and arr[n] do not exist
// - Prevents out-of-bounds errors
//
// CONDITIONS FOR PEAK:
//
// Case 1: First element
// arr[0] > arr[1]
//
// Case 2: Last element
// arr[n-1] > arr[n-2]
//
// Case 3: Middle element
// arr[i] > arr[i-1] AND arr[i] > arr[i+1]
//
// ================= EXAMPLE SOLUTION =================
//
// INPUT:
// Array: 1 3 20 4 1 0
//
// STEP-BY-STEP:
//
// n = 6
// Check first → 1 > 3 ❌
// Check last → 0 > 1 ❌
//
// i = 1 → 3 > 1 but 3 < 20 ❌
// i = 2 → 20 > 3 AND 20 > 4 ✅
//
// OUTPUT:
// Peak element index: 2
//
// ================= EDGE CASES =================
//
// Array: 5
// → Peak index = 0
//
// Array: 5 4 3
// → Peak index = 0
//
// Array: 1 2 3 4
// → Peak index = 3
//
// ================= COMPLEXITY =================
//
// Time Complexity: O(n)
// Space Complexity: O(1)
//
// NOTE:
// - Binary Search solution exists in O(log n)
// ====================================================================
