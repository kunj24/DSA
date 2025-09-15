#include<iostream>
#include<vector>
#include<algorithm>  // Needed for sort();
using namespace std;
int sortArr(vector<int> &arr){
    sort(arr.begin(),arr.end());  //this only work when array last 2 element is unique
    return arr[arr.size()-2];

}
int main(){
    int n;
    cout<<"Enter a number of element :";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter numbers :"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"largest element is :"<<sortArr(arr);
}    