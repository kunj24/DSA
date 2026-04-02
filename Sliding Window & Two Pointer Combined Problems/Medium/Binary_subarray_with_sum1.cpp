#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Problem: Subarray Sum Equals K
// Given an integer array and a target sum k,
// find the total number of subarrays whose sum equals k.
// Goal: Count all such subarrays.
// Approach: Use prefix sum with a hash map.

int subarray_with_sum(const vector<int>& arr, int k) {
    unordered_map<int, int> prevSum;   // map to store prefix sums
    int count = 0;                     // number of valid subarrays
    int curr_sum = 0;                  // current prefix sum

    // traverse the array
    for (int i = 0; i < arr.size(); i++) {   // main loop

        curr_sum += arr[i];   // update prefix sum

        // case 1: subarray from index 0 to i
        if (curr_sum == k) {
            count++;
        }

        // case 2: check if (curr_sum - k) exists
        if (prevSum.find(curr_sum - k) != prevSum.end()) {
            count += prevSum[curr_sum - k];
        }

        // store current prefix sum
        prevSum[curr_sum]++;
    }

    return count;
}

int main() {
    int n;

    cout << "Enter number of elements : ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements that include 0 and 1 : " << endl;
    for (int i = 0; i < n; i++)   // input loop
        cin >> arr[i];

    int k;
    cout << "Enter target sum k: ";
    cin >> k;

    int ans = subarray_with_sum(arr, k);   // corrected function call

    cout << "There are " << ans 
         << " subarrays with sum exactly equal to " << k << endl;

    return 0;
}

/*
Explanation:
We use prefix sum and a hash map.

Key Idea:
If:
current_sum - previous_sum = k
Then:
previous_sum = current_sum - k

So if we have seen (current_sum - k) before,
we found a subarray with sum k.

Steps:
1. Traverse array and compute prefix sum.
2. If prefix sum equals k → count++.
3. Check if (curr_sum - k) exists in map.
4. Add current prefix sum to map.

Example:
Input:
arr = [1, 2, 3]
k = 3

Prefix sums:
1 → no
1+2=3 → count = 1
1+2+3=6 → check 6-3=3 → exists → count = 2

Subarrays:
[1,2]
[3]

Output:
2

Edge Cases:
1. Empty array → return 0
2. Negative numbers present
3. k = 0
4. All elements zero

Time Complexity:
O(n) → single traversal

Space Complexity:
O(n) → hash map for prefix sums
*/
