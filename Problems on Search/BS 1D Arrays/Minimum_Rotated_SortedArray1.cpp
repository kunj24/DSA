#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Find minimum element in rotated sorted array
int findMinimumRotatedArray(const vector<int>& arr) {
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;

    while (low <= high) {

        // If subarray is already sorted
        if (arr[low] <= arr[high]) {
            ans = min(ans, arr[low]);
            break;
        }

        int mid = (low + high) / 2;

        // Left half is sorted
        if (arr[low] <= arr[mid]) {
            ans = min(ans, arr[low]);
            low = mid + 1;
        }
        // Right half is sorted
        else {
            ans = min(ans, arr[mid]);
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements (ROTATED SORTED): ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int result = findMinimumRotatedArray(arr);

    cout << "Minimum element in rotated sorted array: " << result << endl;

    return 0;
}

// ======================= ADDITIONAL EXPLANATION =======================
//
// PROBLEM:
// - Find the minimum element in a rotated sorted array
//
// WHAT IS A ROTATED SORTED ARRAY:
// - A sorted array rotated at some pivot
//
// Example:
// Sorted: 1 2 3 4 5
// Rotated: 3 4 5 1 2
//
// KEY OBSERVATION:
// - At least one half of the array is always sorted
// - The minimum lies in the UNSORTED half
//
// HOW THE ALGORITHM WORKS:
// 1. If current range is already sorted
//    → arr[low] is the minimum
// 2. Identify which half is sorted
// 3. Discard the sorted half after saving its minimum
// 4. Continue on the unsorted half
//
// POSSIBLE CASES:
//
// Case 1: Array is not rotated
// → Minimum = first element
//
// Case 2: Rotation exists
// → Minimum lies near pivot
//
// EXAMPLE:
//
// Array: 4 5 6 7 1 2 3
//
// low = 0, high = 6
// mid = 3 → arr[mid] = 7
// Left half sorted → save arr[low] = 4
//
// low = 4, high = 6
// Subarray sorted → save arr[4] = 1
//
// Minimum = 1
//
// TIME COMPLEXITY:
// - O(log n)
//
// SPACE COMPLEXITY:
// - O(1)
//
// NOTE:
// - This version assumes NO DUPLICATES
// ====================================================================
