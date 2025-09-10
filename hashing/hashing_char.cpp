#include<iostream>
using namespace std;
int main(){
    //hashing character
    string s;
    cout<<"Enter a string :";
    cin>>s;
    int hash[256]={0};
    for(int i=0;i<s.size();i++){
        hash[s[i]]++;
    }

    int q;
    cout<<"Enter a number of character for quries :"<<endl;
    cin>>q;
    cout<<"Enter "<<q<< " character"<<endl;
    while(q--){
        char c;
        cin>>c;
        cout<<hash[c]<<endl;
    }
}