#include<iostream>
#include<vector>
#include<algorithm>  // Needed for sort();
using namespace std;
void sortArr(vector<int> &arr){
    sort(arr.begin(),arr.end());  //this only work when array last 2 element is unique
    cout<<"largest elemnt is : "<<arr[arr.size()-1]<<endl;
    cout<<"2nd largest elment using sort is : "<<arr[arr.size()-2]<<endl; 
    for(int i=arr.size()-1;i>=1;i--){

        // 1,2,3,4,4 so largest=4 2nd largest=4 but we want 2nd largest is 3
         // so we use this for loop so we can print the 2nd large=3

        if (arr[i] != arr[i-1]) {
            cout << "2nd largest is : " << arr[i-1] << endl;
            return;
        }
    }
}
    
int main(){
    int n;
    cout<<"Enter a number of element :";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter numbers unique number :"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"if you use the sorting method in non unique elment"<<endl;
    cout<<"then you need to need one more extra loop for "<<endl;
    cout<<"find the 2nd largest elemnt accroading to sorting"<<endl;
    cout<<"the 2nd largest is alwasy the arr.sieze-1"<<endl;
    cout<<"but not always neccacary"<<endl;
    sortArr(arr);
}    