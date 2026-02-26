#include <iostream>
#include <vector>
using namespace std;


double median(vector<int>& arr1,vector<int>& arr2,int n1,int n2) {

    vector<int> ans;
    int leftpointer=0, rightpointer=0;
    
    while (leftpointer<n1 && rightpointer<n2)
    {
        if(arr1[leftpointer]<arr2[rightpointer]){
            ans.push_back(arr1[leftpointer]);
            leftpointer++;
        }
        else{
            ans.push_back(arr2[rightpointer]);
            rightpointer++;
        }   
    }
    while (leftpointer<n1)
    {
        ans.push_back(arr1[leftpointer]);
        leftpointer++;
    }
    while (rightpointer<n2)
    {
        ans.push_back(arr2[rightpointer]);
        rightpointer++;
    }

    int n=ans.size();
    if(n%2==0){
        return (ans[n/2-1]+ans[n/2])/2.0;
    }
    else{
        return ans[n/2];
    }
    
}

int main() {
    int n1,n2;

    cout << "Enter number of elements for the array 1 : ";
    cin >> n1;

    cout << "Enter number of elements for the array 2 : ";
    cin >> n2;

    vector<int> arr1(n1);
    vector<int> arr2(n2);

    cout << "Enter " << n1 << " Sorted  elements for array 1 in sorted order of array 1 : " << endl;
    for (int i = 0; i < n1; i++){
        cin >> arr1[i];
    }

    cout << "Enter " << n2 << " Sorted  elements for array 2 in sorted order of array 2 : " << endl;
    for (int i = 0; i < n2; i++){
        cin >> arr2[i];
    }

    double ans = median(arr1, arr2, n1, n2);

    cout << "Median of the array 1 and array 2 is : " << ans << endl;
    return 0;
}


