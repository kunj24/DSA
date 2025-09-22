#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int longest_subarray_sum_k(vector<int>& arr, int n, long long k) {
    unordered_map<long long, int> prefix_sum; // Stores prefix_sum -> index
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