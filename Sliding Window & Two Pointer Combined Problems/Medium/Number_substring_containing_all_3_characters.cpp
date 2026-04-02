#include <bits/stdc++.h>
using namespace std;

int number_substring_contain_abc_characters(string& s) {
    int count=0;
    for(int i=0;i<s.size();i++){
        int hash[3]={0};
        for(int j=i;j<s.size();j++){
            hash[s[j]-'a']=1;
            if(hash[0]+hash[1]+hash[2]==3){
                count++;
            }
        }
    }
    return count;
}
int main() {
    string s;

    cout << "Enter a string which contain the a,b,c charater : ";
    cin >> s;

    int result = number_substring_contain_abc_characters(s);

    cout << "The maximum length is: " << result << endl;

    return 0;
}
