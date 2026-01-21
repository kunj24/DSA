#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int calculate(vector<int>& arr, int n) {

    int maxproduct = INT_MIN;  
    int prefixsum = 1;  
    // Product of elements from left to right

    int sufixsum = 1;   
    // Product of elements from right to left

    // Traverse array once
    for (int i = 0; i < n; i++) {

        // If prefix product becomes 0,
        // reset it to 1 to start a new subarray
        if (prefixsum == 0)
            prefixsum = 1;

        // Same logic for suffix product
        if (sufixsum == 0)
            sufixsum = 1;

        // Multiply current element from the left side
        prefixsum *= arr[i];

        // Multiply current element from the right side
        sufixsum *= arr[n - i - 1];

        maxproduct = max(maxproduct, max(prefixsum, sufixsum));
    }

    return maxproduct;
}

int main() {

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements that can be -ve or +ve or 0 : ";

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int ans = calculate(arr, n);

    cout << "Maximum product subarray: " << ans << endl;

    return 0;
}

/*
====================== WHY THIS METHOD WORKS ======================

PROBLEM:
Find the maximum product of a CONTIGUOUS subarray.

KEY CHALLENGES:
1. Negative numbers can flip sign
2. Zero breaks product
3. Maximum product may come from:
   - left side
   - right side
   - between negatives

-------------------------------------------------
WHY PREFIX & SUFFIX?
-------------------------------------------------

Case 1: Even number of negatives
→ whole array product is positive

Case 2: Odd number of negatives
→ maximum product comes after removing:
   - leftmost negative OR
   - rightmost negative

Prefix catches cases from LEFT
Suffix catches cases from RIGHT

-------------------------------------------------
DRY RUN EXAMPLE
-------------------------------------------------

Input:
arr = {2, 3, -2, 4}
n = 4

Initial:
prefixsum = 1
sufixsum = 1
maxproduct = -∞

-------------------------------------------------
i = 0
prefixsum = 1 × 2 = 2
sufixsum = 1 × 4 = 4
maxproduct = 4

-------------------------------------------------
i = 1
prefixsum = 2 × 3 = 6
sufixsum = 4 × (-2) = -8
maxproduct = 6

-------------------------------------------------
i = 2
prefixsum = 6 × (-2) = -12
sufixsum = -8 × 3 = -24
maxproduct = 6

-------------------------------------------------
i = 3
prefixsum = -12 × 4 = -48
sufixsum = -24 × 2 = -48
maxproduct = 6

-------------------------------------------------
FINAL ANSWER:
Maximum product subarray = 6
(subarray = {2, 3})

-------------------------------------------------
ZERO CASE
-------------------------------------------------
arr = {1, 0, -2, 3}

When product becomes 0:
→ reset to 1
→ start fresh subarray

-------------------------------------------------
TIME & SPACE COMPLEXITY
-------------------------------------------------
Time  : O(n)
Space : O(1)

-------------------------------------------------
INTERVIEW NOTE:
This approach avoids:
- nested loops
- extra arrays
- overflow mistakes

=================================================
*/
