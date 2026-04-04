#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Problem: Count Nice Subarrays
// Given an integer array and an integer k,
// find the number of subarrays that contain exactly k odd numbers.
// Goal: Count all such subarrays.
// Approach: Prefix sum of odd counts with a hash map.

int count_nice_subarray(const vector<int>& arr, int k) {

    unordered_map<int, int> freq;   // map to store prefix odd counts
    freq[0] = 1;                    // base case: zero odd count seen once

    int oddCount = 0;   // current number of odd elements
    int result = 0;     // final answer

    // traverse the array
    for (int i = 0; i < arr.size(); i++) {   // main loop

        // if current element is odd, increase oddCount
        if (arr[i] % 2 == 1)
            oddCount++;

        // check if we have seen (oddCount - k) before
        // this means a subarray with exactly k odds exists
        if (freq.count(oddCount - k)) {
            result += freq[oddCount - k];   // add number of such subarrays
        }

        // store current oddCount in map
        freq[oddCount]++;
    }

    return result;   // return final count
}

int main() {
    int n;

    cout << "Enter number of elements : ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements :" << endl;
    for (int i = 0; i < n; i++)   // input loop
        cin >> arr[i];

    int k;
    cout << "Enter target that the array contain the k odd elements : ";
    cin >> k;

    int ans = count_nice_subarray(arr, k);

    cout << "There are " << ans
         << " subarrays with exactly " << k << " odd elements." << endl;

    return 0;
}

/*
Step-by-Step Explanation:

We convert the problem into:
Count subarrays where number of odd elements = k.

We maintain:
oddCount → number of odd elements seen so far.

We use a map:
freq[x] = how many times oddCount = x has appeared.

At each step:
If current oddCount = X
We look for (X - k) in the map.

Why?
Because:
currentOdd - previousOdd = k
→ previousOdd = currentOdd - k

So any prefix with oddCount = (X - k)
forms a valid subarray.

------------------------------------------------

Example:
arr = [1,1,2,1,1]
k = 3

Step-by-step:

i=0 → 1 → oddCount=1
freq: {0:1}
check (1-3=-2) → not found

i=1 → 1 → oddCount=2
check (2-3=-1) → not found

i=2 → 2 → oddCount=2
check (2-3=-1) → not found

i=3 → 1 → oddCount=3
check (3-3=0) → found freq[0]=1
result = 1

i=4 → 1 → oddCount=4
check (4-3=1) → found freq[1]=1
result = 2

Final result = 2

Valid subarrays:
[1,1,2,1]
[1,2,1,1]

------------------------------------------------

Edge Cases:
1. Empty array → return 0
2. No odd numbers and k > 0 → return 0
3. k = 0 → count subarrays with no odd numbers
4. All numbers are odd

Time Complexity:
O(n) → single pass

Space Complexity:
O(n) → hash map for prefix counts
*/
