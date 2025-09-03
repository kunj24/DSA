#include<iostream>
using namespace std;
bool palindrome(string s){
    int start=0;
    int end=s.length()-1;
    while(start<end){
        if(s[start]==s[end]){
            start++;
            end--;
        }
        else{ return false;}
    }
    return true;
}

int main(){
    string s;
    cout<<"Enter the name: ";
    cin>>s;
    bool ans =palindrome(s);
    if(ans==true){
        cout<<"Palindrome";
    }
    else cout<<"not palindrome";
}