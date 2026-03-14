#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool Anagrams_string(string& str1, string& str2) {

    if (str1.length() != str2.length()) {
        return false;  // Strings can't be anagrams if lengths are different
    }
    sort(str1.begin(),str1.end());
    sort(str2.begin(),str2.end());
    for(int i=0;i<str1.length();i++){
        if(str1[i]!=str2[i]){
            return false;
        }
    }
    return true;
}

int main() {

    string s, t;

    cout << "Enter string 1: ";
    cin >> s;

    cout << "Enter string 2: ";
    cin >> t;

    bool result = Anagrams_string(s, t);

    if (result) {
        cout << "This is an Anagrams string" << endl;
    } else {
        cout << "This is not an Anagrams string" << endl;
    }

    return 0;
}


