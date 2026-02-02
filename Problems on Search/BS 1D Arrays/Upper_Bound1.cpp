#include <iostream>
#include <vector>
using namespace std;

// Upper Bound using Binary Search
// Returns first index where arr[index] > target
int upperbound(const vector<int>& arr, int target) {
    int n = arr.size();
    int low = 0, high = n - 1;
    int ans = n;                    // default if upper bound doesn't exist

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] > target) {    // possible upper bound
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

    int result = upperbound(arr, target);

    if (result < n) {
        cout << "Upper bound index: " << result << endl;
    } else {
        cout << "Upper bound does not exist." << endl;
    }

    return 0;
}

// ======================= ADDITIONAL EXPLANATION =======================
//
// WHAT IS UPPER BOUND:
// - Upper bound is the FIRST index such that
//   arr[index] > target
//
// WHY WE USE UPPER BOUND:
// - Used to find range of elements
// - Helpful when duplicates are present
// - Used in STL upper_bound()
//
// IMPORTANT CONDITION:
// - Array MUST be SORTED
//
// POSSIBLE CASES:
//
// Case 1: Elements equal to target exist
// → Upper bound is index after last occurrence
//
// Case 2: Element greater than target exists
// → First greater element index is returned
//
// Case 3: All elements <= target
// → Upper bound does not exist
// → Function returns n
//
// EXAMPLE 1:
//
// Array: 1 3 5 5 5 7 9
// Target: 5
// → Upper bound index = 5 (arr[5] = 7)
//
// EXAMPLE 2:
//
// Array: 1 3 5 7 9
// Target: 6
// → Upper bound index = 3 (arr[3] = 7)
//
// EXAMPLE 3:
//
// Array: 1 3 5 7 9
// Target: 9
// → No element > 9
// → return n
//
// TIME COMPLEXITY:
// - O(log n)
//
// SPACE COMPLEXITY:
// - O(1)
//
// ====================================================================
