#include<iostream>
using namespace std;
int main(){
    int n;
    int hash[13]={0};
    cout<<"Enter a no of element to insert :";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    for(int i=0;i<n;i++){
        hash[arr[i]]+=1;
    }

    for(int i=1;i<=n;i++){
        cout<<i<<"appear in the input is :"<<hash[i]<<endl;
    }
    return 0;
}