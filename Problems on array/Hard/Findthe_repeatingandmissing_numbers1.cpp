#include <iostream>
#include <vector>
using namespace std;

// Hashing approach
pair<int, int> findUsingHash(vector<int>& arr, int n) {

    vector<int> hash(n + 1, 0);  
    // hash[i] will store how many times number i appears

    // Count frequency of each number
    for (int i = 0; i < n; i++) {
        hash[arr[i]]++;   // increase count
    }

    int repeating = -1, missing = -1;

    // Check frequency array
    for (int i = 1; i <= n; i++) {

        if (hash[i] == 2)
            repeating = i;   // appears twice

        else if (hash[i] == 0)
            missing = i;     // missing
    }

    return {repeating, missing};
}

int main() {

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    pair<int, int> ans = findUsingHash(arr, n);

    cout << "\n[HASH METHOD]" << endl;
    cout << "Repeating number: " << ans.first << endl;
    cout << "Missing number: " << ans.second << endl;

    return 0;
}

/*
Example:
Input: 1 2 2 4 5
Hash array becomes:
Index:  1 2 3 4 5
Value:  1 2 0 1 1

2 → frequency 2 → repeating
3 → frequency 0 → missing
*/
