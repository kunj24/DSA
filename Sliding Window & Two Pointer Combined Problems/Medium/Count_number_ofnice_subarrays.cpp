#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int count_nice_subarray(const vector<int>& arr, int k) {
    int count=0;
    for(int i=0;i<arr.size();i++){
        int oddCount=0;
        for(int j=i;j<arr.size();j++){
            if(arr[j]%2!=0){
                oddCount++;
            }
            if(oddCount>k) break;
            if(oddCount==k){
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
    cout << "Enter " << n << " elements :" << endl;
    for (int i = 0; i < n; i++)   // input loop
        cin >> arr[i];

    int k;
    cout << "Enter target that the array contain the k odd element : ";
    cin >> k;

    int ans = count_nice_subarray(arr, k);   // corrected function call

    cout << "There are " << ans 
         << " subarrays with oddElement exactly equal to " << k << endl;

    return 0;
}
