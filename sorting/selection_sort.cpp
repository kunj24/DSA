#include<iostream>
using namespace std;
void selection_sort(int a[],int n){
    for(int i=0;i<n-2;i++){
        int min=i;
        for(int j=i+1;j<=n-1;j++){
            if(a[min]>a[j]){
                min=j;
            }
        }
        int temp = a[min];
        a[min] = a[i];
        a[i] = temp;
    }
}
int main(){
    int n;
    cout<<"Enter a number of element :";
    cin>>n;
    int a[n];
    cout<<"Enter numbers :"<<endl;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    selection_sort(a,n);
    cout<<"sorted array is :"<<endl;

    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }    
    
}