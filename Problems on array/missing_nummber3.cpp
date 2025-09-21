#include<iostream>
#include<vector>
using namespace std;
int missing_num(vector<int>& arr, int n){
    int N=n-1;
    int xor1,xor2=0;
    for(int i=0;i<N;i++){
        xor2=xor2^arr[i];
        xor1=xor1^arr[i+1];
    }
    xor1=xor1^n;
    return xor1^xor2;
}

int main(){
    int n;
    cout << "Enter the maximum number n: ";
    cin >> n;
    vector<int> arr(n); 
    
    cout << "Enter " << n - 1 << " numbers from 1 to " << n << " in sequence :" << endl;
    for(int i = 0; i < n - 1; i++){
        cin >> arr[i];
    }
    
    int val = missing_num(arr, n);
    cout << "Missing number: " << val;
    
    return 0;
}