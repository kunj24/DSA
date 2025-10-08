#include<iostream>
#include<vector>
using namespace std;
vector<int> sort(int arr[],int n){
    vector<int>result;
    int hash[3]={0};
    for(int i=0;i<n;i++){
        hash[arr[i]]++;
    }
    // Add 0s
    for(int i = 0; i < hash[0]; i++){
        result.push_back(0);
    }
    // Add 1s
    for(int i = 0; i < hash[1]; i++){
        result.push_back(1);
    }
    // Add 2s
    for(int i = 0; i < hash[2]; i++){
        result.push_back(2);
    }
    return result;
}
int main(){
    int n,k;
    cout<<"Enter a number of element :";
    cin>>n;
    int arr[n];
    cout<<"Enter numbers with only 0,1 and 2:"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> val = sort(arr, n);
    
    cout << "Sorted array: ";
    for(int num : val){
        cout << num << " ";
    }
    
    cout << endl;
}    