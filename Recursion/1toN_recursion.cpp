#include<iostream>
using namespace std;
void f(int i,int n){
    if(i>n){
        return;
    }
    else{
        cout<<i<<" ";
        f(i+1,n);
    }
}

int main(){
    int n;
    cout<<"Enter a number that is printinh using recursion :";
    cin>>n;
    f(1,n);
}
