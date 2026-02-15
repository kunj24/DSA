#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// =============================================================
// PROBLEM DESCRIPTION:
// -------------------------------------------------------------
// We are given positions of stalls (sorted or unsorted).
// We must place k cows in these stalls such that the
// MINIMUM distance between any two cows is MAXIMIZED.
//
// Return that maximum possible minimum distance.
// =============================================================



// =============================================================
// FUNCTION: Check if cows can be placed with given distance
// -------------------------------------------------------------
// Greedy placement:
// Place first cow at first stall,
// then place next cow only if distance condition satisfied
// =============================================================
bool Is_placed(vector<int>& arr, int n, int distance, int k){

    int count_cow = 1;           // first cow already placed
    int previous = arr[0];

    for(int i = 1; i < n; i++){

        if(arr[i] - previous >= distance){
            count_cow++;
            previous = arr[i];
        }

        if(count_cow >= k)
            return true;
    }

    return false;
}



// =============================================================
// BINARY SEARCH SOLUTION (OPTIMAL)
// -------------------------------------------------------------
// distance range = [1, max-min]
// maximize minimum distance
// =============================================================
int calculate_cows(vector<int>& arr, int n, int k){

    sort(arr.begin(), arr.end());   // IMPORTANT: stalls must be sorted

    int low = 1;
    int high = arr[n-1] - arr[0];

    int ans = 0;

    while(low <= high){

        int mid = low + (high - low) / 2;

        // If cows can be placed, try bigger distance
        if(Is_placed(arr, n, mid, k)){
            ans = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }

    return ans; //or return high
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
// We want cows to be as far apart as possible.
// So we maximize the minimum distance.
//
// This is a "Binary Search on Answer" problem.
//
// -------------------------------------------------------------
// EXAMPLE:
// -------------------------------------------------------------
// stalls = [1, 2, 4, 8, 9]
// k = 3
//
// Place cows at: 1, 4, 8
// Minimum distance = 3
//
// Answer = 3
//
// -------------------------------------------------------------
// EDGE CASES:
// -------------------------------------------------------------
// 1. k = 1 → distance = 0
// 2. stalls not sorted → must sort first
// 3. k = n → minimum adjacent gap
//
// -------------------------------------------------------------
// IMPORTANT LINES:
// -------------------------------------------------------------
// sort(arr.begin(), arr.end());
// - Required for greedy placement
//
// if(arr[i] - previous >= distance)
// - Check spacing condition
//
// ans = mid
// - store valid answer
//
// -------------------------------------------------------------
// TIME COMPLEXITY:
// -------------------------------------------------------------
// Sorting → O(n log n)
// Binary Search → O(log(max-min))
// Check each time → O(n)
//
// Total = O(n log(max-min))
//
// -------------------------------------------------------------
// SPACE COMPLEXITY:
// -------------------------------------------------------------
// O(1) extra space
//
// -------------------------------------------------------------
// NOTE:
// -------------------------------------------------------------
// Classic interview question:
// "Aggressive Cows" or "Maximize Minimum Distance"
//
// =============================================================
