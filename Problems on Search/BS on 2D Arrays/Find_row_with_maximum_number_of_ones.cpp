#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


// =============================================================
// PROBLEM:
// -------------------------------------------------------------
// Given a binary matrix (0s and 1s),
// find the index of the row having maximum number of 1s.
//
// If multiple rows have same count → return first one.
//
// Example:
// 0 1 1 1
// 0 0 1 1
// 1 1 1 1
//
// Output → row 2 (0-based)
// =============================================================



// =============================================================
// FUNCTION: calculateRowWithMaxOnes
// -------------------------------------------------------------
// Count number of 1s in each row
// Track maximum count and row index
//
// Time Complexity  : O(r * c)
// Space Complexity : O(1)
// =============================================================
int calculateRowWithMaxOnes(vector<vector<int>>& matrix, int rows, int cols){

    int maxCount = 0;         // maximum number of 1s
    int rowIndex = -1;       // answer row index

    for(int i = 0; i < rows; i++){

        int count = 0;

        // count 1s in current row
        for(int j = 0; j < cols; j++){

            if(matrix[i][j] == 1){
                count++;
            }
        }

        // update maximum
        if(count > maxCount){
            maxCount = count;
            rowIndex = i;
        }
    }

    return rowIndex;
}



int main(){

    int rows, cols;

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> cols;


    // initialize matrix properly
    vector<vector<int>> matrix(rows, vector<int>(cols));


    // input matrix
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << "Enter element at [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }


    int ans = calculateRowWithMaxOnes(matrix, rows, cols);

    cout << "Row with maximum number of 1s: " << ans << endl;

    return 0;
}



// =============================================================
// QUICK REVISION NOTES
// -------------------------------------------------------------
// • Traverse each row
// • Count 1s
// • Track maximum
//
// Time  = O(r * c)
// Space = O(1)
//
// NOTE:
// If rows are sorted (0 → 1),
// can optimize to O(r + c)
// =============================================================
