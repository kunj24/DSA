#include<iostream>
#include<vector>
using namespace std;

vector<int> Rearrangearray(vector<int>& arr, int n){      
    vector<int> Newarr(n);
    int posindex=0;
    int negindex=1;
    for(int i=0;i<n;i++){
        if(arr[i]<0){
            Newarr[negindex]=arr[i];
            negindex+=2;
        }
        else{
            Newarr[posindex]=arr[i];
            posindex+=2;
        }
    }
    return Newarr;
}

int main(){
    int n;
    cout << "Enter number of elements (even number): ";
    cin >> n;
    
    cout << "Enter " << n/2 << " Postive elemnet "<<n/2<<" Negative element :" << endl;

    vector<int> arr(n);
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    vector<int> ans = Rearrangearray(arr, n);
    
    cout << "Rearranged array: ";
    for(int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    
    return 0;
}