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
        set<int>hashset;
        for(int j = i + 1; j < n; j++){
            int thirdelement=-(arr[i]+arr[j]);
            if(hashset.find(thirdelement) != hashset.end()){
                vector<int> temp={arr[i],arr[j],thirdelement};
                sort(temp.begin(),temp.end());
                 st.insert(temp);
            }
            hashset.insert(arr[j]);
            
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

// hashset = {} (empty)

// j = 1: arr[j] = 0
//   third = -(-1 + 0) = 1
//   Check if 1 exists in hashset? NO
//   Insert arr[j] = 0 into hashset
//   hashset = {0}

// j = 2: arr[j] = 1
//   third = -(-1 + 1) = 0
//   Check if 0 exists in hashset? YES ✓
//   Found triplet: [-1, 0, 1]
//   Insert arr[j] = 1 into hashset
//   hashset = {0, 1}

// j = 3: arr[j] = 2
//   third = -(-1 + 2) = -1
//   Check if -1 exists in hashset? NO
//   Insert arr[j] = 2 into hashset
//   hashset = {0, 1, 2}

// j = 4: arr[j] = -1
//   third = -(-1 + (-1)) = 2
//   Check if 2 exists in hashset? YES ✓
//   Found triplet: [-1, -1, 2]
//   Insert arr[j] = -1 into hashset
//   hashset = {0, 1, 2, -1}

// j = 5: arr[j] = -4
//   third = -(-1 + (-4)) = 5
//   Check if 5 exists in hashset? NO
//   Insert arr[j] = -4 into hashset
//   hashset = {0, 1, 2, -1, -4}


//   hashset = {} (reset for new i)

// j = 2: arr[j] = 1
//   third = -(0 + 1) = -1
//   Check if -1 exists in hashset? NO
//   Insert arr[j] = 1 into hashset
//   hashset = {1}

// j = 3: arr[j] = 2
//   third = -(0 + 2) = -2
//   Check if -2 exists in hashset? NO
//   Insert arr[j] = 2 into hashset
//   hashset = {1, 2}

// j = 4: arr[j] = -1
//   third = -(0 + (-1)) = 1
//   Check if 1 exists in hashset? YES ✓
//   Found triplet: [0, -1, 1] → Sorted: [-1, 0, 1] (duplicate)
//   Insert arr[j] = -1 into hashset
//   hashset = {1, 2, -1}

// j = 5: arr[j] = -4
//   third = -(0 + (-4)) = 4
//   Check if 4 exists in hashset? NO
//   Insert arr[j] = -4 into hashset
//   hashset = {1, 2, -1, -4}

//   i=0 (-1)                    i=1 (0)                    i=2 (1)
//    hashset={}                 hashset={}                 hashset={}
//    j=1: 0 → need 1? No       j=2: 1 → need -1? No       j=3: 2 → need -3? No
//         add 0                      add 1                      add 2
//    j=2: 1 → need 0? ✓       j=3: 2 → need -2? No       j=4: -1 → need -0? No
//         add 1                      add 2                      add -1
//         Found: [-1,0,1]           j=4: -1 → need 1? ✓
//    j=3: 2 → need -1? No           Found: [0,-1,1] 
//         add 2                            (duplicate)
//    j=4: -1 → need 2? ✓
//         add -1
//         Found: [-1,-1,2]
//    j=5: -4 → need 5? No
//         add -4