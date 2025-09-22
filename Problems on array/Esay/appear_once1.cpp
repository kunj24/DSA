#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
int appear(int arr[],int n){
    if(n == 0) return -1;
    int max_val=0;
    map<int ,int > mpp;
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
    }
    for(auto it : mpp){
        if(it.second==1){
            return it.first;
        }
    }
    return -1;
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