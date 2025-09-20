#include<iostream>
#include <set>
#include<vector>
using namespace std;
vector<int> union_arr(vector<int>& arr1,vector<int>& arr2){
    int a=arr1.size();  //1 1 2 3 4 5
    int b=arr2.size();  //2 3 4 4 5 6

    vector<int> unionarr;
    
    for(int i=0;i<a;i++){

    }
    return unionarr; 
}
int main(){
    int n,m;
    cout << "Enter number of elements of 1: ";
    cin >> n;
    vector<int>arr1(n);
    cout << "Enter numbers (shold be sorted ):" << endl;
    for(int i = 0; i < n; i++){
        cin >> arr1[i];
    }
    cout << "Enter number of elements of 2: ";
    cin >> m;
    vector<int>arr2(m);
    cout << "Enter numbers (shold be sorted ):" << endl;
    for(int i = 0; i < m; i++){
        cin >> arr2[i];
    }
    
    vector<int> result = union_arr(arr1, arr2);  
    
    cout << "Union of arrays: ";  
    for(int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}