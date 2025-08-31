#include<iostream>
using namespace std;
int main(){

    int n;
    cout<<"Enter a Number :";
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int x=1;x<i;x++){
            cout<<" ";                  // this is for the space in 1st line space is 0 so 1<o so skip if i=2 then 1<2 then 1 space 
        }
        for(int j=1;j<=2*n-(2*i)+1;j++){
            cout<<"*";                  // this is for the * for i=1 there is 9 star which means 2*5-2*1+1 = 10-2+1 = 9 dont do that 2*n-((2*i)+1)
                                        // for i=2 there is 7 star so 10-6+1 =7
        }
        for(int x=1;x<i;x++){
            cout<<" ";                  // this is for the space in 1st line space 
        }
        cout<<endl;
    }
    
}