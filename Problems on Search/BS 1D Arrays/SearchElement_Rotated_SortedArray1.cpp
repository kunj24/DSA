#include <bits/stdc++.h>
using namespace std;

// Search target in rotated sorted array with duplicates
bool searchInARotatedSortedArrayII(vector<int>& arr, int k) {
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == k)
            return true;

        // Cannot decide sorted half due to duplicates
        if (arr[low] == arr[mid] && arr[mid] == arr[high]) {
            low++;
            high--;
            continue;
        }

        // Left half is sorted
        if (arr[low] <= arr[mid]) {
            if (arr[low] <= k && k < arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        // Right half is sorted
        else {
            if (arr[mid] < k && k <= arr[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return false;
}

int main() {
    vector<int> arr = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
    int k = 3;

    bool ans = searchInARotatedSortedArrayII(arr, k);

    if (ans)
        cout << "Target is present in the array.\n";
    else
        cout << "Target is not present.\n";

    return 0;
}

// ======================= ADDITIONAL EXPLANATION =======================
//
// PROBLEM:
// - Search an element in a rotated sorted array
// - Duplicates are allowed
//
// WHY THIS IS DIFFERENT FROM NORMAL ROTATED SEARCH:
// - With duplicates, we cannot always decide which half is sorted
// - Example: {3,3,3,1,3}
//
// KEY EDGE CASE:
// if arr[low] == arr[mid] == arr[high]
// → We cannot decide the sorted half
// → Safely shrink the search space (low++, high--)
//
// HOW THE ALGORITHM WORKS:
// 1. If arr[mid] == target → FOUND
// 2. If duplicates block decision → shrink range
// 3. Identify the sorted half (left or right)
// 4. Check if target lies in that half
// 5. Discard the other half
//
// POSSIBLE CASES:
//
// Case 1: Target found at mid
// → return true
//
// Case 2: Duplicates at boundaries
// → reduce search space
//
// Case 3: Left half sorted
// → target in left → search left
// → else → search right
//
// Case 4: Right half sorted
// → target in right → search right
// → else → search left
//
// EXAMPLE:
//
// Array: 7 8 1 2 3 3 3 4 5 6
// Target: 3
//
// - mid lands on duplicate values
// - algorithm shrinks boundaries
// - eventually finds 3
//
// TIME COMPLEXITY:
// - Best / Average: O(log n)
// - Worst case (many duplicates): O(n)
//
// SPACE COMPLEXITY:
// - O(1)
//
// NOTE:
// - This is LeetCode 81
// ====================================================================
