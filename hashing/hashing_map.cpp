#include<iostream>
#include <map>
using namespace std;
int main(){
    int n;
    cout<<"Enter a no of element to insert :";
    cin>>n;
    int arr[n];
    cout << "Enter " << n << " numbers: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    map<int,int> mpp;
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
    }
    for(auto it : mpp){
        cout<<it.first  <<" -> " <<it.second<<endl;
    }
    int q;
    cout<<"Enter a number of character for quries :"<<endl;
    cin>>q;
    cout<<"Enter "<<q<< "number "<<endl;

    while(q--){
        int x;
        cin>>x;
        cout << "Frequency of " << x << " = " << mpp[x] << endl;
    }


}