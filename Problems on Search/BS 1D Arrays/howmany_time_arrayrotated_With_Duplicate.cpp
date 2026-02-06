#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Returns number of times array is rotated (index of minimum element)
// Works even when duplicate elements are present
int countRotationsWithDuplicates(const vector<int>& arr) {
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;
    int index = -1;

    while (low <= high) {

        int mid = (low + high) / 2;

        // If duplicates block decision
        if (arr[low] == arr[mid] && arr[mid] == arr[high]) {
            if (arr[low] < ans) {
                ans = arr[low];
                index = low;
            }
            low++;
            high--;
            continue;
        }

        // If subarray is already sorted
        if (arr[low] <= arr[high]) {
            if (arr[low] < ans) {
                ans = arr[low];
                index = low;
            }
            break;
        }

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
    cout << "Enter " << n << " elements (ROTATED SORTED WITH DUPLICATES): ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int rotations = countRotationsWithDuplicates(arr);

    cout << "Array is rotated " << rotations << " times." << endl;

    return 0;
}

// ================= ADDITIONAL EXPLANATION =================
//
// PROBLEM:
// - Find how many times a sorted array is rotated
// - Duplicate elements ARE allowed
//
// IMPORTANT CONCEPT:
// - Number of rotations = index of minimum element
//
// WHY DUPLICATES ARE DIFFICULT:
// - Example: 2 2 2 0 1 2
// - arr[low] == arr[mid] == arr[high]
// - Cannot determine which half is sorted
//
// SOLUTION FOR DUPLICATES:
// - Safely shrink the search space
// - low++ and high--
//
// HOW THE ALGORITHM WORKS:
// 1. Check mid
// 2. If duplicates block decision → shrink range
// 3. Identify sorted half
// 4. Store possible minimum
// 5. Move to unsorted half
//
// ================= EXAMPLE SOLUTION =================
//
// INPUT:
// Array: 3 3 3 1 2 3
//
// EXPECTED OUTPUT:
// Array is rotated 3 times.
//
// DRY RUN:
//
// low = 0, high = 5
// mid = 2 → arr[mid] = 3
// arr[low] == arr[mid] == arr[high]
// → shrink → low = 1, high = 4
//
// low = 1, high = 4
// mid = 2 → arr[mid] = 3
// Left half sorted
// → save arr[low] = 3
// → low = 3
//
// low = 3, high = 4
// Subarray sorted
// → minimum = arr[3] = 1
// → index = 3
//
// FINAL ANSWER:
// Number of rotations = 3
//
// ================= EDGE CASE =================
//
// Array: 2 2 2 2 2
// → All elements same
// → Minimum index = 0
// → Rotations = 0
//
// ================= COMPLEXITY =================
//
// Best / Average Case: O(log n)
// Worst Case (many duplicates): O(n)
//
// Space Complexity: O(1)
//
// =========================================================
