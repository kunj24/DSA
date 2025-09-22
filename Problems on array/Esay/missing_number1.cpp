#include<iostream>
#include<vector>
using namespace std;
int missing_num(vector<int>& arr, int n){
    int hash[n+1]={0};  //declare the n+1 size array
    for(int i=0;i<n;i++){   // 1 2 4 5 
        hash[arr[i]]++;     //hash[0,3]=0
    }                       //hash[1,2,4,5]=1        
    for(int i=1;i<=n;i++){  //starting from 1 so index 3 is 0 so missing is 3
        if(hash[i]==0){
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
    
    cout << "Enter " << n - 1 << " numbers from 1 to " << n << " in sequence :" << endl;
    for(int i = 0; i < n - 1; i++){
        cin >> arr[i];
    }
    
    int val = missing_num(arr, n);
    cout << "Missing number: " << val;
    
    return 0;
}