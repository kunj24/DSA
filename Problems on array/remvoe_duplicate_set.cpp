#include<iostream>
#include <set>
using namespace std;
int removeDuplicates(int arr[],int n){
    set<int> s;
    for(int i=0;i<n;i++){
        s.insert(arr[i]);
    }
    cout << "Array after removing duplicates: ";
    for(auto it: s){
        cout<<it<<" ";
    }
    return s.size();
}
int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    
    int arr[n];
    cout << "Enter numbers (should be sorted and shold be duplicate):" << endl;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    int newSize = removeDuplicates(arr, n);
    
    cout << "Number of unique elements: " << newSize << endl;
    
    return 0;
}