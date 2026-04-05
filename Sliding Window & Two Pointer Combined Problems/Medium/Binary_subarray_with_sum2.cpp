#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Problem: Binary Subarrays With Sum
    // Given a binary array and an integer goal,
    // return the number of subarrays whose sum equals goal.
    // Goal: Count all such subarrays.
    // Approach: Count subarrays with sum ≤ goal
    // and subtract subarrays with sum ≤ (goal - 1).

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // exact sum = atMost(goal) - atMost(goal - 1)
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }

private:

    // Helper function to count subarrays with sum at most k
    int atMost(vector<int>& nums, int k) {

        if (k < 0) return 0;   // no valid subarrays if k is negative

        int left = 0;          // left pointer of window
        int sum = 0;           // current window sum
        int count = 0;         // number of valid subarrays

        // sliding window loop
        for (int right = 0; right < nums.size(); right++) {

            sum += nums[right];   // add current element

            // shrink window if sum exceeds k
            while (sum > k) {     // important shrinking loop
                sum -= nums[left];
                left++;
            }

            // count all valid subarrays ending at right
            count += (right - left + 1);
        }

        return count;
    }
};

// Driver code
int main() {
    Solution sol;
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter " << n << " binary elements (0 or 1):" << endl;
    for (int i = 0; i < n; i++)   // input loop
        cin >> nums[i];

    int goal;
    cout << "Enter goal sum: ";
    cin >> goal;

    int result = sol.numSubarraysWithSum(nums, goal);

    cout << "Number of subarrays with sum = " << goal << " is : "
         << result << endl;

    return 0;
}

/*
Explanation:
We use the formula:

Subarrays with sum = goal
= subarrays with sum ≤ goal
− subarrays with sum ≤ (goal − 1)

Why this works:
Because:
(sum ≤ goal) includes all sums from 0 to goal.
(sum ≤ goal − 1) includes all sums from 0 to goal − 1.

So subtracting gives only sum = goal.

Example:
Input:
nums = [1,0,0,1,1,0]
goal = 2

Subarrays with sum = 2:
[1,0,0,1]
[0,0,1,1]
[0,0,1,1,0]
[0,1,1]
[0,1,1,0]
[1,1]
[1,1,0]

Total = 7

Edge Cases:
1. Empty array → return 0
2. goal = 0 → count subarrays of only zeros
3. All ones
4. All zeros

Time Complexity:
O(n) → single traversal

Space Complexity:
O(1) → no extra space used
*/
