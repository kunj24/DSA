#include<iostream>
#include<vector>
using namespace std;
void movezero(vector<int>& arr, int n){
    int j = 0; // Position for next non-zero element
    
    for(int i = 0; i < n; i++){
        if(arr[i] != 0){       //1,2,0,0,3
            swap(arr[i], arr[j]);  // then i=0,j=0 swap i=1,j=1 swap
            j++;    // i=2 it come 0 so i++ again same so i++
        }   // now i=4 j=2 so swap 0 adn 3
    }   //1,2,3,0,0
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