#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // Required for reverse()

using namespace std;

string rotate_string(string& s) {
    vector<string> ans; // Changed to ans
    string word = "";
    
    // 1. Split string into words
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != ' ') {
            word += s[i];
        } 
        else if (!word.empty()) {
            ans.push_back(word);
            word = "";
        }
    }   
    // Push the very last word
    if (!word.empty()) {
        ans.push_back(word);
    }

    // 2. Reverse the vector of words
    reverse(ans.begin(), ans.end());

    // 3. Join the words back into a single string
    string result = "";
    for (int i = 0; i < ans.size(); i++) {
        result += ans[i];
        // Add a space if it's not the last word
        if (i < (int)ans.size() - 1) {
            result += " ";
        }
    }
    
    return result; // Added return statement
}

int main() {
    string s;
    cout << "Enter string: ";
    getline(cin, s);

    string result = rotate_string(s);
    cout << "Rotated String: [" << result << "]" << endl;

    return 0;
}
