#include <bits/stdc++.h>
using namespace std;

/*
===============================================================================
PROBLEM:
Add 1 to a number represented as a linked list.
Example: 1 -> 9 -> 9  becomes  2 -> 0 -> 0
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

Node* reversell(Node* head){
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
RECURSIVE HELPER
===============================================================================
*/

int helper(Node* temp){
    if(temp == NULL) return 1;

    int carry = helper(temp->next);

    temp->data = temp->data + carry;

    if(temp->data < 10) return 0;

    temp->data = 0;
    return 1;
}

/*
===============================================================================
RECURSIVE APPROACH
===============================================================================
*/

Node* add1toll_recursive(Node* head){
    int carry = helper(head);

    if(carry == 1){
        Node* newnode = new Node(1);
        newnode->next = head;
        return newnode;
    }
    return head;
}

/*
===============================================================================
ITERATIVE (REVERSE) APPROACH
===============================================================================
*/

Node* add1toll(Node* head){

    head = reversell(head);
    Node* temp = head;

    int carry = 1;

    while(temp != NULL){
        temp->data = temp->data + carry;

        if(temp->data < 10){
            carry = 0;
            break;
        }
        else{
            temp->data = 0;
            carry = 1;
        }

        temp = temp->next;
    }

    head = reversell(head);

    if(carry == 1){
        Node* newnode = new Node(1);
        newnode->next = head;
        return newnode;
    }

    return head;
}

/*
===============================================================================
CREATE LINKED LIST
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

    cout << "Enter digits: ";
    Node* head = createList(n);

    cout << "Original List: ";
    printList(head);

    // Recursive
    Node* result1 = add1toll_recursive(head);
    cout << "After +1 (Recursive): ";
    printList(result1);

    // Iterative
    Node* result2 = add1toll(result1);
    cout << "After +1 again (Iterative): ";
    printList(result2);

    return 0;
}