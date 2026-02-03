#include <iostream>
#include <vector>
using namespace std;

int findSingleElement(const vector<int>& arr) {
    int n = arr.size();
    int ans=0;
    for(int i=0;i<n;i++){
        ans=ans^arr[i];
    }
    return ans;  // no single element found
}

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements (SORTED): ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int result = findSingleElement(arr);

    if (result != -1)
        cout << "Single element is: " << result << endl;
    else
        cout << "No single element found" << endl;

    return 0;
}

