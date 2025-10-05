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


Node* createNodeLoop(vector<int>&ver){
    Node* head=new Node(ver[0]);
    Node* temp=head;
    Node* loop=new Node(-1);
    for(int i=1;i<ver.size();i++){
        Node* curr=new Node(ver[i]);
        if(ver[i]==3){
            loop->next=curr;
            loop=loop->next;
        }
        temp->next=curr;
        temp=curr;
    }
    temp->next=loop;
    return head;
}

Node* loopCheck(Node* head){
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        return slow;
    }
    return NULL;
}

int loopLength(Node* head){
   int len=0;
   Node* temp=head;
   Node* itr=head->next;
   while(itr!=NULL&&itr->next!=NULL){
    if(itr==temp)
    return len;
    len++;
    itr=itr->next;
   }
   return 0;
}

int main(){
     vector<int>ver={1,5,2,3,4,5,6,7,8,9};
    Node* head=createNodeLoop(ver);
    Node*temp=head;
    Node* check=loopCheck(head);
    if(check!=NULL){
        int len=loopLength(check);
        cout<<len;
    }
    else
    cout<<"There is no loop";
    return 0;
}