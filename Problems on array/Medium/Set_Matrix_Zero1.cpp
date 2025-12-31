#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> MatrixZero(vector<vector<int>>& matrix, int rows, int cols){      
    // Arrays to mark which rows and columns should be zero
    int zerorow[rows]={0};  //row=3 then create the array 0,0,0
    int zerocols[cols]={0}; //col=3 then create the array 0,0,0
    
    // First pass: mark rows and columns containing zeros
    // 3 1 2
    // 0 3 1
    // 5 0 4
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(matrix[i][j] == 0){  // in i=1 j=0 the value is 0 
                zerorow[i] = 1;    //then mark the array of row of i 1 so row=0,1,0 
                zerocols[j] = 1;   //mark the col array of j 1 so col=1,0,0
            }
        }
    }   // at the last row=0,1,1 col=1,1,0 
    //      1,1,0
    //   0
    //   1
    //   1
    //now place the zero at the one of the array is 1 
    //it will tell as whole row and col mark zero if any row or col is 0    
    // Second pass: set elements to zero
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(zerorow[i] || zerocols[j]){
                matrix[i][j] = 0;
            }
        }
    }
    
    return matrix;
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
    
    vector<vector<int>> ans = MatrixZero(matrix, rows, cols);
    
    cout << "\nMatrix after setting zeroes:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}