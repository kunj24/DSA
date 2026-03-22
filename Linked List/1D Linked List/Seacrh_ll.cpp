#include <bits/stdc++.h>
using namespace std;

struct Node
{
    public:
    int data;
    Node* next;
    Node(int data1,Node* next1){
        data=data1;
        next=next1;
    }
    Node(int data1){
        data=data1;
        next=nullptr;
    }
    
};

Node* converttoll(vector<int>& arr){
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}

int lengthofll(Node* head){
    int count=0;
    Node* temp=head;
    while (temp != nullptr) 
    {
        count++;
        temp = temp->next;  
    }
    return count;
}

int searchll(Node* head,int val){
    Node* temp=head;
    while(temp!=nullptr){
        if(temp->data==val){
            return 1;
        }
        temp=temp->next;
    }
    return 0;
}

int main() {
    // Create an array
    vector<int> arr = {2, 5, 8, 7};

    Node* head=converttoll(arr);
    Node* temp=head;

    while (temp)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    cout<<"length of ll :"<<lengthofll(head);

    int val;
    cout<<endl;
    cout<<"Enter the search value in the LL ";
    cin>>val;
    if(searchll(head,val)==1){
        cout<<"The "<<val<<" present in the ll"<<endl;
    }
    else{
        cout<<"The "<<val<<" is not present in the ll"<<endl;
    }
    return 0;
}

