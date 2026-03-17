#include <iostream>
#include <vector>
using namespace std;

/*
Problem:
Write a function to find the longest common prefix string
amongst an array of strings.
If there is no common prefix, return an empty string.

Example:
Input:
3
flower
flow
flight

Output:
fl
*/

string longestCommonPrefix(vector<string>& strs) {

    // Edge case: empty array
    if (strs.size() == 0) return "";

    string prefix = "";

    // Traverse characters of first string
    for (int i = 0; i < strs[0].length(); i++) {

        char ch = strs[0][i];  // character to compare

        // Compare with all other strings
        for (int j = 1; j < strs.size(); j++) {

            // If index out of range OR mismatch
            // Check if the current word 'j' has finished (i is too large)
            // OR if the character at the current position doesn't match our reference character 'ch'
            if (i >= strs[j].length() || strs[j][i] != ch) {
                // If either is true, the common prefix ends here
                return prefix;
            }

        }

        // If all matched, add character to prefix
        prefix += ch;
    }

    return prefix;
}

int main() {

    int n;
    cout << "Enter number of strings: ";
    cin >> n;

    vector<string> strs(n);

    cout << "Enter the strings:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }

    string result = longestCommonPrefix(strs);

    cout << "Longest Common Prefix: " << result << endl;

    return 0;
}

/*
--------------------------------
Example Run:

Input:
Enter number of strings: 3
Enter the strings:
flower
flow
flight

Output:
Longest Common Prefix: fl

--------------------------------
Edge Cases:
1. n = 0 → output ""
2. One string only → return that string
3. No common prefix → ""

--------------------------------
Time Complexity:
O(N × M)
N = number of strings
M = length of smallest string

Space Complexity:
O(1)
*/
