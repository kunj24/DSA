#include <iostream>
#include <vector>
using namespace std;


int kth_missing_number(const vector<int>& arr, int n,int k) {
    for(int i=0;i<n;i++){
        if(arr[i]<k){
            k++;
        }
        else{
            break;
        }
    }
    return k;
}

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements: " << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int k;
    cout<<"Enter a kth Missing number :";
    cin>>k;
    int ans = kth_missing_number(arr, n, k);
    cout << "Kth missing number is : " << ans << endl;

    return 0;
}


