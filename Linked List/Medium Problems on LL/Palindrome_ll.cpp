#include <bits/stdc++.h>
using namespace std;

/*
===============================================================================
PROBLEM:
Check whether a singly linked list is a palindrome.

METHODS USED:
1. Stack-based approach (Brute)
2. Two-pointer + reverse (Optimal)

FEATURE:
- Restores the list after checking (important for interviews)
===============================================================================
*/

struct Node {
public:
    int data;
    Node* next;

    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    Node(int data1) {
        data = data1;
        next = NULL;
    }
};

/*
===============================================================================
REVERSE LINKED LIST
===============================================================================
*/

Node* reverse(Node* head){
    Node* temp = head;
    Node* prev = NULL;

    while(temp != NULL){
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

/*
===============================================================================
OPTIMAL APPROACH (O(N) time, O(1) space)
===============================================================================
*/

bool palnidrome_optimal(Node* head){

    // Edge case
    if(head == NULL || head->next == NULL) return true;

    Node* slow = head;
    Node* fast = head;

    // Find middle
    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse second half
    Node* secondHalf = reverse(slow->next);

    Node* first = head;
    Node* second = secondHalf;

    // Compare
    while(second != NULL){
        if(first->data != second->data){
            reverse(secondHalf); // restore before returning
            return false;
        }
        first = first->next;
        second = second->next;
    }

    // Restore list
    reverse(secondHalf);

    return true;
}

/*
===============================================================================
STACK APPROACH (O(N) space)
===============================================================================
*/

bool palnidrome(Node* head){
    Node* temp = head;
    stack<int> st;

    // Push all elements
    while(temp != NULL){
        st.push(temp->data);
        temp = temp->next;
    }

    temp = head;

    // Compare
    while(temp != NULL){
        if(temp->data != st.top()) return false;
        st.pop();
        temp = temp->next;
    }

    return true;
}

/*
===============================================================================
CREATE LINKED LIST FROM USER INPUT
===============================================================================
*/

Node* createList(int n){
    if(n == 0) return NULL;

    int x;
    cin >> x;
    Node* head = new Node(x);
    Node* mover = head;

    for(int i = 1; i < n; i++){
        cin >> x;
        Node* temp = new Node(x);
        mover->next = temp;
        mover = temp;
    }

    return head;
}

/*
===============================================================================
PRINT LINKED LIST
===============================================================================
*/

void printList(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

/*
===============================================================================
MAIN FUNCTION
===============================================================================
*/

int main(){

    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter elements: ";
    Node* head = createList(n);

    cout << "Linked List: ";
    printList(head);

    // Stack method
    if(palnidrome(head))
        cout << "Palindrome (Stack Method)" << endl;
    else
        cout << "Not Palindrome (Stack Method)" << endl;

    // Optimal method
    if(palnidrome_optimal(head))
        cout << "Palindrome (Optimal Method)" << endl;
    else
        cout << "Not Palindrome (Optimal Method)" << endl;

    return 0;
}