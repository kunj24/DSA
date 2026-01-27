#include <iostream>
#include <vector>
using namespace std;

// Function to count reverse pairs
int calculate(vector<int>& arr, int n) {

    int count = 0;  // stores number of reverse pairs

    // i goes from 0 to n-1
    for (int i = 0; i < n; i++) {

        // j always starts from i+1 (i < j condition)
        for (int j = i + 1; j < n; j++) {

            // Check reverse pair condition
            if (arr[i] > 2 * arr[j]) {
                count++;  // valid reverse pair found
            }
        }
    }

    return count;
}

int main() {

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int ans = calculate(arr, n);

    cout << "Number of reverse pairs: " << ans << endl;

    return 0;
}



//This is the optimal approach of this problem based on the merge sort 

// #include <bits/stdc++.h>
// using namespace std;

// void merge(vector<int> &arr, int low, int mid, int high) {
//     vector<int> temp; // temporary array
//     int left = low;      // starting index of left half of arr
//     int right = mid + 1;   // starting index of right half of arr

//     //storing elements in the temporary array in a sorted manner//

//     while (left <= mid && right <= high) {
//         if (arr[left] <= arr[right]) {
//             temp.push_back(arr[left]);
//             left++;
//         }
//         else {
//             temp.push_back(arr[right]);
//             right++;
//         }
//     }

//     // if elements on the left half are still left //

//     while (left <= mid) {
//         temp.push_back(arr[left]);
//         left++;
//     }

//     //  if elements on the right half are still left //
//     while (right <= high) {
//         temp.push_back(arr[right]);
//         right++;
//     }

//     // transfering all elements from temporary to arr //
//     for (int i = low; i <= high; i++) {
//         arr[i] = temp[i - low];
//     }
// }

// int countPairs(vector<int> &arr, int low, int mid, int high) {
//     int right = mid + 1;
//     int cnt = 0;
//     for (int i = low; i <= mid; i++) {
//         while (right <= high && arr[i] > 2 * arr[right]) right++;
//         cnt += (right - (mid + 1));
//     }
//     return cnt;
// }

// int mergeSort(vector<int> &arr, int low, int high) {
//     int cnt = 0;
//     if (low >= high) return cnt;
//     int mid = (low + high) / 2 ;
//     cnt += mergeSort(arr, low, mid);  // left half
//     cnt += mergeSort(arr, mid + 1, high); // right half
//     cnt += countPairs(arr, low, mid, high); //Modification
//     merge(arr, low, mid, high);  // merging sorted halves
//     return cnt;
// }

// int team(vector <int> & skill, int n)
// {
//     return mergeSort(skill, 0, n - 1);
// }

// int main()
// {
//     vector<int> a = {4, 1, 2, 3, 1};
//     int n = 5;
//     int cnt = team(a, n);
//     cout << "The number of reverse pair is: "
//          << cnt << endl;
//     return 0;
// }
