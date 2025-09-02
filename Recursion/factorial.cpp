#include<iostream>
using namespace std;

int f(int n){
    if(n == 1){ 
        return 1;
    }
    return n*f(n-1);
}

int main()
{
    int n;
    cout<<"Enter a number : ";
    cin>>n;
    cout<<"factorial is : "<<f(n);
    return 0;
}