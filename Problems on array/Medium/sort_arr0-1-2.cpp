#include<iostream>
#include<vector>
using namespace std;
vector<int> sort(int arr[],int n){
    vector<int>result;
    int hash[3]={0};
    for(int i=0;i<n;i++){
        hash[arr[i]]++;
    }
    for(int i=0;i<n;i++){
        if(arr[i] >= 0 && arr[i] <= 2){
            hash[arr[i]]++;
        }
    }
    for(int i = 0; i < 3; i++){ // For values 0,1,2
        for(int j = 0; j < hash[i]; j++){
            result.push_back(i);
        }
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