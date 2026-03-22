/*
============================================================
Problem: Find the Length of a Singly Linked List
============================================================

Given a singly linked list, write a program to calculate the
total number of nodes present in the linked list.

A linked list is a linear data structure where each element
(node) contains:
1. Data
2. Pointer to the next node

Your task is to traverse the list and count the number of nodes.

Example:
Input:
5
1 3 5 7 9

Output:
Length of Linked List = 5

============================================================
*/

#include <iostream>
#include <vector>
using namespace std;

/*
------------------------------------------------------------
Node Structure Definition
Each node contains:
1. data  -> value stored in node
2. next  -> pointer to next node
------------------------------------------------------------
*/
struct Node
{
    int data;       // stores the value of the node
    Node* next;     // pointer to the next node

    // Constructor to initialize node with data
    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

/*
------------------------------------------------------------
Function: convertToLinkedList
Purpose:
Converts a vector (array) into a linked list.

Parameters:
arr -> vector containing input values

Returns:
Pointer to the head of the linked list
------------------------------------------------------------
*/
Node* convertToLinkedList(vector<int>& arr)
{
    Node* head = new Node(arr[0]); // create first node
    Node* mover = head;            // mover helps attach new nodes

    // iterate through the array and create nodes
    for(int i = 1; i < arr.size(); i++)
    {
        Node* temp = new Node(arr[i]); // create new node
        mover->next = temp;            // link previous node to new node
        mover = temp;                  // move pointer forward
    }

    return head; // return head of the linked list
}

/*
------------------------------------------------------------
Function: lengthOfLinkedList
Purpose:
Counts the number of nodes in the linked list.

Parameters:
head -> pointer to the first node

Returns:
Total number of nodes
------------------------------------------------------------
*/
int lengthOfLinkedList(Node* head)
{
    int count = 0;        // counter to store number of nodes
    Node* temp = head;    // temporary pointer to traverse list

    // traverse until we reach the end of the list
    while(temp != nullptr)
    {
        count++;          // increment count for each node
        temp = temp->next; // move to next node
    }

    return count;         // return final count
}

/*
------------------------------------------------------------
Function: printLinkedList
Purpose:
Prints the linked list elements
------------------------------------------------------------
*/
void printLinkedList(Node* head)
{
    Node* temp = head;

    while(temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main()
{
    int n;

    cout << "Enter number of elements in the linked list: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Convert array to linked list
    Node* head = convertToLinkedList(arr);

    cout << "Linked List: ";
    printLinkedList(head);

    // Calculate length
    int length = lengthOfLinkedList(head);

    cout << "Length of Linked List = " << length << endl;

    return 0;
}


/*
=====================================================================
STEP-BY-STEP EXPLANATION
=====================================================================

1. We define a Node structure containing:
   - data
   - pointer to next node

2. Convert array into linked list:
   - First element becomes the head node
   - Remaining elements are added one by one
   - Each new node is connected using the next pointer

3. Traverse the linked list:
   - Start from head
   - Move to next node using temp = temp->next
   - Count each node visited

4. Stop when pointer becomes NULL

5. Return the count as the length of the linked list.

=====================================================================
EXAMPLE INPUT
=====================================================================

Enter number of elements in the linked list:
5

Enter the elements:
2 5 8 7 11

=====================================================================
OUTPUT
=====================================================================

Linked List: 2 5 8 7 11
Length of Linked List = 5

=====================================================================
ALGORITHM EXECUTION TABLE
=====================================================================

Step    Current Node Value    Count
-----------------------------------
1       2                     1
2       5                     2
3       8                     3
4       7                     4
5       11                    5
6       NULL                  Stop

=====================================================================
EDGE CASES
=====================================================================

1. Empty List
Input:
0

Output:
Length = 0

2. Single Node
Input:
1
10

Output:
Length = 1

3. Large List
The algorithm still works efficiently.

=====================================================================
TIME COMPLEXITY
=====================================================================

O(N)

Because we traverse the linked list once.

=====================================================================
SPACE COMPLEXITY
=====================================================================

O(1)

No extra memory is used except a few variables.

=====================================================================
INTERVIEW TIP
=====================================================================

Common linked list interview questions related to this:

1. Find length of linked list
2. Delete head node
3. Delete tail node
4. Reverse linked list
5. Detect cycle (Floyd's algorithm)
6. Find middle node (slow & fast pointer)

=====================================================================
*/