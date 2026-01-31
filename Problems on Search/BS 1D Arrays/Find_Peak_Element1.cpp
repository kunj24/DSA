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

    int low = 1;
    int high = n - 2;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
            return mid;
        }
        else if (arr[mid] > arr[mid - 1]) {
            low = mid + 1;
        }
        else if (arr[mid] > arr[mid + 1]) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
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
// - An element that is strictly greater than its neighbors
// - For first element → compare only with next
// - For last element → compare only with previous
//
// WHY BINARY SEARCH WORKS:
// - If arr[mid] > arr[mid-1], slope is rising
//   → a peak must exist on the RIGHT side
// - If arr[mid] < arr[mid-1], slope is falling
//   → a peak must exist on the LEFT side
// - We always move in the direction where a peak is guaranteed
//
// WHY AT LEAST ONE PEAK ALWAYS EXISTS:
// - Either the array goes up then down
// - Or first / last element itself is a peak
//
// ================= EXAMPLE SOLUTION =================
//
// INPUT:
// Array: 1 2 3 1
//
// STEP-BY-STEP DRY RUN:
//
// n = 4
//
// Check first:
// arr[0] > arr[1] → 1 > 2 ❌
//
// Check last:
// arr[3] > arr[2] → 1 > 3 ❌
//
// low = 1, high = 2
//
// mid = 1 → arr[mid] = 2
// arr[1] > arr[0] but arr[1] < arr[2]
// → slope rising → move right
// low = 2
//
// mid = 2 → arr[mid] = 3
// arr[2] > arr[1] AND arr[2] > arr[3]
// → PEAK FOUND
//
// OUTPUT:
// Peak element index: 2
//
// ================= EDGE CASES =================
//
// Array: 5
// → Peak index = 0
//
// Array: 5 4 3 2
// → Peak index = 0
//
// Array: 1 2 3 4
// → Peak index = 3
//
// ================= COMPLEXITY =================
//
// Time Complexity: O(log n)
// Space Complexity: O(1)
//
// =========================================================
