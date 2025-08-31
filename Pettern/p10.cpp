#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter a number :";
    cin>>n;
    for(int i=1;i<=2*n - 1;i++){        // for the i=5 then there is 9 row so 2n-1 
        int stars=i;                        // for reverse the pettern we need to assign the int stars for j loop
        if(i>n){                            //from i = 5 we need to reverse the pettern
            stars=2*n-i;
        }   
        for(int j=1;j<=stars;j++){          
            cout<<"*";
        }
        cout<<endl;
    }
}