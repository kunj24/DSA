#include<iostream>
using namespace std;

void f(int i,int n){
    if(i>n){
        return ;
    }
    else{
        cout<<i<<" Kunj"<<endl;
        f(i+1,n);
    }
}

int main(){
    int n;
    cout<<"Enter a number of time that you need to print name using recursion :";
    cin>>n;
    f(1,n);
}
