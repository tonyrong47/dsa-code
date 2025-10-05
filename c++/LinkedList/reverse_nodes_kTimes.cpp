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

Node* reverseNode(Node* head){
    Node* back=NULL;
    Node* curr=head;
    Node* front=NULL;
    while(curr){
        front=curr->next;
        curr->next=back;
        back=curr;
        curr=front;
    }
    return back;
}

Node* findkthNode(Node* head,int k){
    Node* temp=head;
    while(--k){
        if(temp==NULL)
        return NULL;
        temp=temp->next;
    }
    return temp;
}

Node* reverseKtimes(Node* head,int k){
    Node* temp=head;
    Node* nextNode;
    Node* preNode;
    while(temp!=NULL){
        Node* kthNode=findkthNode(temp,k);
        if(kthNode==NULL){
            if(preNode)
            preNode->next=temp;
            break;
        }
        nextNode=kthNode->next;
        kthNode->next=NULL;
        Node* rev=reverseNode(temp);
        if(temp==head)
        head=rev;
        else
        {
            preNode->next=kthNode;
        }
        preNode=temp;
        temp=nextNode;
    }
    return head;
}

int main(){
    vector<int>ver={1,2,3,4,5,6,7,8,9,10};
    Node* head=createNode(ver);
    Node*temp=head;
    while(temp){
        cout<<temp->val<<"\n";
        temp=temp->next;
    }
    cout<<"Reversing kth time \n";
    Node* head1=reverseKtimes(head,3);
    Node*temp1=head1;
    while(temp1){
        cout<<temp1->val<<"\n";
        temp1=temp1->next;
    }
    return 0;
}