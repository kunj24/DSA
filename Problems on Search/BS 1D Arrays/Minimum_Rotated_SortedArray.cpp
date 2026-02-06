#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Find minimum element in rotated sorted array
int findMinimumRotatedArray(const vector<int>& arr) {

    int ans = INT_MAX;
    for(int i=0;i<arr.size()-1;i++){
        ans=min(ans,arr[i]);
    }
    return ans;
}

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements (ROTATED SORTED): ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int result = findMinimumRotatedArray(arr);

    cout << "Minimum element in rotated sorted array: " << result << endl;

    return 0;
}

