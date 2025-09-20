#include<iostream>
#include <map>
#include<vector>
using namespace std;
vector<int> union_arr(vector<int>& arr1,vector<int>& arr2){
    int a=arr1.size();  //[1, 2, 3, 3] (a = 4)
    int b=arr2.size();  //[3, 4, 5] (b = 3)



    vector<int> unionarr;
    map<int,int> freq;
    for(int i=0;i<a;i++){
        freq[arr1[i]]++;   //{1:1, 2:1, 3:2}
    }
    for(int i=0;i<a;i++){
        freq[arr2[i]]++;  //{1:1, 2:1, 3:3, 4:1, 5:1}
    }
    for(auto it: freq){
        unionarr.push_back(it.first);
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