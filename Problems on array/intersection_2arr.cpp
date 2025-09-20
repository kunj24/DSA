#include<iostream>
#include<vector>
#include<algorithm>//for min(a,b) function
using namespace std;
vector<int> intersection_arr(vector<int>& arr1,vector<int>& arr2){
    int a=arr1.size();  //1 1 2 3 4 5
    int b=arr2.size();  //2 3 4 4 5 6
    int i=0;
    int j=0;
    vector<int> intersecarr;
    while (i<a && j<b)
    {
        if(arr1[i]<arr2[j]){
            i++;
        }
        else if (arr1[i]>arr2[j])
        {
            j++;
        }
        else{
            intersecarr.push_back(arr1[i]);
            i++;
            j++;
        }

    }
    
    return intersecarr; 
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
    
    vector<int> result = intersection_arr(arr1, arr2);  
    
    cout << "Inersection of arrays with more than one duplicate is : ";  
    for(int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}