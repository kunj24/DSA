#include<iostream>
using namespace std;
int appear(int arr[],int n){

    for(int i=0;i<n;i++){
        int num=arr[i];
        int count=0;
        for(int j=0;j<n;j++){
            if(arr[j]==num){
                count++;
            }
        }
        if(count==1){
            return num;
        }
    }
    return 0;
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