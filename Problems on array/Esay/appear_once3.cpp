#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int appear(int arr[],int n){
    int xor1=0; //1 1 2 3 3 
    for(int i=0;i<n;i++){
        xor1=xor1^arr[i]; //0^1 then 1^1=0 then 0^2=2 then 2^3=1 then 1^3=2
    }  // in sort 0 ^ 1 ^ 1 ^ 2 ^ 3 ^ 3 =(1 ^ 1) ^ (3 ^ 3) ^ 2 ^ 0 = 0 ^ 0 ^ 2 ^ 0 = 2                    
    return xor1; // so result is 2 
}
int main(){
    int n;
    cout<<"Enter a number of element :";
    cin>>n;
    int arr[n];
    cout<<"Enter numbers in all number in twice execpt one :"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int val=appear(arr,n);
    cout<<"The signle element is :"<<val;

}    