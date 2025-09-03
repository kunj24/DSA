#include<iostream>
using namespace std;

void reverse(int i,int a[],int n){
    if(i<n/2){
        swap(a[i],a[n-i-1]);
        reverse(i+1,a,n);
    }
    else return;
}

int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int a[n];
    
    cout<<"Enter " << n << " numbers: ";
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    
    reverse(0,a,n);
    
    cout<<"Reversed array: ";
    for(int i=0; i<n; i++){
        cout<<a[i] << " ";
    }
    
    return 0;
}