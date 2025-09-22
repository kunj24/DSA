#include <iostream>
using namespace std;

void RotateToLeft(int arr[], int n, int k) {
    if (n == 0) return;
    k = k % n;  // Handle k > n cases
        //for more logic go to the left_rotate_byK.cpp
    int temp[k];
    
    // Store first k elements in temp
    for (int i = 0; i < k; i++) {
        temp[i] = arr[i];
    }
    
    // Shift remaining elements to the left
    for (int i = 0; i < n - k; i++) {
        arr[i] = arr[i + k];
    }
    
    // Place temp elements at the end
    for (int i = 0; i < k; i++) {
        arr[n - k + i] = temp[i];
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    
    int arr[n];
    cout << "Enter " << n << " numbers:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int k;
    cout << "Enter number of positions to rotate left: ";
    cin >> k;
    
    RotateToLeft(arr, n, k);
    
    cout << "After rotating left by " << k << " positions:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}