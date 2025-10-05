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

Node* rotate_K_Nodes(Node* head,int k){
    Node* tail=head;
    Node* temp=head;
    int len=1;
    while(tail->next){
        tail=tail->next;
        len++;
    }
    tail->next=temp;
    int diff=abs(len-k%len);
    for(int i=1;i<diff;i++){
        temp=temp->next;
    }
    head=temp->next;
    temp->next=NULL;

    return head;

}

int main(){
    vector<int>ver={1,2,3,4,5,6,};
    Node* head=createNode(ver);
    Node*temp=head;
    while(temp){
        cout<<temp->val<<"\n";
        temp=temp->next;
    }
    cout<<"After rotation\n";
    Node* head1=rotate_K_Nodes(head,2);
    Node*temp1=head1;
    while(temp1){
        cout<<temp1->val<<"\n";
        temp1=temp1->next;
    }
    return 0;
}