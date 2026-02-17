#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// =============================================================
// PROBLEM DESCRIPTION:
// -------------------------------------------------------------
// We are given pages of books and k students.
// Each student must get contiguous books.
// Allocate books such that the MAX pages assigned to a student
// is MINIMIZED.
//
// Return the minimum possible maximum pages.
// If students > books → return -1.
// =============================================================



// -------------------------------------------------------------
// Count how many students are required for given page limit
// -------------------------------------------------------------
int count_student(vector<int>& arr, int n, int page_limit){

    int pagesum = 0;
    int student = 1;

    for(int i = 0; i < n; i++){

        // assign book to current student
        if(pagesum + arr[i] <= page_limit){
            pagesum += arr[i];
        }
        else{
            // allocate to next student
            student++;
            pagesum = arr[i];
        }
    }
    return student;
}



// -------------------------------------------------------------
// Binary Search on Answer
// -------------------------------------------------------------
int Find_pages(vector<int>& arr, int n, int k){

    if(k > n) return -1;   // not possible

    int low = *max_element(arr.begin(), arr.end());  // minimum
    int high = 0;

    for(int i = 0; i < n; i++){
        high += arr[i];   // maximum
    }

    int ans = high;

    while(low <= high){

        int mid = low + (high - low) / 2;

        int required_students = count_student(arr, n, mid);

        // If possible, try smaller page limit
        if(required_students <= k){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    return ans;
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
// We want to minimize the maximum pages assigned to any student.
// Search space is sorted:
// low  = max book pages
// high = sum of all pages
//
// Use binary search to find smallest valid limit.
//
// -------------------------------------------------------------
// EXAMPLE:
// -------------------------------------------------------------
// arr = [12, 34, 67, 90]
// k = 2
//
// allocation:
// student1 → 12+34+67 = 113
// student2 → 90
//
// answer = 113
//
// -------------------------------------------------------------
// EDGE CASES:
// -------------------------------------------------------------
// 1. k > n → not possible → return -1
// 2. k = 1 → answer = sum
// 3. k = n → answer = max element
//
// -------------------------------------------------------------
// IMPORTANT LINES:
// -------------------------------------------------------------
// low = max_element
// - at least largest book must fit
//
// high = sum
// - one student takes all books
//
// required_students <= k
// - feasible solution
//ṇ
// -------------------------------------------------------------
// TIME COMPLEXITY:
// -------------------------------------------------------------
// count_student → O(n)
// Binary Search → O(log(sum))
//
// Total = O(n log sum)
//
// -------------------------------------------------------------
// SPACE COMPLEXITY:
// -------------------------------------------------------------
// O(1)
//
// -------------------------------------------------------------
// NOTE:
// -------------------------------------------------------------
// Classic interview problem:
// "Book Allocation" / "Allocate Minimum Pages"
//
// =============================================================
