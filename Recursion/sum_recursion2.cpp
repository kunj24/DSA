#include<bits/stdc++.h>
using namespace std;

void func(int i, int sum){
   
   // Base Condition.
   if(i<1)
   {
       cout<<sum<<endl;
       return;
   }

   // Function call to increment sum by i till i decrements to 1.
   func(i-1,sum+i);

}
int main(){
    int n;
    cout<<"Enter a number :";
    cin>>n;
    cout<<"sum of number is : ";
    func(n,0);
}