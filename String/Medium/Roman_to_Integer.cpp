#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

/*
Problem:
Convert a Roman numeral into an integer.

Roman Symbols:
I=1, V=5, X=10, L=50, C=100, D=500, M=1000

Example:
Input: "IV"
Output: 4
*/

int romanintoint(string s) {

    // Step 1: Create mapping
    unordered_map<char, int> roman = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, 
        {'C', 100}, {'D', 500}, {'M', 1000}
    };

    int total = 0;

    // Step 2: Traverse string
    for (int i = 0; i < s.length(); i++) {

        // If next value is greater → subtract
        if (i + 1 < s.length() && roman[s[i]] < roman[s[i + 1]]) {
            total -= roman[s[i]];
        }
        else {
            // Otherwise add
            total += roman[s[i]];
        }
    }

    return total;
}

int main() {

    string s;

    cout << "Enter Roman string (UPPERCASE): ";
    cin >> s;

    int result = romanintoint(s);

    cout << "Integer value: " << result << endl;

    return 0;
}

/*
------------------------------------------------
Step-by-Step Table Example:

Input:
s = "MCMIV"

Index | s[i] | Next | Value | Action        | Total
-----------------------------------------------------
0     | M    | C    | 1000  | Add           | 1000
1     | C    | M    | 100   | Subtract      | 900
2     | M    | I    | 1000  | Add           | 1900
3     | I    | V    | 1     | Subtract      | 1899
4     | V    | -    | 5     | Add           | 1904

Output:
1904

------------------------------------------------
Example 2:

Input: "IX"

Index | s[i] | Next | Action
--------------------------------
0     | I    | X    | Subtract → -1
1     | X    | -    | Add → +10

Total = 9

------------------------------------------------
Key Idea:
- If smaller value comes before larger → subtract
- Else → add

------------------------------------------------
Edge Cases:
1. Single character → return its value
2. Valid Roman numerals assumed
3. All uppercase letters required

------------------------------------------------
Time Complexity:
O(n)

Space Complexity:
O(1)
*/