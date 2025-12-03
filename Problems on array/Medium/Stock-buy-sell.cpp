#include<iostream>
#include<vector>
#include<map>
using namespace std;
int stockbuysell(vector<int>& arr, int n){      //715364
    int buy=arr[0];
    int profit=0;
    int cost,buyat,sellat;
    for(int i=1;i<n;i++){
        cost=arr[i]-buy;
        if(cost>profit) sellat=i;
        profit=max(profit,cost);
        if(arr[i]<buy) buyat=i;
        buy=min(buy,arr[i]);
    }
    cout<<"The stock is buy at :"<<buyat<<endl;
    cout<<"The stock is sell at :"<<sellat<<endl;
    return profit;
}
int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    
    cout << "Enter elements :" << endl;
    vector<int> arr(n);
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int ans=stockbuysell(arr,n);

    cout << "Max Profit is: " << ans << endl;
}


// i	arr[i]	buy	cost (arr[i]-buy)	profit
// 1	1	min(7,1)=1	1-1=0	max(0,0)=0
// 2	5	min(1,5)=1	5-1=4	max(0,4)=4
// 3	3	min(1,3)=1	3-1=2	max(4,2)=4
// 4	6	min(1,6)=1	6-1=5	max(4,5)=5
// 5	4	min(1,4)=1	4-1=3	max(5,3)=5
