#include<iostream>
#include<vector>
#include <cmath>
#include<algorithm>
using namespace std;

// =============================================================
// PROBLEM DESCRIPTION:
// -------------------------------------------------------------
// Given weights of packages and a number of days,
// find the MINIMUM ship capacity so that all packages
// can be shipped within the given days.
// Packages must be shipped in order.
// =============================================================


// Function to calculate days required for a given capacity
int day_require(vector<int>& arr, int n, int capacity){

    int days = 1;     // At least one day
    int load = 0;

    for(int i = 0; i < n; i++){

        if(load + arr[i] > capacity){
            days++;
            load = arr[i];
        }
        else{
            load += arr[i];
        }
    }
    return days;
}


// Binary Search solution
int Capacityof_ship_within_d_days(vector<int>& arr, int n, int days){

    int low = *max_element(arr.begin(), arr.end()); // minimum capacity
    int high = 0;

    for(int i = 0; i < n; i++){
        high += arr[i];  // maximum capacity
    }

    int ans = high;

    while(low <= high){

        int mid = low + (high - low) / 2;

        int required_days = day_require(arr, n, mid);

        // If capacity works, try smaller one because i need more smaller capacity 
        // so we need to mid-1     12345678910 mid=55/2= 32 so day require is 2<5 so mid-1 
        if(required_days <= days){
            ans = mid;
            high = mid - 1;
        }
        else{
            // Capacity too small
            low = mid + 1;
        }
    }

    return ans; //you can also return the low insted of the ans
}

int main(){

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements: " << endl;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int days;
    cout << "Enter how many days: ";
    cin >> days;

    int ans = Capacityof_ship_within_d_days(arr, n, days);

    cout << "Minimum ship capacity required: " << ans << endl;

    return 0;
}


// =============================================================
// ADDITIONAL EXPLANATION
// =============================================================
//
// PROBLEM IDEA:
// -------------------------------------------------------------
// The capacity range is sorted:
// minimum = max element
// maximum = sum of all elements
//
// We use binary search to find the smallest capacity
// that ships all packages within given days.
//
// -------------------------------------------------------------
// EXAMPLE:
// -------------------------------------------------------------
// arr = [1,2,3,4,5,6,7,8,9,10]
// days = 5
//
// Capacity = 15 → valid
// Capacity = 14 → not valid
//
// Answer = 15
//
// -------------------------------------------------------------
// EDGE CASES:
// -------------------------------------------------------------
// 1. days == n → answer = max element
// 2. days == 1 → answer = sum of all elements
// 3. Single package → capacity = package weight
//
// -------------------------------------------------------------
// IMPORTANT LINES:
// -------------------------------------------------------------
// low = max_element
// - Ship must carry at least the heaviest package
//
// if(required_days <= days)
// - Capacity is valid, try smaller one
//
// -------------------------------------------------------------
// TIME COMPLEXITY:
// -------------------------------------------------------------
// day_require → O(n)
// Binary Search → O(log(sum))
//
// Total = O(n log sum)
//
// -------------------------------------------------------------
// SPACE COMPLEXITY:
// -------------------------------------------------------------
// O(1) extra space
//
// -------------------------------------------------------------
// NOTE:
// -------------------------------------------------------------
// This is the OPTIMAL solution.
// Frequently asked in interviews & exams.
//
// =============================================================
