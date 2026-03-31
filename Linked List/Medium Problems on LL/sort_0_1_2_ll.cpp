#include <bits/stdc++.h>
using namespace std;


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


Node* sort012(Node* head, int n) {

    Node* temp=head;
    int count0=0,count1=0,count2=0;

    while(temp!=NULL){
        if(temp->data==1){
            count1++;
        }
        else if(temp->data==2){
            count2++;
        }
        else{
            count0++;
        }
        temp=temp->next;
    }

    temp=head;

    while (temp!=NULL)
    {
        if(count0){
            temp->data=0; 
            count0--;
        }
        else if (count1) {
            temp->data=1; 
            count1--;
        }
        else{
            temp->data=2;
            count2--;
        }
        temp=temp->next;
    }
    
    return head;
}


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
    cout << "Enter elements (only 0,1,2): ";
    for(int i = 0; i < n; i++) cin >> arr[i];

    Node* head = converttoll(arr);

    cout << "\nOriginal List: ";
    printList(head);

    // Apply sorting
    Node* result = sort012(head,n);

    cout << "After sorting 0,1,2: ";
    printList(result);

    return 0;
}


