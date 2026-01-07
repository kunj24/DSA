#include<iostream>
#include<vector>
using namespace std;

// Print the entier Row

// Pascal's Triangle visualization:
// Row 0:          1
// Row 1:        1   1
// Row 2:      1   2   1
// Row 3:    1   3   3   1
// Row 4:  1   4   6   4   1

// Find a specific element in Pascal's Triangle using combination formula
vector<int> PrintRow(int r){
    vector<int>row;
    int ans=1;
    row.push_back(ans);
    // Generate elements from column 1 to column r
    for(int i = 1; i <= r; i++){
        ans = ans * (r - i + 1);  // Multiply by (n - k + 1)
        ans = ans / i;            // Divide by k
        row.push_back(ans);
    }
    return row;
}


int main(){
    int n;
    
    cout << "Enter the number of rows you want to print (starting from row 0): ";
    cin >> n;
    
    vector<vector<int>> triangle;
    
    // Generate rows from 0 to n-1
    for(int i = 0; i < n; i++){  
        triangle.push_back(PrintRow(i));
    }
    
    // Print the triangle in pyramid form
    for(int i = 0; i < triangle.size(); i++){
        // Add spacing for pyramid shape
        for(int space = 0; space < n - i - 1; space++){
            cout << "  ";  // Two spaces for better alignment
        }
                // Print elements of current row
        for(int j = 0; j < triangle[i].size(); j++){
            cout << triangle[i][j] << "   ";  // Three spaces between numbers
        }
        cout << endl;
    }
    
    return 0;
}

// triangle[0] = [1]
// triangle[1] = [1, 1]
// triangle[2] = [1, 2, 1]
// triangle[3] = [1, 3, 3, 1]