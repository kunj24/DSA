

#include<iostream>
#include<vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int rows, int cols, int target){

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(matrix[i][j]==target){
                return true;
            }
        }
    }
    return false;
}


// ----------------------------------------------------------
// Main Function
// ----------------------------------------------------------
int main(){

    int rows, cols;

    cout << "Enter rows : ";
    cin >> rows;
    cout<<"Enter a columns :";
    cin>>cols;

    // create matrix
    vector<vector<int>> matrix(rows, vector<int>(cols));

    // input matrix
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cin >> matrix[i][j];
        }
    }

    int target;

    cout << "Enter target to search: ";
    cin >> target;

    // call search
    bool found = searchMatrix(matrix, rows, cols, target);

    if(found)
        cout << "Element Found";
    else
        cout << "Element Not Found";

    return 0;
}


