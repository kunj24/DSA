#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int a[n];
    
    cout<<"Enter " << n << " numbers: ";
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    
    int start = 0;
    int end = n-1;
    
    // Reverse the array
    while(start < end){
        swap(a[start], a[end]);
        start++;
        end--;  // Decrement end, not increment
    }
    
    cout<<"Reversed array: ";
    for(int i=0; i<n; i++){
        cout<<a[i] << " ";
    }
    
    return 0;
}