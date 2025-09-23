#include<iostream>
#include<vector>
using namespace std;
vector<int> sum(int arr[],int n,int k){
    vector<int> ans;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]+arr[j]==k){
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    return ans;
}
int main(){
    int n,k;
    cout<<"Enter a number of element :";
    cin>>n;
    int arr[n];
    cout<<"Enter numbers :"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter a two number of sum :";
    cin>>k;
    vector<int> val = sum(arr, n, k);
    if (!val.empty()) {
        cout << "Indices: " << val[0] << " " << val[1] << endl;
    } else {
        cout << "No such pair found." << endl;
    }
}    