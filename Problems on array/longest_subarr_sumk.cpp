#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int longest_subarr_sumofk(vector<int>& arr, int n,int k){
    int len=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int s=0;
            for(int x = i; x <= j; x++){  
                s += arr[x];
            }
            if(s == k) {
                len = max(len, j - i + 1);
            }
        }
    }
    return len;
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
    int k;
    cout<<"Enter a number for longest sub array of sum :";
    cin>>k;
    int val = longest_subarr_sumofk(arr, n,k);
    cout<<"The length of the longest subarray is :"<<val<<endl;
    return 0;
}