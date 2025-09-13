#include<iostream>
using namespace std;

void insertion_sort(int arr[], int n){
    for(int i = 1; i < n; i++) {  // ✅ Start from index 1
        int j = i;
        while (j > 0 && arr[j-1] > arr[j]) {  // ✅ Fixed condition
            int temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = temp;
            j--;
        }  // ✅ Added missing closing brace
    }
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

    insertion_sort(arr, n);
    cout << "Sorted array using insertion sort is:" << endl;  // ✅ Fixed message

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }   
    cout << endl;
    
    return 0;
}