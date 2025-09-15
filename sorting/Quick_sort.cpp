#include<iostream>
#include<vector>
using namespace std;
int partition(vector<int> &arr,int low,int high){
    int pivot=arr[low];
    int i=low;
    int j=high;
    while (i<j)
    {
        while (arr[i]<=pivot && i<=high-1)
        {
            i++;            //find the grater element to the pviot from left
        }
        while (arr[j]>=pivot && j>=low+1)
        {
            j--;            //find the small element to the pviot from right 
        }    
        if(i<j){
            swap(arr[i],arr[j]);      //if found without crossing then swap and continue where 
        }                             //you left if you crossing then exit end swap
    }        //then elemnet from of pviot and j so our pviot element is in correct postion         
    swap(arr[low],arr[j]);
    return j;
}    
void quick_sort(vector <int> &arr,int low,int high){
    if(low<high){
        int pindex = partition(arr,low,high);
        quick_sort(arr,low,pindex);
        quick_sort(arr,pindex+1,high);
    }
}

int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector <int> arr(n);
    cout << "Enter numbers:" << endl;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    quick_sort(arr, 0, n - 1);
    
    cout << "Sorted array using quick sort is:" << endl;
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }    
    cout << endl;
    
    return 0;
}