#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

// Function to find all unique triplets that sum to 0
vector<vector<int>> Threesum(vector<int>& arr, int n){
    vector<vector<int>>ans;
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        if(i>0 && arr[i]==arr[i-1]) continue;
        int j=i+1;
        int k=n-1;  
        while (j<k)
        {
            int sum=arr[i]+arr[j]+arr[k];
            if(sum<0){
                j++; 
            }
            else if(sum>0){
                k--;
            }
            else{
                vector<int> temp ={arr[i],arr[j],arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                while( j<k && arr[j]==arr[j-1]) j++;
                while( j<k && arr[k]==arr[k+1]) k--;
            }

        }
        
    }
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

// Input: arr = [-4, -1, -1, 0, 1, 2] (sorted)

// Iteration 1: i = 0 (arr[i] = -4)

// j = 1 (-1), k = 5 (2)
// Sum = -4 + (-1) + 2 = -3 < 0 → j++

// j = 2 (-1), k = 5 (2)
// Sum = -4 + (-1) + 2 = -3 < 0 → j++

// j = 3 (0), k = 5 (2)
// Sum = -4 + 0 + 2 = -2 < 0 → j++

// j = 4 (1), k = 5 (2)
// Sum = -4 + 1 + 2 = -1 < 0 → j++

// j = 5, k = 5 → loop ends (j >= k)


// Iteration 2: i = 1 (arr[i] = -1)


// j = 2 (-1), k = 5 (2)
// Sum = -1 + (-1) + 2 = 0 ✓ → Found [-1, -1, 2]
// Move: j=3, k=4
// Skip duplicates: none

// j = 3 (0), k = 4 (1)
// Sum = -1 + 0 + 1 = 0 ✓ → Found [-1, 0, 1]
// Move: j=4, k=3 → loop ends (j >= k)


// Iteration 3: i = 2 (arr[i] = -1)

// Skip because arr[2] == arr[1] (duplicate)


// Iteration 4: i = 3 (arr[i] = 0)


// j = 4 (1), k = 5 (2)
// Sum = 0 + 1 + 2 = 3 > 0 → k--
// j = 4, k = 4 → loop ends


// Sorted array: [-4, -1, -1, 0, 1, 2]
// Index:          0   1   2   3  4  5

// i=0 (-4):
//   j=1 (-1), k=5 (2): -4-1+2 = -3 < 0 → j++
//   j=2 (-1), k=5 (2): -4-1+2 = -3 < 0 → j++
//   ... continues

// i=1 (-1):
//   j=2 (-1), k=5 (2): -1-1+2 = 0 ✓
//   j=3 (0), k=4 (1): -1+0+1 = 0 ✓

// i=2 (-1): Skip (duplicate)

// i=3 (0):
//   j=4 (1), k=5 (2): 0+1+2 = 3 > 0 → k--
//   Done