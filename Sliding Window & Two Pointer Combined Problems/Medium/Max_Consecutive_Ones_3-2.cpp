#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Max_consecutive_ones(const vector<int>& arr, int n, int k) {
    int maxlength=0;
    int left=0;
    int right=0;
    int zero=0;
    while(right<n){
        if(arr[right]==0) zero++;
        if(zero>k){ 
            if(arr[left]==0) zero--;
            left++;
        }
        if(zero<=k){
            maxlength=max(maxlength,right-left+1);
        }
        right++;
    }
    return maxlength;
}

int main() {
    int n;

    cout << "Enter number of elements : ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements that only include 0 and 1 : " << endl;
    for (int i = 0; i < n; i++)   // input loop
        cin >> arr[i];

    int k;
    cout << "Enter k that you need to convert 0 to 1 : ";
    cin >> k;

    int ans = Max_consecutive_ones(arr, n, k);
    cout << ans << endl;

    return 0;
}


