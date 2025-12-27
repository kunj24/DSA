#include<iostream>
#include<map>
#include<vector>
using namespace std;

int sum(vector<int>& arr, int n, int key){   
    // Create a map to store frequency of prefix sums
    // key: prefix sum value, value: how many times it has appeared
    map<int, int> mpp;
    
    // Initialize with {0:1} because an empty subarray has sum 0
    // This handles cases where subarray starts from index 0
    mpp[0] = 1;
    
    int count = 0;      // Count of subarrays with sum = key
    int prevsum = 0;    // Running prefix sum
    
    // Traverse through the array
    for(int i = 0; i < n; i++){
        // Update the running prefix sum with current element
        prevsum += arr[i];
        
        // Calculate what previous prefix sum we need to remove
        // If current prefix sum = X, and we want sum = key
        // Then we need to find if we had prefix sum = (X - key) earlier
        int remove = prevsum - key;
        
        // Add to count the number of times we've seen this required prefix sum
        // Each occurrence means there's a subarray ending at current index with sum = key
        count += mpp[remove];
        
        // Store/update the frequency of current prefix sum in map
        mpp[prevsum] += 1;
    }

    // Return the total count of subarrays with sum = key
    return count;
}

int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    
    int key;
    cout << "Enter elements (can contain positive and negative numbers): " << endl;
    vector<int> arr(n);

    // Read array elements from user
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    cout << "Enter a key or target sum: " << endl;
    cin >> key;
    
    // Call function to count subarrays with sum = key
    int ans = sum(arr, n, key);
    
    // Output the result
    cout << "The number of subarrays with sum " << key << " is: " << ans << endl;
    
    return 0;
}

// Initial: mpp = {0:1}, count = 0, prevsum = 0

// i	arr[i]	prevsum	remove=prevsum-3	count += mpp[remove]	mpp[prevsum]++      mpp state
// 0	1	        1	        -2	            count += 0	            mpp[1]=1	    {0:1, 1:1}
// 1	2	        3	        0	            count += 1	            mpp[3]=1	    {0:1, 1:1, 3:1}
// 2	3	        6	        3	            count += 1	            mpp[6]=1	    {0:1, 1:1, 3:1, 6:1}
// 3	-3	        3	        0	            count += 1	            mpp[3]=2	    {0:1, 1:1, 3:2, 6:1}
// 4	1	        4	        1	            count += 1	            mpp[4]=1	    {0:1, 1:1, 3:2, 6:1, 4:1}
// 5	1	        5	        2	            count += 0	            mpp[5]=1	    {0:1, 1:1, 3:2, 6:1, 4:1, 5:1}
// 6	1	        6	        3	            count += 2	            mpp[6]=2	    {0:1, 1:1, 3:2, 6:2, 4:1, 5:1}
// 7	4	        10	        7	            count += 0	            mpp[10]=1	    {0:1, 1:1, 3:2, 6:2, 4:1, 5:1, 10:1}
// 8	2	        12	        9	            count += 0	            mpp[12]=1	    {0:1, 1:1, 3:2, 6:2, 4:1, 5:1, 10:1, 12:1}
// 9	-3	        9	        6	            count += 2	            mpp[9]=1	    {0:1, 1:1, 3:2, 6:2, 4:1, 5:1, 10:1, 12:1, 9:1}
// Final count = 0 + 1 + 1 + 1 + 1 + 0 + 2 + 0 + 0 + 2 = 8