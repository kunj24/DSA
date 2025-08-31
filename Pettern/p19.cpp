#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter a number: ";
    cin >> n;
    
    int space = 0;
    // Top half
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n - i + 1; j++) cout << "*";
        for(int x = 0; x < space; x++) cout << " ";
        for(int j = 1; j <= n - i + 1; j++) cout << "*";
        space += 2;
        cout << endl;
    }
    
    // Bottom half - starting from the next pattern
    space -= 2; // Adjust for the first row of bottom half
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++) cout << "*";
        for(int x = 0; x < space; x++) cout <<" ";
        for(int j = 1; j <= i; j++) cout << "*";
        space -= 2;
        cout << endl;
    }
    
    return 0;
}