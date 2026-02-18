#include<iostream>
#include<vector>
#include <cmath>
#include<algorithm>
using namespace std;

// =============================================================
// PROBLEM DESCRIPTION:
// -------------------------------------------------------------
// You are given an array where each element represents the
// weight of a package. You must ship all packages within
// a given number of days.
//
// Each day, you can ship packages in order without exceeding
// the ship's capacity.
//
// Find the MINIMUM ship capacity required to ship all packages
// within the given number of days.
// =============================================================


// Function to calculate how many days are required
// for a given ship capacity
int day_require(vector<int>& arr, int n, int capacity){

    int days = 1;   // At least one day is required
    int load = 0;

    for(int i = 0; i < n; i++){

        // If adding current package exceeds capacity
        // start a new day
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


// Brute-force solution to find minimum capacity
int Capacityof_ship_within_d_days(vector<int>& arr, int n, int days){

    int max_element_of_array = *max_element(arr.begin(), arr.end());

    int total_sum = 0;
    for(int i = 0; i < n; i++){
        total_sum += arr[i];
    }

    // Try every possible capacity
    for(int capacity = max_element_of_array; capacity <= total_sum; capacity++){

        int required_days = day_require(arr, n, capacity);

        if(required_days <= days){
            return capacity;   // Return capacity (NOT days)
        }
    }

    return -1;
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
// We want the smallest ship capacity such that all packages
// can be shipped within the given number of days.
// Packages must be shipped in order.
//
// -------------------------------------------------------------
// EXAMPLE:
// -------------------------------------------------------------
// arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
// days = 5
//
// Capacity = 15
// Day 1: 1 + 2 + 3 + 4 + 5 = 15
// Day 2: 6 + 7 = 13
// Day 3: 8
// Day 4: 9
// Day 5: 10
//
// Output = 15
//
// -------------------------------------------------------------
// EDGE CASES:
// -------------------------------------------------------------
// 1. Minimum capacity = max element of array
// 2. Maximum capacity = sum of all elements
// 3. If days == n, capacity = max element
// 4. Single package → capacity = that package
//
// -------------------------------------------------------------
// IMPORTANT LINES:
// -------------------------------------------------------------
// if(load + arr[i] > capacity)
// - Start a new day if capacity exceeded
//
// for(int capacity = max_element; capacity <= total_sum; capacity++)
// - Try all valid capacities
//
// -------------------------------------------------------------
// TIME COMPLEXITY:
// -------------------------------------------------------------
// Capacity range = total_sum - max_element
// For each capacity, we scan array
//
// Time Complexity = O(n * sum)
//
// -------------------------------------------------------------
// SPACE COMPLEXITY:
// -------------------------------------------------------------
// O(1) extra space
//
// -------------------------------------------------------------
// NOTE:
// -------------------------------------------------------------
// This is a BRUTE-FORCE solution.
// It can be optimized using BINARY SEARCH to
// O(n log(sum)).
//
// =============================================================
