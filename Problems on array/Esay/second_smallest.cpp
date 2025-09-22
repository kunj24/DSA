#include<iostream>
using namespace std;
int secondsmall(int arr[],int n){
    int smallest=arr[0];
    int secondsmallest=INT_MAX;
    for(int i=0;i<n;i++){       
        if(arr[i]<smallest){       
            secondsmallest=smallest;  
            smallest=arr[i];
        }
        else if(arr[i]!=smallest && arr[i] < secondsmallest) {
            secondsmallest = arr[i];
        }
    } 
    return secondsmallest;
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

    cout<<"The 2nd smallest element is :"<<secondsmall(arr,n);

}    