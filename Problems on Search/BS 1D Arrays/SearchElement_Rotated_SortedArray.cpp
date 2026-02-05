#include <iostream>
#include <vector>
using namespace std;

// Search element in a rotated sorted array
int searchRotatedSortedArray(const vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == target)
            return mid;

        // Left half is sorted
        if (arr[low] <= arr[mid]) {
            if (arr[low] <= target && target < arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        // Right half is sorted
        else {
            if (arr[mid] < target && target <= arr[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int n, target;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements (ROTATED SORTED): ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter target element: ";
    cin >> target;

    int result = searchRotatedSortedArray(arr, target);

    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}

// ======================= ADDITIONAL EXPLANATION =======================
//
// WHAT IS A ROTATED SORTED ARRAY:
// - A sorted array rotated at some pivot
//
// Example:
// Sorted: 1 2 3 4 5 6 7
// Rotated: 4 5 6 7 1 2 3
//
// WHY NORMAL BINARY SEARCH FAILS:
// - Array is not fully sorted
//
// HOW THIS ALGORITHM WORKS:
// - At least one half (left or right) is always sorted
// - Identify the sorted half
// - Check if target lies in that half
// - Discard the other half
//
// POSSIBLE CASES:
//
// Case 1: arr[mid] == target
// → Return mid
//
// Case 2: Left half is sorted
// → If target lies in left half, search left
// → Else search right
//
// Case 3: Right half is sorted
// → If target lies in right half, search right
// → Else search left
//
// EXAMPLE:
//
// Array: 4 5 6 7 0 1 2
// Target: 0
//
// low = 0, high = 6
// mid = 3 → arr[mid] = 7
// Left half sorted (4 5 6 7)
// Target not in left → search right
//
// low = 4, high = 6
// mid = 5 → arr[mid] = 1
// Right half sorted (0 1 2)
// Target in right → search left
//
// mid = 4 → arr[mid] = 0 → FOUND
//
// TIME COMPLEXITY:
// - O(log n)
//
// SPACE COMPLEXITY:
// - O(1)
//
// ====================================================================
