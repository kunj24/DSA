#include<iostream>
using namespace std;
int main(){
    string s;
    cin>>s;

    int hash[25]={0};
    for(int i=0;i<s.size();i++){
        hash[s[i]-'a']++;
    }

    int q;
    cout<<"Enter a number of character for quries :"<<endl;
    cin>>q;
    cout<<"Enter "<<q<< " character"<<endl;
    while(q--){
        char c;
        cin>>c;
        cout<<hash[c-'a']<<endl;
    }
}