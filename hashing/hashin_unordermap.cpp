#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements to insert: ";
    cin >> n;
    
    int arr[n];
    cout << "Enter " << n << " numbers: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    unordered_map<int, int> mpp;
    for(int i = 0; i < n; i++) {
        mpp[arr[i]]++;
    }
    
    cout << "\nFrequency count (unordered):" << endl;
    for(auto it : mpp) {
        cout << it.first << " -> " << it.second << endl;
    }
    int maxFreq = 0, minFreq = n;
    int maxEle = 0, minEle = 0;
    
    for (auto it : mpp) {
        if (it.second > maxFreq) {
            maxFreq = it.second;
            maxEle = it.first;
        }
        if (it.second < minFreq) {
            minFreq = it.second;
            minEle = it.first;
        }
    }
    
 // Display results
    cout << "Analysis Results:\n";
    cout << "=================\n";
    cout << "Highest frequency element: " << maxEle << " (appears " << maxFreq << " times)\n";
    cout << "Lowest frequency element: " << minEle << " (appears " << minFreq << " times)\n\n";
    
    int q;
    cout << "\nEnter number of queries: ";
    cin >> q;
    cout << "Enter " << q << " numbers to query:" << endl;
    
    while(q--) {
        int x;
        cin >> x;
        cout << "Frequency of " << x << " = " << mpp[x] << endl;
    }
    
    return 0;
}