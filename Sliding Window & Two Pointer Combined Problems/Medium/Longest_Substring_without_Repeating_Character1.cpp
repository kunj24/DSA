#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Problem: Longest Substring Without Repeating Characters
    // Given a string, find the length of the longest substring
    // that contains no repeating characters.
    // Goal: Return the maximum length.
    // Approach: Sliding window using hash table to store last occurrence.

    int longestNonRepeatingSubstring(string& s) {
        int n = s.size();     // length of string
        
        int HashLen = 256;    // assuming ASCII characters
        
        int hash[HashLen];    // store last index of characters
        
        // initialize hash table with -1
        for (int i = 0; i < HashLen; ++i) {   // initialization loop
            hash[i] = -1;
        }

        int l = 0;            // left pointer of window
        int r = 0;            // right pointer of window
        int maxLen = 0;       // store maximum length

        // sliding window loop
        while (r < n) {

            // if character already seen in current window
            if (hash[s[r]] != -1) {
                // move left pointer to avoid repetition
                l = max(hash[s[r]] + 1, l);
            }

            int len = r - l + 1;        // current window length

            maxLen = max(len, maxLen);  // update maximum length

            hash[s[r]] = r;             // store last index of character

            r++;                        // move right pointer
        }

        return maxLen;   // return result
    }
};

int main() {
    string s;

    cout << "Enter a string: ";
    cin >> s;

    Solution sol;
    int result = sol.longestNonRepeatingSubstring(s);

    cout << "The maximum length is: " << result << endl;

    return 0;
}

/*
Explanation:
We use a sliding window technique.

Steps:
1. Use two pointers: left (l) and right (r).
2. Expand the window using r.
3. If a repeated character is found:
   Move l to the right of its last occurrence.
4. Keep updating the maximum length.

Example:
Input:
s = "cadbzabcd"

Process:
Window expands:
c → ca → cad → cadb → cadbz → repeat 'a'
Shift left pointer

Longest substring:
"cadbz" → length = 5

Output:
5

Edge Cases:
1. Empty string → return 0
2. Single character → return 1
3. All same characters ("aaaa") → return 1
4. All unique characters ("abcdef") → return 6

Time Complexity:
O(n) → each character processed once

Space Complexity:
O(1) → fixed size hash array (256)
*/
