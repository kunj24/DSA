#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter a number :";
    cin>>n;
    for(int i=1;i<=n;i++){

        for(char ch='A';ch <'A'+i;ch++){
            cout<<ch;
        }
        cout<<endl;
    }
    
}

// A
// AB
// ABC
// ABCD