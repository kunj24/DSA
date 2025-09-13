#include<iostream>
using namespace std;
void selection_sort(int a[],int n){
    for(int i=0;i<n-2;i++){
        int min=i;
        for(int j=i+1;j<=n-1;j++){
            if(a[min]>a[j]){       // [5, 2, 8, 1, 3] if(a[i] > a[j]) min=j if we do that
                min=j;          // j = 0: 5 > 5? → No  j = 1: 5 > 2? → Yes → min = 1
            }                   //j = 3: 5 > 1? → Yes → min = 3 (overwrites previous min!)
        }                     //j = 4: 5 > 3? → Yes → min = 4 (overwrites again!)    
        int temp = a[min];  //Result: min = 4 (wrong! The actual minimum is at index 3 with value 1)
        a[min] = a[i];      //if(a[j] < a[min]) min =j
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