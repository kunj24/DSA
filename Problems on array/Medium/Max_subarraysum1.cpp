#include<iostream>
#include<vector>
#include<map>
using namespace std;
int subarraysum(vector<int>& arr, int n){
    int maxsum=INT_MIN;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum=sum+arr[j];
            maxsum=max(maxsum,sum);
        }
    }
    return maxsum;
}
int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    
    cout << "Enter elements you can also add negative :" << endl;
    vector<int> arr(n);
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int ans=subarraysum(arr,n);

    cout << "Maximum subarray sum is: " << ans << endl;


}