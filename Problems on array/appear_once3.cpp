#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int appear(int arr[],int n){
    int xor1=0; 
    for(int i=0;i<n;i++){
        xor1=xor1^arr[i];
    }
    return xor1;
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