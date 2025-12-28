#include<iostream>
#include<vector>
#include<map>
using namespace std;

// in Array the leader is everything to the right side is smaller from the element 
// 10, 22, 12, 3, 0, 6 leader element is 22,12,6 
// because to the right side of the 22,12,6 every element is smaller then the leader element
vector<int> leader(vector<int>& arr, int n){

    vector<int>ans;

    for(int i=0;i<n;i++){   //10 22 12 3 0 6 leader is : 22 12 6
        bool leader=true;
        for(int j=i;j<n;j++){
            if(arr[i]<arr[j]){
                leader=false;   // Found a larger element on the right → NOT a leader
                break;
            }
        }
        if(leader){
            ans.push_back(arr[i]);
        }
    }
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
