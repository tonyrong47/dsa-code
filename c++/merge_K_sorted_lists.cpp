/*
 * Problem: Merge K Sorted Linked Lists
 * 
 * Description:
 * - Given K sorted linked lists, merge them into a single sorted linked list
 * - Each linked list is sorted in ascending order
 * 
 * Solution Approach:
 * 1. Uses divide and conquer strategy
 * 2. Repeatedly merges pairs of lists until only one list remains
 * 3. mergeTwo() function handles merging of two sorted lists
 * 4. Time Complexity: O(N * log K) where N is total nodes and K is number of lists
 * 5. Space Complexity: O(1) as we're reusing existing nodes
 */

#include <bits/stdc++.h>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL) {}
};
ListNode* mergeTwo(ListNode* a,ListNode* b) {
    if(!a) return b;
    if(!b) return a;
    ListNode* head=NULL;
    if(a->val<b->val) {head=a; a=a->next;}
    else{head=b; b=b->next;}
    ListNode* tail=head;
    while(a&&b) {
        if(a->val<b->val) {tail->next=a;tail=a;a=a->next;}
        else{
            tail->next=b; tail=b; b=b->next;
        }
    }
    if(a) tail->next=a;
    if(b) tail->next=b;
    return head;
}
ListNode* mergeKLists(vector<ListNode*>& lists) {
    if(lists.empty()) return NULL;
    while(lists.size()>1) {
        vector<ListNode*> v1;
        for(int i=0;i+1<lists.size();i+=2) v1.push_back(mergeTwo(lists[i],lists[i+1]));
        if(lists.size()%2) v1.push_back(lists.back());
        lists=v1;
    }
    return lists[0];
}
int main() {
    int k;cin>>k;
    vector<ListNode*> lists;
    for(int i=0;i<k;i++) {
        int n;cin>>n;
        ListNode* head=NULL;
        ListNode* tail=NULL;
        for(int j=0;j<n;j++) {
            int x;cin>>x;
            ListNode* node=new ListNode(x);
            if(!head) {head=tail=node;}else{tail->next=node;tail=node;}
        }
        lists.push_back(head);
    }
    ListNode* ans=mergeKLists(lists);
    while(ans) {cout<<ans->val<<" ";ans=ans->next;}
}
