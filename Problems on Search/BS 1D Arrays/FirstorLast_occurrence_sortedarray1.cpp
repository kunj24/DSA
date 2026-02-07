#include <iostream>
#include <vector>
using namespace std;

// Find first occurrence of target
int firstOccurrence(const vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int ans = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == target) {
            ans = mid;          // possible answer
            high = mid - 1;     // search left side
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

// Find last occurrence of target
int lastOccurrence(const vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int ans = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == target) {
            ans = mid;          // possible answer
            low = mid + 1;      // search right side
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
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
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter target element: ";
    cin >> target;

    int first = firstOccurrence(arr, target);
    int last = lastOccurrence(arr, target);

    cout << "\nFirst Occurrence Index: " << first << endl;
    cout << "Last Occurrence Index: " << last << endl;

    return 0;
}

// ======================= ADDITIONAL EXPLANATION =======================
//
// WHAT THIS PROGRAM DOES:
// - Finds the FIRST index of target
// - Finds the LAST index of target
// - Works efficiently using Binary Search
//
// IMPORTANT CONDITION:
// - Array MUST be SORTED
//
// POSSIBLE CASES:
//
// Case 1: Target occurs multiple times
// → First occurrence = first index
// → Last occurrence = last index
//
// Case 2: Target occurs once
// → First = Last = index
//
// Case 3: Target does not exist
// → First = -1, Last = -1
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
// - O(log n)
//
// SPACE COMPLEXITY:
// - O(1)
//
// NOTE:
// - Number of occurrences = (last - first + 1)
// ====================================================================
