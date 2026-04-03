#include <bits/stdc++.h>
using namespace std;

// Helper function to count subarrays with at most K distinct integers
int atMostK(vector<int>& nums, int K) {
    unordered_map<int, int> freq;   // stores frequency of elements
    int left = 0;                   // left pointer of window
    int count = 0;                  // total subarrays

    // traverse array using right pointer
    for (int right = 0; right < nums.size(); right++) {

        // if this element is new in window
        if (freq[nums[right]] == 0) {
            K--;                    // one distinct element used
        }

        // increase frequency
        freq[nums[right]]++;

        // if more than allowed distinct elements
        while (K < 0) {             // important shrinking loop
            freq[nums[left]]--;     

            // if an element frequency becomes zero
            if (freq[nums[left]] == 0) {
                K++;                // we removed one distinct element
            }
            left++;                 // shrink window
        }

        // all subarrays ending at right are valid
        count += (right - left + 1);
    }

    return count;
}

// Main function to return number of subarrays with exactly K distinct integers
int subarraysWithKDistinct(vector<int>& nums, int k) {

    // Why k and k-1?
    // atMostK(k) counts subarrays with ≤ k distinct elements
    // atMostK(k-1) counts subarrays with ≤ (k-1) distinct elements
    //
    // So:
    // exactly k distinct =
    // atMostK(k) − atMostK(k−1)
    //
    // Because:
    // atMostK(k) includes:
    //   1 distinct, 2 distinct, ..., k distinct
    //
    // atMostK(k−1) includes:
    //   1 distinct, 2 distinct, ..., (k−1) distinct
    //
    // Subtracting removes all cases with fewer than k,
    // leaving only subarrays with exactly k distinct elements.

    return atMostK(nums, k) - atMostK(nums, k - 1);
}

// Driver code
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int k;
    cout << "Enter k: ";
    cin >> k;

    int result = subarraysWithKDistinct(nums, k);

    cout << "Subarrays with exactly " << k 
         << " distinct elements: " << result << endl;

    return 0;
}

/*
Example:
nums = [1,2,1,2,3]
k = 2

All subarrays:
[1] → 1 distinct
[1,2] → 2 distinct
[1,2,1] → 2 distinct
[1,2,1,2] → 2 distinct
[1,2,1,2,3] → 3 distinct
[2] → 1 distinct
[2,1] → 2 distinct
[2,1,2] → 2 distinct
[2,1,2,3] → 3 distinct
[1] → 1 distinct
[1,2] → 2 distinct
[1,2,3] → 3 distinct
[2] → 1 distinct
[2,3] → 2 distinct
[3] → 1 distinct

Subarrays with exactly 2 distinct:
[1,2]
[1,2,1]
[1,2,1,2]
[2,1]
[2,1,2]
[1,2]
[2,3]

Total = 7

Using formula:
atMost(2) = 12
atMost(1) = 5

exactly(2) = 12 − 5 = 7

Time Complexity:
O(n)

Space Complexity:
O(k)
*/
