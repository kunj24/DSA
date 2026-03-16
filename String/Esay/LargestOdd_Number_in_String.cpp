#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
Problem:
Given a numeric string, return the largest odd-numbered substring
that starts from the left and ends at the rightmost odd digit.

Example:
Input: "504321"
Output: "54321"
*/

string countlargeoddnumber(string& s, int n) {

    int ind = -1;

    // Find the rightmost odd digit
    for (int i = n - 1; i >= 0; i--) {
        if ((s[i] - '0') % 2 == 1) {   // check if digit is odd
            ind = i;
            break;
        }
    }

    // If no odd digit found, return empty string
    if (ind == -1) return "";

    // Skip leading zeros
    int i = 0;
    while (i <= ind && s[i] == '0') {
        i++;
    }

    return s.substr(i, ind - i + 1);
}

int main() {

    string s;
    cout << "Enter a string: ";
    cin >> s;

    int n = s.length();

    string result = countlargeoddnumber(s, n);

    cout << "Largest odd substring: " << result << endl;

    return 0;
}

/*
-------------------------
Explanation:

Idea:
1. Scan from right to left.
2. Find the first odd digit.
3. That index becomes the end of the result.
4. Remove leading zeros from the start.
5. Return the substring.

Example:
Input: "0054321"

Step 1: Rightmost odd digit = '1' at index 6
Step 2: Skip leading zeros → start at index 2
Step 3: Substring from index 2 to 6 → "54321"

Output: "54321"

Edge Cases:
1. No odd digits → return ""
2. String with only zeros → return ""

Time Complexity:
O(n) → single scan

Space Complexity:
O(1) → no extra space except output
*/
