#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

vector<int> calculate(vector<int>& arr, int n){
    vector<int> result;
    unordered_map<int, int> freq;
    
    // Count frequency of each element
    for(int i = 0; i < n; i++){
        freq[arr[i]]++;
    }
    
    // Check which elements appear more than n/3 times
    for(auto& pair : freq){
        if(pair.second > n/3){ 
            result.push_back(pair.first);
        }
    }

    return result;
}

int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    
    cout << "Enter " << n << " elements: " << endl;
    vector<int> arr(n);
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    vector<int> ans = calculate(arr, n);
    
    if(ans.empty()){
        cout << "No element appears more than n/3 times" << endl;
    } else {
        cout << "Elements appearing more than n/3 times: ";
        for(int i = 0; i < ans.size(); i++){
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}