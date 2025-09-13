#include<iostream>
using namespace std;
void selection_sort(int a[],int n){
    for(int i=0;i<n-2;i++){
        int min=i;
        for(int j=i;j<=n;j++){
            if(a[i]>a[j]){
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

    cout<<"";
    cout<<"sorted array is :"<<endl;

    for(int i=1;i<=n;i++){
        cout<<a[i];
    }    
    
}