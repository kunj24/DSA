#include<iostream>
#include<vector>
using namespace std;

vector<int> Rearrangearray(vector<int>& arr, int n){      
    vector<int> positive;
    vector<int> negative;
    
    for(int i = 0; i < n; i++){
        if(arr[i] >= 0){
            positive.push_back(arr[i]);
        }
        else{
            negative.push_back(arr[i]);
        }
    }
    
    int pos_size = positive.size();
    int neg_size = negative.size();
    
    
    // Alternate between positive and negative up to the smaller size
    int min_size = min(pos_size, neg_size);
    for(int i = 0; i < min_size; i++){
        arr[2*i] = positive[i];
        arr[2*i + 1] = negative[i];
    }
    
    int index=2*min_size;   
    //Each complete positive–negative pair uses two positions in the array.
    //After placing all pairs, the next free position is at index 2 * min_size
    //Positives = {1, 2, 3} → size = 3
    // Negatives = {-1, -2} → size = 2
    // min_size = 2 so 2* min size = 4 so place the rest element to the index 4..
    // + -  + -
    //   ^   ^  

    // Add remaining positive elements
    for(int i = min_size; i < pos_size; i++){
        arr[index++] = positive[i];
    }
    
    // Add remaining negative elements
    for(int i = min_size; i < neg_size; i++){
        arr[index++] = negative[i];
    }
    
    return arr;
}

int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    
    cout << "Enter elements (can contain positive and negative numbers): " << endl;
    vector<int> arr(n);
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    vector<int> ans = Rearrangearray(arr, n);
    
    cout << "Rearranged array: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}