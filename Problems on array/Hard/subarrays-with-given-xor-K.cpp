#include<iostream>
#include<vector>
using namespace std;

// Function returns count of subarrays with XOR equal to Target
int countSubarraysWithXOR(vector<int>& arr, int n, int Target){
    int count = 0;
    
    // Generate all subarrays and check their XOR
    for(int i = 0; i < n; i++){
        int xorval = 0;
        for(int j = i; j < n; j++){
            xorval = xorval ^ arr[j];  // XOR of subarray arr[i..j]
            if(xorval == Target){
                count++;
            }
        }
    }
    return count;
}

int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    
    cout << "Enter " << n << " elements: ";
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    int Target;
    cout << "Enter Target XOR value: ";
    cin >> Target;
    
    int ans = countSubarraysWithXOR(arr, n, Target);
    cout << "Number of subarrays with XOR = " << Target << ": " << ans << endl;
    
    return 0;
}

// n = 4
// arr = [4, 2, 2, 6]
// Target = 6


// [4] = 4
// [4,2] = 4^2 = 6 ✓ count=1
// [4,2,2] = 4^2^2 = 4
// [4,2,2,6] = 4^2^2^6 = 2

// [2] = 2
// [2,2] = 2^2 = 0
// [2,2,6] = 2^2^6 = 6 ✓ count=2

// [2] = 2
// [2,6] = 2^6 = 4

// [6] = 6 ✓ count=3
