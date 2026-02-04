#include <iostream>
#include <vector>
using namespace std;

// Search Insert Position using Binary Search
int searchInsertPosition(const vector<int>& arr, int target) {
    int n = arr.size();
    int low = 0, high = n - 1;
    int ans = n;                    // default insert position

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] >= target) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n, target;

    // Input size
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    // Input sorted array
    cout << "Enter " << n << " sorted elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // Input target
    cout << "Enter target element: ";
    cin >> target;

    // Find insert position
    int index = searchInsertPosition(arr, target);

    // Insert target
    arr.insert(arr.begin() + index, target);

    // Output in required format
    cout << "\nResult (index): " << index << endl;
    cout << "Explanation: " << target
         << " is not present in the array. So, if we will insert "
         << target << " in the " << index
         << "rd index(0-based indexing), the array will still be sorted. ";

    cout << "{";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i != arr.size() - 1) cout << ",";
    }
    cout << "}";

    return 0;
}

// ======================= ADDITIONAL EXPLANATION =======================
//
// INPUT EXAMPLE:
//
// Enter number of elements: 4
// Enter 4 sorted elements: 1 2 4 7
// Enter target element: 6
//
// OUTPUT:
//
// Result: 3
// Explanation: 6 is not present in the array. So, if we will insert 6
// in the 3rd index(0-based indexing), the array will still be sorted.
// {1,2,4,6,7}
//
// NOTE:
// - Works only on sorted array
// - Based on Binary Search (Lower Bound)
//
// TIME COMPLEXITY:
// - O(log n) for search
// - O(n) for insertion
//
// ====================================================================
