#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
Problem:
Sort characters of a string based on frequency in descending order.
If frequencies are same, sort characters in ascending order (A-Z).

Example:
Input: "tree"
Output: "eert" OR "eetr"
*/

bool compare(pair<int, char> a, pair<int, char> b) {
    
    // Rule 1: Higher frequency comes first
    if (a.first != b.first) {
        return a.first > b.first;
    }

    // Rule 2: If same frequency, sort alphabetically
    return a.second < b.second;
}

string frequencySort(string& s) {

    // Step 1: Create frequency array for ASCII characters
    vector<pair<int, char>> freq(128);

    for (int i = 0; i < 128; i++) {
        freq[i] = {0, (char)i};
    }

    // Step 2: Count frequency
    for (char c : s) {
        freq[c].first++;
    }

    // Step 3: Sort based on custom comparator
    sort(freq.begin(), freq.end(), compare);

    // Step 4: Build result string
    string result = "";

    for (int i = 0; i < 128; i++) {
        if (freq[i].first > 0) {
            result.append(freq[i].first, freq[i].second);
        }
    }

    return result;
}

int main() {
    string s;

    cout << "Enter string: ";
    cin >> s;

    cout << "Sorted Result: " << frequencySort(s) << endl;

    return 0;
}

/*
------------------------------------------------
Step-by-Step Table Example:

Input:
s = "tree"

Step 1: Frequency Count

Char | Frequency
----------------
t    | 1
r    | 1
e    | 2

Step 2: Store in vector (freq, char)

(2, e)
(1, r)
(1, t)

Step 3: Sort using rules

Rule:
- Higher frequency first
- If equal → alphabetical

Sorted:
(2, e)
(1, r)
(1, t)

Step 4: Build result

Index | Char | Times | Result
------------------------------
0     | e    | 2     | "ee"
1     | r    | 1     | "eer"
2     | t    | 1     | "eert"

Output:
"eert"

------------------------------------------------
Example 2:

Input: "cccaaa"

Step 1:
c → 3
a → 3

Step 2:
(3, a), (3, c)

Step 3:
Same frequency → alphabetical

Result:
"aaaccc"

------------------------------------------------
Edge Cases:
1. Empty string → ""
2. All same characters → same string
3. Mixed ASCII characters supported

------------------------------------------------
Time Complexity:
O(n + 128 log 128) ≈ O(n)

Space Complexity:
O(128) ≈ O(1)
*/