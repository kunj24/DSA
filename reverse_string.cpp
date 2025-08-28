#include<iostream>
#include<stack>
using namespace std;
int main(){
    string s;
    s="Hi How are you";
    string store;

    stack<char> s1;
    cout<<"Initial String is: "<<s<<endl;
    for(int i=0;i<=s.length();i++){
        if(s[i]==' '){
            while(!s1.empty()){
                store=store + s1.top();
                s1.pop();
            }
            store = store + " ";
        }
        else{
            s1.push(s[i]);
        }
    }
    while(!s1.empty()){
        store=store + s1.top();
        s1.pop();
    }
    cout<<"Reverse String is: ";
    for(int i=0;i<=store.length();i++){
        cout<<store[i];
    }
}



