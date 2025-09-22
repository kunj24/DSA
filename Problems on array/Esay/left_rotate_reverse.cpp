#include<iostream>
using namespace std;
void Reverse(int arr[],int start,int end){
    while (start<=end)
    {
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }
    
}
void RotateToLeft(int arr[],int n,int k){ //1 2 3 4 5 k=2
    Reverse(arr,0,k-1); // Reverse first k elements 2 1 3 4 5
    Reverse(arr,k,n-1); // Reverse remaining elements 2 1 5 4 3
    Reverse(arr,0,n-1); // Reverse entire array 3 4 5 1 2 (answere)
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
}