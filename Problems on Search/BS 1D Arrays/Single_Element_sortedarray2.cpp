#include <iostream>
#include <vector>
using namespace std;

// Finds the element that appears only once
// All other elements appear exactly twice
int findSingleElement(const vector<int>& arr) {
    int n = arr.size();

    if (n == 1) return arr[0];
    if (arr[0] != arr[1]) return arr[0];
    if (arr[n - 1] != arr[n - 2]) return arr[n - 1];

    int low = 1, high = n - 2;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1])
            return arr[mid];

        if ((mid % 2 == 1 && arr[mid] == arr[mid - 1]) ||
            (mid % 2 == 0 && arr[mid] == arr[mid + 1])) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements (SORTED): ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int result = findSingleElement(arr);

    if (result != -1)
        cout << "Single element is: " << result << endl;
    else
        cout << "No single element found" << endl;

    return 0;
}

// ================= ADDITIONAL EXPLANATION =================
//
// PROBLEM:
// - Given a sorted array
// - Every element appears exactly twice except one
// - Find the single element in O(log n) time
//
// KEY OBSERVATION:
// - Before the single element:
//   pairs start at EVEN index (0,1), (2,3), ...
// - After the single element:
//   pairs start at ODD index (1,2), (3,4), ...
//
// WHY MID INDEX PARITY MATTERS:
// - If mid is EVEN and arr[mid] == arr[mid+1]
//   → single element is on the RIGHT side
// - If mid is ODD and arr[mid] == arr[mid-1]
//   → single element is on the RIGHT side
// - Otherwise, single element is on the LEFT side
//
// ================= EXAMPLE SOLUTION =================
//
// INPUT:
// Array: 1 1 2 3 3 4 4
//
// STEP-BY-STEP DRY RUN:
//
// n = 7
// low = 1, high = 5
//
// mid = 3 → arr[mid] = 3
// arr[3] == arr[4]
// mid is ODD and matches next → pattern broken
// → search LEFT
//
// high = 2
//
// mid = 2 → arr[mid] = 2
// arr[2] != arr[1] AND arr[2] != arr[3]
// → SINGLE ELEMENT FOUND
//
// OUTPUT:
// Single element is: 2
//
// ================= EDGE CASES =================
//
// Case 1:
// Array: 5
// → Single element = 5
//
// Case 2:
// Array: 2 3 3 4 4
// → Single element at start → 2
//
// Case 3:
// Array: 1 1 2
// → Single element at end → 2
//
// ================= COMPLEXITY =================
//
// Time Complexity: O(log n)
// Space Complexity: O(1)
//
// =========================================================
