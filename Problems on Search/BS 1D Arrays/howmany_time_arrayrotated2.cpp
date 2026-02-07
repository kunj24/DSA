#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Returns number of times array is rotated
// (index of minimum element)
int countRotations(const vector<int>& arr) {
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;
    int index = -1;

    while (low <= high) {

        // If current subarray is already sorted
        if (arr[low] <= arr[high]) {
            if (arr[low] < ans) {
                ans = arr[low];
                index = low;
            }
            break;
        }

        int mid = (low + high) / 2;

        // Left half is sorted
        if (arr[low] <= arr[mid]) {
            if (arr[low] < ans) {
                ans = arr[low];
                index = low;
            }
            low = mid + 1;
        }
        // Right half is sorted
        else {
            if (arr[mid] < ans) {
                ans = arr[mid];
                index = mid;
            }
            high = mid - 1;
        }
    }
    return index;
}

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements (ROTATED SORTED): ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int rotations = countRotations(arr);

    cout << "Array is rotated " << rotations << " times." << endl;

    return 0;
}

// ======================= ADDITIONAL EXPLANATION =======================
//
// WHAT DOES "HOW MANY TIMES ARRAY IS ROTATED" MEAN:
// - It means how many times a sorted array was rotated clockwise
// - This equals the index of the minimum element
//
// EXAMPLE:
//
// Sorted array: 1 2 3 4 5
// Rotated array: 3 4 5 1 2
//
// Minimum element = 1
// Index of 1 = 3
// → Array rotated 3 times
//
// WHY THIS WORKS:
// - Rotated sorted array has one minimum element
// - Binary search helps locate it in O(log n)
//
// KEY OBSERVATION:
// - At least one half is always sorted
// - Minimum lies in the unsorted half
//
// POSSIBLE CASES:
//
// Case 1: Array not rotated
// → Minimum at index 0
// → Rotations = 0
//
// Case 2: Array rotated k times
// → Minimum at index k
//
// TIME COMPLEXITY:
// - O(log n)
//
// SPACE COMPLEXITY:
// - O(1)
//
// NOTE:
// - Assumes NO DUPLICATES
// ====================================================================

// ======================= EXAMPLE SOLUTION =======================
//
// INPUT:
// n = 7
// Array: 4 5 6 7 1 2 3
//
// STEP-BY-STEP DRY RUN:
//
// Initial:
// low = 0, high = 6
// ans = INF, index = -1
//
// Iteration 1:
// arr[low] = 4, arr[high] = 3
// → array NOT sorted
// mid = 3 → arr[mid] = 7
// Left half (4 5 6 7) is sorted
// → save arr[low] = 4
// → ans = 4, index = 0
// → move right → low = 4
//
// Iteration 2:
// low = 4, high = 6
// arr[low] = 1, arr[high] = 3
// → subarray is sorted
// → save arr[low] = 1
// → ans = 1, index = 4
// → break
//
// FINAL RESULT:
// Minimum element = 1
// Index of minimum = 4
//
// OUTPUT:
// Array is rotated 4 times.
//
// WHY THIS WORKS:
// - Number of rotations = index of minimum element
// - Binary search finds minimum in O(log n)
//
// EDGE CASE:
// Array: 1 2 3 4 5
// → Already sorted
// → Minimum at index 0
// → Rotations = 0
//
// TIME COMPLEXITY:
// O(log n)
//
// SPACE COMPLEXITY:
// O(1)
//
// ===============================================================