#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Function to merge overlapping intervals
vector<vector<int>> Mergeoverlap(vector<vector<int>>& intervals, int n){
    if(n == 0) return {};
    
    // Sort intervals based on start time
    sort(intervals.begin(), intervals.end());
    
    vector<vector<int>> merged;
    
    for(int i = 0; i < n; i++){
        // If merged is empty or current interval doesn't overlap with last merged
        if(merged.empty() || intervals[i][0] > merged.back()[1]){
            merged.push_back(intervals[i]);
        }
        else{
            // Merge the intervals: update end time if needed
            merged.back()[1] = max(merged.back()[1], intervals[i][1]);
        }
    }
    
    return merged;
}

int main(){
    int n;
    cout << "Enter number of intervals: ";
    cin >> n;
    
    cout << "Enter " << n << " intervals (start end): " << endl;
    vector<vector<int>> intervals(n, vector<int>(2));
    
    for(int i = 0; i < n; i++){
        cout << "Interval " << i+1 << ": ";
        cin >> intervals[i][0] >> intervals[i][1];
    }
    
    vector<vector<int>> result = Mergeoverlap(intervals, n);
    
    cout << "\nMerged Intervals: " << endl;
    for(int i = 0; i < result.size(); i++){
        cout << "[" << result[i][0] << ", " << result[i][1] << "]" << endl;
    }
    
    return 0;
}

// n = 4
// Intervals: [[1,3], [2,6], [8,10], [15,18]]
// Step-by-step:

// Sort intervals: Already sorted

// Start with [1,3]

// Check [2,6]: Overlaps (2 ≤ 3) → Merge → [1, max(3,6)=6]

// Check [8,10]: Doesn't overlap (8 > 6) → Add [1,6] to result

// Start new with [8,10]

// Check [15,18]: Doesn't overlap (15 > 10) → Add [8,10] to result

// Add [15,18]

