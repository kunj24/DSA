#include <bits/stdc++.h>
using namespace std;

/*
===============================================================================
PROBLEM: Linked List Operations (Insertion, Deletion, Traversal)
===============================================================================

This program performs the following operations on a Singly Linked List:

1. Convert an array into a Linked List
2. Print the Linked List
3. Find the length of the Linked List
4. Delete the first node
5. Delete the last node
6. Delete the kth node
7. Delete a node containing a specific element

A Singly Linked List contains nodes where each node has:
    - Data
    - Pointer to the next node

Example Linked List:
2 -> 5 -> 8 -> 7 -> 11 -> 4 -> 1 -> NULL

===============================================================================
*/


// Node structure
struct Node
{
public:
    int data;
    Node* next;

    // Constructor with data and next pointer
    Node(int data1, Node* next1)
    {
        data = data1;
        next = next1;
    }

    // Constructor with only data
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};



// Convert array to Linked List
Node* convertToLL(vector<int>& arr)
{
    Node* head = new Node(arr[0]); // first element becomes head
    Node* mover = head;

    for(int i = 1; i < arr.size(); i++)
    {
        Node* temp = new Node(arr[i]); // create new node
        mover->next = temp;            // attach node
        mover = temp;                  // move pointer forward
    }

    return head;
}



// Print Linked List
void printLL(Node* head)
{
    Node* temp = head;

    while(temp != nullptr)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}



// Find length of Linked List
int lengthOfLL(Node* head)
{
    int count = 0;
    Node* temp = head;

    while(temp != nullptr)
    {
        count++;
        temp = temp->next;
    }

    return count;
}



// Delete first node
Node* deleteAtStart(Node* head)
{
    if(head == NULL)
        return head;

    Node* temp = head;
    head = head->next;  // move head
    delete temp;        // delete old head

    return head;
}



// Delete last node
Node* deleteAtTail(Node* head)
{
    if(head == NULL || head->next == NULL)
        return NULL;

    Node* temp = head;

    // move to second last node
    while(temp->next->next != NULL)
    {
        temp = temp->next;
    }

    delete temp->next;      // delete last node
    temp->next = NULL;      // update tail

    return head;
}



// Delete kth node
Node* deleteatk(Node* head, int k)
{
    if(head == NULL)
        return NULL;

    // if first node needs to be deleted
    if(k == 1)
        return deleteAtStart(head);

    Node* temp = head;
    Node* prev = NULL;
    int count = 0;

    while(temp != NULL)
    {
        count++;

        if(count == k)
        {
            prev->next = temp->next; // bypass node
            delete temp;
            break;
        }

        prev = temp;
        temp = temp->next;
    }

    return head;
}



// Delete node containing given element
Node* deleteelement(Node* head, int element)
{
    if(head == NULL)
        return NULL;

    // if element is at head
    if(head->data == element)
        return deleteAtStart(head);

    Node* temp = head;
    Node* prev = NULL;

    while(temp != NULL)
    {
        if(temp->data == element)
        {
            prev->next = temp->next; // bypass node
            delete temp;
            break;
        }

        prev = temp;
        temp = temp->next;
    }

    return head;
}



int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];


    // Convert array to Linked List
    Node* head = convertToLL(arr);

    cout << "\nInitial Linked List:\n";
    printLL(head);

    cout << "Length of Linked List: " << lengthOfLL(head) << endl;



    // Delete first node
    head = deleteAtStart(head);

    cout << "\nAfter Deleting First Node:\n";
    printLL(head);

    cout << "Length of Linked List: " << lengthOfLL(head) << endl;



    // Delete last node
    head = deleteAtTail(head);

    cout << "\nAfter Deleting Last Node:\n";
    printLL(head);

    cout << "Length of Linked List: " << lengthOfLL(head) << endl;



    // Delete kth node
    int k;
    cout << "\nEnter position (k) to delete: ";
    cin >> k;

    head = deleteatk(head, k);

    cout << "After Deleting kth Node:\n";
    printLL(head);



    // Delete specific element
    int ele;
    cout << "\nEnter element to delete: ";
    cin >> ele;

    head = deleteelement(head, ele);

    cout << "After Deleting Element:\n";
    printLL(head);

    return 0;
}



/*
===============================================================================
STEP-BY-STEP EXPLANATION
===============================================================================

1. Take input elements from the user.
2. Store them in a vector.
3. Convert vector to Linked List.
4. Print the Linked List.
5. Calculate the length using traversal.
6. Delete the first node.
7. Delete the last node.
8. Delete kth node.
9. Delete node containing given element.
10. Print the Linked List after each operation.

===============================================================================
EXAMPLE INPUT
===============================================================================

Enter number of elements: 7
Enter elements: 2 5 8 7 11 4 1
Enter position (k) to delete: 3
Enter element to delete: 11

===============================================================================
EXAMPLE OUTPUT
===============================================================================

Initial Linked List:
2 -> 5 -> 8 -> 7 -> 11 -> 4 -> 1 -> NULL

After Deleting First Node:
5 -> 8 -> 7 -> 11 -> 4 -> 1 -> NULL

After Deleting Last Node:
5 -> 8 -> 7 -> 11 -> 4 -> NULL

After Deleting kth Node:
5 -> 8 -> 11 -> 4 -> NULL

After Deleting Element:
5 -> 8 -> 4 -> NULL

===============================================================================
TIME COMPLEXITY
===============================================================================

Convert Array → Linked List : O(N)
Print Linked List           : O(N)
Find Length                 : O(N)
Delete First Node           : O(1)
Delete Last Node            : O(N)
Delete kth Node             : O(N)
Delete Element              : O(N)

===============================================================================
SPACE COMPLEXITY
===============================================================================

Extra Space : O(1)

===============================================================================
*/