#include <iostream>
#include <vector>
using namespace std;


// =============================================================
// PROBLEM:
// -------------------------------------------------------------
// Given two SORTED arrays,
// find the element at position k (1-based index)
// in the merged sorted array WITHOUT actually merging.
//
// Example:
// arr1 = [1,4,7]
// arr2 = [2,3,9]
// k = 4
//
// merged = [1,2,3,4,7,9]
// answer = 4
// =============================================================



// =============================================================
// FUNCTION: findKthElement
// -------------------------------------------------------------
// Use merge-like traversal with two pointers
// Count elements while traversing
// When count == k → return that element
//
// Time Complexity  : O(n1 + n2)
// Space Complexity : O(1)
// =============================================================
int findKthElement(vector<int>& array1, vector<int>& array2, int size1, int size2, int k)
{
    int pointer1 = 0;     // pointer for first array
    int pointer2 = 0;     // pointer for second array
    int currentIndex = 0; // merged index counter


    // ---------------------------------------------------------
    // Traverse both arrays together
    // ---------------------------------------------------------
    while(pointer1 < size1 && pointer2 < size2){

        int currentElement;

        // take smaller element (merge logic)
        if(array1[pointer1] < array2[pointer2]){
            currentElement = array1[pointer1];
            pointer1++;
        }
        else{
            currentElement = array2[pointer2];
            pointer2++;
        }

        currentIndex++;

        // when we reach kth position, return element
        if(currentIndex == k){
            return currentElement;
        }
    }


    // ---------------------------------------------------------
    // Remaining elements of array1
    // ---------------------------------------------------------
    while(pointer1 < size1){

        currentIndex++;

        if(currentIndex == k){
            return array1[pointer1];
        }

        pointer1++;
    }


    // ---------------------------------------------------------
    // Remaining elements of array2
    // ---------------------------------------------------------
    while(pointer2 < size2){

        currentIndex++;

        if(currentIndex == k){
            return array2[pointer2];
        }

        pointer2++;
    }


    // if k is invalid
    return -1;
}



int main() {

    int size1, size2;

    cout << "Enter number of elements for array 1: ";
    cin >> size1;

    cout << "Enter number of elements for array 2: ";
    cin >> size2;

    vector<int> array1(size1);
    vector<int> array2(size2);


    // input sorted arrays
    cout << "Enter sorted elements for array 1:" << endl;
    for(int i = 0; i < size1; i++){
        cin >> array1[i];
    }

    cout << "Enter sorted elements for array 2:" << endl;
    for(int i = 0; i < size2; i++){
        cin >> array2[i];
    }


    int k;
    cout << "Enter index (k): ";
    cin >> k;


    int answer = findKthElement(array1, array2, size1, size2, k);

    cout << "Element at index " << k << " is: " << answer << endl;

    return 0;
}



// =============================================================
// QUICK REVISION NOTES
// -------------------------------------------------------------
// • Two pointers merge logic
// • Count index
// • Stop at kth position
//
// Time  = O(n1 + n2)
// Space = O(1)
//
// NOTE:
// Can be optimized to O(log(min(n1,n2))) using binary search
// =============================================================
