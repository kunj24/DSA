#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Problem:
Find the longest common prefix among an array of strings.
If no common prefix exists, return an empty string.

Approach:
Sort the array and compare the first and last string.
The common prefix of these two will be the answer.

Example:
Input:
["flower", "flow", "flight"]
Output:
"fl"
*/

string longestCommonPrefix(vector<string>& strs) {

    // Edge case: empty array
    if (strs.size() == 0) return "";

    // Step 1: Sort the strings
    sort(strs.begin(), strs.end());

    // Step 2: Take first and last string
    string first = strs[0];
    string last = strs[strs.size() - 1];

    string prefix = "";

    
    // Input:
    // ["flower", "flow", "flight"]

    // After sorting:
    // ["flight", "flow", "flower"]

    // First = "flight"
    // Last  = "flower"

    // Compare:
    // f == f → add 'f'
    // l == l → add 'l'
    // i != o → stop


    // Step 3: Compare characters
    for (int i = 0; i < min(first.length(), last.length()); i++) {

        // If characters match, add to prefix
        if (first[i] == last[i]) {
            prefix += first[i];
        }
        else {
            // Stop when mismatch occurs
            break;
        }
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
        cin >> strs[i];   // taking user input
    }

    string result = longestCommonPrefix(strs);

    cout << "Longest Common Prefix: " << result << endl;

    return 0;
}

/*
----------------------------------------------------
Explanation:

Idea:
1. Sort all strings lexicographically.
2. After sorting:
   - The most different strings will be at the ends.
3. Compare the first and last string.
4. Their common prefix is the answer.

----------------------------------------------------
Example Dry Run:

Input:
["flower", "flow", "flight"]

After sorting:
["flight", "flow", "flower"]

First = "flight"
Last  = "flower"

Compare:
f == f → add 'f'
l == l → add 'l'
i != o → stop

Output: "fl"

----------------------------------------------------
Edge Cases:
1. Empty array → return ""
2. One string only → return that string
3. No common prefix → return ""

----------------------------------------------------
Time Complexity:
Sorting: O(N log N)
Comparison: O(M)

Overall: O(N log N)

N = number of strings
M = length of smallest string

----------------------------------------------------
Space Complexity:
O(1) extra space
*/
