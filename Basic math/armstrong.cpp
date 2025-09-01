#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter a number :";
    cin>>n;
    int ld,sum,dub;
    dub=n;
    while (n>0)
    {
        ld =n%10;
        sum=sum+(ld*ld*ld);
        n=n/10;
    }
    if(sum==dub){
    cout<<"Number is armstrong ";
    }  
    else cout<<"Number is Not armstrong";

}