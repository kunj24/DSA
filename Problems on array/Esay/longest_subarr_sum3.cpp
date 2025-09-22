#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int longest_subarr_sumofk(vector<int>& arr, int n,int k){
    int left=0,right=0;
    int sum=arr[0],maxlength=0;
    while (right<n)
    {
        while (left<=right && sum>k)
        {
            sum-=arr[left];
            left++;
        }
        if(sum==k){
            maxlength=max(maxlength,right-left+1);
        }
        
        right++;
        if(right<n) sum+=arr[right];
    }
    return maxlength;
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