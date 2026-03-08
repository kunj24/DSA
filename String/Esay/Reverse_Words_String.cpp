#include <iostream>
#include <string> 
#include <algorithm> // Required for std::reverse

using namespace std;

// Changed name to 'reverseWords' to stop the naming conflict
string reverseWords(string& s, int n) {
    string ans = "";
    
    // 1. Reverse the entire string first
    // (e.g., "Hello World" -> "dlroW olleH")
    reverse(s.begin(), s.end());

    for(int i = 0; i < n; i++) {
        string word = "";
        
        // 2. Extract a word
        while(i < n && s[i] != ' ') {
            word += s[i];
            i++;
        }
        
        // 3. Reverse that word back to normal
        // (e.g., "dlroW" -> "World")
        reverse(word.begin(), word.end());
        
        if(word.length() > 0) {
            ans += " " + word;
        }   
    }
    
    // 4. Return result without the leading space
    // Added a check to ensure we don't call substr on an empty string
    return (ans.length() > 0) ? ans.substr(1) : "";
}   

int main() {
    string s;
    cout << "Enter a string: ";
    
    // getline reads the whole line including spaces
    getline(cin, s); 

    int n = s.length();
    string result = reverseWords(s, n);

    cout << "Reversed sentence: " << result << endl;

    return 0;
}
