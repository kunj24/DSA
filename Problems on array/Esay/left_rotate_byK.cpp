#include<iostream>
#include<vector>
using namespace std;

void leftrotate(vector<int> &arr,int n){
    int temp=arr[0];
    for(int i=1;i<n;i++){
        arr[i-1]=arr[i];
    }
    arr[n-1]=temp;
}
void leftrotateBYk(vector<int> &arr,int k,int n){
    k=k%n;                    //arr is 1,2,3,4,5 then k=6 so arr is 23451 becz 
    for(int i=0;i<k;i++){     //6= 5+1 so we just rotate 1 becz 5 roatate-> arr it self
        leftrotate(arr,n);    // so k%n 6%5=1 2%5=2
    }
}

int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
   vector<int> arr(n);
 
    cout << "Enter numbers :" << endl;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int k;
    cout << "Enter number of positions to rotate: ";
    cin>>k;
    
    leftrotateBYk(arr,k, n);
    
    cout<<"After rotating 1 elemnt in the left :"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}