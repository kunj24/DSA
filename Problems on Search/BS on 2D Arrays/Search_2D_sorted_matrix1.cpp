// ==========================================================
// Problem Description:
// Given a fully sorted 2D matrix:
// 1. Each row is sorted
// 2. First element of next row > last of previous row
//
// Search a target using Binary Search.
//
// Treat matrix as virtual 1D array using:
// row = mid / cols
// col = mid % cols
//
// Return index (1D position) or -1 if not found.
// ==========================================================

#include<iostream>
#include<vector>
using namespace std;


// ----------------------------------------------------------
// Function: searchMatrix
// Purpose:
//   Apply Binary Search on virtual 1D matrix
// Returns:
//   1D index if found else -1
// ----------------------------------------------------------
int searchMatrix(vector<vector<int>>& matrix, int rows, int cols, int target)
{
    int low = 0;
    int high = rows * cols - 1; //convert into 1d    

    // Binary search loop
    while(low <= high)
    {
        int mid = low + (high - low) / 2;

        // convert 1D → 2D
        int r = mid / cols;   // row index
        int c = mid % cols;   // column index

        int current = matrix[r][c];

        // target found
        if(current == target)
            return mid;

        // move right
        else if(current < target)
            low = mid + 1;

        // move left
        else
            high = mid - 1;
    }

    return -1; // not found
}


// ----------------------------------------------------------
// Main Function (Interactive Input System)
// ----------------------------------------------------------
int main()
{
    int rows, cols;

    // take rows
    cout << "Enter number of rows: ";
    cin >> rows;

    // take columns
    cout << "Enter number of columns: ";
    cin >> cols;

    // create matrix
    vector<vector<int>> matrix(rows, vector<int>(cols));

    // input elements with clear prompts
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

    int index = searchMatrix(matrix, rows, cols, target);

    if(index == -1)
        cout << "Element Not Found";
    else
        cout << "Element Found at 1D index: " << index;

    return 0;
}


/*
==============================================================
Additional Explanation:

Problem Idea:
-------------
Matrix is completely sorted like a 1D array.
So instead of nested loops, we use Binary Search.

We imagine:
Matrix:
1 3 5
7 9 11

Virtual array:
[1,3,5,7,9,11]


Mapping Logic:
--------------
mid = 4

row = 4 / 3 = 1
col = 4 % 3 = 1

matrix[1][1]


Dry Run:
---------
Input:
2 3
1 3 5
7 9 11
target = 9

low=0, high=5
mid=2 → 5 < 9
mid=4 → 9 found

Return 4


Edge Cases:
------------
- single row
- single column
- not found → -1


Time Complexity:
----------------
O(log(rows*cols))

Space Complexity:
----------------
O(1)


Exam Tip:
----------
Always remember:
row = mid / cols
col = mid % cols

Very common viva question 🔥
==============================================================
*/
