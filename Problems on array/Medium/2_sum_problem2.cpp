#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

void sort(vector<int>& arr){
    sort(arr.begin(), arr.end());
}

vector<int> twoSum(int arr[], int n, int k){
    int i=0;
    int j=n-1;
    vector<int> result;

    while(i<j){
        if(arr[i]+arr[j]==k){
            result.push_back(i);
            result.push_back(j);
            return result;
        }
        else if(arr[i]+arr[j]>k){
            j--;
        }
        else{
            i++;
        }
    }
    return result;
}

int main(){
    int n, k;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    
    cout << "Enter numbers: " << endl;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    cout << "Enter target sum: ";
    cin >> k;

    vector<int> original_arr = arr;
    sort(arr);

    vector<int> result = twoSum(arr.data(), n, k);
    
    if (!result.empty()) {
        cout << "Indices: " << result[0] << " " << result[1] << endl;
        cout << "Values: " << arr[result[0]] << " + " << arr[result[1]] << " = " << k << endl;
        cout << "Original array: ";
        for(int num : original_arr) cout << num << " ";
        cout << endl;
        cout << "Sorted array:   ";
        for(int num : arr) cout << num << " ";
        cout << endl;
    } 
    else {
        cout << "No such pair found." << endl;
    }
    
    
    
    
    return 0;
}