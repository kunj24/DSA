#include <iostream>
#include <vector>
using namespace std;

// Lower Bound: returns first index where arr[i] >= target
// Works correctly when array is SORTED
int lowerbound(const vector<int>& arr, int target) {
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        if (arr[i] >= target) {
            return i;   // first element >= target
        }
    }
    return -1;          // no such element found
}

int main() {
    int n, target;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements (SORTED): " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter target element: ";
    cin >> target;

    int result = lowerbound(arr, target);

    if (result != -1) {
        cout << "Lower bound index: " << result << endl;
    } else {
        cout << "Lower bound does not exist." << endl;
    }

    return 0;
}

// ======================= ADDITIONAL EXPLANATION =======================
//
// WHAT IS LOWER BOUND:
// - Lower bound is the FIRST index where value is
//   greater than or equal to the target
//
// WHY WE USE LOWER BOUND:
// - Used in searching ranges
// - Used in STL (lower_bound)
// - Helpful in binary search based problems
//
// IMPORTANT CONDITION:
// - Array should be SORTED
//
// POSSIBLE CASES:
//
// Case 1: arr[i] == target
// → That index is the lower bound
//
// Case 2: arr[i] > target
// → That index is also the lower bound
//
// Case 3: All elements < target
// → Lower bound does not exist → return -1
//
// EXAMPLE 1:
//
// Array: 1 3 5 7 9
// Target: 5
// → arr[2] = 5 (>= target)
// → Lower bound index = 2
//
// EXAMPLE 2:
//
// Array: 1 3 5 7 9
// Target: 6
// → arr[3] = 7 (first >= 6)
// → Lower bound index = 3
//
// EXAMPLE 3:
//
// Array: 1 3 5 7 9
// Target: 10
// → No element >= 10
// → return -1
//
// TIME COMPLEXITY (this code):
// - O(n) because linear scan is used
//
// NOTE:
// - STL lower_bound or binary search version works in O(log n)
// ====================================================================
