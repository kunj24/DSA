#include <bits/stdc++.h>
using namespace std;

// ====================== Node Structure ======================
// Each node stores data and pointer to the next node
struct Node{
public:
    int data;
    Node* next;

    // Constructor with data and next pointer
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    // Constructor with only data
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};


// ====================== Convert Array → Linked List ======================
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


// ====================== Print Linked List ======================
void printtLL(Node* head){

    Node* temp = head;

    // Traverse list until NULL
    while(temp != nullptr){
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}


// ====================== Find Length ======================
int lengthOfLL(Node* head){

    Node* temp = head;
    int count = 0;

    // Count nodes using traversal
    while(temp != nullptr){
        count++;
        temp = temp->next;
    }

    return count;
}


// ====================== Insert at Head ======================
Node* inserthead(Node* head, int val){

    // New node points to old head
    Node* temp = new Node(val, head);

    // New node becomes head
    return temp;
}


// ====================== Insert at Tail ======================
Node* insertattail(Node* head, int val){

    // If list empty create first node
    if(head == NULL)
        return new Node(val);

    Node* temp = head;

    // Traverse until last node
    while(temp->next != NULL){
        temp = temp->next;
    }

    Node* newnode = new Node(val);

    temp->next = newnode; // attach new node at end

    return head;
}


// ====================== Insert at Kth Position ======================
Node* insertatk(Node* head, int val, int k){

    // If inserting at first position
    if(k == 1){
        return inserthead(head, val);
    }

    Node* temp = head;
    int count = 1;

    while(temp != NULL){

        // When we reach node before kth position
        if(count == k - 1){

            Node* newnode = new Node(val, temp->next);

            temp->next = newnode; // connect new node

            break;
        }

        temp = temp->next;
        count++;
    }

    return head;
}


// ====================== Insert Before Given Value ======================
Node* insertbeforeval(Node* head, int val, int element){

    if(head == NULL)
        return NULL;

    // If element is at head
    if(head->data == element){
        return inserthead(head, val);
    }

    Node* temp = head;

    while(temp->next != NULL){

        // When next node contains target element
        if(temp->next->data == element){

            Node* newnode = new Node(val, temp->next);

            temp->next = newnode;

            break;
        }

        temp = temp->next;
    }

    return head;
}



// ====================== MAIN FUNCTION ======================
int main(){

    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements: ";

    for(int i = 0; i < n; i++)
        cin >> arr[i];


    // Convert array to Linked List
    Node* head = converttoll(arr);

    cout << "\nInitial Linked List:\n";
    printtLL(head);

    cout << "Length of Linked List: " << lengthOfLL(head) << endl;



    // Insert at Head
    int val;

    cout << "\nEnter value to insert at head: ";
    cin >> val;

    head = inserthead(head, val);

    cout << "\nAfter Inserting at Head:\n";
    printtLL(head);



    // Insert at Tail
    cout << "\nEnter value to insert at tail: ";
    cin >> val;

    head = insertattail(head, val);

    cout << "\nAfter Inserting at Tail:\n";
    printtLL(head);



    // Insert at Kth Position
    int k;

    cout << "\nEnter value to insert: ";
    cin >> val;

    cout << "Enter position k: ";
    cin >> k;

    head = insertatk(head, val, k);

    cout << "\nAfter Inserting at Position k:\n";
    printtLL(head);



    // Insert Before Element
    int element;

    cout << "\nEnter value to insert: ";
    cin >> val;

    cout << "Insert before element: ";
    cin >> element;

    head = insertbeforeval(head, val, element);

    cout << "\nAfter Insert Before Element:\n";
    printtLL(head);

}