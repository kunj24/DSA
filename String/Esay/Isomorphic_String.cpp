#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
Problem:
Check if two strings are isomorphic.

Two strings are isomorphic if:
- Characters in string s can be replaced to get string t.
- Each character maps to only one character.
- Mapping must be consistent.

Example:
s = "egg"
t = "add"
Output: true
*/

bool isomorphicString(string& s, string& t) {

    // Step 1: If lengths are different → not isomorphic
    if (s.length() != t.length()) return false;

    // Step 2: Create mapping arrays
    int m1[256] = {0};  // mapping for s
    int m2[256] = {0};  // mapping for t

    // Step 3: Traverse strings
    for (int i = 0; i < s.length(); i++) {

        // If mappings are different → not isomorphic
        if (m1[s[i]] != m2[t[i]])
            return false;

        // Store current position +1
        m1[s[i]] = i + 1;
        m2[t[i]] = i + 1;
    }

    return true;
}

int main() {

    string s, t;

    cout << "Enter string 1: ";
    cin >> s;

    cout << "Enter string 2: ";
    cin >> t;

    bool result = isomorphicString(s, t);

    if (result) {
        cout << "This is an isomorphic string" << endl;
    } else {
        cout << "This is not an isomorphic string" << endl;
    }

    return 0;
}

/*

/*
------------------------------------------------
Explanation:

Idea:
1. Two characters must always map consistently.
2. Use two arrays to store last seen positions.
3. If mapping differs at any point → return false.

------------------------------------------------
Example:

s = "egg"
t = "add"

Step-by-step:
i=0 → e → a → store position 1
i=1 → g → d → store position 2
i=2 → g → d → mapping matches → continue

Output: true

------------------------------------------------
Edge Cases:
1. Different lengths → false
2. Single character strings → true
3. Repeating mismatch → false

------------------------------------------------
Time Complexity:
O(n)

Space Complexity:
O(1) (constant size arrays)
*/
