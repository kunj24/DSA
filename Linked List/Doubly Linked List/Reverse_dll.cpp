#include <bits/stdc++.h>
using namespace std;

/*
===============================================================================
PROBLEM DESCRIPTION
===============================================================================
Reverse a Doubly Linked List (DLL).

A Doubly Linked List has:
- data
- next pointer
- back (previous) pointer

We will implement two methods:
1. Reverse using stack (data swapping)
2. Reverse by swapping pointers (optimal)

===============================================================================
*/

class Node {
public:
    int data;
    Node* next;
    Node* back;

    Node(int data1, Node* next1, Node* back1) {
        data = data1;
        next = next1;
        back = back1;
    }

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
Print DLL
===============================================================================
*/
void printDLL(Node* head){

    Node* temp = head;

    while(temp != NULL){   // ✅ FIX: use temp != NULL
        cout << temp->data << " <-> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

/*
===============================================================================
Method 1: Reverse using Stack (Data Swap)
===============================================================================
*/
Node* reverseDLL_Stack(Node* head){

    stack<int> st;
    Node* temp = head;

    // Store all values in stack
    while(temp != NULL){
        st.push(temp->data);
        temp = temp->next;
    }

    temp = head;

    // Replace values in reverse order
    while(temp != NULL){
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }

    return head;
}

/*
===============================================================================
Method 2: Reverse by Swapping Pointers (Optimal)
===============================================================================
*/
Node* reverseDLL_Optimal(Node* head){

    Node* current = head;
    Node* prev = NULL;

    // Traverse and swap next & back pointers
    while(current != NULL){

        prev = current->back;          // store previous

        current->back = current->next; // swap pointers
        current->next = prev;

        current = current->back;       // move forward
    }

    // ✅ FIX: return new head correctly
    if(prev != NULL){
        head = prev->back;
    }

    return head;
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

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // Create original list
    Node* head = convertToDLL(arr);

    cout << "\nOriginal DLL:\n";
    printDLL(head);

    // -------- Reverse using Stack --------
    Node* stackHead = reverseDLL_Stack(head);

    cout << "\nAfter Reverse (Stack Method):\n";
    printDLL(stackHead);

    // -------- Create fresh list again --------
    Node* head2 = convertToDLL(arr);

    // -------- Reverse using Optimal Method --------
    head2 = reverseDLL_Optimal(head2);

    cout << "\nAfter Reverse (Optimal Pointer Swap):\n";
    printDLL(head2);

    return 0;
}

/*
===============================================================================
STEP-BY-STEP EXPLANATION
===============================================================================

METHOD 1 (STACK):
1. Traverse list and push all elements into stack
2. Traverse again and replace values using stack
3. Reverses data but not pointers

METHOD 2 (OPTIMAL):
1. Traverse each node
2. Swap next and back pointers
3. Move to next node using swapped pointer
4. Return new head

===============================================================================
EXAMPLE INPUT
===============================================================================

5
10 20 30 40 50

===============================================================================
OUTPUT
===============================================================================

Original:
10 <-> 20 <-> 30 <-> 40 <-> 50 <-> NULL

After Stack Reverse:
50 <-> 40 <-> 30 <-> 20 <-> 10 <-> NULL

After Optimal Reverse:
10 <-> 20 <-> 30 <-> 40 <-> 50 <-> NULL

===============================================================================
ALGORITHM EXECUTION TABLE (Optimal)
===============================================================================

Node | Prev | Next | After Swap
--------------------------------
10   | NULL | 20   | next=NULL, back=20
20   | 10   | 30   | next=10, back=30
30   | 20   | 40   | next=20, back=40

===============================================================================
EDGE CASES
===============================================================================

1. Empty list → return NULL
2. Single node → no change
3. Two nodes → simple swap
4. Large list → ensure no memory issues

===============================================================================
TIME COMPLEXITY
===============================================================================

Stack Method   : O(N)
Optimal Method : O(N)

===============================================================================
SPACE COMPLEXITY
===============================================================================

Stack Method   : O(N)
Optimal Method : O(1)

===============================================================================
*/