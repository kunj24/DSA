// ==========================================================
// Problem Description:
// Given a matrix where:
// 1. Each row is sorted left to right
// 2. Each column is sorted top to bottom
//
// Search for a target element using Staircase Search.
// Start from top-right corner.
//
// Return row and column index if found,
// otherwise return {-1, -1}.
// ==========================================================

#include<iostream>
#include<vector>
using namespace std;


// ----------------------------------------------------------
// Function: searchMatrix
// Purpose:
//   Use staircase search (top-right approach)
// Returns:
//   {row, col} if found
//   {-1, -1} if not found
// ----------------------------------------------------------
vector<int> searchMatrix(vector<vector<int>>& matrix, int rows, int cols, int target)
{
    int rowpointer = 0;          // start from first row
    int colpointer = cols - 1;  // start from last column
    //you can also start from left bottom corner row=n-1 and col =0 but logic is reverse in while loop

    // traverse until out of matrix bounds
    while (rowpointer < rows && colpointer >= 0)
    {
        // if target found
        if(matrix[rowpointer][colpointer] == target)
        {
            return {rowpointer, colpointer};
        }

        // if current element is greater than target → move left
        else if(matrix[rowpointer][colpointer] > target)
        {
            colpointer--;
        }

        // if current element is smaller than target → move down
        else
        {
            rowpointer++;
        }
    }

    // target not found
    return {-1, -1};
}


// ----------------------------------------------------------
// Main Function (Interactive Input)
// ----------------------------------------------------------
int main()
{
    int rows, cols;

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> cols;

    // create matrix
    vector<vector<int>> matrix(rows, vector<int>(cols));

    // input matrix elements
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cout << "Enter element at [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }

    int target;
    cout << "Enter target to search: ";
    cin >> target;

    vector<int> index = searchMatrix(matrix, rows, cols, target);

    // check result
    if(index[0] == -1)
        cout << "Element Not Found";
    else
        cout << "Element Found at index: (" 
             << index[0] << ", " << index[1] << ")";

    return 0;
}


/*
==============================================================
Additional Explanation:

Problem Idea:
-------------
We start from the top-right corner because:
- Left side → smaller elements
- Down side → larger elements

This allows us to eliminate one row or one column
in each step.


Dry Run Example:
----------------
Matrix:
1  4  7
2  5  8
3  6  9

Target = 6

Start at (0,2) → 7 > 6 → move left
(0,1) → 4 < 6 → move down
(1,1) → 5 < 6 → move down
(2,1) → 6 FOUND ✅


Edge Cases:
------------
- target not present
- single row
- single column
- empty matrix


Time Complexity:
----------------
O(rows + cols)


Space Complexity:
----------------
O(1)


Interview Tip:
--------------
This is the MOST OPTIMAL solution for
row-wise & column-wise sorted matrix.
Always preferred over brute force.
==============================================================
*/
