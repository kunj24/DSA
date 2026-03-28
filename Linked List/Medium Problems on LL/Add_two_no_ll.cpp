#include <bits/stdc++.h>
using namespace std;

/*
===============================================================================
PROBLEM DESCRIPTION
===============================================================================
Add two numbers represented as Linked Lists.

Each linked list represents a non-negative integer where:
- Each node contains a single digit.
- The digits are stored in reverse order.
  (i.e., 1's digit at head)

Example:
List1: 2 -> 4 -> 3   (represents 342)
List2: 5 -> 6 -> 4   (represents 465)

Output:
7 -> 0 -> 8          (represents 807)

We need to return a new linked list representing the sum.
===============================================================================
*/

// Node structure
class Node {
public:
    int data;
    Node* next;

    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

/*
===============================================================================
CONVERT ARRAY TO LINKED LIST (USING YOUR FUNCTION)
===============================================================================
*/
Node* converttoll(vector<int>& arr){

    // First element becomes the head
    Node* head = new Node(arr[0]);
    Node* mover = head;

    // Create remaining nodes and attach them
    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i]); // create new node
        mover->next = temp;            // connect previous node
        mover = temp;                  // move pointer forward
    }

    return head;
}

/*
===============================================================================
FUNCTION TO ADD TWO LINKED LISTS
===============================================================================
*/
Node* addTwoNumbers(Node* l1, Node* l2) {

    Node* dummy = new Node(0); // dummy node for result
    Node* current = dummy;
    int carry = 0;

    // Traverse both lists
    while (l1 != NULL || l2 != NULL || carry) {

        int sum = carry; // start with carry

        // Add first list value
        if (l1 != NULL) {
            sum += l1->data;
            l1 = l1->next;
        }

        // Add second list value
        if (l2 != NULL) {
            sum += l2->data;
            l2 = l2->next;
        }

        carry = sum / 10;       // update carry
        int digit = sum % 10;   // extract digit

        current->next = new Node(digit); // create node
        current = current->next;         // move forward
    }

    return dummy->next;
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

    int n1, n2;

    // Input first list
    cout << "Enter size of first array: ";
    cin >> n1;

    vector<int> arr1(n1);
    cout << "Enter elements (digits in reverse order): ";
    for(int i = 0; i < n1; i++) cin >> arr1[i];

    // Convert array to linked list
    Node* l1 = converttoll(arr1);

    // Input second list
    cout << "Enter size of second array: ";
    cin >> n2;

    vector<int> arr2(n2);
    cout << "Enter elements (digits in reverse order): ";
    for(int i = 0; i < n2; i++) cin >> arr2[i];

    // Convert array to linked list
    Node* l2 = converttoll(arr2);

    // Add two numbers
    Node* result = addTwoNumbers(l1, l2);

    // Output result
    cout << "Resultant Linked List (Sum): ";
    printList(result);

    return 0;
}

/*
===============================================================================
DETAILED EXPLANATION
===============================================================================

STEP-BY-STEP APPROACH:
1. Convert arrays into linked lists using converttoll().
2. Use a dummy node to simplify result list creation.
3. Traverse both lists simultaneously.
4. Add digits + carry.
5. Store result digit (sum % 10).
6. Update carry (sum / 10).
7. Continue until lists and carry are finished.

-------------------------------------------------------------------------------

EXAMPLE:

Input:
arr1 = [2,4,3]
arr2 = [5,6,4]

Linked Lists:
2 -> 4 -> 3
5 -> 6 -> 4

Process:

Step | l1 | l2 | carry | sum | digit | result
------------------------------------------------
1    | 2  | 5  | 0     | 7   | 7     | 7
2    | 4  | 6  | 0     | 10  | 0     | 7->0
3    | 3  | 4  | 1     | 8   | 8     | 7->0->8

Output:
7 -> 0 -> 8

-------------------------------------------------------------------------------

EXECUTION TABLE:

Iteration | Value1 | Value2 | Carry In | Sum | Digit | Carry Out
----------------------------------------------------------------
1         | 2      | 5      | 0        | 7   | 7     | 0
2         | 4      | 6      | 0        | 10  | 0     | 1
3         | 3      | 4      | 1        | 8   | 8     | 0

-------------------------------------------------------------------------------

EDGE CASES:
1. One list empty → works automatically.
2. Different sizes → handled in loop.
3. Final carry → extra node added.
4. Single digit lists.

-------------------------------------------------------------------------------

TIME COMPLEXITY:
O(max(n, m))

SPACE COMPLEXITY:
O(max(n, m))

-------------------------------------------------------------------------------

KEY INTERVIEW POINTS:
- Dummy node simplifies code.
- Loop condition is very important.
- Carry handling is the core logic.
- Works for unequal lengths.

===============================================================================
*/