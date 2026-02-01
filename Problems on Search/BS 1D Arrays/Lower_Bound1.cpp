#include <iostream>
#include <vector>
using namespace std;

// Lower Bound using Binary Search
// Returns first index where arr[index] >= target
int lowerbound(const vector<int>& arr, int target) {
    int n = arr.size();
    int low = 0, high = n - 1;
    int ans = n;                    // default answer if no lower bound exists

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] >= target) {   // possible lower bound
            ans = mid;
            high = mid - 1;         // search left part
        } else {
            low = mid + 1;          // search right part
        }
    }
    return ans;
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

    if (result < n) {
        cout << "Lower bound index: " << result << endl;
    } else {
        cout << "Lower bound does not exist." << endl;
    }

    return 0;
}

// ======================= ADDITIONAL EXPLANATION =======================
//
// WHAT IS LOWER BOUND:
// - Lower bound is the FIRST index such that
//   arr[index] >= target
//
// WHY WE USE LOWER BOUND:
// - Efficient searching in sorted arrays
// - Used in STL lower_bound()
// - Helpful in range queries and optimization problems
//
// IMPORTANT CONDITION:
// - Array MUST be SORTED
//
// POSSIBLE CASES:
//
// Case 1: Element equal to target exists
// → First occurrence index is returned
//
// Case 2: Element greater than target exists
// → First greater element index is returned
//
// Case 3: All elements < target
// → Lower bound does not exist
// → Function returns n
//
// EXAMPLE 1:
//
// Array: 1 3 5 7 9
// Target: 5
// → arr[2] = 5
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
// → ans = n (lower bound does not exist)
//
// TIME COMPLEXITY:
// - O(log n)
//
// SPACE COMPLEXITY:
// - O(1)
//
// ====================================================================
