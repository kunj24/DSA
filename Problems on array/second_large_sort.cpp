#include<iostream>
#include<vector>
#include<algorithm>  // Needed for sort();
using namespace std;
void sortArr(vector<int> &arr){
    sort(arr.begin(),arr.end());  //this only work when array last 2 element is unique
    cout<<"largest elemnt is : "<<arr[arr.size()-1]<<endl;
    cout<<"2nd largest elment is : "<<arr[arr.size()-2];
    // 1,2,3,4,4 so largest=4 2nd largest=4 but we want 2nd largest is 3
}
int main(){
    int n;
    cout<<"Enter a number of element :";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter numbers unique number :"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sortArr(arr);
}    