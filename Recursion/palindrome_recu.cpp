#include<iostream>
using namespace std;

bool palindrome(string s, int left, int right) {
    // Base case: if left >= right, we've checked all characters
    if (left >= right) {
        return true;
    }
    
    // If characters don't match, it's not a palindrome
    if (s[left] != s[right]) {
        return false;
    }
    
    // Recursively check the next pair of characters
    return palindrome(s, left + 1, right - 1);
}

int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;
    
    bool ans = palindrome(s, 0, s.length() - 1);
    
    if (ans == true) {
        cout << "Palindrome";
    } else {
        cout << "Not palindrome";
    }
    
    return 0;
}