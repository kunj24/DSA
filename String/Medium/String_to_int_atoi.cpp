#include <iostream>
#include <string>
#include <climits>
#include <cctype>
using namespace std;

/*
Problem:
Convert a string to an integer similar to the C/C++ atoi() function.

Rules:
1. Ignore leading spaces
2. Handle '+' or '-' sign
3. Read digits until non-digit appears
4. Handle overflow
*/

int my_atoi(string s) {

    int sign = 1;
    int i = 0;
    long long result = 0;
    int n = s.length();

    // 1. Skip leading spaces
    while (i < n && s[i] == ' ')
        i++;

    // 2. Check sign
    if (i < n && (s[i] == '+' || s[i] == '-')) {
        if (s[i] == '-') sign = -1;
        i++;
    }

    // 3. Convert digits
    while (i < n && isdigit(s[i])) {

        result = result * 10 + (s[i] - '0');

        // 4. Handle overflow
        if (result * sign >= INT_MAX) return INT_MAX;
        if (result * sign <= INT_MIN) return INT_MIN;

        i++;
    }

    return result * sign;
}

int main() {

    string s;

    cout << "Enter string: ";
    getline(cin, s);

    int result = my_atoi(s);

    cout << "Integer value: " << result << endl;

    return 0;
}

/*
------------------------------------------------
Example:

Input:
"   -42abc"

Step Table:

Index | Char | Action | Result
--------------------------------
0-2   | ' '  | Skip spaces
3     | '-'  | sign = -1
4     | '4'  | result = 4
5     | '2'  | result = 42
6     | 'a'  | Stop

Output = -42
------------------------------------------------
Time Complexity: O(n)
Space Complexity: O(1)
*/