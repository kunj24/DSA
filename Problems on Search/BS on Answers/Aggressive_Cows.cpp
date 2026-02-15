#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// =============================================================
// PROBLEM DESCRIPTION:
// -------------------------------------------------------------
// We are given positions of stalls.
// We must place k cows such that the minimum distance
// between any two cows is as large as possible.
//
// Return the maximum possible minimum distance.
// =============================================================


// -------------------------------------------------------------
// Check if we can place k cows with given distance
// -------------------------------------------------------------
bool Is_placed(vector<int>& arr, int n, int distance, int k){

    int previous_cow = arr[0];  // first cow placed
    int count_cow = 1;

    // try placing remaining cows
    for(int i = 1; i < n; i++){

        if(arr[i] - previous_cow >= distance){
            count_cow++;
            previous_cow = arr[i];
        }

        if(count_cow >= k)
            return true;
    }

    return false;
}



// -------------------------------------------------------------
// BRUTE FORCE solution
// Try every possible distance from 1 to max gap
// -------------------------------------------------------------
int calculate_cows(vector<int>& arr, int n, int k){

    sort(arr.begin(), arr.end());   // stalls must be sorted

    int max_distance = arr[n-1] - arr[0];

    for(int dist = 1; dist <= max_distance; dist++){

        if(!Is_placed(arr, n, dist, k)){
            return dist - 1;   // previous distance was valid
        }
    }

    return max_distance;
}



int main(){

    int n;
    cout << "Enter number of stalls: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter stall positions: " << endl;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int k;
    cout << "Enter how many cows to place: ";
    cin >> k;

    int ans = calculate_cows(arr, n, k);

    cout << "Maximum minimum distance: " << ans << endl;

    return 0;
}


// =============================================================
// ADDITIONAL EXPLANATION
// =============================================================
//
// PROBLEM IDEA:
// -------------------------------------------------------------
// We want cows to be placed as far apart as possible.
// So we try different minimum distances and check if placement
// is possible.
//
// -------------------------------------------------------------
// EXAMPLE:
// -------------------------------------------------------------
// stalls = [1, 2, 4, 8, 9]
// k = 3
//
// distance = 3
// place at 1, 4, 8
//
// minimum distance = 3
//
// Answer = 3
//
// -------------------------------------------------------------
// EDGE CASES:
// -------------------------------------------------------------
// 1. k = 1 → answer = 0
// 2. stalls not sorted → must sort first
// 3. k = n → answer = smallest adjacent gap
//
// -------------------------------------------------------------
// IMPORTANT LINES:
// -------------------------------------------------------------
// sort(arr.begin(), arr.end());
// - required for greedy placement
//
// arr[i] - previous_cow >= distance
// - spacing condition
//
// -------------------------------------------------------------
// TIME COMPLEXITY (BRUTE FORCE):
// -------------------------------------------------------------
// For each distance → O(n)
// Distances up to (max-min)
//
// Total = O(n * (max-min))
//
// -------------------------------------------------------------
// SPACE COMPLEXITY:
// -------------------------------------------------------------
// O(1)
//
// -------------------------------------------------------------
// NOTE:
// -------------------------------------------------------------
// This is brute-force.
// Optimal solution uses Binary Search → O(n log(max-min)).
//
// =============================================================
