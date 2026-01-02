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
    int r;
    
    cout << "Enter row (0-based): ";
    cin >> r;

    vector<int> ans = PrintRow(r);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}

//n=4;

// Start: ans = 1, row = [1]

// i = 1:
//   ans = 1 × (4 - 1 + 1) = 1 × 4 = 4
//   ans = 4 / 1 = 4
//   row = [1, 4] ✓

// i = 2:
//   ans = 4 × (4 - 2 + 1) = 4 × 3 = 12
//   ans = 12 / 2 = 6
//   row = [1, 4, 6] ✓

// i = 3:
//   ans = 6 × (4 - 3 + 1) = 6 × 2 = 12
//   ans = 12 / 3 = 4
//   row = [1, 4, 6, 4] ✓

// i = 4:
//   ans = 4 × (4 - 4 + 1) = 4 × 1 = 4
//   ans = 4 / 4 = 1
//   row = [1, 4, 6, 4, 1] ✓