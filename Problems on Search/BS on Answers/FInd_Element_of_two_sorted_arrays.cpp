#include <iostream>
#include <vector>
using namespace std;


// =============================================================
// PROBLEM:
// -------------------------------------------------------------
// Given two SORTED arrays, find the POSITION (1-based index)
// of a given element (targetValue) in the merged sorted array
// WITHOUT actually merging the arrays.
//
// If element not present → return -1
//
// Example:
// arr1 = [1,4,7]
// arr2 = [2,3,9]
// target = 4
//
// merged = [1,2,3,4,7,9]
// position = 4
// =============================================================



// =============================================================
// FUNCTION: findElementPosition
// -------------------------------------------------------------
// Uses merge-sort style traversal (two pointers)
//
// IDEA:
// Move pointers like merge process
// Count index
// When target found → return position
//
// Time Complexity  : O(n1 + n2)
// Space Complexity : O(1)
// =============================================================
int findElementPosition(vector<int>& array1,
                        vector<int>& array2,
                        int size1,
                        int size2,
                        int targetValue)
{
    int pointer1 = 0;      // pointer for array1
    int pointer2 = 0;      // pointer for array2
    int mergedIndex = 0;   // current position in merged array


    // ---------------------------------------------------------
    // Traverse both arrays simultaneously
    // ---------------------------------------------------------
    while(pointer1 < size1 && pointer2 < size2){

        int currentElement;

        // choose smaller element (merge logic)
        if(array1[pointer1] < array2[pointer2]){
            currentElement = array1[pointer1];
            pointer1++;
        }
        else{
            currentElement = array2[pointer2];
            pointer2++;
        }

        mergedIndex++;  // increase merged position

        // if element matches target, return position
        if(currentElement == targetValue){
            return mergedIndex;
        }
    }


    // ---------------------------------------------------------
    // Check remaining elements of array1
    // ---------------------------------------------------------
    while(pointer1 < size1){

        mergedIndex++;

        if(array1[pointer1] == targetValue){
            return mergedIndex;
        }
        pointer1++;
    }


    // ---------------------------------------------------------
    // Check remaining elements of array2
    // ---------------------------------------------------------
    while(pointer2 < size2){

        mergedIndex++;

        if(array2[pointer2] == targetValue){
            return mergedIndex;
        }
        pointer2++;
    }


    // if not found
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


    // input sorted array1
    cout << "Enter sorted elements for array 1:" << endl;
    for(int i = 0; i < size1; i++){
        cin >> array1[i];
    }

    // input sorted array2
    cout << "Enter sorted elements for array 2:" << endl;
    for(int i = 0; i < size2; i++){
        cin >> array2[i];
    }


    int targetValue;
    cout << "Enter element to find: ";
    cin >> targetValue;


    int answer = findElementPosition(array1, array2, size1, size2, targetValue);


    if(answer == -1)
        cout << "Element not found" << endl;
    else
        cout << "Position in merged array: " << answer << endl;

    return 0;
}



// =============================================================
// QUICK NOTES (for exam revision)
// -------------------------------------------------------------
// • Two pointers → simulate merging
// • Compare elements → move smaller
// • Count position
// • Stop when found
//
// Time  = O(n1 + n2)
// Space = O(1)
//
// =============================================================
