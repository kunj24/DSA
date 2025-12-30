#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int linearsearch(vector<int>&arr,int x,int n){
    for(int i=0;i<n;i++){
        if(arr[i]==x){
            return true;
        }
    }
    return false;
}

int longest_consecutive_sequence(vector<int>& arr, int n){    
    int longest=1;                      //100, 4, 200, 1, 3, 2 output is 4 because 1,2,3,4 is consecutive 
    for(int i=0;i<n;i++){
        int count=1;
        int x=arr[i];
        while(linearsearch(arr,x+1,n)==true){
            x+=1;
            count+=1;
        }
        longest=max(longest,count);
    }
    return longest;
}
int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    
    cout << "Enter elements :" << endl;
    vector<int> arr(n);
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int ans = longest_consecutive_sequence(arr, n);
    
    cout << "Longest consecutive sequence length: " << ans << endl;
    
}
