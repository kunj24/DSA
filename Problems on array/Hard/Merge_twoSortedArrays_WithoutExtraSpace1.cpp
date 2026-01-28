#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void MergeInPlace(vector<int>& arr1, vector<int>& arr2, int n, int m){
    int left=n-1;
    int right=0;
    while (left>=0 && right<m)
    {
        if(arr1[left]>arr2[right]){
            swap(arr1[left],arr2[right]);
            left--;
            right++;
        }
        else{
            break;
        }   
    }
    
    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());

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
// arr1: [1, 4, 8, 10]  (n=4)
// arr2: [2, 3, 9]      (m=3)

// Step 1 - Swapping:
// left=3 (10), right=0 (2): 10 > 2? YES → Swap
// arr1: [1, 4, 8, 2]
// arr2: [10, 3, 9]

// left=2 (8), right=1 (3): 8 > 3? YES → Swap
// arr1: [1, 4, 3, 2]
// arr2: [10, 8, 9]

// left=1 (4), right=2 (9): 4 > 9? NO → Break

// Step 2 & 3 - Sorting:
// arr1 sorted: [1, 2, 3, 4]
// arr2 sorted: [8, 9, 10]

// Output:
// Array 1: [1, 2, 3, 4]
// Array 2: [8, 9, 10]