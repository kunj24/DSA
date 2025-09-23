#include<iostream>
#include<vector>
#include<map>
using namespace std;

vector<int> twoSum(int arr[], int n, int k){
    vector<int> ans;
    map<int, int> mpp; // key: number, value: index
    
    for(int i = 0; i < n; i++){
        int current = arr[i];
        int needed = k - current;
        
        if(mpp.find(needed) != mpp.end()){
            // Found the pair - return indices
            ans.push_back(mpp[needed]); // index of the needed number
            ans.push_back(i);           // current index
            return ans;
        }
        // Store current number with its index
        mpp[current] = i;
    }
    return ans; // return empty vector if no pair found
}

int main(){
    int n, k;
    cout << "Enter number of elements: ";
    cin >> n;
    
    // Use vector instead of variable-length array
    vector<int> arr(n);
    
    cout << "Enter numbers: " << endl;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    cout << "Enter target sum: ";
    cin >> k;
    
    vector<int> result = twoSum(arr.data(), n, k);
    
    if (!result.empty()) {
        cout << "Indices: " << result[0] << " " << result[1] << endl;
        cout << "Values: " << arr[result[0]] << " + " << arr[result[1]] << " = " << k << endl;
    } else {
        cout << "No such pair found." << endl;
    }
    
    return 0;
}