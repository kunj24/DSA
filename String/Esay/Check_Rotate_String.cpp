#include<iostream>
using namespace std;

/*
Problem:
Check if string 'goal' can be obtained by rotating string 's'.
If yes, return the rotation index.
Otherwise, return -1.

Example:
s = "abcde"
goal = "cdeab"
Output: 2
*/

int Found_rotate_string(string& s, string& goal) {

    // Step 1: Length must be equal
    if (s.length() != goal.length())
        return -1;

    int n = s.length();

    // Let's say s = "coding" and i = 2:
    // s.substr(2) 
    //  Starts at index 2 ('d') to the end: "ding"
    // s.substr(0, 2) 
    //  Starts at index 0, takes 2 characters: "co"
    // Result: "ding" + "co" = "dingco"
    // Step 2: Try all possible rotations

    for (int i = 0; i < n; i++) {

        // Create rotated string
        string rotated = s.substr(i) + s.substr(0, i);

        // Check if it matches goal
        if (rotated == goal) {
            return i;   // rotation index found
        }
    }

    return -1;   // no rotation matches
}

int main() {

    string s, goal;

    cout << "Enter string 1: ";
    cin >> s;

    cout << "Enter string 2: ";
    cin >> goal;

    int result = Found_rotate_string(s, goal);

    if (result != -1) {
        cout << "This is a rotated string with " 
             << result << " index rotation" << endl;
    } else {
        cout << "This is not a rotated string" << endl;
    }

    return 0;
}

/*
------------------------------------------------
Step-by-Step Table Example:

Input:
s = "abcde"
goal = "cdeab"

Index | Rotation | Rotated String | Match?
--------------------------------------------
0     | 0 shift  | abcde          | No
1     | 1 shift  | bcdea          | No
2     | 2 shift  | cdeab          | Yes → return 2

Output:
Rotated string with index 2

------------------------------------------------
Edge Cases:
1. Different lengths → return -1
2. Same strings → rotation index 0
3. No valid rotation → return -1

------------------------------------------------
Time Complexity:
O(n²)  (n rotations × n comparison)

Space Complexity:
O(n)
*/
