#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter a number :";
    cin>>n;
    int x=n;
    int reverse=0;
    while (n>0)
    {
        int id =n%10;
        reverse=(reverse*10)+id;
        n=n/10;
    }
    if(x==reverse) cout<<"palindrome";
    else  cout<<"not plaindrome";
    

}   