#include<iostream>
using namespace std;

// Function to find a specific element in Pascal's Triangle
// Pascal's Triangle element at row r, column c = rCc = nCr = r!/(c!*(r-c)!)
// Example: 10C3 = (10*9*8)/(1*2*3) = 120

// Pascal's Triangle visualization:
// Row 0:          1
// Row 1:        1   1
// Row 2:      1   2   1
// Row 3:    1   3   3   1
// Row 4:  1   4   6   4   1

// Find a specific element in Pascal's Triangle using combination formula
int ncr(int r, int c){
    long long res = 1;
    
    // Optimized nCr calculation: n*(n-1)*...*(n-c+1) / 1*2*...*c
    for(int i = 0; i < c; i++){  // Loop c times
        res = res * (r - i);     // Build numerator
        res = res / (i + 1);     // Divide by denominator
    }
    return (int)res;
}

int main(){
    int r, c;
    
    cout << "Enter row (0-based): ";
    cin >> r;
    
    cout << "Enter column (0-based): ";
    cin >> c;
    
    // Note: column should not exceed row in Pascal's Triangle
    int ans = ncr(r, c);
    
    cout << "Value at position (" << r << "," << c << ") is: " << ans << endl;
    
    return 0;
}

// Example: For row 4, column 2: 4C2 = (4*3)/(1*2) = 6
// In Pascal's Triangle: Row 4: 1 4 6 4 1