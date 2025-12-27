#include<iostream>
#include<vector>
#include<map>
using namespace std;
int subarraysum(vector<int>& arr, int n){
    int maxsum=INT_MIN;
    int sum=0;
    int startindex,endindex;
    for(int i=0;i<n;i++){
        if(sum==0) startindex=i;
        sum+=arr[i];            // -2,-3,4,-1,-2,1,5,-3 sum=-2 
        if(sum>maxsum){ // for i=2 sum=4 i=4 sum=1 still positive then i=6 sum is 7 so max is 7
            maxsum=sum;
            endindex=i;
        }
        if(sum<0){      //no need to carry negative number if sum is negative so -2,-3 skip
            sum=0;       
        }   
    }
    cout<<"Starting index of the sum is "<<startindex<<endl;
    cout<<"Ending index of the sum is "<<endindex<<endl;
    cout<<"Subarray sum's array is : ";
    for(int i=startindex;i<=endindex;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
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