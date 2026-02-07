// ==========================================================
// Problem Description:
// Given a 2D matrix, find a peak element.
// A peak element is one that is strictly greater than
// its top, bottom, left, and right neighbors.
//
// Return the index (row, col) of the peak.
// If no peak exists, return {-1, -1}.
// ==========================================================

#include<iostream>
#include<vector>
using namespace std;


// ----------------------------------------------------------
// Function: Find_peakelement
// Purpose:
//   Traverse matrix and check neighbors
//   Return index of peak element
// ----------------------------------------------------------
vector<int> Find_peakelement(vector<vector<int>>& matrix, int rows, int cols)
{
    // Traverse each cell
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            int current = matrix[i][j];

            // Assume neighbors are smaller initially
            bool up = true, down = true, left = true, right = true;

            // Check upper neighbor
            if(i > 0)
                up = current > matrix[i-1][j];

            // Check lower neighbor
            if(i < rows - 1)
                down = current > matrix[i+1][j];

            // Check left neighbor
            if(j > 0)
                left = current > matrix[i][j-1];

            // Check right neighbor
            if(j < cols - 1)
                right = current > matrix[i][j+1];

            // If greater than all valid neighbors → peak
            if(up && down && left && right)
                return {i, j};
        }
    }

    // no peak found
    return {-1, -1};
}


// ----------------------------------------------------------
// Main Function
// ----------------------------------------------------------
int main()
{
    int rows, cols;

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));

    // input matrix
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cout << "Enter element at [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }

    vector<int> index = Find_peakelement(matrix, rows, cols);

    if(index[0] == -1)
        cout << "Peak Element Not Found";
    else
        cout << "Peak Element Found at index: (" 
             << index[0] << ", " << index[1] << ")";

    return 0;
}


/*
==============================================================
Additional Explanation:

Problem Idea:
-------------
A peak element is greater than all its neighbors.

For each cell:
Check top, bottom, left, right.
If all are smaller → peak found.


Example:
---------
Matrix:
1  4  3
2  9  5
7  6  8

Check (1,1) = 9
Neighbors:
4, 2, 5, 6

9 > all → Peak at (1,1)


Edge Cases:
------------
- Single element matrix → it is a peak
- Border elements only check available neighbors


Time Complexity:
----------------
O(rows * cols)
We check every cell once.


Space Complexity:
----------------
O(1)


Interview Tip:
--------------
Brute force → O(n*m)

Optimal solution exists:
Binary search on columns → O(n log m)
Very common advanced interview question.
==============================================================
*/
