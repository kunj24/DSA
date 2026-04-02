#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int subarray_with_sum(const vector<int>& arr, int n, int k) {
    int count=0;
    for(int i=0;i<arr.size();i++){
        int sum=0;
        for(int j=i;j<arr.size();j++){
            sum+=arr[j];
            if(sum==k){
                count++;
            }
        }
    }
    return count;
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
    cout << "Enter a goal that you need : ";
    cin >> k;

    int ans = subarray_with_sum(arr, n, k);
    cout << "There are "<<ans<<" subarrays with sum exactly equal to "<< k << endl;
    cout<<"so ans is "<<ans;

    return 0;
}