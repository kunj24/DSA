#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

//[-1, 0, 1, 2, -1, -4]

// Function to find all unique triplets that sum to 0
vector<vector<int>> Threesum(vector<int>& arr, int n){
    set<vector<int>> st;  // Set to store unique triplets
    
    // Brute force approach - check all combinations
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(int k = j + 1; k < n; k++){  
                if(arr[i] + arr[j] + arr[k] == 0){
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());  // Sort to identify duplicates
                    st.insert(temp);
                }
            }
        }
    }
    
    // Convert set to vector of vectors
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    
    cout << "Enter " << n << " elements: ";
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    vector<vector<int>> result = Threesum(arr, n);
    
    if(result.empty()){
        cout << "No triplets found that sum to 0" << endl;
    } else {
        cout << "Triplets that sum to 0:" << endl;
        for(int i = 0; i < result.size(); i++){
            cout << "[";
            for(int j = 0; j < result[i].size(); j++){
                cout << result[i][j];
                if(j < result[i].size() - 1) cout << ", ";
            }
            cout << "]" << endl;
        }
    }
    
    return 0;
}