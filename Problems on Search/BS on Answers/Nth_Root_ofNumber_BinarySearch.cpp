#include <iostream>
using namespace std;

int NthRoot(int root, int target) {
    // Handle special cases
    if (target == 0) return 0;
    if (target == 1) return 1;
    
    // Try all possible numbers from 0 to target
    for (int num = 0; num <= target; num++) {
        long long power = 1;
        
        // Calculate num^root
        for (int i = 0; i < root; i++) {
            power *= num;
            
            // Early exit if power exceeds target
            if (power > target) break;
        }
        
        // Check if we found the root
        if (power == target) return num;
        
        // If power already > target, no need to continue
        if (power > target) break;
    }
    
    return -1;  // No integer root found
}

int main() {
    int root, target;
    
    cout << "Enter root value: ";
    cin >> root;
    
    cout << "Enter target number: ";
    cin >> target;
    
    int result = NthRoot(root, target);
    
    if (result != -1) {
        cout << root << "-th root of " << target << ":" << result << endl;
    } else {
        cout << "No integer " << root << "-th root for " << target << endl;
    }
    
    return 0;
}   