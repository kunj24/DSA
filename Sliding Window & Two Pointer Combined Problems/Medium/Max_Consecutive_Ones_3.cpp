#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Max_consecutive_ones(const vector<int>& arr, int n, int k) {
    int maxlength=0;
    for(int i=0;i<n;i++){
        int count=0;
        for(int j=0;j<n;j++){
            if(arr[j]==0){
                count++;
            }
            if(count>k){
                break;
            }
            maxlength=max(maxlength,j-i+1);
        }
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


