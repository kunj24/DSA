#include<iostream>
#include<vector>
#include <cmath>
#include<algorithm>
using namespace std;

int calculate(vector<int>& arr, int n, int threshold){

    // We try every possible divisor i from 1 to n
    // (i should NEVER be 0 because division by 0 is invalid)
    for(int i = 1; i <= n; i++){

        int sum = 0;

        // For each element in the array,
        // divide it by i and take the ceiling value
        for(int j = 0; j < n; j++){
            sum += ceil((double)arr[j] / i);
        }

        // If the calculated sum matches the threshold,
        // we return the divisor i
        if(sum <= threshold){
            return i;
        }
    }

    // If no divisor satisfies the condition
    return -1;
}

int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements: " << endl;
    vector<int> arr(n);

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

/*
================================================================
================= ADDITIONAL EXPLANATION ========================
================================================================

PROBLEM IDEA:
-------------
We are trying to find a number (divisor) such that:
For every element in the array:
    ceil(arr[j] / divisor)
When we add all these values together,
the total becomes exactly equal to the given threshold.

---------------------------------------------------------------

EXAMPLE:
--------
Input:
n = 4
arr = [1, 2, 5, 9]
threshold = 6

Try different divisor values:

i = 1:
ceil(1/1) + ceil(2/1) + ceil(5/1) + ceil(9/1)
= 1 + 2 + 5 + 9 = 17 ❌

i = 2:
ceil(1/2) + ceil(2/2) + ceil(5/2) + ceil(9/2)
= 1 + 1 + 3 + 5 = 10 ❌

i = 3:
ceil(1/3) + ceil(2/3) + ceil(5/3) + ceil(9/3)
= 1 + 1 + 2 + 3 = 7 ❌

i = 4:
ceil(1/4) + ceil(2/4) + ceil(5/4) + ceil(9/4)
= 1 + 1 + 2 + 3 = 7 ❌

i = 5:
ceil(1/5) + ceil(2/5) + ceil(5/5) + ceil(9/5)
= 1 + 1 + 1 + 2 = 5 ❌

i = 6:
ceil(1/6) + ceil(2/6) + ceil(5/6) + ceil(9/6)
= 1 + 1 + 1 + 2 = 5 ❌

i = 7:
ceil(1/7) + ceil(2/7) + ceil(5/7) + ceil(9/7)
= 1 + 1 + 1 + 2 = 5 ❌

If threshold was 7, answer would be 3 or 4

---------------------------------------------------------------

EDGE CASES:
-----------
1. Division by zero ❌
   - i must start from 1, not 0

2. If no divisor produces the required threshold:
   - Function returns -1

3. If threshold < n:
   - Impossible case, because minimum sum is n
     (each ceil division gives at least 1)

4. Single element array:
   arr = [10], threshold = 2
   divisor = 5 → ceil(10/5) = 2 ✔

---------------------------------------------------------------

IMPORTANT LINES EXPLANATION:
----------------------------
sum += ceil((double)arr[j] / i);
- Converts arr[j] to double to avoid integer division
- ceil ensures rounding UP

for(int i = 1; i <= n; i++)
- Starts from 1 to avoid division by zero

if(sum == threshold)
- Checks exact match, then returns divisor

---------------------------------------------------------------

TIME COMPLEXITY:
----------------
Outer loop runs n times
Inner loop runs n times

Total Time Complexity = O(n²)

---------------------------------------------------------------

SPACE COMPLEXITY:
-----------------
Uses only a few variables (sum, i, j)

Space Complexity = O(1) extra space

---------------------------------------------------------------

NOTE:
-----
This solution is BRUTE FORCE.
For large inputs, this can be optimized using BINARY SEARCH.

================================================================
*/
