#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;

int longest_consecutive_sequence(vector<int>& arr, int n){   
    if(n==0) return 0;
    unordered_set<int>st;           
    int longest=1;              
    for(int i=0;i<n;i++){
        st.insert(arr[i]);
    }
    for(int i = 0; i < n; i++){      //5 8 3 2 4 1
        int num = arr[i];               

        // Only start counting if num-1 does NOT exist
        // meaning num is the START of a sequence
        if(st.find(num - 1) == st.end()){   //check i=0 for 5 check 4 is in the set 
            //yes 4 is in the set so i++ then 8 
            //8-1 7 is not present so int cnt=1;.....
            //then 3,2,1 in 1 there is no 0 so cnt=1;....
            int cnt = 1;
            int x = num;

            // Count sequence forward: num, num+1, num+2...
            while(st.find(x + 1) != st.end()){
                x = x + 1;
                cnt++;
            }

            longest = max(longest, cnt);
        }
    }
    
    // i	arr[i]	num-1 in set?	Action	        Sequence Found	Length
    // 0	5	    4 exists ✓	    Skip	        -	            -
    // 1	8	    7 not exists ✗	Start counting	8	            1
    // 2	3   	2 exists ✓	    Skip	        -	            -
    // 3	2	    1 exists ✓	    Skip	        -	            -
    // 4	4	    3 exists ✓	    Skip	        -	            -
    // 5	1	    0 not exists ✗	Start counting	1,2,3,4,5	    5


    //this is 2nd representation of the for loop same code as upper but using auto it

    // for(auto it : st){
    //     if(st.find(it-1)==st.end()){
    //         int cnt=1;
    //         int x=it;
    //         while(st.find(x+1)!=st.end()){
    //             x=x+1;
    //             cnt=cnt+1;
    //         }
    //         longest=max(longest,cnt);
    //     }
    // }
    return longest;
}


int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    
    cout << "Enter elements: " << endl;
    vector<int> arr(n);
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int ans = longest_consecutive_sequence(arr, n);
    cout << "Longest consecutive sequence length: " << ans << endl;
    
    return 0;
}