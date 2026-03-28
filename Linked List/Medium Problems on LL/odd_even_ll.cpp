#include <bits/stdc++.h>
using namespace std;

/*
===============================================================================
PROBLEM DESCRIPTION
===============================================================================
Rearrange a linked list such that:
- All nodes at odd positions come first
- Followed by nodes at even positions

NOTE:
- Position is based on index (1-based), NOT value.
- Maintain relative order of odd and even nodes.

Example:
Input:  1 -> 2 -> 3 -> 4 -> 5
Output: 1 -> 3 -> 5 -> 2 -> 4

We will implement TWO approaches:
1. Optimal Approach (In-place pointer manipulation)
2. Brute Force Approach (Using extra array)
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
APPROACH 1: OPTIMAL (O(1) SPACE)
===============================================================================
*/
Node* oddevenll_optimal(Node* head, int n) {

    // Edge case: empty or single node
    if (head == NULL || head->next == NULL) return head;

    Node* odd = head;              // pointer for odd positions
    Node* even = head->next;       // pointer for even positions
    Node* evenhead = even;         // store start of even list

    // Traverse and rearrange links
    while (even != NULL && even->next != NULL) {

        odd->next = odd->next->next;   // connect odd nodes
        even->next = even->next->next; // connect even nodes

        odd = odd->next;   // move odd pointer
        even = even->next; // move even pointer
    }

    odd->next = evenhead; // attach even list after odd list

    return head;
}

/*
===============================================================================
APPROACH 2: BRUTE FORCE (USING ARRAY)
===============================================================================
*/
Node* oddevenll_bruteforce(Node* head, int n) {

    vector<int> arr; // dynamic array to store values
    Node* temp = head;

    // Step 1: Store odd index values
    while (temp != NULL) {
        arr.push_back(temp->data);
        if (temp->next != NULL)
            temp = temp->next->next;
        else
            break;
    }

    // Step 2: Store even index values
    temp = head->next;

    while (temp != NULL) {
        arr.push_back(temp->data);
        if (temp->next != NULL)
            temp = temp->next->next;
        else
            break;
    }

    // Step 3: Rewrite linked list
    temp = head;
    int i = 0;

    while (temp != NULL) {
        temp->data = arr[i];
        i++;
        temp = temp->next;
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

int main() {

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) cin >> arr[i];

    Node* head = converttoll(arr);

    cout << "\nOriginal List: ";
    printList(head);

    // Optimal approach
    Node* result1 = oddevenll_optimal(head, n);
    cout << "After Odd-Even (Optimal): ";
    printList(result1);

    // Re-create list for brute force (since list is modified)
    head = converttoll(arr);

    Node* result2 = oddevenll_bruteforce(head, n);
    cout << "After Odd-Even (Brute Force): ";
    printList(result2);

    return 0;
}

/*
===============================================================================
DETAILED EXPLANATION
===============================================================================

APPROACH 1: OPTIMAL (POINTER MANIPULATION)

STEP-BY-STEP:
1. Maintain two pointers:
   - odd → tracks odd index nodes
   - even → tracks even index nodes
2. Store even head separately.
3. Link odd nodes together.
4. Link even nodes together.
5. Attach even list at the end of odd list.

-------------------------------------------------------------------------------

APPROACH 2: BRUTE FORCE

STEP-BY-STEP:
1. Traverse list and store odd index values.
2. Traverse again and store even index values.
3. Rewrite linked list using stored values.

-------------------------------------------------------------------------------

EXAMPLE:

Input:
1 -> 2 -> 3 -> 4 -> 5

ODD nodes: 1, 3, 5
EVEN nodes: 2, 4

Output:
1 -> 3 -> 5 -> 2 -> 4

-------------------------------------------------------------------------------

EXECUTION TABLE (OPTIMAL):

Step | Odd | Even | List State
--------------------------------
1    | 1   | 2    | 1->3->5->2->4
2    | 3   | 4    | continues rearranging

-------------------------------------------------------------------------------

EDGE CASES:
1. Empty list → return NULL
2. Single node → return same
3. Two nodes → no change
4. Large list → handled efficiently

-------------------------------------------------------------------------------

TIME COMPLEXITY:
- Optimal: O(n)
- Brute Force: O(n)

SPACE COMPLEXITY:
- Optimal: O(1)
- Brute Force: O(n)

-------------------------------------------------------------------------------

KEY INTERVIEW POINTS:
- Optimal uses pointer manipulation (important!)
- No extra space in optimal
- Maintain relative order
- Brute force is easier but less efficient

===============================================================================
*/