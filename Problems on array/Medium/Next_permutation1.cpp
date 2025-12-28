#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Next permutation means the next bigger arrangement of the same numbers
// Given a sequence, the next permutation is the smallest permutation that is greater than the current one.
// 1,2,3 next is 1,3,2 which is closest 1,3,2 closest is 2,1,3 then 231 then 312 then 321
vector<int> Nextpermutation(vector<int>& arr, int n){       //2,1,5,4,3,0,0
    int index = -1;
    // Step 1: Find the break point
    for(int i = n - 2; i >= 0; i--){        //start from n-2 because 
        if(arr[i] < arr[i + 1]){            //arr[5]=0 and arr[6]=0 
            index = i;
            break;
        }
    }
    // Start from right: compare arr[i] with arr[i+1]
    // i=5: 0 > 0 ✓ (decreasing)
    // i=4: 3 > 0 ✓ (decreasing)
    // i=3: 4 > 3 ✓ (decreasing)
    // i=2: 5 > 4 
    // i=1: 1 < 5 ✗ Break point found at index=2

    // Step 2: If no breakpoint found → last permutation
    if(index == -1){
        reverse(arr.begin(), arr.end());    //3,2,1, then 1,2,3
        return arr;
    }


    // Step 3: Swap with next greater element
    for(int i = n - 1; i > index; i--){
        if(arr[i] > arr[index]){
            swap(arr[i], arr[index]);
            break;
        }
    }
    // From right, find first element > arr[2] (which is 1)
    // i=6: 0 > 1? No
    // i=5: 0 > 1? No
    // i=4: 3 > 1? Yes → swap arr[2] and arr[4]

    // Step 4: Reverse remaining part
    reverse(arr.begin() + index + 1, arr.end());
    return arr;
    // Reverse from index+1 to end: [5, 4, 1, 0, 0] becomes [0, 0, 1, 4, 5]
    // Final: [2, 3, 0, 0, 1, 4, 5]
}

int main(){
    int n;
    cout << "Enter number of elements : ";
    cin >> n;
    
    cout << "Enter Elements :" << endl;

    vector<int> arr(n);
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    vector<int> ans = Nextpermutation(arr, n);
    
    cout << "Next Permutation is : ";
    for(int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    
    return 0;
}
