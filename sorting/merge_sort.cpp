#include<iostream>
#include<vector>
using namespace std;

void merge(int arr[], int low, int mid, int high){
    vector<int> temp;
    int left_pointer = low;
    int right_pointer = mid + 1;

    while (left_pointer <= mid && right_pointer <= high) {
        if (arr[left_pointer] <= arr[right_pointer]) {  
            temp.push_back(arr[left_pointer]);
            left_pointer++;
        }
        else {
            temp.push_back(arr[right_pointer]);
            right_pointer++;
        }
    }
    
    // Copy remaining elements from left half
    while (left_pointer <= mid) {
        temp.push_back(arr[left_pointer]);
        left_pointer++;
    }
    
    // Copy remaining elements from right half
    while (right_pointer <= high) {
        temp.push_back(arr[right_pointer]);
        right_pointer++;
    }
    
    // Copy sorted elements back to original array
    for(int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void merge_sort(int arr[], int low, int high){
    if(low >= high) return;  //  Base candition
    
    int mid = low + (high - low) / 2;  
    
    merge_sort(arr, low, mid);
    merge_sort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter numbers:" << endl;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    merge_sort(arr, 0, n - 1);
    
    cout << "Sorted array using merge sort is:" << endl;
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }    
    cout << endl;
    
    return 0;
}