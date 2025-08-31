#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter a number :";
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i;j++){
            cout<<" ";
        }
        char ch='A';
        int breakpoint=2*i+1;
        for(int x=1;x<=2*i-1;x++){
            cout<<ch;
            if(x<=breakpoint) ch++;
            else ch--;
        }
        for(int j=1;j<=n-i;j++){
            cout<<" ";
        }
        cout<<endl;
    }
}
