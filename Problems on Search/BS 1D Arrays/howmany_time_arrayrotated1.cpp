#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int countRotations(const vector<int>& arr) {

    for(int i=0;i<arr.size()-1;i++){
        if(arr[i]>arr[i+1]){
            return i+1;
        }
    }
    return -1;
}

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements (ROTATED SORTED): ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];


    int rotations = countRotations(arr);

    cout << "Array is rotated " << rotations << " times." << endl;
    return 0;
}

