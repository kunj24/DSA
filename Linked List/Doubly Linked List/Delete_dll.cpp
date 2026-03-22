#include <bits/stdc++.h>
using namespace std;

/*
===============================================================================
PROBLEM DESCRIPTION
===============================================================================
Implement and demonstrate different deletion operations in a Doubly Linked List.

Operations included in this program:

1. Convert an array to a Doubly Linked List
2. Print the Doubly Linked List
3. Delete the head node
4. Delete the tail node
5. Delete node at a given position (k)
6. Delete a node directly using node pointer

A Doubly Linked List node contains:
1. Data
2. Pointer to next node
3. Pointer to previous node
===============================================================================
*/

class Node {
public:
    int data;
    Node* next;
    Node* back;

    // Constructor with data, next, and back
    Node(int data1, Node* next1, Node* back1) {
        data = data1;
        next = next1;
        back = back1;
    }

    // Constructor with only data
    Node(int data1) {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

/*
===============================================================================
Convert array to Doubly Linked List
===============================================================================
*/
Node* convertToDLL(vector<int>& arr){

    Node* head = new Node(arr[0]);
    Node* prev = head;

    for(int i = 1; i < arr.size(); i++){

        Node* temp = new Node(arr[i], nullptr, prev);

        prev->next = temp;
        prev = temp;
    }

    return head;
}

/*
===============================================================================
Print Doubly Linked List
===============================================================================
*/
void printDLL(Node* head){

    while(head != NULL){
        cout << head->data << " <-> ";
        head = head->next;
    }

    cout << "NULL" << endl;
}

/*
===============================================================================
Delete Head Node
===============================================================================
*/
Node* deleteHead(Node* head){

    if(head == NULL || head->next == NULL){
        return NULL;
    }

    Node* prev = head;

    head = head->next;

    head->back = nullptr;
    prev->next = nullptr;

    delete prev;

    return head;
}

/*
===============================================================================
Delete Tail Node
===============================================================================
*/
Node* deleteTail(Node* head){

    Node* tail = head;

    while(tail->next != nullptr){
        tail = tail->next;
    }

    Node* newTail = tail->back;

    newTail->next = nullptr;
    tail->back = nullptr;

    delete tail;

    return head;
}

/*
===============================================================================
Delete Node at Position K
===============================================================================
*/
Node* deleteAtKPosition(Node* head, int k){

    Node* temp = head;
    int count = 0;

    while(temp != NULL){
        count++;
        if(count == k) break;
        temp = temp->next;
    }

    Node* prev = temp->back;
    Node* front = temp->next;

    if(prev == nullptr && front == nullptr){
        return NULL;
    }
    else if(prev == nullptr){
        return deleteHead(head);
    }
    else if(front == nullptr){
        return deleteTail(head);
    }
    else{

        prev->next = front;
        front->back = prev;

        temp->next = nullptr;
        temp->back = nullptr;

        delete temp;
    }

    return head;
}

/*
===============================================================================
Delete Given Node
===============================================================================
*/
void deleteGivenNode(Node* temp){

    Node* prev = temp->back;
    Node* front = temp->next;

    if(front == NULL){

        prev->next = nullptr;
        temp->back = nullptr;

        delete temp;
        return;
    }

    prev->next = front;
    front->back = prev;

    temp->next = nullptr;
    temp->back = nullptr;

    delete temp;
}

/*
===============================================================================
MAIN FUNCTION
===============================================================================
*/
int main(){

    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements: ";

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    // Convert array to DLL
    Node* head = convertToDLL(arr);

    cout << "\nOriginal Doubly Linked List:\n";
    printDLL(head);


    // ---------------- DELETE HEAD ----------------
    head = deleteHead(head);

    cout << "\nAfter Deleting Head:\n";
    printDLL(head);


    // ---------------- DELETE TAIL ----------------
    head = deleteTail(head);

    cout << "\nAfter Deleting Tail:\n";
    printDLL(head);


    // ---------------- DELETE AT POSITION K ----------------
    int k;

    cout << "\nEnter position to delete: ";
    cin >> k;

    head = deleteAtKPosition(head, k);

    cout << "\nAfter Deleting at Position " << k << ":\n";
    printDLL(head);


    // ---------------- DELETE GIVEN NODE ----------------
    if(head != NULL && head->next != NULL){

        Node* temp = head->next; // deleting second node

        deleteGivenNode(temp);

        cout << "\nAfter Deleting Second Node using Pointer:\n";
        printDLL(head);
    }

    return 0;
}

/*
===============================================================================
STEP BY STEP EXPLANATION
===============================================================================

1. User enters number of elements.
2. Elements are stored in a vector.
3. convertToDLL() creates a doubly linked list.
4. printDLL() displays the list.
5. deleteHead() removes first node.
6. deleteTail() removes last node.
7. deleteAtKPosition() removes node at user-given position.
8. deleteGivenNode() removes node using pointer reference.

===============================================================================
EXAMPLE INPUT
===============================================================================

Enter number of elements: 5
Enter elements: 10 20 30 40 50
Enter position to delete: 2

===============================================================================
OUTPUT
===============================================================================

Original List
10 <-> 20 <-> 30 <-> 40 <-> 50 <-> NULL

After Deleting Head
20 <-> 30 <-> 40 <-> 50 <-> NULL

After Deleting Tail
20 <-> 30 <-> 40 <-> NULL

After Deleting Position 2
20 <-> 40 <-> NULL

After Deleting Second Node
20 <-> NULL

===============================================================================
EDGE CASES
===============================================================================

1. Empty list
2. Single node list
3. Deleting head
4. Deleting tail
5. Invalid position

===============================================================================
TIME COMPLEXITY
===============================================================================

Traversal operations : O(N)
Deletion operations  : O(N)

===============================================================================
SPACE COMPLEXITY
===============================================================================

O(N) for storing nodes in the linked list.

===============================================================================
*/