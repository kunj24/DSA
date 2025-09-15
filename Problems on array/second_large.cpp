#include<iostream>
using namespace std;
int secondlarge(int arr[],int n){
    int large=arr[0];
    int secondlarge=-1;
    for(int i=0;i<n;i++){
        if(arr[i]>large){
            secondlarge=large;
            large=arr[i];
        }
        else if(arr[i] < large && arr[i] > secondlarge) {
            secondlarge = arr[i];
        }
    } 
    return secondlarge;
}
int main(){
    int n;
    cout<<"Enter a number of element :";
    cin>>n;
    int arr[n];
    cout<<"Enter numbers :"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"The 2nd largest element is :"<<secondlarge(arr,n);

}    