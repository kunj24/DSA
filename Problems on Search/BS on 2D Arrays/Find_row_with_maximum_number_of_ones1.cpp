// ==========================================================
// Problem Description:
// Given a binary matrix (0s and 1s),
// find the index of the row that contains the maximum number of 1s.
// If multiple rows have same count, return the first one.
// ==========================================================

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


// ----------------------------------------------------------
// Function: calculate_row
// Purpose:
//   Sorts the row and finds the first occurrence of 1.
//   Returns index of first 1.
//   From that index we can calculate number of 1s.
// ----------------------------------------------------------
int calculate_row(vector<int>& arr, int row, int col){

    // Sorting row so that all 0s come first and 1s come after
    sort(arr.begin(), arr.end());

    // Traverse the sorted row
    for(int i = 0; i < arr.size(); i++){

        // First 1 found → return its index
        if(arr[i] == 1){
            return i;
        }
    }

    // If no 1 exists, return -1
    return -1;
}


// ----------------------------------------------------------
// Function: calculateRowWithMaxOnes
// Purpose:
//   For each row:
//   → count number of 1s
//   → track maximum count
//   → return row index with maximum 1s
// ----------------------------------------------------------
int calculateRowWithMaxOnes(vector<vector<int>>& matrix, int rows, int cols){

    int cnt_max = -1;   // stores maximum number of 1s found so far
    int index = -1;     // stores row index having max 1s
    int cnt_ones=0;
    // Traverse every row
    for(int i = 0; i < matrix.size(); i++){

        // calculate first index of 1
        int firstOneIndex = calculate_row(matrix[i], rows, cols);

        // number of 1s = total columns - first index
        if(firstOneIndex==-1){
            cnt_ones=0;
        }
        else{
        cnt_ones = cols - firstOneIndex;
        }
        // update max and row index
        if(cnt_ones > cnt_max){
            cnt_max = cnt_ones;
            index = i;
        }
    }

    return index;
}


// ----------------------------------------------------------
// Main Function
// ----------------------------------------------------------
int main(){

    int rows, cols;

    // Input number of rows
    cout << "Enter number of rows: ";
    cin >> rows;

    // Input number of columns
    cout << "Enter number of columns: ";
    cin >> cols;

    // Create matrix with given size
    vector<vector<int>> matrix(rows, vector<int>(cols));

    // Take matrix input
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){

            // Taking each element
            cout << "Enter element at [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }

    // Call function to get answer
    int ans = calculateRowWithMaxOnes(matrix, rows, cols);

    // Output result
    cout << "Row with maximum number of 1s: " << ans << endl;

    return 0;
}


/*
==============================================================
Additional Explanation:

Problem Idea:
-------------
For every row:
1. Sort it so 0s come first and 1s come later
2. Find first 1
3. Count number of 1s
4. Track row with maximum count

Why it works:
-------------
After sorting:
Example row: [0 0 0 1 1 1]
First 1 at index = 3
Total 1s = 6 - 3 = 3


Example:
---------
Input matrix:
0 1 1
1 1 1
0 0 1

Row 0 → 2 ones
Row 1 → 3 ones
Row 2 → 1 one

Output:
1


Edge Cases:
-----------
- No 1 in matrix → returns -1
- All rows equal → first row returned


Time Complexity:
----------------
Sorting each row → O(cols log cols)
For all rows → O(rows * cols log cols)

Space Complexity:
----------------
O(1) extra space


⚠️ Important Improvement Tip (Interview level):
----------------------------------------------
If rows are already sorted,
you can use Binary Search → O(rows * log cols)
or optimal top-right traversal → O(rows + cols)

Sorting inside loop is costly.
==============================================================
*/
