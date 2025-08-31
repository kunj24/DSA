#include<iostream>
using namespace std;
int main(){

    int n;
    cout<<"Enter a Number :";
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int x=1;x<=n-i;x++){
            cout<<" ";                  // this is for the space in 1st line space is n-i for i=1 so space is 4 then..
        }
        for(int j=1;j<=(2*i)-1;j++){
            cout<<"*";                  // this is for the * for i=2 there is 3 star so 2*2-1 so print them
        }
        for(int x=1;x<=n-i;x++){
            cout<<" ";                  // this is same as the first space loop
        }
        cout<<endl;
    }
    
}