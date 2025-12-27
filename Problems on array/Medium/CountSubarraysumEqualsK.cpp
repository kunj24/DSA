#include<iostream>
#include<vector>
using namespace std;

int sum(vector<int>& arr, int n,int key){   
    int count=0;   
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum=0;
            for(int k=i;k<=j;k++){
                sum+=arr[k];
            }
            if(sum==key){
                count++;
            }
        }
    }
    return count;
}

int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int key;
    cout << "Enter elements (can contain positive and negative numbers): " << endl;
    vector<int> arr(n);

    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    cout<<"Enter a key or target :"<<endl;
    cin>>key;
    int ans = sum(arr, n,key);
    cout<<"The number of subarrays is : "<<ans;
    cout << endl;
    
    return 0;
}