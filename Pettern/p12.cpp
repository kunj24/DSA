#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter a number :";
    cin>>n;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){              
            cout<<j;
        }
        for(int x=1;x<=2*(n-i);x++){        
            cout<<" ";
        }
        for(int j=i;j>=1;j--){
            cout<<j;
        }
        cout<<endl;
    }


}
// 1      1 
// 12    21  
// 123  321   
// 12344321