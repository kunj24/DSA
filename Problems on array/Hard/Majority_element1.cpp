#include<iostream>
#include<vector>
using namespace std;

vector<int> calculate(vector<int>& arr, int n){
    vector<int> result;
    
    if(n == 0) return result;
    
    int count1 = 0, count2 = 0;
    int candidate1 = -1, candidate2 = -1;
    
    // First pass: Find two potential candidates
    for(int i = 0; i < n; i++){
        int num = arr[i];
        
        if(num == candidate1){
            count1++;
        }
        else if(num == candidate2){
            count2++;
        }
        else if(count1 == 0){
            candidate1 = num;
            count1 = 1;
        }
        else if(count2 == 0){
            candidate2 = num;
            count2 = 1;
        }
        else{
            count1--;
            count2--;
        }
    }
    
    // Second pass: Verify candidates
    count1 = 0;
    count2 = 0;
    for(int i = 0; i < n; i++){
        int num = arr[i];
        if(num == candidate1){
            count1++;
        }
        else if(num == candidate2){
            count2++;
        }
    }
    
    if(count1 > n/3) result.push_back(candidate1);
    if(count2 > n/3) result.push_back(candidate2);
    
    return result;
}

int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    
    cout << "Enter " << n << " elements: ";
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    vector<int> ans = calculate(arr, n);
    
    if(ans.empty()){
        cout << "No element appears more than n/3 times" << endl;
    } else {
        cout << "Elements appearing more than n/3 times: ";
        for(int i = 0; i < ans.size(); i++){
            cout << ans[i] << " ";
        }
    }
    
    return 0;
}



// Step 1: First Pass - Find Candidates
// Initialize: count1=0, count2=0, cand1=-1, cand2=-1

// Element	Action	                            cand1	count1	cand2	count2
// 3	    count1=0, so set cand1=3	            3	    1	    -1	    0
// 1	    count2=0, so set cand2=1	            3	    1	    1	    1
// 2	    Neither match, decrement both	        3	    0	    1	    0
// 3	    count1=0, so set cand1=3	            3	    1	    1	    0
// 3	    Matches cand1, increment	            3	    2	    1	    0
// 1	    Matches cand2, increment	            3	    2	    1	    1
// 1	    Matches cand2, increment	            3	    2	    1	    2
// 2	    Neither match, decrement both	        3	    1	    1	    1
// Candidates found: cand1 = 3, cand2 = 1   

// Step 2: Second Pass - Verify Candidates
// Count actual occurrences:

// Count of 3 = 3

// Count of 1 = 3

// Both > 2.66 ✓

// Output: 3 1


