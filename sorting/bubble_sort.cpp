#include<iostream>
using namespace std;
void bubble_sort(int arr[],int n){
    for(int i=0;i<n-1;i++){             //Largest element goes to the end at each -> 
        for(int j=0;j<n-i-1;j++){      //-> itreationso ignore the last element so n-i-1
            if(arr[j]>arr[j+1]){        
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
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

    bubble_sort(arr,n);
    cout<<"sorted array using selection sort is :"<<endl;

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }   
}    