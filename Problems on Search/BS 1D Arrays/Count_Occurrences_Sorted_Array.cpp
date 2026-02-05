#include <iostream>
#include <vector>
using namespace std;


int occurencesinarray(const vector<int>& arr, int target) {
    int count=0;
    for(int i=0;i<arr.size();i++){
        if(arr[target]==arr[i]){
            count++;
        }
    }
    return count;
}

int main() {
    int n, target;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " Sorted  elements: " << endl;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << "Enter target element: ";
    cin >> target;

    int ans=occurencesinarray(arr, target);
    
    cout << "The number of occurrences of "<<target <<" is: " <<ans;

    return 0;
}


