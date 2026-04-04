#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Problem: Max Consecutive Ones III
// Given a binary array (0s and 1s) and an integer k,
// you can flip at most k zeros to ones.
// Goal: Find the length of the longest subarray
// containing only 1s after at most k flips.
// Approach: Sliding window with two pointers.

int Max_consecutive_ones(const vector<int>& arr, int n, int k) {

    int maxLength = 0;   // store maximum window size
    int left = 0;        // left pointer of window
    int zero = 0;        // count of zeros in current window

    // expand window using right pointer
    for (int right = 0; right < n; right++) {   // main sliding window loop

        if (arr[right] == 0) {   // if we see a zero
            zero++;              // increase zero count
        }

        // if zeros exceed k, shrink window from left
        while (zero > k) {       // important shrinking loop
            if (arr[left] == 0) {
                zero--;          // remove zero from count
            }
            left++;              // move left pointer
        }

        // update maximum length
        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
}

int main() {
    int n;

    cout << "Enter number of elements : ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements that only include 0 and 1 : " << endl;
    for (int i = 0; i < n; i++)   // input loop
        cin >> arr[i];

    int k;
    cout << "Enter k that you need to convert 0 to 1 : ";
    cin >> k;

    int ans = Max_consecutive_ones(arr, n, k);
    cout << "Maximum consecutive ones: " << ans << endl;

    return 0;
}

/*
Explanation:
We use a sliding window technique.

Steps:
1. Expand the window using the right pointer.
2. Count the number of zeros inside the window.
3. If zeros exceed k, shrink the window from the left.
4. Track the maximum window size.

Example:
Input:
arr = [1,1,1,0,0,0,1,1,1,1,0]
k = 2

Process:
Best window after flipping two zeros:
[1,1,1,0,0,1,1,1,1] → length = 6

Output:
6

Edge Cases:
1. k = 0 → find longest existing 1s segment
2. All elements are 1 → answer = n
3. All elements are 0 → answer = min(n, k)
4. Empty array → answer = 0

Time Complexity:
O(n) → each element visited at most twice

Space Complexity:
O(1) → constant extra space
*/
