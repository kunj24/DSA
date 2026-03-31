#include <bits/stdc++.h>
using namespace std;

/*
===============================================================================
PROBLEM DESCRIPTION
===============================================================================
Reverse a singly linked list.

Example:
Input:  1 -> 2 -> 3 -> 4 -> 5
Output: 5 -> 4 -> 3 -> 2 -> 1

We will implement 3 approaches:
1. Brute Force (Using Stack)
2. Optimal Iterative (Pointer Reversal)
3. Recursive Approach
===============================================================================
*/

// Node structure
class Node {
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = nullptr;
    }
};

/*
===============================================================================
CONVERT ARRAY TO LINKED LIST
===============================================================================
*/
Node* converttoll(vector<int>& arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i]);
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
    while(head != NULL){
        cout << head->data;
        if(head->next != NULL) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

/*
===============================================================================
APPROACH 1: BRUTE FORCE (USING STACK)
===============================================================================
*/
Node* reversell(Node* head){

    stack<int> st;
    Node* temp = head;

    // Store elements in stack
    while(temp != NULL){
        st.push(temp->data);
        temp = temp->next;
    }

    temp = head;

    // Replace values from stack
    while(temp != NULL){
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }

    return head;
}

/*
===============================================================================
APPROACH 2: OPTIMAL ITERATIVE (POINTER REVERSAL)
===============================================================================
*/
Node* reversellbetter(Node* head){

    Node* temp = head;
    Node* prev = NULL;

    while(temp != NULL){

        Node* front = temp->next; // store next node

        temp->next = prev; // reverse link

        prev = temp; // move prev forward
        temp = front; // move temp forward
    }

    return prev; // new head
}

/*
===============================================================================
APPROACH 3: RECURSIVE
===============================================================================
*/
Node* reversellrecursive(Node* head){

    // Base case
    if(head == NULL || head->next == NULL)
        return head;

    // Reverse remaining list
    Node* newHead = reversellrecursive(head->next);

    // Fix current node
    head->next->next = head; // reverse link
    head->next = NULL;       // set next to NULL

    return newHead;
}

/*
===============================================================================
MAIN FUNCTION
===============================================================================
*/
int main(){

    int n;
    cout << "Enter size: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) cin >> arr[i];

    Node* head = converttoll(arr);

    cout << "\nOriginal List: ";
    printList(head);

    // Iterative
    Node* result1 = reversellbetter(head);
    cout << "Reversed (Iterative): ";
    printList(result1);

    // Recreate list
    head = converttoll(arr);

    // Recursive
    Node* result2 = reversellrecursive(head);
    cout << "Reversed (Recursive): ";
    printList(result2);

    return 0;
}

/*
===============================================================================
DETAILED EXPLANATION
===============================================================================

APPROACH 1: STACK
- Store all values in stack
- Rewrite list in reverse order

Time: O(n)
Space: O(n)

-------------------------------------------------------------------------------

APPROACH 2: ITERATIVE (BEST)

STEP:
1. Maintain 3 pointers:
   - prev → previous node
   - temp → current node
   - front → next node

2. Reverse links one by one.

-------------------------------------------------------------------------------

APPROACH 3: RECURSIVE

STEP:
1. Reverse rest of list
2. Fix current node:
   head->next->next = head
3. Set head->next = NULL

-------------------------------------------------------------------------------

EXAMPLE:

Input:
1 -> 2 -> 3

Recursive Flow:
reverse(1)
  reverse(2)
    reverse(3) → return 3

Now:
2->3 becomes 3->2
1->2 becomes 2->1

Output:
3 -> 2 -> 1

-------------------------------------------------------------------------------

EXECUTION TABLE (ITERATIVE):

Step | temp | prev | Result
--------------------------------
1    | 1    | NULL | 1->NULL
2    | 2    | 1    | 2->1
3    | 3    | 2    | 3->2->1

-------------------------------------------------------------------------------

EDGE CASES:
1. Empty list → return NULL
2. Single node → same
3. Two nodes → simple swap

-------------------------------------------------------------------------------

TIME COMPLEXITY:
All approaches → O(n)

SPACE COMPLEXITY:
- Stack → O(n)
- Iterative → O(1) ✅
- Recursive → O(n) (call stack)

-------------------------------------------------------------------------------

COMMON MISTAKE (YOU DID ❌):
❌ forgot to declare "front"

Correct:
Node* front = temp->next;

-------------------------------------------------------------------------------

KEY INTERVIEW POINTS:
- Iterative is most preferred
- Recursive is elegant but uses stack
- Understand pointer manipulation clearly

===============================================================================
*/