#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Function to reverse a single row of the matrix
vector<vector<int>> Reverserow(vector<vector<int>>& matrix, int rows, int cols, int i){      
    int p1 = 0;           // Pointer 1 starts from beginning of row
    int p2 = cols - 1;    // Pointer 2 starts from end of row
    
    // Swap elements from both ends moving towards center
    while(p1 < p2){
        swap(matrix[i][p1], matrix[i][p2]);  // Swap elements at p1 and p2
        p1++;  // Move p1 forward
        p2--;  // Move p2 backward
    }
    return matrix;
}

// Main function to rotate matrix 90 degrees clockwise
vector<vector<int>> MatrixZero(vector<vector<int>>& matrix, int rows, int cols){      
    
    // STEP 1: TRANSPOSE THE MATRIX
    // Transpose means converting rows to columns
    // We swap matrix[i][j] with matrix[j][i] for all i < j
    // This creates a mirror image across the main diagonal
    for(int i = 0; i < rows; i++){            // For each row
        for(int j = i + 1; j < cols; j++){    // For each column starting from i+1
            // Why j = i+1? To avoid swapping twice (i,j) and (j,i)
            swap(matrix[i][j], matrix[j][i]);  // Swap across diagonal
        }
    }
    
    // STEP 2: REVERSE EACH ROW
    // After transpose, reversing each row gives 90-degree clockwise rotation
    for(int i = 0; i < rows; i++){
        Reverserow(matrix, rows, cols, i);  // Reverse each row using custom function
    }
    
    // Alternative: Using built-in reverse function
    // for(int i = 0; i < rows; i++){
    //     reverse(matrix[i].begin(), matrix[i].end());  // Reverse the i-th row
    // }
    
    return matrix;
}

int main(){
    int rows, cols;
    cout << "Enter number of Rows: ";
    cin >> rows;
    cout << "Enter number of Columns: ";
    cin >> cols;
    
    // Check if matrix is square for 90-degree rotation
    // 90-degree rotation only works for square matrices (rows == cols)
    if(rows != cols){
        cout << "Error: Matrix must be square for 90-degree rotation!" << endl;
        return 1;  
    }
    
    // Create a 2D vector (matrix) with given rows and columns
    vector<vector<int>> matrix(rows, vector<int>(cols));

    cout << "\nEnter the elements of the matrix:\n";
    // Read matrix elements from user
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element at [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
    
    // Display original matrix
    cout << "\nOriginal Matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;  
    }
    
    // Rotate matrix 90 degrees clockwise
    vector<vector<int>> ans = MatrixZero(matrix, rows, cols);
    
    // Display rotated matrix
    cout << "\nMatrix after rotating 90 degrees clockwise:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}