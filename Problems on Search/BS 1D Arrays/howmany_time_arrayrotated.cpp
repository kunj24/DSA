#include <iostream>
#include <vector>
#include <climits>
using namespace std;


int countRotations(const vector<int>& arr) {

    int minval=arr[0];
    int minindex=0;
    for(int i=0;i<arr.size()-1;i++){
        if(arr[i]<minval){
            minval=arr[i];
            minindex=i;
        }
    }
    return minindex;
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

