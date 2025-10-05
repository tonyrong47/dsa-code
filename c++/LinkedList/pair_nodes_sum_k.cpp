#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* next;
    Node* prev;

    public:
    Node(int data){
        val=data;
        next=NULL;
        prev=NULL;
    }
};

Node* creatingDLL(vector<int>& vec){
    Node* head=new Node(vec[0]);
    Node* temp=head;
    for(int i=1;i<vec.size();i++){
        Node* temp1=new Node(vec[i]);
        temp->next=temp1;
        temp1->prev=temp;
        temp=temp1;
    }
    return head;
}

vector<pair<int,int>> findPair(Node* head,int key){
    Node* right=head;
    int l=0,r=0;
    vector<pair<int,int>>ver;
    while(right->next){
        right=right->next;
        r++;
    }
    Node* left=head;
    while(left&&right&&l<=r){
        int sum=left->val+right->val;
        if(sum==key){
            ver.push_back({left->val,right->val});
            left=left->next;
            right=right->prev;
            l++;
            r--;
        }
        else if(sum>key){
            right=right->prev;
            r--;
        }
        else{
            left=left->next;
            l++;
        }
    }
    return ver;
}

int main(){
    vector<int>v={1,2,3,4,5};
    Node* head=creatingDLL(v);
    Node* temp=head;
    for(Node* i=temp;i!=NULL;i=i->next){
        cout<<i->val<<"\n";
    }
    vector<pair<int,int>>ver1=findPair(head,5);
    for(auto v:ver1){
        cout<<v.first<<","<<v.second<<"\n";
    }
    return 0;
}