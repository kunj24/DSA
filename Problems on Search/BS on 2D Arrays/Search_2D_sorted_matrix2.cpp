#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to perform binary search on a 1D vector
    bool binarySearch(vector<int>& nums, int target) {
        // Get the size of the array
        int n = nums.size();

        // Initialize low and high pointers for binary search
        int low = 0, high = n - 1;

        // Binary search loop
        while (low <= high) {
            // Calculate the middle index
            int mid = (low + high) / 2;

            // If the middle element is the target, return true
            if (nums[mid] == target)
                return true;

            // If the target is greater, move to the right half
            else if (target > nums[mid])
                low = mid + 1;

            // Otherwise, move to the left half
            else
                high = mid - 1;
            
        }

        // Return false if target not found
        return false;
    }

    // Function to search for target in the 2D matrix
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Get the number of rows
        int n = matrix.size();

        // Get the number of columns
        int m = matrix[0].size();

        // Traverse each row
        for (int i = 0; i < n; i++) {
            // Check if target could be within this row
            if (matrix[i][0] <= target && target <= matrix[i][m - 1]) {
                // Apply binary search on the current row
                return binarySearch(matrix[i], target);
            }
        }

        // Return false if target is not found in any row
        return false;
    }
};

// Driver code
int main() {
    // Define a 2D matrix
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    // Create an object of the Solution class
    Solution obj;

    // Call the searchMatrix function and print the result
    if (obj.searchMatrix(matrix, 8))
        cout << "true\n";
    else
        cout << "false\n";

    return 0;
}
