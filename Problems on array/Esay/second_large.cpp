#include<iostream>
using namespace std;
int secondlarge(int arr[],int n){
    int large=arr[0];
    int secondlarge=-1;
    for(int i=0;i<n;i++){       //in that case if we 1,2,3,5,5
        if(arr[i]>large){       //then it give 3 as 2nd largest 
            secondlarge=large;  //in sorting it give 5 as 2nd largest
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