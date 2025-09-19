#include<iostream>
#include<vector>
using namespace std;
void movezero(vector<int>& arr,int n){

    vector<int>temp;
    for(int i=0;i<arr.size();i++){
        if(arr[i]!=0){
            temp.push_back(arr[i]);
        }       
    }
    int nonzero=temp.size();
    for(int i=0;i<nonzero;i++){
        arr[i]=temp[i];
    }

    for(int i=nonzero;i<n;i++){
        arr[i]=0;
    }
}
int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
   vector<int> arr(n);
 
    cout << "Enter numbers with 0 :" << endl;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    movezero(arr, n);
    
    cout<<"Array after moving zeros:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}