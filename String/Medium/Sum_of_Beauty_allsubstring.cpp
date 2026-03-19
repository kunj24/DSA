#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

/*
Problem:
Beauty of substring = max frequency - min frequency
Find the sum of beauty of all substrings.
*/

int beauty(string s) {

    int n = s.length();
    int totalBeauty = 0;

    for (int i = 0; i < n; i++) {

        unordered_map<char,int> freq;

        for (int j = i; j < n; j++) {

            freq[s[j]]++;

            int mini = INT_MAX;
            int maxi = INT_MIN;

            for (auto it : freq) {
                mini = min(mini, it.second);
                maxi = max(maxi, it.second);
            }

            totalBeauty += (maxi - mini);
        }
    }

    return totalBeauty;
}

int main() {

    string s;

    cout << "Enter string: ";
    cin >> s;

    int result = beauty(s);

    cout << "Total Beauty: " << result << endl;

    return 0;
}

/*
Example:

Input:
s = "aab"

Substrings:
a → 1-1 = 0
aa → 2-2 = 0
aab → 2-1 = 1
a → 1-1 = 0
ab → 1-1 = 0
b → 1-1 = 0

Total = 1

Time Complexity: O(n² * 26)
Space Complexity: O(26)
*/