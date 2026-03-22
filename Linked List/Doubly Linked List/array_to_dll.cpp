#include <bits/stdc++.h>
using namespace std;

// Node class represents a node in the linked list
class Node {
public:
    int data;     // Data value
    Node* next;   // Pointer to next node
    Node* back;

    // Constructor with data and next
    Node(int data1, Node* next1, Node* back1) { // Node* y = new Node(arr[0],nullptr); for this
        data = data1;
        next = next1;
        back = back1;
    }

    // Constructor with only data
    Node(int data1) {    //Node* y = new Node(arr[0]); for this
        data = data1;
        next = nullptr;
        back =nullptr;
    }
};  

Node* converttodll(vector<int>& arr){

    Node* head= new Node(arr[0]);
    Node* prev=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i],nullptr,prev);
        prev->next=temp;
        prev=temp; 
    }
    return head;
}
void printdll(Node* head){
    while (head!=NULL){
        cout<<head->data<<" -> ";
        head=head->next;
    }

}
int main() {
    // Create an array
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements: ";

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    Node* head=converttodll(arr);
    printdll(head);
}
