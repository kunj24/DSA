#include<iostream>
#include<vector>
using namespace std;
int missing_num(vector<int>& arr, int n){
    for(int i=1;i<=n;i++){
        int flag=0;
        for(int j=0;j<n-1;j++){
            if(arr[j]==i){
                flag=1;
                break;
            }
        }
        if(flag==0){
            return i;
        }
    }
    return -1;
}

int main(){
    int n;
    cout << "Enter the maximum number n: ";
    cin >> n;
    vector<int> arr(n - 1); // Array should have n-1 elements
    
    cout << "Enter " << n - 1 << " numbers from 1 to " << n << "in sequence :" << endl;
    for(int i = 0; i < n - 1; i++){
        cin >> arr[i];
    }
    
    int val = missing_num(arr, n);
    cout << "Missing number: " << val;
    
    return 0;
}