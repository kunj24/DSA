#include<iostream>
#include<vector>
using namespace std;

vector<int> MatrixZero(vector<vector<int>>& matrix, int rows, int cols){      
    // Vector to store final spiral order result
    vector<int> result;
    // Time complexity is :- o(n*m)


    //top,left
    // 1 → 2 → 3right
    //         ↓    output is :-1,2,3,6,9,7,8,4,5
    // 4 → 5   6
    // ↑       ↓
    // 7 ← 8 ← 9
    //botom 
     // Get number of rows and columns
    int top = 0;
    int bottom = rows - 1;
    int left = 0;
    int right = cols - 1;

    // Traverse the matrix in spiral order
    while(top <= bottom && left <= right) {

        // Traverse from left to right across the top row
        for(int i = left; i <= right; i++) {
            result.push_back(matrix[top][i]);
        }
        top++; // Move top boundary down

        // Traverse from top to bottom on the right column
        for(int i = top; i <= bottom; i++) {
            result.push_back(matrix[i][right]);
        }
        right--; // Move right boundary left

        // Check if there are rows remaining
        if(top <= bottom) {
            // Traverse from right to left on the bottom row
            for(int i = right; i >= left; i--) {
                result.push_back(matrix[bottom][i]);
            }
            bottom--; // Move bottom boundary up
        }

        // Check if there are columns remaining
        if(left <= right) {
            // Traverse from bottom to top on the left column
            for(int i = bottom; i >= top; i--) {
                result.push_back(matrix[i][left]);
            }
            left++; // Move left boundary right
        }
    }
    // Return the final spiral order
    return result;
}

int main(){
    int rows, cols;
    cout << "Enter number of Rows: ";
    cin >> rows;
    cout << "Enter number of Columns: ";
    cin >> cols;
    
    vector<vector<int>> matrix(rows, vector<int>(cols));

    cout << "\nEnter the elements of the matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element at [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
    
    cout << "\nOriginal Matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    vector<int> ans = MatrixZero(matrix, rows, cols);
    
    cout << "\nMatrix after Spiral Traversal :\n";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    
    return 0;
}