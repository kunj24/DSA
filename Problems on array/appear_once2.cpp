#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int appear(int arr[],int n){
    if(n == 0) return -1;
    int max_val=0;
    for(int i=0;i<n;i++){       //1 1 2 3 3
        max_val=max(max_val,arr[i]);   // max_val =3
    }                                 //max is 3 so hash[0,1,2,3] so hash is 4   
    vector<int> hash(max_val + 1, 0);   //hash of 4 all are 0

    for(int i=0;i<n;i++){
        hash[arr[i]]++;     // hash[1]=2,[2]=1,[3]=2
    }

    for(int i=0;i<=max_val;i++){
        if(hash[i]==1){     
            return i;
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