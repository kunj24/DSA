#include<iostream>
#include<vector>
#include<map>
using namespace std;
int calculate(vector<int>& arr, int n){
    map<int,int>mpp;
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
    }
    for(auto it:mpp){
        if(it.second>n/2){
            return it.first;
        }
    }
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
        map<int, int> freq;
        
        for(int num : arr) freq[num]++;
        cout << "It appears " << freq[ans] << " times out of " << n << " elements" << endl;
    } else {
        cout << "No majority element found" << endl;
    }

}