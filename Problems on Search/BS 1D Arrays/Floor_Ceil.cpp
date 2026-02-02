#include <iostream>
#include <vector>
using namespace std;

// Floor: greatest element <= target
int findFloor(const vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int floorVal = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] <= target) {
            floorVal = arr[mid];   // possible floor
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return floorVal;
}

// Ceil: smallest element >= target
int findCeil(const vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int ceilVal = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] >= target) {
            ceilVal = arr[mid];    // possible ceil
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ceilVal;
}

int main() {
    int n, target;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " sorted elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter target element: ";
    cin >> target;

    int floorVal = findFloor(arr, target);
    int ceilVal = findCeil(arr, target);

    cout << "\nFloor: " << floorVal << endl;
    cout << "Ceil: " << ceilVal << endl;

    return 0;
}

// ======================= ADDITIONAL EXPLANATION =======================
//
// WHAT IS FLOOR:
// - Greatest element in array that is <= target
//
// WHAT IS CEIL:
// - Smallest element in array that is >= target
//
// WHY WE USE CEIL & FLOOR:
// - Range problems
// - Searching nearest values
// - Mathematical & interview problems
//
// IMPORTANT CONDITION:
// - Array MUST be SORTED
//
// POSSIBLE CASES:
//
// Case 1: Target exists in array
// → Floor = target, Ceil = target
//
// Case 2: Target lies between elements
// → Floor = nearest smaller
// → Ceil = nearest greater
//
// Case 3: Target < smallest element
// → Floor = -1 (does not exist)
// → Ceil = first element
//
// Case 4: Target > largest element
// → Floor = last element
// → Ceil = -1 (does not exist)
//
// EXAMPLE:
//
// Array: 1 2 4 6 8
// Target: 5
//
// Floor = 4
// Ceil = 6
//
// TIME COMPLEXITY:
// - O(log n)
//
// SPACE COMPLEXITY:
// - O(1)
//
// ====================================================================
