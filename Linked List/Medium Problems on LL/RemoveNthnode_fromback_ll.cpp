#include <bits/stdc++.h>
using namespace std;

/*
===============================================================================
PROBLEM DESCRIPTION
===============================================================================
Delete the k-th node from the END of a singly linked list.

Example:
Input:  1 -> 2 -> 3 -> 4 -> 5, k = 2
Output: 1 -> 2 -> 3 -> 5

Explanation:
The 2nd node from the end is 4 → delete it.

We will implement:
1. Optimal Approach (Two Pointer / Fast-Slow)
2. Brute Force Approach (Using length)
===============================================================================
*/

// Node structure
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

/*
===============================================================================
CONVERT ARRAY TO LINKED LIST
===============================================================================
*/
Node* convertToLL(vector<int>& arr){
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
void printLL(Node* head){
    while(head != NULL){
        cout << head->data;
        if(head->next != NULL) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

/*
===============================================================================
FIND LENGTH OF LINKED LIST
===============================================================================
*/
int lengthOfLL(Node* head){
    int cnt = 0;
    while(head != NULL){
        cnt++;
        head = head->next;
    }
    return cnt;
}

/*
===============================================================================
APPROACH 1: OPTIMAL (TWO POINTER)
===============================================================================
*/
Node* deleteatkfromend_optimal(Node* head, int k){

    Node* fast = head;
    Node* slow = head;

    // Move fast pointer k steps ahead
    for(int i = 0; i < k; i++){
        fast = fast->next;
    }

    // If fast becomes NULL → delete head
    if(fast == NULL){
        Node* newHead = head->next;
        delete head;
        return newHead;
    }

    // Move both pointers until fast reaches last node
    while(fast->next != NULL){
        fast = fast->next;
        slow = slow->next;
    }

    // Delete node
    Node* deleteNode = slow->next;
    slow->next = slow->next->next;
    delete deleteNode;

    return head;
}

/*
===============================================================================
APPROACH 2: BRUTE FORCE (USING LENGTH)
===============================================================================
*/
Node* deleteatkfromend(Node* head, int k){

    int cnt = lengthOfLL(head);

    // If deleting head
    if(cnt == k){
        Node* newHead = head->next;
        delete head;
        return newHead;
    }

    int target = cnt - k;
    Node* temp = head;

    // Move to node before target
    for(int i = 1; i < target; i++){
        temp = temp->next;
    }
    /*
    while(temp!=NULL){
     result--; (target--;)
      if(result==0){ break; } 
      temp=temp->next; }
    */   

    Node* deleteNode = temp->next;
    temp->next = temp->next->next;
    delete deleteNode;

    return head;
}

/*
===============================================================================
MAIN FUNCTION
===============================================================================
*/
int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    Node* head = convertToLL(arr);

    cout << "\nInitial Linked List:\n";
    printLL(head);

    cout << "Length of Linked List: " << lengthOfLL(head) << endl;

    int k;
    cout << "\nEnter position (k) to delete from end: ";
    cin >> k;

    // Use optimal
    head = deleteatkfromend_optimal(head, k);

    cout << "After Deleting kth Node:\n";
    printLL(head);

    return 0;
}

/*
===============================================================================
DETAILED EXPLANATION
===============================================================================

APPROACH 1: OPTIMAL (FAST-SLOW POINTER)

STEP-BY-STEP:
1. Move fast pointer k steps ahead.
2. Move both slow & fast together.
3. When fast reaches last node:
   → slow is just before node to delete.
4. Delete slow->next.

-------------------------------------------------------------------------------

EXAMPLE:

Input:
1 -> 2 -> 3 -> 4 -> 5, k = 2

Step 1:
fast moves 2 steps → points at 3

Step 2:
Move both pointers:
fast → 5
slow → 3

Step 3:
Delete slow->next → delete 4

Output:
1 -> 2 -> 3 -> 5

-------------------------------------------------------------------------------

EXECUTION TABLE:

Step | Fast | Slow
-------------------
Init | 1    | 1
k=2  | 3    | 1
Move | 4    | 2
Move | 5    | 3

Delete node after slow (4)

-------------------------------------------------------------------------------

EDGE CASES:
1. k == length → delete head
2. k == 1 → delete last node
3. Single node → becomes NULL
4. k > length → invalid (should handle separately)

-------------------------------------------------------------------------------

TIME COMPLEXITY:
O(n)

SPACE COMPLEXITY:
O(1)

-------------------------------------------------------------------------------

COMMON MISTAKE (YOUR CODE ❌):
❌ fast = fast->next->next → WRONG
   (this skips nodes like in middle finding)

✅ Correct:
Move fast k steps first, then move both together

-------------------------------------------------------------------------------

KEY INTERVIEW POINTS:
- Two-pointer technique is must-know
- Avoid calculating length for optimal solution
- Handle head deletion carefully

===============================================================================
*/