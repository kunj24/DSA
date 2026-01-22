#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

int calculate(vector<int>& arr, int n){
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                count++;
            }
        }
    }
    return count;
}

int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    
    cout << "Enter " << n << " elements: " << endl;
    vector<int> arr(n);
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    int ans = calculate(arr, n);
    cout << "The number of inversions is: " << ans << endl;
    return 0;
}

// incersions is left element > right element
// Input Format: N = 5, array[] = {5,3,2,1,4}
// Result: 7
// Explanation: There are 7 pairs 
// (5,1), (5,3), (5,2), (5,4),(3,2), (3,1), (2,1) and 
// we have left 2 pairs (2,4) and (1,4) as both are not satisfy our condition.