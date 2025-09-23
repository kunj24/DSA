#include<iostream>
#include<vector>
#include<map>
using namespace std;

vector<int> twoSum(int arr[], int n, int k){
    vector<int> ans;    //[2, 7, 11, 15] and k = 9
    map<int, int> mpp; // key: number, value: index
    
    for(int i = 0; i < n; i++){
        int current = arr[i];   //current = arr[0] = 2 needed = k - current = 9 - 2 = 7
        int needed = k - current;   //for i=2 current =7 and need =2 
        //mpp.find(7) != mpp.end() → False (7 not in map yet)So condition fails, skip the if-block
        if(mpp.find(needed) != mpp.end()){//for i=1 mpp.find(2) and it is true so push in the vector and return
            // Found the pair - return indices
            ans.push_back(mpp[needed]); // index of the needed number
            ans.push_back(i);           // current index
            return ans;
        }
        // Store current number with its index
        mpp[current] = i; //mpp[current] = i  → mpp[2] = 0
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