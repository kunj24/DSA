#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

/*
Problem:
Find substrings with exactly K distinct characters
using sliding window optimization.

Formula:
Exactly K = AtMost(K) - AtMost(K-1)
*/

class Solution {

public:

    long long atMostK(string s, int k) {

        if (k < 0) return 0;

        int i = 0;
        long long count = 0;

        unordered_map<char,int> freq;

        for (int j = 0; j < s.length(); j++) {

            freq[s[j]]++;

            while (freq.size() > k) {

                freq[s[i]]--;

                if (freq[s[i]] == 0)
                    freq.erase(s[i]);

                i++;
            }

            count += (j - i + 1);
        }

        return count;
    }

    long long countSubstringsWithExactlyK(string s, int k) {

        return atMostK(s, k) - atMostK(s, k - 1);
    }
};

int main() {

    Solution obj;

    string s;
    int k;

    cout << "Enter string: ";
    cin >> s;

    cout << "Enter K: ";
    cin >> k;

    cout << "Total substrings: "
         << obj.countSubstringsWithExactlyK(s, k)
         << endl;

    return 0;
}

/*
------------------------------------------------
Example:

s = "aba"
k = 2

Substrings with exactly 2 distinct:

ab
ba
aba

Total = 3

------------------------------------------------
Time Complexity:
O(n)

Space Complexity:
O(k)
*/