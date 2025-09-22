#include<iostream>
#include <set>
using namespace std;
int removeDuplicates(int arr[],int n){
    set<int> s;
    for(int i=0;i<n;i++){
        s.insert(arr[i]);   //set is used for the removing the duplicate and store it
    }                       //for more go to stl and then set
    cout << "Array after removing duplicates: ";
    for(auto it: s){
        cout<<it<<" ";
    }
    cout<<endl;
    return s.size();
}
int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    
    int arr[n];
    cout << "Enter numbers (shold be duplicate or sorted or unsorted):" << endl;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    int newSize = removeDuplicates(arr, n);

    cout << "Number of unique elements: " << newSize << endl;
    
    return 0;
}