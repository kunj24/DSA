#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Problem: Longest Repeating Character Replacement
    // Given a string consisting of uppercase letters and an integer k,
    // you can replace at most k characters in a substring.
    // Goal: Find the length of the longest substring
    // that can be made of the same character after at most k replacements.
    // Approach: Brute force – check all substrings and track
    // the most frequent character in each substring.

    int characterReplacement(string s, int k) {
        
        int maxLength = 0;   // store maximum valid substring length
        
        // try all starting points
        for (int i = 0; i < s.length(); i++) {   // outer loop: start index
            
            vector<int> freq(26, 0);   // frequency array for A–Z
            int maxFreq = 0;           // most frequent character count
            
            // expand substring from index i
            for (int j = i; j < s.length(); j++) {   // inner loop: end index
                
                freq[s[j] - 'A']++;   // update frequency of current character
                
                // update maximum frequency character
                maxFreq = max(maxFreq, freq[s[j] - 'A']);
                
                int windowLength = j - i + 1;   // current substring length
                
                // number of replacements needed
                int replace = windowLength - maxFreq;
                
                // check if within allowed replacements
                if (replace <= k) {
                    maxLength = max(maxLength, windowLength);
                }
            }
        }
        
        return maxLength;
    }
};

int main() {
    Solution sol;
    string s;
    int k;

    cout << "Enter the string (uppercase letters): ";
    cin >> s;

    cout << "Enter k (max replacements): ";
    cin >> k;

    int result = sol.characterReplacement(s, k);

    cout << "Maximum length: " << result << endl;

    return 0;
}

/*
Explanation:
We check every possible substring.

Steps:
1. Start at index i.
2. Expand substring using index j.
3. Track frequency of each character.
4. Find the most frequent character in substring.
5. Calculate replacements needed:
      replacements = windowLength - maxFreq
6. If replacements ≤ k:
      update maximum length.

Example:
Input:
s = "AABABBA"
k = 1

Substrings:
"AABA" → can replace 1 'B' → "AAAA" → length = 4
"ABAB" → needs 2 replacements → invalid

Output:
4

Edge Cases:
1. Empty string → return 0
2. k = 0 → longest existing same-character substring
3. All characters same → return string length
4. k ≥ string length → return string length

Time Complexity:
Outer loop: O(n)
Inner loop: O(n)
Total: O(n²)

Space Complexity:
O(1) → fixed size frequency array (26)
*/
