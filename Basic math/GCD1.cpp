#include<iostream>
using namespace std;
int main(){
    int n1,n2;
    cout<<"Enter a number 1:" ;
    cin>>n1;
    cout<<"Enter a number 2:";
    cin>>n2;
    int gcd = 1;

    for(int i=1;i<=min(n1,n2);i++){
        if(n1%i==0 && n2%i==0){
            gcd=i;
        }
    }
    cout<<gcd;
}