#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> MatrixZero(vector<vector<int>>& matrix, int rows, int cols){      

    vector<vector<int>> newmatrix(rows,vector<int>(cols));

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            newmatrix[j][(cols-1)-i]=matrix[i][j];
        }
    }
    return newmatrix;
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
    
    cout << "\nMatrix after Rotating 90 degree  :\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
