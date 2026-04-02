#include <bits/stdc++.h>
using namespace std;

/*
===============================================================================
PROBLEM STATEMENT:
Find the middle node of a singly linked list.

If the number of nodes is even:
→ Return the second middle node (standard interview convention)

Example:
Input: 1 -> 2 -> 3 -> 4 -> 5
Output: 3

Input: 1 -> 2 -> 3 -> 4
Output: 3

===============================================================================
UNDERSTANDING:
There are two approaches:

1. Brute Force:
   - Count total nodes
   - Traverse again to reach middle

2. Optimal (Tortoise & Hare):
   - Use slow and fast pointers
   - Slow moves 1 step, fast moves 2 steps
   - When fast reaches end, slow is at middle

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
OPTIMAL APPROACH (TWO POINTER)
TIME: O(N)
SPACE: O(1)
===============================================================================
*/

Node* middleofll_optimal(Node* head){

    Node* fast = head;
    Node* slow = head;

    // Move fast by 2 and slow by 1
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    // Slow will be at middle
    return slow;
}

/*
===============================================================================
BRUTE FORCE APPROACH
TIME: O(N + N) ≈ O(N)
SPACE: O(1)
===============================================================================
*/

Node* middleofll(Node* head) {

    if (head == NULL) return NULL;

    // Step 1: Count length
    Node* temp = head;
    int len = 0;

    while (temp != NULL) {
        len++;
        temp = temp->next;
    }

    // Step 2: Move to middle
    temp = head;
    int mid = len / 2;

    while (mid--){
        temp = temp->next;
    }

    return temp;
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

    cout << "Enter elements: ";
    Node* head = createList(n);

    cout << "Linked List: ";
    printList(head);

    // Optimal result
    Node* mid1 = middleofll_optimal(head);
    cout << "Middle (Optimal): " << mid1->data << endl;

    // Brute result
    Node* mid2 = middleofll(head);
    cout << "Middle (Brute): " << mid2->data << endl;

    return 0;
}

/*
===============================================================================
EDGE CASES:
===============================================================================

1. Empty list (head == NULL)
   → Return NULL

2. Single node
   → That node is the middle

3. Even number of nodes
   → Return second middle (as per standard)

4. Odd number of nodes
   → Return exact middle

===============================================================================
TIME & SPACE COMPLEXITY:
===============================================================================

Brute Force:
Time  = O(N + N) ≈ O(N)
Space = O(1)

Optimal:
Time  = O(N)
Space = O(1)

===============================================================================
INTERVIEW TIP:
===============================================================================

Best answer:
→ "I will use slow and fast pointer approach because it finds the middle
   in a single traversal with constant space."

===============================================================================
*/