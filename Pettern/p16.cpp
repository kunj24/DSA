#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter a number :";
    cin>>n;

    for(char ch='A';ch <'A'+n;ch++){
        for(int i=1;i<=ch-64;i++){
            cout<<ch;
        }
        cout<<endl;
    }
    
}