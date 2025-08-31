#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter a number :";
    cin>>n;
    // Initialize a counter variable
    // 'cnt' to store the count of digits.
    int count = 0;
    // While loop iterates until 'n'
    // becomes 0 (no more digits left).
    while(n > 0){
        // Increment the counter
        // for each digit encountered.
        count = count + 1;
        // Divide 'n' by 10 to
        // remove the last digit.
        n = n / 10;
    }
    // Return the
    // count of digits
    cout<<"count is :"<<count;
    return count;

}