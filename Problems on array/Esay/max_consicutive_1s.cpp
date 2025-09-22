#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int count_1(vector<int>& arr, int n){
    int count=0;
    int maxcount=0;

    for(int i=0;i<n;i++){
        if(arr[i]==1){
            count++;
            maxcount=max(maxcount,count);
        }
        else{
            count=0;
        }
    }
    return maxcount;
}

int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> arr(n);
 
    cout << "Enter numbers with 0 and 1 only :" << endl;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int val = count_1(arr, n);
    cout<<"Number of maximum consicutive 1's is :"<<val<<endl;
    return 0;
}