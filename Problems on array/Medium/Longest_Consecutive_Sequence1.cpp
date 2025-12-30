#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int longest_consecutive_sequence(vector<int>& arr, int n){    //100,4,200,1,3,2
    if(n == 0) return 0;
    
    sort(arr.begin(), arr.end());       //then we use the sort so 1,2,3,4,100,200
    int lastNumber = INT_MIN;
    int count = 0;
    int longest = 1;
    
    for(int i = 0; i < n; i++){     //so the array is 1,2,3,4,100,200 output is :4
        // Skip duplicates
        if(arr[i] == lastNumber) continue;
        
        // Check if consecutive
        if(arr[i] == lastNumber + 1){
            count++;
        } else {
            // New sequence starts
            count = 1;
        }
        
        lastNumber = arr[i];
        longest = max(longest, count);
    }
    
    return longest;
}

int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    
    cout << "Enter elements: " << endl;
    vector<int> arr(n);
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int ans = longest_consecutive_sequence(arr, n);
    cout << "Longest consecutive sequence length: " << ans << endl;
    
    return 0;
}