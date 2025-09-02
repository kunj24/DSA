#include<iostream>
using namespace std;

int f(int n){
    if(n == 0){ 
        return 0;
    }
    return n + f(n-1);
}

int main()
{
    int n;
    cout<<"Enter a number : ";
    cin>>n;
    cout<<"Sum of numbers is : "<<f(n);
    return 0;
}