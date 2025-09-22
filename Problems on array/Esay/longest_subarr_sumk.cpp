#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int longest_subarr_sumofk(vector<int>& arr, int n,int k){
    int len=0;
    for(int i=0;i<n;i++){   //2 3 5 1 9 sum=10 output is 3 2+3+5(maximum not 9+1 minimum)
        for(int j=i;j<n;j++){   //start from i 
            int s=0;    //every time sum=0
            for(int x = i; x <= j; x++){  
                s += arr[x];    //first time s=2 then 5 then 10
            }
            if(s == k) {        //if sum=k
                len = max(len, j - i + 1);  //then len=max(length and j-i+1(3-1+1)) 
            }       //suppose if we cover new len then compaer the len and j-i+1
        }       //like we cover the k=10 at 9+1 then max(3,j-i+1,4-3+1=2)
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