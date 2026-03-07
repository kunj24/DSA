#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


// =============================================================
// PROBLEM DESCRIPTION:
// -------------------------------------------------------------
// Given board lengths and k painters,
// each painter paints contiguous boards.
//
// Find the MINIMUM time required to paint all boards.
//
// This is BRUTE FORCE (Linear Search on answer).
// =============================================================



// =============================================================
// FUNCTION: countPainters
// -------------------------------------------------------------
// For a given maxTime, count how many painters are needed.
// =============================================================
int countPainters(vector<int>& boards, int n, int maxTime){

    int currentTime = 0;        // time used by current painter
    int paintersUsed = 1;       // at least one painter

    for(int i = 0; i < n; i++){

        if(currentTime + boards[i] <= maxTime){
            currentTime += boards[i];
        }
        else{
            paintersUsed++;
            currentTime = boards[i];
        }
    }

    return paintersUsed;
}



// =============================================================
// LINEAR + LINEAR SOLUTION (BRUTE FORCE)
// -------------------------------------------------------------
// Try every possible time from low → high
// =============================================================
int paintersPartitionLinear(vector<int>& boards, int n, int k){

    if(k > n) return -1;

    // minimum possible time
    int low = *max_element(boards.begin(), boards.end());

    // maximum possible time
    int high = 0;
    for(int i = 0; i < n; i++){
        high += boards[i];
    }

    // Try each possible time (LINEAR SEARCH)
    for(int time = low; time <= high; time++){

        if(countPainters(boards, n, time) <= k){
            return time;
        }
    }

    return -1;
}



int main(){

    int n;
    cout << "Enter number of boards: ";
    cin >> n;

    vector<int> boards(n);

    cout << "Enter board lengths:" << endl;
    for(int i = 0; i < n; i++){
        cin >> boards[i];
    }

    int k;
    cout << "Enter number of painters: ";
    cin >> k;

    int ans = paintersPartitionLinear(boards, n, k);

    cout << "Minimum time required: " << ans << endl;

    return 0;
}
