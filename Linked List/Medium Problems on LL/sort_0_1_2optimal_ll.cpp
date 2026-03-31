#include <bits/stdc++.h>
using namespace std;

/*
===============================================================================
PROBLEM DESCRIPTION
===============================================================================
Sort a linked list containing only 0s, 1s, and 2s.

The goal is to rearrange the nodes such that:
- All 0s come first
- Then all 1s
- Then all 2s

Example:
Input:  1 -> 2 -> 0 -> 1 -> 2 -> 0
Output: 0 -> 0 -> 1 -> 1 -> 2 -> 2

APPROACH:
We use 3 dummy linked lists:
- zero list
- one list
- two list

Then we connect them together.
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
CONVERT ARRAY TO LINKED LIST (YOUR FUNCTION)
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
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data;
        if (head->next != NULL) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

/*
===============================================================================
OPTIMAL APPROACH (DUTCH NATIONAL FLAG USING LINKED LIST)
===============================================================================
*/
Node* sort012optimal(Node* head){

    // Edge case
    if(head == NULL || head->next == NULL) return head;

    Node* temp = head;

    // Dummy nodes for 0,1,2 lists
    Node* zerohead = new Node(-1);
    Node* onehead  = new Node(-1);
    Node* twohead  = new Node(-1);

    // Tail pointers
    Node* zero = zerohead;
    Node* one  = onehead;
    Node* two  = twohead;

    // Traverse list
    while(temp != NULL){

        if(temp->data == 0){
            zero->next = temp;
            zero = temp;
        }
        else if(temp->data == 1){
            one->next = temp;
            one = temp;
        }
        else{ // temp->data == 2
            two->next = temp;
            two = temp;
        }

        temp = temp->next;
    }

    // Connect three lists

    // If 1's list exists, connect 0 -> 1
    zero->next = (onehead->next != NULL) ? onehead->next : twohead->next;

    // Connect 1 -> 2
    one->next = twohead->next;

    // End the list
    two->next = NULL;

    // New head (skip dummy node)
    return zerohead->next;
}   

/*
===============================================================================
MAIN FUNCTION
===============================================================================
*/
int main() {

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements (only 0,1,2): ";
    for(int i = 0; i < n; i++) cin >> arr[i];

    Node* head = converttoll(arr);

    cout << "\nOriginal List: ";
    printList(head);

    // Apply sorting
    Node* result = sort012optimal(head);

    cout << "After sorting 0,1,2: ";
    printList(result);

    return 0;
}

/*
===============================================================================
DETAILED EXPLANATION
===============================================================================

STEP-BY-STEP APPROACH:
1. Create 3 dummy lists:
   - zero list for 0s
   - one list for 1s
   - two list for 2s

2. Traverse original list:
   - Attach nodes to respective lists

3. Connect:
   - zero list → one list → two list

4. Return head of zero list

-------------------------------------------------------------------------------

EXAMPLE:

Input:
1 -> 2 -> 0 -> 1 -> 2 -> 0

Step 1:
Zero list: 0 -> 0
One list: 1 -> 1
Two list: 2 -> 2

Step 2:
Connect:
0 -> 0 -> 1 -> 1 -> 2 -> 2

-------------------------------------------------------------------------------

EXECUTION TABLE:

Node | Action      | List Updated
-----------------------------------
1    | one list    | 1
2    | two list    | 2
0    | zero list   | 0
1    | one list    | 1->1
2    | two list    | 2->2
0    | zero list   | 0->0

-------------------------------------------------------------------------------

EDGE CASES:
1. All nodes are same → works fine
2. No 0s or no 1s → handled using conditional linking
3. Single node → return same
4. Empty list → return NULL

-------------------------------------------------------------------------------

TIME COMPLEXITY:
O(n) → single traversal

SPACE COMPLEXITY:
O(1) → no extra space (only pointers)

-------------------------------------------------------------------------------

COMMON MISTAKES (YOU DID 👇):
❌ temp->data = 2  → assignment instead of comparison  
✅ temp->data == 2

❌ Forgot to connect lists  
❌ Forgot to return head  
❌ Forgot to terminate list (two->next = NULL)

-------------------------------------------------------------------------------

KEY INTERVIEW POINTS:
- This is linked list version of Dutch National Flag
- Use dummy nodes to simplify logic
- Always terminate last node
- Handle missing lists carefully

===============================================================================
*/