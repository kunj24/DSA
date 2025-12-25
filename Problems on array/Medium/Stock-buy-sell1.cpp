#include<iostream>
#include<vector>
#include<map>
using namespace std;
int stockbuysell(vector<int>& arr, int n){      //715364
    int price=INT_MAX;
    int profit=0;   
    for(int i=0;i<n;i++){
        if(price>arr[i]){
            price=arr[i];
        }
        else{
            profit=max(profit,arr[i]-price);
        }
    }
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


// Trace with Example: [7, 1, 5, 3, 6, 4]

// i	arr[i]	price(INT_MAX)	Condition	    Action	        profit
// 0	7	    INT_MAX	        price(∞) > 7	price=7	        0
// 1	1	    7	            price(7) > 1	price=1	        0
// 2	5	    1	            price(1) < 5	else	        max(0,4)=4
// 3	3	    1	            price(1) < 3	else	        max(4,2)=4
// 4	6	    1	            price(1) < 6	else	        max(4,5)=5
// 5	4	    1               price(1) < 4	else	        max(5,3)=5
