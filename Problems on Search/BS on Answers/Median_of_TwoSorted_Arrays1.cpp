#include <iostream>
#include <vector>
using namespace std;

// =============================================================
// PROBLEM DESCRIPTION:
// -------------------------------------------------------------
// Given two sorted arrays, find the median of the combined array
// without fully merging them.
//
// We simulate merging using two pointers.
// =============================================================

// =============================================================
// FUNCTION: findMedianSortedArrays
// -------------------------------------------------------------
// Merge-like traversal to find middle element(s)
// Time Complexity: O(n1 + n2)
// Space Complexity: O(1)
// =============================================================
double findMedianSortedArrays(vector<int>& array1, vector<int>& array2, int size1, int size2) {
    int totalSize = size1 + size2;
    int medianIndex2 = totalSize / 2;
    int medianIndex1 = medianIndex2 - 1;
    
    int elementAtIndex1 = -1;
    int elementAtIndex2 = -1;
    
    int pointer1 = 0;
    int pointer2 = 0;
    int currentIndex = 0;

    // ---------------------------------------------------------
    // Traverse both arrays like merge step of merge sort
    // ---------------------------------------------------------
    while(pointer1 < size1 && pointer2 < size2) {
        int currentElement;
        
        if(array1[pointer1] < array2[pointer2]) {
            currentElement = array1[pointer1];
            pointer1++;
        } else {
            currentElement = array2[pointer2];
            pointer2++;
        }

        if(currentIndex == medianIndex1) elementAtIndex1 = currentElement;
        if(currentIndex == medianIndex2) elementAtIndex2 = currentElement;
        
        currentIndex++;
    }

    // ---------------------------------------------------------
    // Process remaining elements of array1
    // ---------------------------------------------------------
    while(pointer1 < size1) {
        int currentElement = array1[pointer1];
        pointer1++;
        if(currentIndex == medianIndex1) elementAtIndex1 = currentElement;
        if(currentIndex == medianIndex2) elementAtIndex2 = currentElement;
        currentIndex++;
    }

    // ---------------------------------------------------------
    // Process remaining elements of array2
    // ---------------------------------------------------------
    while(pointer2 < size2) {
        int currentElement = array2[pointer2];
        pointer2++;
        if(currentIndex == medianIndex1) elementAtIndex1 = currentElement;
        if(currentIndex == medianIndex2) elementAtIndex2 = currentElement;
        currentIndex++;
    }

    // ---------------------------------------------------------
    // Return median
    // ---------------------------------------------------------
    if(totalSize % 2 == 1)
        return elementAtIndex2;
    else
        return (elementAtIndex1 + elementAtIndex2) / 2.0;
}

int main() {
    int size1, size2;

    cout << "Enter number of elements for array 1 : ";
    cin >> size1;

    cout << "Enter number of elements for array 2: ";
    cin >> size2;

    vector<int> array1(size1);
    vector<int> array2(size2);

    cout << "Enter " << size1 << " Sorted  elements for array 1 in sorted order of array 1 : " << endl;
    for(int i = 0; i < size1; i++){
        cin >> array1[i];
    }

    cout << "Enter " << size2 << " Sorted  elements for array 2 in sorted order of array 2 : " << endl;
    for(int i = 0; i < size2; i++){
        cin >> array2[i];
    }

    double answer = findMedianSortedArrays(array1, array2, size1, size2);

    cout << "Median of the two arrays: " << answer << endl;

    return 0;
}

// =============================================================
// MULTIPLE TEST CASES WITH EXPLANATIONS:
// =============================================================

// TEST CASE 1: Equal sized arrays, even total length
// -------------------------------------------------------------
// array1 = [1, 3]
// array2 = [2, 4]
// Combined: [1, 2, 3, 4]
// Total size = 4 (even)
// medianIndex1 = 1, medianIndex2 = 2
// Elements needed: ans[1] and ans[2]
// Simulation:
//   currentIndex=0: 1 (not median)
//   currentIndex=1: 2 (ans[1] = 2)
//   currentIndex=2: 3 (ans[2] = 3)
// Median = (2 + 3) / 2 = 2.5
// -------------------------------------------------------------

// TEST CASE 2: Equal sized arrays, odd total length
// -------------------------------------------------------------
// array1 = [1, 3, 5]
// array2 = [2, 4]
// Combined: [1, 2, 3, 4, 5]
// Total size = 5 (odd)
// medianIndex2 = 2 (only need ans[2])
// Simulation:
//   currentIndex=0: 1
//   currentIndex=1: 2
//   currentIndex=2: 3 (ans[2] = 3)
// Median = 3
// -------------------------------------------------------------

// TEST CASE 3: First array larger
// -------------------------------------------------------------
// array1 = [10, 20, 30, 40, 50]
// array2 = [15, 25]
// Combined: [10, 15, 20, 25, 30, 40, 50]
// Total size = 7 (odd)
// medianIndex2 = 3
// Simulation:
//   currentIndex=0: 10
//   currentIndex=1: 15
//   currentIndex=2: 20
//   currentIndex=3: 25 (ans[3] = 25)
// Median = 25
// -------------------------------------------------------------

// TEST CASE 4: Second array larger
// -------------------------------------------------------------
// array1 = [5, 15]
// array2 = [10, 20, 30, 40, 50]
// Combined: [5, 10, 15, 20, 30, 40, 50]
// Total size = 7 (odd)
// medianIndex2 = 3
// Simulation:
//   currentIndex=0: 5
//   currentIndex=1: 10
//   currentIndex=2: 15
//   currentIndex=3: 20 (ans[3] = 20)
// Median = 20
// -------------------------------------------------------------

// TEST CASE 5: One array empty
// -------------------------------------------------------------
// array1 = [1, 2, 3, 4, 5]
// array2 = []
// Combined: [1, 2, 3, 4, 5]
// Total size = 5 (odd)
// medianIndex2 = 2
// Simulation (only array1 processes):
//   currentIndex=0: 1
//   currentIndex=1: 2
//   currentIndex=2: 3 (ans[2] = 3)
// Median = 3
// -------------------------------------------------------------

// TEST CASE 6: Both arrays empty (edge case - won't work with current code)
// -------------------------------------------------------------
// array1 = []
// array2 = []
// Combined: []
// Total size = 0
// Need to handle separately (current code would crash)
// -------------------------------------------------------------

// TEST CASE 7: Arrays with negative numbers
// -------------------------------------------------------------
// array1 = [-5, -3, -1]
// array2 = [-4, -2, 0]
// Combined: [-5, -4, -3, -2, -1, 0]
// Total size = 6 (even)
// medianIndex1 = 2, medianIndex2 = 3
// Simulation:
//   currentIndex=0: -5
//   currentIndex=1: -4
//   currentIndex=2: -3 (ans[2] = -3)
//   currentIndex=3: -2 (ans[3] = -2)
// Median = (-3 + -2) / 2 = -2.5
// -------------------------------------------------------------

// TEST CASE 8: Arrays with duplicates
// -------------------------------------------------------------
// array1 = [1, 2, 2, 3]
// array2 = [2, 4, 4]
// Combined: [1, 2, 2, 2, 3, 4, 4]
// Total size = 7 (odd)
// medianIndex2 = 3
// Simulation:
//   currentIndex=0: 1
//   currentIndex=1: 2
//   currentIndex=2: 2
//   currentIndex=3: 2 (ans[3] = 2)
// Median = 2
// -------------------------------------------------------------

// TEST CASE 9: Large difference in array sizes
// -------------------------------------------------------------
// array1 = [100]
// array2 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
// Combined: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 100]
// Total size = 11 (odd)
// medianIndex2 = 5
// Simulation:
//   currentIndex=0: 1
//   currentIndex=1: 2
//   currentIndex=2: 3
//   currentIndex=3: 4
//   currentIndex=4: 5
//   currentIndex=5: 6 (ans[5] = 6)
// Median = 6
// -------------------------------------------------------------

// TEST CASE 10: All elements same
// -------------------------------------------------------------
// array1 = [5, 5, 5]
// array2 = [5, 5, 5, 5]
// Combined: [5, 5, 5, 5, 5, 5, 5]
// Total size = 7 (odd)
// medianIndex2 = 3
// Simulation:
//   currentIndex=0: 5
//   currentIndex=1: 5
//   currentIndex=2: 5
//   currentIndex=3: 5 (ans[3] = 5)
// Median = 5
// -------------------------------------------------------------