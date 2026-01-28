#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

// Gap method for in-place merging (Shell Sort approach)
void MergeInPlaceGapMethod(vector<int>& arr1, vector<int>& arr2, int n, int m){
    int total = n + m;
    int gap = (total + 1) / 2;  // Ceil division
    
    while(gap > 0){
        int i = 0;
        int j = gap;
        
        while(j < total){
            // Compare and swap elements
            if(i < n && j < n){  // Both in arr1
                if(arr1[i] > arr1[j]){
                    swap(arr1[i], arr1[j]);
                }
            }
            else if(i < n && j >= n){  // i in arr1, j in arr2
                int j_idx = j - n;
                if(arr1[i] > arr2[j_idx]){
                    swap(arr1[i], arr2[j_idx]);
                }
            }
            else{  // Both in arr2
                int i_idx = i - n;
                int j_idx = j - n;
                if(arr2[i_idx] > arr2[j_idx]){
                    swap(arr2[i_idx], arr2[j_idx]);
                }
            }
            i++;
            j++;
        }
        
        if(gap == 1) break;
        gap = (gap + 1) / 2;  // Next gap (ceil division)
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
    MergeInPlaceGapMethod(arr1, arr2, n, m);
    
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