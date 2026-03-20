#include <iostream>
#include <string>
using namespace std;

/*
Problem:
Find the longest palindromic substring.

Example:
Input: "babad"
Output: "bab" or "aba"
*/

string expand(string s, int left, int right) {

    while (left >= 0 && right < s.length() && s[left] == s[right]) {
        left--;
        right++;
    }

    return s.substr(left + 1, right - left - 1);
}

string longestPalindrome(string s) {

    string longest = "";

    for (int i = 0; i < s.length(); i++) {

        string odd = expand(s, i, i);
        if (odd.length() > longest.length())
            longest = odd;

        string even = expand(s, i, i + 1);
        if (even.length() > longest.length())
            longest = even;
    }

    return longest;
}

int main() {

    string s;

    cout << "Enter string: ";
    cin >> s;

    string result = longestPalindrome(s);

    cout << "Longest Palindromic Substring: " << result << endl;

    return 0;
}

/*
Example:

Input:
s = "babad"

Centers checked:
b
a
b
a
d

Palindromes found:
bab
aba

Output:
bab

Time Complexity: O(n²)
Space Complexity: O(1)
*/