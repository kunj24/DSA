#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


// =============================================================
// PROBLEM DESCRIPTION:
// -------------------------------------------------------------
// We are given boards with different lengths.
// There are k painters.
// Each painter paints only contiguous boards.
//
// Every painter paints at same speed.
//
// Find the MINIMUM time required to paint all boards.
//
// (Time ∝ length of boards)
//
// =============================================================



// =============================================================
// FUNCTION: countPainters
// -------------------------------------------------------------
// For a given maxTime limit,
// calculate how many painters are required.
//
// If current painter exceeds time → assign new painter
// =============================================================
int countPainters(vector<int>& boards, int n, int maxTime){

    int currentTime = 0;       // time used by current painter
    int paintersNeeded = 1;   // at least one painter

    for(int i = 0; i < n; i++){

        // if board fits in current painter time
        if(currentTime + boards[i] <= maxTime){
            currentTime += boards[i];
        }
        else{
            // assign new painter
            paintersNeeded++;
            currentTime = boards[i];
        }
    }

    return paintersNeeded;
}



// =============================================================
// FUNCTION: paintersPartition (Binary Search - Optimal)
// -------------------------------------------------------------
// Find minimum possible maximum time
// =============================================================
int paintersPartition(vector<int>& boards, int n, int painters){

    if(painters > n) return -1;

    // minimum time = largest board
    int low = *max_element(boards.begin(), boards.end());

    // maximum time = sum of all boards
    int high = 0;
    for(int i = 0; i < n; i++){
        high += boards[i];
    }

    int answer = high;

    while(low <= high){

        int mid = low + (high - low) / 2;

        int requiredPainters = countPainters(boards, n, mid);

        // if possible within painters, try smaller time
        if(requiredPainters <= painters){
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
    cout << "Enter number of boards: ";
    cin >> n;

    vector<int> boards(n);

    cout << "Enter length of each board: " << endl;
    for(int i = 0; i < n; i++){
        cin >> boards[i];
    }

    int painters;
    cout << "Enter number of painters: ";
    cin >> painters;

    int ans = paintersPartition(boards, n, painters);

    cout << "Minimum time required: " << ans << endl;

    return 0;
}


