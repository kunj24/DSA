#include<iostream>
#include<vector>
using namespace std;

int calculate(vector<int>& arr, int n){
    for(int i = 0; i < n; i++){
        int count = 0;
        for(int j = 0; j < n; j++){ 
            if(arr[j] == arr[i]){
                count++;
            }
        }
        if(count > n/2){  
            return arr[i];
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
    
    int ans = calculate(arr, n);
    
    if(ans != -1) {
        cout << ans << " is the Majority element which appears more than half in the array" << endl;
    } else {
        cout << "No majority element found" << endl;
    }
    
    return 0;
}