#include<iostream>
#include<vector>
#include<map>
using namespace std;
int calculate(vector<int>& arr, int n){
    int element;
    int count=0;

    for(int i=0;i<n;i++){
        
        if(count==0){
            element=arr[i];
            count=1;
        }
        else if(arr[i]==element){
            count++;
        }
        else{ count--;}
    }
    int cnt1=0;
    for(int i=0;i<n;i++){
        if(arr[i]==element) cnt1++;
    }
    if(cnt1>n/2) return element;
    return -1;
}
int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    
    cout << "Enter elements (make sure one element repeats more than half): " << endl;
    vector<int> arr(n);
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int ans=calculate(arr,n);

    if(ans != -1) {
        cout << ans << " is the Majority element which appears more than half in the array" << endl;
    } else {
        cout << "No majority element found" << endl;
    }

}