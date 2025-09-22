#include<iostream>
#include<vector>
#include<map>
using namespace std;

                    // check the example after the main function 

int longest_subarray_sum_k(vector<int>& arr, int n, long long k) {
    map<long long, int> prefix_sum; // Stores prefix_sum -> index
    long long current_sum = 0;          // 2 1 0 0 3 k=3 ans is =4
    int max_length = 0;
    
    for(int i = 0; i < n; i++) {
        // Step 1: Add current element to the running sum
        current_sum += arr[i];  // for i=0 s=2,i=1 s=3 

        // Step 2: If current sum equals k, entire subarray from start to i is valid
        if(current_sum == k) {
            max_length = i + 1; // Length = index + 1   //max=2 for i=1
        }
        
        // Step 3: Check if we've seen (current_sum - k) before
        long long remaining = current_sum - k;
        if(prefix_sum.find(remaining) != prefix_sum.end()) {    
            int length = i - prefix_sum[remaining];
            max_length = max(max_length, length);
        }
        
        // Step 4: Store the first occurrence of this prefix sum
        if(prefix_sum.find(current_sum) == prefix_sum.end()) {
            prefix_sum[current_sum] = i;
        }
    }
    
    return max_length;
}

int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter numbers: " << endl;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    long long k;
    cout << "Enter the target sum k: ";
    cin >> k;
    
    int result = longest_subarray_sum_k(arr, n, k);
    cout << "The length of the longest subarray with sum " << k << " is: " << result << endl;
    
    return 0;
}
/*
EXAMPLE: Array [2, 1, 0, 0, 3] with k = 3

Step-by-step execution:

Initial: prefix_sum = {0:-1}, current_sum = 0, max_length = 0

i=0: arr[0]=2
  current_sum = 0+2 = 2
  Check: 2 == 3? ❌
  remaining = 2-3 = -1 (not in map)
  Store: prefix_sum[2] = 0
  prefix_sum = {0:-1, 2:0}, max_length = 0

i=1: arr[1]=1
  current_sum = 2+1 = 3
  Check: 3 == 3? ✅ → max_length = max(0, 1+1) = 2
  remaining = 3-3 = 0 (found at index -1)
  length = 1 - (-1) = 2 → max_length = max(2,2) = 2
  Store: prefix_sum[3] = 1
  prefix_sum = {0:-1, 2:0, 3:1}, max_length = 2

i=2: arr[2]=0
  current_sum = 3+0 = 3
  Check: 3 == 3? ✅ → max_length = max(2, 2+1) = 3
  remaining = 3-3 = 0 (found at index -1)
  length = 2 - (-1) = 3 → max_length = max(3,3) = 3
  prefix_sum[3] already exists → skip
  prefix_sum = {0:-1, 2:0, 3:1}, max_length = 3

i=3: arr[3]=0
  current_sum = 3+0 = 3
  Check: 3 == 3? ✅ → max_length = max(3, 3+1) = 4
  remaining = 3-3 = 0 (found at index -1)
  length = 3 - (-1) = 4 → max_length = max(4,4) = 4
  prefix_sum[3] already exists → skip
  prefix_sum = {0:-1, 2:0, 3:1}, max_length = 4

i=4: arr[4]=3
  current_sum = 3+3 = 6
  Check: 6 == 3? ❌
  remaining = 6-3 = 3 (found at index 1)
  length = 4 - 1 = 3 → max_length = max(4,3) = 4
  Store: prefix_sum[6] = 4
  prefix_sum = {0:-1, 2:0, 3:1, 6:4}, max_length = 4

Final result: 4

Valid subarrays with sum 3:
1. [2,1]           → indices 0-1 → sum=3, length=2
2. [2,1,0,0]       → indices 0-3 → sum=3, length=4 ← LONGEST
3. [0,0,3]         → indices 2-4 → sum=3, length=3
4. [3]             → index 4    → sum=3, length=1
*/