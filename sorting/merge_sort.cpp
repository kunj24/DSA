#include<iostream>
#include<vector>
using namespace std;
void merge_sort(int arr[],int low,int high){

    if(low=high) return;
    int mid=(low+high)/2;
    merge_sort(arr,low,mid);
    merge_sort(arr,mid+1,high);
    merge(arr,low,mid,high);

}
void merge(int arr[],int low,int mid,int high){
    vector<int> temp;
    int left_pointer=low;
    int right_pointer=mid+1;
    while (left_pointer<=mid && right_pointer<=high)
    {   
        if (left_pointer<right_pointer)
        {
            temp.push_back(arr[left_pointer]);
            left_pointer++;
        }
        else{
            temp.push_back(arr[right_pointer]);
            right_pointer++;
        }
        
    }
    while (left_pointer<=mid)
    {
        temp.push_back(arr[left_pointer]);
        left_pointer++;
    }
    while (right_pointer<=high)
    {
        temp.push_back(arr[right_pointer]);
        right_pointer++;
    }
    


}
int main(){
    int n;
    cout<<"Enter a number of element :";
    cin>>n;
    int arr[n];
    cout<<"Enter numbers :"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int low=arr[0];
    int high=arr[n];
    merge_sort(arr,low,high);
    cout<<"sorted array using merge sort is :"<<endl;

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }    
    
}