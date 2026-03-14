#include<iostream>
using namespace std;

/*
Problem:
Check whether two strings are anagrams.

Two strings are anagrams if:
- They contain same characters
- Same frequency of each character

Example:
str1 = "LISTEN"
str2 = "SILENT"
Output: true
*/

bool Anagrams_string(string& str1, string& str2) {

    // Step 1: Length check
    if (str1.length() != str2.length()) {
        return false;
    }

    // Step 2: Frequency array for A-Z
    int freq[26] = {0};

    // Step 3: Count characters of str1
    for (int i = 0; i < str1.length(); i++) {
        freq[str1[i] - 'A']++;   // increment
    }

    // Step 4: Subtract characters of str2
    for (int i = 0; i < str2.length(); i++) {
        freq[str2[i] - 'A']--;   // decrement
    }

    // Step 5: Check all frequencies
    for (int i = 0; i < 26; i++) {
        if (freq[i] != 0)
            return false;
    }

    return true;
}

int main() {

    string s, t;

    cout << "Enter string 1 (UPPERCASE): ";
    cin >> s;

    cout << "Enter string 2 (UPPERCASE): ";
    cin >> t;

    bool result = Anagrams_string(s, t);

    if (result) {
        cout << "This is an Anagram string" << endl;
    } else {
        cout << "This is not an Anagram string" << endl;
    }

    return 0;
}

/*
------------------------------------------------
Step-by-Step Table Example:

Input:
str1 = "LISTEN"
str2 = "SILENT"

Step 1: Count str1

Index | Char | freq[char]
-------------------------
0     | L    | L=1
1     | I    | I=1
2     | S    | S=1
3     | T    | T=1
4     | E    | E=1
5     | N    | N=1

Step 2: Subtract str2

Index | Char | freq after decrement
-----------------------------------
0     | S    | S=0
1     | I    | I=0
2     | L    | L=0
3     | E    | E=0
4     | N    | N=0
5     | T    | T=0

Step 3:
All frequencies = 0 → Anagram

Output:
True

------------------------------------------------
Example 2:

str1 = "HELLO"
str2 = "WORLD"

After processing:
Some freq ≠ 0 → Not anagram

------------------------------------------------
Edge Cases:
1. Different lengths → false
2. Case sensitive → "abc" ≠ "ABC"
3. Only alphabets assumed

------------------------------------------------
Time Complexity:
O(n)

Space Complexity:
O(1)
*/