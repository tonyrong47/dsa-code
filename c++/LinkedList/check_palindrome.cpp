#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* next;

    public:
    Node(int data){
        val=data;
        next=NULL;
    }
};

Node* createNode(vector<int>&ver){
    Node* head=new Node(ver[0]);
    Node* temp=head;
    for(int i=1;i<ver.size();i++){
        Node* curr=new Node(ver[i]);
        temp->next=curr;
        temp=curr;
    }
    return head;
}

Node* reverseLL(Node* head){
    Node* pre=NULL;
    Node* curr=head;
    Node* next=NULL;
    while(curr){
        next=curr->next;
        curr->next=pre;
        pre=curr;
        curr=next;
    }
    return pre;
}

bool palindromeCheck(Node* head){
    Node*slow=head;
    Node* fast=head;
    Node* temp=head;
    while(fast->next!=NULL&& fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    Node* newHead=reverseLL(slow->next);
    Node* check=newHead;
    while(temp!=NULL&& check!=NULL){
        if(temp->val!=check->val){
            reverseLL(newHead);
            return false;
        }
        check=check->next;
        temp=temp->next;
    }
    reverseLL(newHead);
    return true;
}

int main(){
    vector<int>ver={1,2,3,3,3,1};
    Node* head=createNode(ver);
    bool val=palindromeCheck(head);
    cout<<val;
    return 0;
}