#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter a number :";
    cin>>n;
    for(int i=1;i<=2*n-1;i++){
        for(int j=1;j<=2*n-1;j++){
            int top=i-1;
            int left=j-1;
            int right=(2*n-1)-j;
            int down=(2*n-1)-i;
            cout<<n- min(min(right,left),min(top,down));
        }
        cout<<endl;
    }
}