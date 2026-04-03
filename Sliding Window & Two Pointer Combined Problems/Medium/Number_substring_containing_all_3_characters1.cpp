#include <bits/stdc++.h>
using namespace std;

// Problem: Number of Substrings Containing All Three Characters
// Given a string consisting only of characters 'a', 'b', and 'c'.
// Goal: Count the number of substrings that contain at least
// one occurrence of each character: 'a', 'b', and 'c'.
// Approach: For each starting index, expand the substring
// until all three characters are found.

int number_substring_contain_abc_characters(string& s) {
    int n = s.size();
    int count = 0;   // store total valid substrings

    // try every starting index
    for (int i = 0; i < n; i++) {   // outer loop: starting point
        
        int hash[3] = {0};   // track presence of a, b, c
        
        // expand substring from i
        for (int j = i; j < n; j++) {   // inner loop: ending point
            
            hash[s[j] - 'a'] = 1;   // mark character present
            
            // if substring contains a, b, and c
            if (hash[0] + hash[1] + hash[2] == 3) {
                
                /*
                If s[i...j] is valid,
                then s[i...j], s[i...j+1], ..., s[i...n-1]
                are all valid substrings.
                */
                count += (n - j);   // add all valid substrings
                break;              // stop checking further
            }
        }
    }

    return count;
}

int main() {
    string s;

    cout << "Enter a string which contains a, b, c characters: ";
    cin >> s;

    int result = number_substring_contain_abc_characters(s);

    cout << "Total valid substrings: " << result << endl;

    return 0;
}

/*
Explanation:
We check every possible substring.

Steps:
1. Start from index i.
2. Expand substring using index j.
3. Track presence of a, b, c.
4. Once all three appear:
   - All substrings from j to end are valid.
   - Add (n - j) to count.
   - Break and move to next i.

Example:
Input:
s = "abcabc"

Substrings containing a, b, c:
"abc"
"abca"
"abcab"
"abcabc"
"bca"
"bcab"
"bcabc"
"cab"
"cabc"
"abc"

Total = 10

Output:
10

Edge Cases:
1. Empty string → return 0
2. String length < 3 → return 0
3. String with only one or two characters → return 0
4. All same characters → return 0

Time Complexity:
Outer loop: O(n)
Inner loop: O(n)
Total: O(n²)

Space Complexity:
O(1) → fixed hash array of size 3
*/
