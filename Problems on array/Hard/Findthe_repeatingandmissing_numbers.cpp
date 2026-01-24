#include <iostream>
#include <vector>
using namespace std;

// Function to find repeating and missing number
pair<int, int> calculate(vector<int>& arr, int n) {

    int repeating = -1, missing = -1;  
    // repeating → number that appears twice
    // missing   → number that does not appear

    // Outer loop checks numbers from 1 to n
    for (int i = 1; i <= n; i++) {

        int cnt = 0;  
        // cnt counts how many times i appears in array

        // Inner loop checks all elements of array
        for (int j = 0; j < n; j++) {

            // Compare current array element with i
            if (arr[j] == i) {
                cnt++;  // increment count if match found
            }
        }

        // After checking entire array
        if (cnt == 2)
            repeating = i;  // found repeating number

        else if (cnt == 0)
            missing = i;    // found missing number

        // Stop if both are found
        if (repeating != -1 && missing != -1)
            break;
    }

    return {repeating, missing};
}

int main() {

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter " << n 
         << " elements (one repeated, one missing): ";

    // User enters array values
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Function call
    pair<int, int> ans = calculate(arr, n);

    // Output result
    cout << "\nRepeating number: " << ans.first << endl;
    cout << "Missing number: " << ans.second << endl;

    return 0;
}

/*
===================== USER INPUT EXAMPLE =====================

User Input:
Enter number of elements: 5
Enter 5 elements: 1 2 2 4 5

Array Stored As:
arr = {1, 2, 2, 4, 5}

-------------------------------------------------
i = 1
Check array:
1 → found once → cnt = 1 → OK

-------------------------------------------------
i = 2
Check array:
2 → found twice → cnt = 2 → repeating = 2

-------------------------------------------------
i = 3
Check array:
3 → not found → cnt = 0 → missing = 3

Both found → loop stops

-------------------------------------------------
OUTPUT:
Repeating number: 2
Missing number: 3

=================================================

WHY THIS WORKS:
- Numbers should be from 1 to n
- One number appears twice
- One number is missing
- Count occurrences to detect both

TIME COMPLEXITY:
O(n²)  (simple and easy to understand)

=================================================
*/
