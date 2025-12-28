#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> leader(vector<int>& arr, int n){    //10 22 12 3 0 6

    vector<int>ans;
    int maxi=INT_MIN;
    for(int i=n-1;i>=0;i--){

        if(arr[i]>maxi){    
            ans.push_back(arr[i]);      
        }
        maxi=max(maxi,arr[i]);
    }
    //output is 6 12 22 so u can use sort or reverse to make output like 22 12 6
    reverse(ans.begin(), ans.end());    //Reverse to restore left-to-right order
    return ans;
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

    vector<int> ans = leader(arr, n);
    
    cout << "Leaders are : ";
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    
}
