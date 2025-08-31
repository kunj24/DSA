#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter a number :";
    cin>>n;
    for(int i=1;i<=n;i++){
        int star;
        int space;
        int last_star;
        if(i==1 || i==n){
            star=n;
            space=0;
            last_star=0;
        }
        else{
            star=1;
            space=n-2;
            last_star=1;
        }
        for(int j=1;j<=star;j++){
            cout<<"*";
        }
        for(int j=1;j<=space;j++){
            cout<<" ";
        }
        for(int j=1;j<=last_star;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}