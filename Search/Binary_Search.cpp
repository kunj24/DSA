#include <iostream>
#include <vector>
using namespace std;

// Binary Search (works only on SORTED arrays)
// Time Complexity: O(log n)
int binarySearch(const vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid = (low + high) / 2;   // middle index

        if (arr[mid] == target)
            return mid;              // element found
        else if (target > arr[mid])
            low = mid + 1;           // search right half
        else
            high = mid - 1;          // search left half
    }
    return -1;                       // element not found
}

int main() {
    int n, target;
    cin >> n;

    vector<int> arr(n);              // array must be sorted
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cin >> target;

    int result = binarySearch(arr, target);

    if (result != -1)
        cout << "Element found at index: " << result;
    else
        cout << "Element not found";

    return 0;
}

// ======================= ADDITIONAL EXPLANATION =======================
//
// WHY WE USE BINARY SEARCH:
// - Faster than linear search
// - Efficient for large datasets
// - Reduces comparisons by half each step
//
// IMPORTANT CONDITION:
// - Array MUST be sorted
//
// POSSIBLE CASES:
//
// Case 1: arr[mid] == target
// → Target found, return index
//
// Case 2: target > arr[mid]
// → Target lies in the RIGHT half
// → low = mid + 1
//
// Case 3: target < arr[mid]
// → Target lies in the LEFT half
// → high = mid - 1
//
// EXAMPLE DRY RUN:
//
// Array: 1 3 5 7 9
// Target: 7
//
// low = 0, high = 4
// mid = 2 → arr[mid] = 5
// 7 > 5 → move right
//
// low = 3, high = 4
// mid = 3 → arr[mid] = 7
// FOUND → index = 3
//
// WHEN ELEMENT IS NOT FOUND:
//
// Array: 1 3 5 7 9
// Target: 8
// → low > high
// → return -1
//
// ====================================================================
