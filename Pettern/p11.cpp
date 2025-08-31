#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter a number :";
    cin>>n;

    for(int i=1;i<=n;i++){

        for(int j=i;j<=2*i-1;j++){
            cout<<j%2;
        }
        cout<<endl;
    }
    cout<<"or methoad"<<endl;
    // or
    int start = 1;
    for(int i=0;i<n;i++){

        if(i % 2 == 0)  start = 1;
        else start = 0;
        for(int j=0;j<=i;j++ ){
            cout<<start;
            start=1-start;
        }
        cout<<endl;
    }
}

// 1
// 0 1
// 1 0 1 
// 0 1 0 1
// 1 0 1 0 1