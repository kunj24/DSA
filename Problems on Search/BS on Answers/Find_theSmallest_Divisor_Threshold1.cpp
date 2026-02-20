#include<iostream>
#include<vector>
#include <cmath>
#include<algorithm>
using namespace std;

// =============================================================
// PROBLEM DESCRIPTION:
// -------------------------------------------------------------
// Given an array of integers and a threshold value,
// find the smallest positive divisor such that the sum of
// ceil(arr[i] / divisor) for all elements is less than
// or equal to the threshold.
// =============================================================


// Function to calculate sum of ceiling divisions
int smallestdiv(vector<int>& arr, int n, int divisor){

    int sum = 0;   // IMPORTANT: initialize sum

    for(int i = 0; i < n; i++){
        // Convert to double to avoid integer division
        sum += ceil((double)arr[i] / divisor);
    }
    return sum;
}


// Binary Search based solution
int calculate(vector<int>& arr, int n, int threshold){

    int low = 1;   // divisor cannot be 0
    int high = *max_element(arr.begin(), arr.end());
    int ans;
    while(low <= high){

        int mid = low + (high - low) / 2;

        // If sum is within threshold, try smaller divisor
        if(smallestdiv(arr, n, mid) <= threshold){
            high = mid - 1;
            ans=mid;
        }
        else{
            // If sum is greater, need larger divisor
            low = mid + 1;
        }
    }

    // low will be the smallest valid divisor
    return ans;
}

int main(){

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements: " << endl;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int threshold;
    cout << "Enter a Threshold value: ";
    cin >> threshold;

    int ans = calculate(arr, n, threshold);

    cout << "Answer is: " << ans << endl;
    cout << "If we choose " << ans << " as divisor, we get the threshold value" << endl;

    return 0;
}


// =============================================================
// ADDITIONAL EXPLANATION
// =============================================================
//
// PROBLEM IDEA:
// -------------------------------------------------------------
// We need the SMALLEST divisor such that the sum of ceiling
// divisions of all array elements does not exceed the threshold.
// Since the answer range is sorted, we use Binary Search.
//
// -------------------------------------------------------------
// EXAMPLE:
// -------------------------------------------------------------
// arr = [1, 2, 5, 9]
// threshold = 6
//
// divisor = 3 → 1 + 1 + 2 + 3 = 7 ❌
// divisor = 4 → 1 + 1 + 2 + 3 = 7 ❌
// divisor = 5 → 1 + 1 + 1 + 2 = 5 ✅
//
// Answer = 5
//
// -------------------------------------------------------------
// EDGE CASES:
// -------------------------------------------------------------
// 1. Divisor cannot be 0 (division by zero)
// 2. Threshold < n → no possible solution
// 3. Single element array works correctly
//
// -------------------------------------------------------------
// IMPORTANT LINES:
// -------------------------------------------------------------
// int low = 1;
// - Prevents division by zero
//
// ceil((double)arr[i] / divisor);
// - Ensures correct ceiling division
//
// -------------------------------------------------------------
// TIME COMPLEXITY:
// -------------------------------------------------------------
// Binary Search → O(log(max_element))
// Each step takes O(n)
//
// Total = O(n log M)
//
// -------------------------------------------------------------
// SPACE COMPLEXITY:
// -------------------------------------------------------------
// O(1) extra space
//
// -------------------------------------------------------------
// NOTE:
// -------------------------------------------------------------
// This is an optimized solution compared to brute force.
// Commonly asked in interviews and LeetCode.
//
// =============================================================
