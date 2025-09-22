#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int longest_subarr_sumofk(vector<int>& arr, int n,int k){
    int left=0,right=0;     //1, 2, 3, 1, 1, 1, 1 k=3
    int sum=arr[0],maxlength=0;
    while (right<n)
    {
        while (left<=right && sum>k) // for sum=1 1>3 nope 1+2+3>3 2+3+1>3 3+1+1>6
        {
            sum-=arr[left]; //left=1 so remove the 1 so sum=5 same remove 2 so sum=4 same remove the 3 
            left++; //left=2 //left=3 //left=1
        }
        if(sum==k){//sum =3 then maxlength=2,sum=3 
            maxlength=max(maxlength,right-left+1); //maxlength=(2,5-3+1)=3
        }
        
        right++; //right=2 right++ right++ same
        if(right<n) sum+=arr[right];//sum=3 ,sum=6, sum=6(we remove the 1 from left),sum=5,sum=3
    }
    return maxlength;
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
    cout<<"Enter a number for longest sub array of sum :";
    cin>>k;
    int val = longest_subarr_sumofk(arr, n,k);
    cout<<"The length of the longest subarray is :"<<val<<endl;
    return 0;
}