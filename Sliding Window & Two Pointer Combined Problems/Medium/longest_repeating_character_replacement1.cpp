#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Problem: Longest Repeating Character Replacement
    // Given a string of uppercase letters and an integer k,
    // you can replace at most k characters in any substring.
    // Goal: Find the length of the longest substring
    // that can be converted into all same characters.
    // Approach: Sliding window with frequency tracking.

    int characterReplacement(string s, int k) {
        
        unordered_map<char, int> freq;   // frequency map of characters
        
        int left = 0;        // left pointer of window
        int max_freq = 0;    // most frequent character count
        int max_len = 0;     // store maximum window size

        // sliding window loop
        for (int right = 0; right < s.length(); right++) {   // expand window

            freq[s[right]]++;   // increase frequency of current character

            // update max frequency seen so far
            max_freq = max(max_freq, freq[s[right]]);

            // if window becomes invalid
            while ((right - left + 1) - max_freq > k) {   // important shrink condition

                freq[s[left]]--;   // reduce frequency of left character
                left++;            // move left pointer
            }

            // update maximum valid window length
            max_len = max(max_len, right - left + 1);
        }

        return max_len;   // return result
    }
};

int main() {
    Solution sol;
    string s;
    int k;

    cout << "Enter uppercase string: ";
    cin >> s;

    cout << "Enter k (max replacements): ";
    cin >> k;

    int result = sol.characterReplacement(s, k);

    cout << "Maximum length: " << result << endl;

    return 0;
}

/*
Explanation:
We use a sliding window approach.

Steps:
1. Expand window using right pointer.
2. Track frequency of characters in window.
3. Keep track of most frequent character (max_freq).
4. If replacements needed > k:
      shrink window from left.
5. Track maximum window size.

Key Idea:
Replacements needed = window length - max_freq

If this is ≤ k, the window is valid.

Example:
Input:
s = "AABABBA"
k = 1

Process:
"AABA" → replace one 'B' → "AAAA"
Length = 4

Output:
4

Edge Cases:
1. Empty string → return 0
2. k = 0 → longest same-character substring
3. All characters same → return string length
4. k ≥ string length → return string length

Time Complexity:
O(n) → each character processed once

Space Complexity:
O(1) → at most 26 characters stored
*/
