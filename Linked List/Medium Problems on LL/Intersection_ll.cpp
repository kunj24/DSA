#include <bits/stdc++.h>
using namespace std;

/*
===============================================================================
PROBLEM STATEMENT:
Given two singly linked lists, find the node at which they intersect.

Intersection means:
- Both lists share the same node (same memory address), not same value.

Example:
List1: 1 -> 2 -> 3 \
                        -> 7 -> 8
List2:       4 -> 5 /

Output: Node with value 7

===============================================================================
APPROACHES USED:
1. Brute Force (Map)
2. Optimal using Length Difference
3. Most Optimal (Two Pointer Switching)

===============================================================================
UNDERSTANDING:
- Intersection is based on POINTER, not value.
- Once lists intersect, they share all nodes after that point.
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
APPROACH 1: MAP (BRUTE FORCE)
TIME: O(N + M)
SPACE: O(N)
===============================================================================
*/

Node* Intersection_normal(Node* head1, Node* head2){

    map<Node*, int> mpp;
    Node* temp = head1;

    // Store all nodes of list1
    while(temp != NULL){
        mpp[temp] = 1;
        temp = temp->next;
    }

    temp = head2;

    // Check in list2
    while(temp != NULL){
        if(mpp.find(temp) != mpp.end()){
            return temp;
        }
        temp = temp->next;
    }

    return NULL;
}

/*
===============================================================================
HELPER FUNCTION: FIND LENGTH DIFFERENCE
===============================================================================
*/

int getDifference(Node* head1, Node* head2) {
    int len1 = 0, len2 = 0;

    while (head1 != NULL) {
        len1++;
        head1 = head1->next;
    }

    while (head2 != NULL) {
        len2++;
        head2 = head2->next;
    }

    return len1 - len2;
}

/*
===============================================================================
APPROACH 2: LENGTH DIFFERENCE
TIME: O(N + M)
SPACE: O(1)
===============================================================================
*/

Node* Intersection_optimal(Node* head1, Node* head2){

    int diff = getDifference(head1, head2);

    // Move pointer of longer list
    if(diff > 0){
        while(diff--){
            head1 = head1->next;
        }
    }
    else{
        while(diff++){
            head2 = head2->next;
        }
    }

    // Traverse together
    while(head1 != NULL && head2 != NULL){
        if(head1 == head2) return head1;
        head1 = head1->next;
        head2 = head2->next;
    }

    return NULL;
}

/*
===============================================================================
APPROACH 3: TWO POINTER SWITCHING (BEST)
TIME: O(N + M)
SPACE: O(1)
===============================================================================
*/

Node* Instersection_optimal_1(Node* head1, Node* head2){

    Node* t1=head1;
    Node* t2=head2;

    while (t1!=t2)
    {
        t1=t1->next;
        t2=t2->next;
        if(t1=t2) return t1;
        if(t1==NULL) t1=head2;
        if(t2==NULL) t2=head1;
    }
    return t1;
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
PRINT LIST
===============================================================================
*/

void printList(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

/*
===============================================================================
MAIN FUNCTION
===============================================================================
*/

int main(){

    /*
    NOTE:
    For intersection, both lists must share nodes manually.
    Here we demonstrate simple lists (no intersection by default).
    */

    int n1, n2;

    cout << "Enter size of List 1: ";
    cin >> n1;
    cout << "Enter elements of List 1: ";
    Node* head1 = createList(n1);

    cout << "Enter size of List 2: ";
    cin >> n2;
    cout << "Enter elements of List 2: ";
    Node* head2 = createList(n2);

    cout << "List 1: ";
    printList(head1);

    cout << "List 2: ";
    printList(head2);

    Node* ans1 = Intersection_normal(head1, head2);
    Node* ans2 = Intersection_optimal(head1, head2);
    Node* ans3 = Instersection_optimal_1(head1, head2);

    cout << "Intersection (Map): ";
    if(ans1) cout << ans1->data << endl;
    else cout << "No Intersection\n";

    cout << "Intersection (Length Diff): ";
    if(ans2) cout << ans2->data << endl;
    else cout << "No Intersection\n";

    cout << "Intersection (Two Pointer): ";
    if(ans3) cout << ans3->data << endl;
    else cout << "No Intersection\n";

    return 0;
}

/*
===============================================================================
EDGE CASES:
===============================================================================

1. One or both lists are NULL
   → Return NULL

2. No intersection
   → Return NULL

3. Intersection at head
   → Return head directly

4. Lists of different lengths
   → Handled by optimal approaches

5. Single node lists
   → If same node → intersection, else NULL

===============================================================================
TIME & SPACE SUMMARY:
===============================================================================

Approach 1 (Map):
Time  = O(N + M)
Space = O(N)

Approach 2 (Length Difference):
Time  = O(N + M)
Space = O(1)

Approach 3 (Two Pointer Switching):
Time  = O(N + M)
Space = O(1)

===============================================================================
INTERVIEW TIP:
===============================================================================

Best answer:
→ "I will use two pointer switching method because it avoids length calculation 
   and works in O(1) space efficiently."

===============================================================================
*/
