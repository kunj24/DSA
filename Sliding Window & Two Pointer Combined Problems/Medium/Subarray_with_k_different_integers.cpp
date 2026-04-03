#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Problem: Subarrays with Exactly K Different Elements
// Given an integer array and an integer k,
// find the number of subarrays that contain exactly k distinct elements.
// Goal: Count all such subarrays.
// Approach: Brute force using hash map to track distinct elements.

int k_different_element(const vector<int>& arr, int k) {

    int count = 0;   // store number of valid subarrays

    // try every starting index
    for (int i = 0; i < arr.size(); i++) {   // outer loop: start index

        unordered_map<int, int> mpp;   // map to track frequencies

        // expand subarray from index i
        for (int j = i; j < arr.size(); j++) {   // inner loop: end index

            mpp[arr[j]]++;   // add current element to map

            // if exactly k distinct elements
            if (mpp.size() == k) {
                count++;     // valid subarray found
            }

            // if more than k distinct elements, stop expanding
            if (mpp.size() > k) {
                break;       // important break condition
            }
        }
    }

    return count;   // return final count
}

int main() {
    int n;

    cout << "Enter number of elements : ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " Elements : " << endl;
    for (int i = 0; i < n; i++)   // input loop
        cin >> arr[i];

    int k;
    cout << "Enter k number of Different Elements: ";
    cin >> k;

    int ans = k_different_element(arr, k);

    cout << "There are " << ans
         << " subarrays that contain exactly "
         << k << " different elements." << endl;

    return 0;
}

/*
Step-by-Step Explanation:

We check every possible subarray.

Steps:
1. Start from index i.
2. Expand the subarray using index j.
3. Keep track of distinct elements using a map.
4. If map size becomes exactly k → count++.
5. If map size exceeds k → stop this subarray.

------------------------------------------------

Example:
arr = [1,2,1,2,3]
k = 2

Valid subarrays:
[1,2]
[1,2,1]
[1,2,1,2]
[2,1]
[2,1,2]
[1,2]
[2,3]

Total = 7

------------------------------------------------

Edge Cases:
1. Empty array → return 0
2. k = 0 → return 0
3. k > number of unique elements → return 0
4. All elements same and k = 1 → many valid subarrays

Time Complexity:
Outer loop: O(n)
Inner loop: O(n)
Total: O(n²)

Space Complexity:
O(k) → map stores at most k+1 elements
*/
