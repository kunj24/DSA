#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Problem: Longest Substring Without Repeating Characters
// Given a string, find the length of the longest substring
// that contains no repeating characters.
// Approach: Brute force using a hash array for each starting index.

int LongestSubstringWithoutRepeating(string s) {

    int n = s.length();
    int maxLength = 0;   // store the maximum length found

    // Try every starting index
    for (int i = 0; i < n; i++) {   // outer loop: starting point

        int hash[256] = {0};   // hash to track visited characters
        int length = 0;

        // Expand substring from index i
        for (int j = i; j < n; j++) {   // inner loop: ending point

            if (hash[s[j]] == 1)   // if character already seen
                break;             // stop this substring

            hash[s[j]] = 1;        // mark character as seen
            length = j - i + 1;    // update current length

            maxLength = max(maxLength, length);   // update max
        }
    }

    return maxLength;
}

int main() {
    string s;

    cout << "Enter a string: ";
    cin >> s;

    int ans = LongestSubstringWithoutRepeating(s);
    cout << "Length of longest substring: " << ans << endl;

    return 0;
}

/*
Explanation:
We check every possible substring starting from each index.

Steps:
1. Start at index i.
2. Use a hash array to track characters.
3. Expand substring until a repeated character appears.
4. Track the maximum length.

Example:
Input:
s = "abcabcbb"

Substrings checked:
"abc" → length = 3
"bca" → length = 3
"cab" → length = 3
"bb" → stops at repeat

Output:
3

Edge Cases:
1. Empty string → answer = 0
2. Single character → answer = 1
3. All same characters → answer = 1
4. All unique characters → answer = length of string

Time Complexity:
Outer loop: O(n)
Inner loop: O(n)
Total: O(n²)

Space Complexity:
O(1) → fixed size hash array (256)
*/
