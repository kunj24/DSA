#include<iostream>
#include <set>
#include<vector>
using namespace std;
vector<int> union_arr(vector<int>& arr1,vector<int>& arr2){
    int a=arr1.size();  //1 1 2 3 4 5
    int b=arr2.size();  //2 3 4 4 5 6
    int i=0;
    int j=0;
    vector<int> unionarr;
    while (i<a && j<b)
    {           
        if(arr1[i]<=arr2[j]){   //1<2
            if(unionarr.size()==0 ||  //first time so push the 1
                unionarr.back()!=arr1[i]){ // then i++ 1<2 push the 1 but 
                    unionarr.push_back(arr1[i]); //it has already 1 so check the .back!=arr[i]
            }               //if yes then i++ 2<2 .back!=a[i] 1!=2 push the 2 i++
            i++;    
        }
        else{       //3>2 so insert 2 but there is alreay 2 so j++ same process
            if(unionarr.size()==0 ||
                unionarr.back()!=arr2[j]){
                unionarr.push_back(arr2[j]);
            }
            j++;
        }
    }
    while (j<b) // 1 2  //3 4 5 there is two array if one array os ending then 
    {           //insert all element of array 2 same for array 1
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