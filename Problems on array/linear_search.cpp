#include<iostream>
#include<vector>
using namespace std;
int linear_search(vector<int>& arr,int n,int s){

    for(int i=0;i<n;i++){
        if(arr[i]==s){
            return i;
        }
    }
    return -1;
}
int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
   vector<int> arr(n);
 
    cout << "Enter numbers :" << endl;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int s;
    cout<<"Enter a number that you need to search :";
    cin>>s;
    int val=linear_search(arr, n, s);
    cout<<"The number is at "<<val<<"index";

    return 0;
}