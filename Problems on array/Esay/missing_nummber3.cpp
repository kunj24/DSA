#include<iostream>
#include<vector>
using namespace std;
int missing_num(vector<int>& arr, int n){
    int N=n-1;      //n = 5 and array [1, 2, 4, 5] (missing 3)
    int xor1,xor2=0; //i=0: xor2 = 0^1 = 1, xor1 = 0^1 = 1 
    for(int i=0;i<N;i++){ //i=1: xor2 = 1^2 = 3, xor1 = 1^2 = 3  
        xor2=xor2^arr[i];  //i=2: xor2 = 3^4 = 7, xor1 = 3^3 = 0
        xor1=xor1^(i+1);   //i=3: xor2 = 7^5 = 2, xor1 = 0^4 = 4
    }                   
    xor1=xor1^n;    //xor1 = 4 ^ 5 = 1  (XOR with n=5)
    return xor1^xor2;       // 1^2 =3
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