#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Function to find maximum product subarray
int calculate(vector<int>& arr, int n) {

    int maxProduct = INT_MIN;

    // Starting index of subarray
    for (int i = 0; i < n; i++) {

        int product = 1;   // reset for each new subarray start

        // Ending index of subarray
        for (int j = i; j < n; j++) {

            product *= arr[j];     // extend subarray
            maxProduct = max(maxProduct, product); // update answer
        }
    }

    return maxProduct;
}

int main() {

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements that can be -ve or +ve or 0: ";

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int ans = calculate(arr, n);

    cout << "Maximum product subarray: " << ans << endl;

    return 0;
}
