// ==========================================================
// Problem Description:
// Given a 2D matrix, find the median of all elements.
// The median is the middle value after sorting all elements.
//
// Approach:
// 1. Flatten matrix into a single array
// 2. Sort the array
// 3. Return the middle element
// ==========================================================

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


// ----------------------------------------------------------
// Function: median
// Purpose:
//   Flatten matrix, sort elements, return median
// ----------------------------------------------------------
int median(vector<vector<int>>& matrix, int rows, int cols)
{   
    vector<int> ans;

    // copy all elements into 1D array
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            ans.push_back(matrix[i][j]);
        }
    }

    // sort the array
    sort(ans.begin(), ans.end());

    int n = ans.size();

    // return middle element
    return ans[n / 2];    
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

    // get median value
    int med = median(matrix, rows, cols);

    cout << "Median of matrix: " << med;

    return 0;
}


/*
==============================================================
Additional Explanation:

Problem Idea:
-------------
We convert the 2D matrix into a 1D array.
Then we sort it and pick the middle element.


Example:
---------
Matrix:
1 3 5
2 6 9
3 6 9

Flattened:
[1,3,5,2,6,9,3,6,9]

Sorted:
[1,2,3,3,5,6,6,9,9]

n = 9
Median index = 9/2 = 4

Median = 5


Edge Cases:
------------
- Single element matrix
- Even number of elements → this code returns upper median


Time Complexity:
----------------
Flattening: O(rows*cols)
Sorting: O(n log n)

Total:
O(n log n)
where n = rows*cols


Space Complexity:
----------------
O(n) extra space for flattened array


Interview Tip:
--------------
Brute force approach: O(n log n)

Optimal approach exists:
Binary search on value range → O(rows * log(max-min))

Very common interview problem.
==============================================================
*/
