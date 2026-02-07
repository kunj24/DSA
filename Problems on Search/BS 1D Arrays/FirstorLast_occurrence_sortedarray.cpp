#include <iostream>
#include <vector>
using namespace std;

// First and Last Occurrence using Linear Search
void firstAndLastOccurrence(const vector<int>& arr, int target) {
    int first = -1;
    int last = -1;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) {
            if (first == -1){        // first time target is found
                first = i;
            }
            last = i;               // update last occurrence
        }
    }

    cout << "\nFirst Occurrence Index: " << first << endl;
    cout << "Last Occurrence Index: " << last << endl;
}

int main() {
    int n, target;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements: " << endl;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << "Enter target element: ";
    cin >> target;

    firstAndLastOccurrence(arr, target);

    return 0;
}

// ======================= ADDITIONAL EXPLANATION =======================
//
// WHAT THIS PROGRAM DOES:
// - Scans the array from left to right
// - Stores index of first occurrence
// - Keeps updating index of last occurrence
//
// WHY USE LINEAR SEARCH:
// - Very simple to implement
// - Works on both SORTED and UNSORTED arrays
// - Good for small input sizes
//
// POSSIBLE CASES:
//
// Case 1: Target occurs multiple times
// → first = first index
// → last = last index
//
// Case 2: Target occurs once
// → first = last = index
//
// Case 3: Target does not exist
// → first = -1, last = -1
//
// EXAMPLE:
//
// Array: 1 2 4 4 4 5 6
// Target: 4
//
// First Occurrence = 2
// Last Occurrence  = 4
//
// TIME COMPLEXITY:
// - O(n)
//
// SPACE COMPLEXITY:
// - O(1)
//
// COMPARISON:
// - Linear Search: O(n), simple
// - Binary Search: O(log n), faster but needs sorted array
//
// ====================================================================
