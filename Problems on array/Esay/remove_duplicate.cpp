#include<iostream>
using namespace std;

int removeDuplicates(int arr[], int n){
    int i = 0;
    for(int j = 1; j < n; j++){
        if(arr[i] != arr[j]){
            i++;
            arr[i] = arr[j];
        }
    }
    return i + 1;
}

int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    
    int arr[n];
    cout << "Enter numbers (should be sorted and shold be duplicate):" << endl;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    int newSize = removeDuplicates(arr, n);
    
    cout << "Array after removing duplicates: ";
    for(int i = 0; i < newSize; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    
    cout << "Number of unique elements: " << newSize << endl;
    
    return 0;
}