#include <bits/stdc++.h>
using namespace std;

/*
===============================================================================
PROBLEM DESCRIPTION
===============================================================================
Implement insertion operations in a Doubly Linked List (DLL).

Operations covered:
1. Insert at head
2. Insert before tail
3. Insert before k-th element
4. Insert before a given node

Each node contains:
- data
- next pointer
- back pointer
===============================================================================
*/

class Node {
public:
    int data;
    Node* next;
    Node* back;

    // Constructor with all parameters
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
Convert Array to DLL
===============================================================================
*/
Node* convertToDLL(vector<int>& arr) {

    Node* head = new Node(arr[0]);
    Node* prev = head;

    for(int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }

    return head;
}

/*
===============================================================================
Print DLL
===============================================================================
*/
void printDLL(Node* head) {

    while(head != NULL) {
        cout << head->data << " <-> ";
        head = head->next;
    }
    cout << "NULL\n";
}

/*
===============================================================================
Insert at Head
===============================================================================
*/
Node* insertHead(Node* head, int val) {

    Node* newNode = new Node(val, head, nullptr);

    if(head != NULL) {
        head->back = newNode;   // update previous pointer of old head
    }

    return newNode;
}

/*
===============================================================================
Insert Before Tail
===============================================================================
*/
Node* insertBeforeTail(Node* head, int val) {

    // If only one node → insert at head
    if(head->next == NULL) {
        return insertHead(head, val);
    }

    Node* tail = head;

    // Move to last node
    while(tail->next != NULL) {
        tail = tail->next;
    }

    Node* prev = tail->back;

    Node* newNode = new Node(val, tail, prev);

    prev->next = newNode;
    tail->back = newNode;

    return head;
}

/*
===============================================================================
Insert Before K-th Element
===============================================================================
*/
Node* insertBeforeKth(Node* head, int k, int val) {

    // If inserting before first node → insert at head
    if(k == 1) {
        return insertHead(head, val);
    }

    Node* temp = head;
    int count = 1;

    // Traverse to k-th node
    while(temp != NULL && count < k) {
        temp = temp->next;
        count++;
    }

    Node* prev = temp->back;

    Node* newNode = new Node(val, temp, prev);

    prev->next = newNode;
    temp->back = newNode;

    return head;
}

/*
===============================================================================
Insert Before Given Node
===============================================================================
*/
void insertBeforeNode(Node* node, int val) {

    Node* prev = node->back;

    Node* newNode = new Node(val, node, prev);

    if(prev != NULL) {
        prev->next = newNode;
    }

    node->back = newNode;
}

/*
===============================================================================
MAIN FUNCTION
===============================================================================
*/
int main() {

    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements: ";

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Node* head = convertToDLL(arr);

    cout << "\nOriginal DLL:\n";
    printDLL(head);

    // ---------------- INSERT HEAD ----------------
    head = insertHead(head, 100);

    cout << "\nAfter inserting at head (100):\n";
    printDLL(head);

    // ---------------- INSERT BEFORE TAIL ----------------
    head = insertBeforeTail(head, 200);

    cout << "\nAfter inserting before tail (200):\n";
    printDLL(head);

    // ---------------- INSERT BEFORE K ----------------
    int k;
    cout << "\nEnter position (k) to insert before: ";
    cin >> k;

    head = insertBeforeKth(head, k, 300);

    cout << "\nAfter inserting before position " << k << " (300):\n";
    printDLL(head);

    // ---------------- INSERT BEFORE NODE ----------------
    if(head != NULL && head->next != NULL) {

        Node* temp = head->next; // second node

        insertBeforeNode(temp, 400);

        cout << "\nAfter inserting before second node (400):\n";
        printDLL(head);
    }

    return 0;
}

/*
===============================================================================
STEP-BY-STEP EXPLANATION
===============================================================================

1. Convert array → DLL
2. Insert at head → new node becomes first
3. Insert before tail → new node added before last node
4. Insert before k-th → traverse to k-th node
5. Insert before node → use pointer

===============================================================================
EXAMPLE INPUT
===============================================================================

n = 4
10 20 30 40
k = 3

===============================================================================
OUTPUT
===============================================================================

Original:
10 <-> 20 <-> 30 <-> 40 <-> NULL

After head insert:
100 <-> 10 <-> 20 <-> 30 <-> 40 <-> NULL

After before tail:
100 <-> 10 <-> 20 <-> 30 <-> 200 <-> 40 <-> NULL

After before k=3:
100 <-> 10 <-> 300 <-> 20 <-> 30 <-> 200 <-> 40 <-> NULL

===============================================================================
EDGE CASES
===============================================================================

1. Empty list
2. Single node list
3. k = 1 (insert at head)
4. Invalid k

===============================================================================
TIME COMPLEXITY
===============================================================================

Insertion operations → O(N) (due to traversal)

===============================================================================
SPACE COMPLEXITY
===============================================================================

O(1) extra space

===============================================================================
*/