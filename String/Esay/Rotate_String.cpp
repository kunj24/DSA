#include<iostream>
#include<string>
using namespace std;

/*
Problem:
Rotate a string by k positions in either left or right direction.

Example:
Input:
s = "abcdef"
k = 2
direction = "right"

Output:
"efabcd"
*/

string rotate_string(string& s, int k, string& direction) {
    
    int n = s.length();

    // Edge case: empty string
    if (n == 0) return s;
    
    // Normalize k if larger than string length
    k %= n;

    // Right rotation
    if (direction == "right") {
        // Last k characters move to front
        return s.substr(n - k) + s.substr(0, n - k);
    } 
    // Left rotation
    else {
        // First k characters move to back
        return s.substr(k) + s.substr(0, k);
    }
}

int main() {
    string s, direction;

    cout << "Enter string: ";
    cin >> s;   

    int k;
    cout << "Enter number of characters to rotate: ";
    cin >> k;

    cout << "Enter direction (left/right): ";
    cin >> direction;

    string result = rotate_string(s, k, direction);
    
    cout << "\nRotated String (" << direction << "): " << result << endl;
    
    return 0;
}

/*
------------------------------------------------
Step-by-Step Table Example (Right Rotation)

Input:
s = "abcdef"
k = 2
direction = "right"

String length = 6
k = 2

Step 1:
Take last k characters:
s.substr(6-2) = s.substr(4) = "ef"

Step 2:
Take remaining front part:
s.substr(0, 4) = "abcd"

Step 3:
Combine:
"ef" + "abcd" = "efabcd"

Output:
"efabcd"

------------------------------------------------
Step-by-Step Table Example (Left Rotation)

Input:
s = "abcdef"
k = 2
direction = "left"

Step 1:
Take first k characters:
s.substr(0,2) = "ab"

Step 2:
Take remaining part:
s.substr(2) = "cdef"

Step 3:
Combine:
"cdef" + "ab" = "cdefab"

Output:
"cdefab"

------------------------------------------------
Edge Cases:
1. k = 0 → same string
2. k > length → normalized using k % n
3. Empty string → return as is

------------------------------------------------
Time Complexity:
O(n)

Space Complexity:
O(n) (new rotated string created)
*/
    