#include<iostream>
#include<vector>
using namespace std;
void partiotion(vector<int> arr,int low,int high){
    int pivot=arr[low];
    int i=low;
    int j=high;
    while (i<j)
    {
        while (arr[i]<=pivot && i<=high-1)
        {
            i++;
        }
        while (arr[j]>=pivot && j>=low+1)
        {
            j++;
        }    
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[low],arr[j]);
    return j;
}    
void quick_sort(vector <int> arr[],int low,int high){
    if(low<high){
        int pindex = partiotion(arr,low,high);
        quick_sort(arr,low,pindex);
        quick_sort(arr,pindex+1,high);
    }
}

int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter numbers:" << endl;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    quick_sort(arr, 0, n - 1);
    
    cout << "Sorted array using merge sort is:" << endl;
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }    
    cout << endl;
    
    return 0;
}