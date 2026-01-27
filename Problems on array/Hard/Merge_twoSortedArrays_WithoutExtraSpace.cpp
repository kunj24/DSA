#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Function to merge two sorted arrays in-place
// arr1 will contain first n smallest, arr2 will contain remaining m elements
void MergeInPlace(vector<int>& arr1, vector<int>& arr2, int n, int m){
    // Merge and put result in a temporary array
    vector<int> result(n + m);
    int left = 0;    // Pointer for arr1
    int right = 0;   // Pointer for arr2
    int index = 0;   // Pointer for result
    
    // Merge while both arrays have elements
    while(left < n && right < m){
        if(arr1[left] <= arr2[right]){
            result[index] = arr1[left];
            left++;
        }
        else{
            result[index] = arr2[right];
            right++;
        }
        index++;
    }
    
    // Copy remaining elements from arr1
    while(left < n){
        result[index] = arr1[left];
        left++;
        index++;
    }
    
    // Copy remaining elements from arr2
    while(right < m){
        result[index] = arr2[right];
        right++;
        index++;
    }
    
    // Copy first n elements back to arr1
    for(int i = 0; i < n; i++){
        arr1[i] = result[i];
    }
    
    // Copy remaining m elements back to arr2
    for(int i = 0; i < m; i++){
        arr2[i] = result[n + i];
    }
}

int main(){
    int n, m;
    
    // Input first array
    cout << "Enter number of elements in array 1: ";
    cin >> n;
    cout << "Enter " << n << " sorted elements for array 1: " << endl;
    vector<int> arr1(n);
    for(int i = 0; i < n; i++){
        cin >> arr1[i];
    }
    
    // Input second array
    cout << "Enter number of elements in array 2: ";
    cin >> m;
    cout << "Enter " << m << " sorted elements for array 2: " << endl;
    vector<int> arr2(m);
    for(int i = 0; i < m; i++){
        cin >> arr2[i];
    }
    
    cout << "\nBefore merging:" << endl;
    cout << "Array 1: ";
    for(int i = 0; i < n; i++) cout << arr1[i] << " ";
    cout << "\nArray 2: ";
    for(int i = 0; i < m; i++) cout << arr2[i] << " ";
    cout << endl;
    
    // Merge arrays in-place
    MergeInPlace(arr1, arr2, n, m);
    
    cout << "\nAfter merging:" << endl;
    cout << "Array 1: ";
    for(int i = 0; i < n; i++){
        cout << arr1[i] << " ";
    }
    cout << "\nArray 2: ";
    for(int i = 0; i < m; i++){
        cout << arr2[i] << " ";
    }
    cout << endl;
    
    return 0;
}

// Input:
// Array 1: [1, 4, 8, 10]  (n=4)
// Array 2: [2, 3, 9]      (m=3)

// Step 1: Merge into result array
// Result: [1, 2, 3, 4, 8, 9, 10]

// Step 2: Copy back:
// First 4 elements to arr1: [1, 2, 3, 4]
// Remaining 3 elements to arr2: [8, 9, 10]

// Output:
// Array 1: [1, 2, 3, 4]
// Array 2: [8, 9, 10]