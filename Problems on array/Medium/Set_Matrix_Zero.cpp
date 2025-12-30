#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> Markcolzero(vector<vector<int>>& matrix,int rows,int cols,int i){      
    for(int j=0;j<cols;j++){
        if(matrix[i][j]!=0){
            matrix[i][j]=-1;
        }
    }
    return matrix;
}
vector<vector<int>> Markrawzero(vector<vector<int>>& matrix,int rows,int cols,int j){      
    for(int i=0;i<rows;i++){
            if(matrix[i][j]!=0){
                matrix[i][j]=-1;
            }
    }
    return matrix;
}
vector<vector<int>> MatrixZero(vector<vector<int>>& matrix,int rows,int cols){      
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(matrix[i][j]==0){
                Markrawzero(matrix,rows,cols,j);
                Markcolzero(matrix,rows,cols,i);
            } 
        }
    }
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(matrix[i][j]==-1){
                matrix[i][j]=0;
            }
        }
    }
    return matrix;
}

int main(){
    int rows,cols;
    cout << "Enter number of Raw :";
    cin>>rows;
    cout<<"Enter number of coloumns :";
    cin>>cols;
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
    vector<vector<int>> ans= MatrixZero(matrix,rows,cols);
    cout << "\nMatrix after setting zeroes:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}