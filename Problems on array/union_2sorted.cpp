#include<iostream>
#include <set>
#include<vector>
using namespace std;
vector<int> union_arr(vector<int>& arr1,vector<int>& arr2){
    int a=arr1.size();
    int b=arr2.size();
    int i=0;
    int j=0;
    vector<int> unionarr;
    while (i<a && j<b)
    {
        if(arr1[i]<=arr2[j]){
            if(unionarr.size()==0 ||
                unionarr.back()!=arr1[i]){
                    unionarr.push_back(arr1[i]);
            }
            i++;    
        }
        else{
            if(unionarr.size()==0 ||
                unionarr.back()!=arr2[j]){
                unionarr.push_back(arr2[j]);
            }
            j++;
        }
    }
    while (j<b)
    {
        if(unionarr.size()==0 ||
            unionarr.back()!=arr2[j]){
            unionarr.push_back(arr2[j]);
            }
        j++;
    }
    while (i<a)
    {
        if(unionarr.size()==0 ||
            unionarr.back()!=arr1[i]){
            unionarr.push_back(arr1[i]);
            }
        i++;   
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