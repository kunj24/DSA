#include <bits/stdc++.h>
using namespace std;

// Node class represents a node in the linked list
class Node {
public:
    int data;     // Data value
    Node* next;   // Pointer to next node

    // Constructor with data and next
    Node(int data1, Node* next1) { // Node* y = new Node(arr[0],nullptr); for this
        data = data1;
        next = next1;
    }

    // Constructor with only data
    Node(int data1) {    //Node* y = new Node(arr[0]); for this
        data = data1;
        next = nullptr;
    }
};  

Node* converttoll(vector<int>& arr){

    Node* head= new Node(arr[0]);
    Node* mover=head;
    for(int i=0;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}
int main() {
    // Create an array
    vector<int> arr = {2, 5, 8, 7};

    Node* head=converttoll(arr);
    cout<<head->data;

    return 0;
}
