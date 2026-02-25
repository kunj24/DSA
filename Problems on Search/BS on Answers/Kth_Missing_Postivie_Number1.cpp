    #include <iostream>
#include <vector>
using namespace std;

// =============================================================
// PROBLEM DESCRIPTION:
// -------------------------------------------------------------
// Given a sorted positive integer array arr and an integer k,
// return the kth missing positive number.
//
// Example:
// arr = [2,3,4,7,11], k = 5
// Missing numbers = 1,5,6,8,9,10...
// 5th missing = 9
// =============================================================
// -------------------------------------------------------------
// missing count till index i = arr[i] - (i+1)
// If missing < k → move right
// else → move left
// =============================================================
int kth_missing_binary(const vector<int>& arr, int n, int k){

    int low = 0;
    int high = n - 1;

    while(low <= high){

        int mid = low + (high - low) / 2;

        // Count how many numbers are missing till mid
        int missing = arr[mid] - (mid + 1);

        if(missing < k){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    //// arr = [2,3,4,7,11], k = 5 at the end low=n in this case so low+k index of 11 is 4+ k id 5
    //so 4 + 5 = 9 it is the answer
    // Final answer
    return low + k;
}



int main() {

    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements: " << endl;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int k;
    cout << "Enter kth Missing number: ";
    cin >> k;

    // choose binary version
    int ans = kth_missing_binary(arr, n, k);

    cout << "Kth missing number is : " << ans << endl;

    return 0;
}



// =============================================================
// ADDITIONAL EXPLANATION
// =============================================================
//
// PROBLEM IDEA:
// -------------------------------------------------------------
// We must find the kth number that is NOT present in the array.
//
// Since array is sorted, we can calculate:
// missing till index i = arr[i] - (i+1)
//
// Example:
// index 0 → value 2 → missing = 2-1 = 1
// index 3 → value 7 → missing = 7-4 = 3
//
// -------------------------------------------------------------
// EXAMPLE:
// -------------------------------------------------------------
// arr = [2,3,4,7,11], k = 5
//
// Missing numbers:
// 1,5,6,8,9,10...
//
// Answer = 9
//
// -------------------------------------------------------------
// EDGE CASES:
// -------------------------------------------------------------
// 1. k before first element → answer = k
// 2. All numbers continuous → answer = n + k
// 3. Single element works correctly
//
// -------------------------------------------------------------
// IMPORTANT LINES:
// -------------------------------------------------------------
// missing = arr[mid] - (mid+1)
// - counts missing numbers till mid
//
// return low + k
// - final kth missing number
//
// -------------------------------------------------------------
// TIME COMPLEXITY:
// -------------------------------------------------------------
// Linear  → O(n)
// Binary  → O(log n)
//
// -------------------------------------------------------------
// SPACE COMPLEXITY:
// -------------------------------------------------------------
// O(1)
//
// -------------------------------------------------------------
// NOTE:
// -------------------------------------------------------------
// Binary search is preferred for large arrays.
// Very common interview question.
//
// =============================================================
