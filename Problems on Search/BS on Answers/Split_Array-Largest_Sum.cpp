#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


// =============================================================
// PROBLEM DESCRIPTION:
// -------------------------------------------------------------
// Split array into k contiguous subarrays such that
// the largest subarray sum is minimized.
// Return that minimum possible largest sum.
// =============================================================



// =============================================================
// FUNCTION: countPartitions
// -------------------------------------------------------------
// For a given maxAllowedSum,
// count how many partitions are required.
//
// Greedy:
// Keep adding until limit exceeded → new partition
// =============================================================
int countPartitions(vector<int>& arr, int n, int maxAllowedSum){

    int currentSum = 0;
    int partitions = 1;

    for(int i = 0; i < n; i++){

        if(currentSum + arr[i] <= maxAllowedSum){
            currentSum += arr[i];
        }
        else{
            partitions++;
            currentSum = arr[i];
        }
    }

    return partitions;
}



// =============================================================
// BRUTE FORCE (Linear + Linear)
// Time: O(n * sum)
// =============================================================
int splitArrayLinear(vector<int>& arr, int n, int k){

    int low = *max_element(arr.begin(), arr.end());

    int high = 0;
    for(int x : arr) high += x;

    for(int limit = low; limit <= high; limit++){

        if(countPartitions(arr, n, limit) <= k){
            return limit;
        }
    }

    return -1;
}



// =============================================================
// BINARY SEARCH (Optimal)
// Time: O(n log sum)
// =============================================================
int splitArrayBinary(vector<int>& arr, int n, int k){

    int low = *max_element(arr.begin(), arr.end());

    int high = 0;
    for(int x : arr) high += x;

    int answer = high;

    while(low <= high){

        int mid = low + (high - low) / 2;

        int needed = countPartitions(arr, n, mid);

        // if valid, try smaller
        if(needed <= k){
            answer = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    return answer;
}



int main(){

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements: " << endl;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int k;
    cout << "Enter number of splits: ";
    cin >> k;

    // choose optimal
    int ans = splitArrayBinary(arr, n, k);

    cout << "Minimum largest subarray sum: " << ans << endl;
    cout<<"Check the painter's Partition Problem this is the part of this ";

    return 0;
}
