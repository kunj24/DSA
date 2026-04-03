#include <bits/stdc++.h>
using namespace std;

// Problem: Number of Substrings Containing All Three Characters
// Given a string consisting only of characters 'a', 'b', and 'c'.
// Goal: Count the number of substrings that contain at least
// one occurrence of each character: 'a', 'b', and 'c'.
// Approach: Track the last seen index of a, b, and c.

int numberOfSubstrings(string s) {
    int n = s.size();
    int count = 0;

    // Store last seen index of a, b, c
    int hash[3] = {-1, -1, -1};

    // single pass through string
    for (int i = 0; i < n; i++) {   // main loop

        hash[s[i] - 'a'] = i;   // update last seen index

        // check if all three characters have appeared
        if (hash[0] != -1 && hash[1] != -1 && hash[2] != -1) {

            // add number of valid substrings ending at i
            count += (1 + min({hash[0], hash[1], hash[2]}));
        }
    }

    return count;
}

int main() {
    string s;

    cout << "Enter a string which contains a, b, c characters: ";
    cin >> s;

    int result = numberOfSubstrings(s);   // corrected function call

    cout << "Total valid substrings: " << result << endl;

    return 0;
}

/*
Explanation:
We track the last occurrence of 'a', 'b', and 'c'.

At each index i:
1. Update the last seen position of the character.
2. If all three characters have appeared:
   - Find the smallest index among them.
   - All substrings ending at i and starting
     from 0 to that index are valid.

Example:
Input:
s = "abcabc"

At i = 2 → substring "abc"
count += 1

At i = 3 → "abca"
count += 2

At i = 4 → "abcab"
count += 3

At i = 5 → "abcabc"
count += 4

Total = 10

Edge Cases:
1. Empty string → return 0
2. Length < 3 → return 0
3. String without all a, b, c → return 0
4. All same characters → return 0

Time Complexity:
O(n) → single pass through string

Space Complexity:
O(1) → fixed size array of 3
*/
