#include <iostream>
#include <vector>
using namespace std;

// Maths approach
pair<int, int> findUsingMath(vector<int>& arr, int n) {

    long long S = 0, S2 = 0;  
    // S  = sum of elements
    // S2 = sum of squares of elements

    for (int i = 0; i < n; i++) {
        S += arr[i];
        S2 += (long long)arr[i] * arr[i];
    }

    // Expected sum and square sum
    long long Sn = (long long)n * (n + 1) / 2;
    long long S2n = (long long)n * (n + 1) * (2 * n + 1) / 6;

    // Let:
    // x = repeating, y = missing
    // S - Sn  = x - y  ----(1)
    // S2 - S2n = x^2 - y^2 = (x - y)(x + y) ----(2)

    long long diff = S - Sn;          // x - y
    long long diffSq = S2 - S2n;      // x^2 - y^2

    long long sum = diffSq / diff;    // x + y = number/x-y because the x+y x-y = x^2-y^2
    //so you got a x+y and x-y so 2x=diff+sum so...
    long long x = (diff + sum) / 2;   // repeating
    long long y = x - diff;           // missing

    return {(int)x, (int)y};
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

    pair<int, int> ans = findUsingMath(arr, n);

    cout << "\n[MATH METHOD]" << endl;
    cout << "Repeating number: " << ans.first << endl;
    cout << "Missing number: " << ans.second << endl;

    return 0;
}

/*
Example:
Input: 1 2 2 4 5
n = 5

Expected sum = 15
Actual sum = 14 → x - y = -1

Expected square sum = 55
Actual square sum = 50 → x^2 - y^2 = -5

Solve equations:
x - y = -1
x + y = 5

Repeating = 2
Missing = 3
*/
