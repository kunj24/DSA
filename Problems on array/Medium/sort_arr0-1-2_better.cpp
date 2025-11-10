#include <iostream>
#include <vector>
using namespace std;

void sortArray(vector<int>& arr, int n) {
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) cnt0++;
        else if (arr[i] == 1) cnt1++;
        else cnt2++;
    }

    // Replace the places in the original array:
    for (int i = 0; i < cnt0; i++) arr[i] = 0; // replacing 0's
    for (int i = cnt0; i < cnt0 + cnt1; i++) arr[i] = 1; // replacing 1's
    for (int i = cnt0 + cnt1; i < n; i++) arr[i] = 2; // replacing 2's
}

int main() {
    int n;
    
    // Get array size from user
    cout << "Enter the number of elements: ";
    cin >> n;
    
    // Input validation
    if (n <= 0) {
        cout << "Invalid array size!" << endl;
        return 1;
    }
    
    vector<int> arr(n);
    
    // Get array elements from user
    cout << "Enter " << n << " elements (only 0, 1, or 2):" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        
        // Input validation - ensure only 0,1,2 are entered
        if (arr[i] < 0 || arr[i] > 2) {
            cout << "Invalid input! Please enter only 0, 1, or 2." << endl;
            i--; // Retry this input
        }
    }
    
    // Display original array
    cout << "\nOriginal array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    // Sort the array
    sortArray(arr, n);
    
    // Display sorted array
    cout << "After sorting: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    
    return 0;
}