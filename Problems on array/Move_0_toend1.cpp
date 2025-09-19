#include<iostream>
#include<vector>
using namespace std;
void movezero(vector<int>& arr, int n){
    int j = 0; // Position for next non-zero element
    
    for(int i = 0; i < n; i++){
        if(arr[i] != 0){
            swap(arr[i], arr[j]);
            j++;
        }
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