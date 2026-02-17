#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// =============================================================
// PROBLEM DESCRIPTION:
// -------------------------------------------------------------
// We have n books with pages.
// Allocate books to k students such that:
// 1. Books are contiguous
// 2. Each student gets at least one book
// 3. Maximum pages assigned to a student is minimized
//
// Return that minimum possible maximum pages.
// If k > n → return -1
// =============================================================



// -------------------------------------------------------------
// Count how many students are required for given page limit
// -------------------------------------------------------------
int count_student(vector<int>& arr, int n, int page_limit){

    int pagesum = 0;
    int student = 1;

    for(int i = 0; i < n; i++){

        if(pagesum + arr[i] <= page_limit){
            pagesum += arr[i];
        }
        else{
            student++;
            pagesum = arr[i];
        }
    }

    return student;
}



// -------------------------------------------------------------
// BRUTE FORCE solution
// Try every possible page limit
// -------------------------------------------------------------
int Find_pages(vector<int>& arr, int n, int k){

    if(k > n) return -1;

    int low = *max_element(arr.begin(), arr.end()); // minimum

    int high = 0;  // maximum
    for(int i = 0; i < n; i++){
        high += arr[i];
    }

    for(int page = low; page <= high; page++){

        // if possible within k students
        if(count_student(arr, n, page) <= k){
            return page;
        }
    }

    return -1;
}



int main(){

    int n;
    cout << "Enter number of Books: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter pages of each book:" << endl;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int k;
    cout << "Enter number of students: ";
    cin >> k;

    int ans = Find_pages(arr, n, k);

    cout << "Minimum possible maximum pages: " << ans << endl;

    return 0;
}



// =============================================================
// ADDITIONAL EXPLANATION
// =============================================================
//
// PROBLEM IDEA:
// -------------------------------------------------------------
// We want to minimize the maximum pages any student reads.
// So we try page limits from low to high and check feasibility.
//
// -------------------------------------------------------------
// EXAMPLE:
// -------------------------------------------------------------
// arr = [12, 34, 67, 90]
// k = 2
//
// limit = 113
// student1 → 12+34+67
// student2 → 90
//
// Answer = 113
//
// -------------------------------------------------------------
// EDGE CASES:
// -------------------------------------------------------------
// 1. k > n → impossible → -1
// 2. k = 1 → answer = sum
// 3. k = n → answer = max element
//
// -------------------------------------------------------------
// IMPORTANT LINES:
// -------------------------------------------------------------
// low = max_element → at least largest book must fit
// high = sum → one student takes all books
//
// -------------------------------------------------------------
// TIME COMPLEXITY (BRUTE):
// -------------------------------------------------------------
// O(n * sum)
//
// -------------------------------------------------------------
// SPACE COMPLEXITY:
// -------------------------------------------------------------
// O(1)
//
// -------------------------------------------------------------
// NOTE:
// -------------------------------------------------------------
// This is brute force.
// Optimal approach uses Binary Search → O(n log sum).
//
// =============================================================
