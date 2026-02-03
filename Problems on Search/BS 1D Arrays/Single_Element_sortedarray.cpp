#include <iostream>
#include <vector>
using namespace std;

// Finds the element that appears only once
// All other elements appear exactly twice
int findSingleElement(const vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n; i++) {

        // First element
        if (i == 0) {
            if (arr[i] != arr[i + 1])
                return arr[i];
        }
        // Last element
        else if (i == n - 1) {
            if (arr[i] != arr[i - 1])
                return arr[i];
        }
        // Middle elements
        else {
            if (arr[i] != arr[i - 1] && arr[i] != arr[i + 1])
                return arr[i];
        }
    }
    return -1;  // no single element found
}

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements (SORTED): ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int result = findSingleElement(arr);

    if (result != -1)
        cout << "Single element is: " << result << endl;
    else
        cout << "No single element found" << endl;

    return 0;
}

// ================= ADDITIONAL EXPLANATION =================
//
// PROBLEM:
// - Given a sorted array
// - Every element appears twice except one
// - Find the element that appears only once
//
// WHY LINEAR SEARCH WORKS:
// - We compare each element with its neighbors
// - The unique element will differ from both
//
// CONDITIONS CHECKED:
// 1. First element → compare with next
// 2. Last element → compare with previous
// 3. Middle element → compare with both sides
//
// ================= EXAMPLE SOLUTION =================
//
// INPUT:
// Array: 1 1 2 3 3 4 4
//
// DRY RUN:
//
// i = 0 → arr[0] == arr[1] → not single
// i = 1 → arr[1] == arr[0] → not single
// i = 2 → arr[2] = 2
//        arr[2] != arr[1] AND arr[2] != arr[3]
//        → SINGLE ELEMENT FOUND
//
// OUTPUT:
// Single element is: 2
//
// ================= EDGE CASE =================
//
// Array: 5
// → Only one element
// → Single element = 5
//
// ================= COMPLEXITY =================
//
// Time Complexity: O(n)
// Space Complexity: O(1)
//
// NOTE:
// - Faster solution using Binary Search exists (O(log n))
// ====================================================================
