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
void RotateToLeft(int arr[],int n,int k){
    Reverse(arr,0,k-1);
    Reverse(arr,k,n-1);
    Reverse(arr,0,n-1);
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