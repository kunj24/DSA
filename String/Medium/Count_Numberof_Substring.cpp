#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
Problem:
Count substrings that contain exactly K distinct characters.

Example:
Input:
s = "pqpqs"
k = 2

Output:
7
*/

int countSubstringsWithKDistinct(string s, int k) {

    int n = s.length();
    int totalCount = 0;

    for (int i = 0; i < n; i++) {

        vector<int> freq(26, 0);
        int distinctCount = 0;

        for (int j = i; j < n; j++) {

            int index = s[j] - 'a';

            if (freq[index] == 0)
                distinctCount++;

            freq[index]++;

            if (distinctCount == k)
                totalCount++;

            else if (distinctCount > k)
                break;
        }
    }

    return totalCount;
}

int main() {

    string s;
    int k;

    cout << "Enter string: ";
    cin >> s;

    cout << "Enter K: ";
    cin >> k;

    int result = countSubstringsWithKDistinct(s, k);

    cout << "Total substrings: " << result << endl;

    return 0;
}

/*
------------------------------------------------
Example:

s = "pqpqs"
k = 2

Valid substrings:

pq
pqp
qp
pqpq
qpq
pq
qs

Total = 7

------------------------------------------------
Time Complexity:
O(n²)

Space Complexity:
O(26) ≈ O(1)
*/