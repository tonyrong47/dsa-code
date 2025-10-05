#include<bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *ans = new ListNode(0);
    ListNode *temp = ans;
    int c = 0;
    while (l1 && l2)
    {
        // cout<<l1->val<<" "<<l2->val<<endl;
        int x = l1->val + l2->val + c;
        // cout<<"x : "<<x<<endl;
        int d = x % 10;
        // cout<<"d : "<<d<<endl;
        c = x / 10;
        // cout<<"c : "<<c<<endl;
        ans->next = new ListNode(d);
        // cout<<"ans->val : "<<ans->next->val<<endl;
        ans = ans->next;
        l1 = l1->next;
        l2 = l2->next;
    }
    while (l1)
    {
        // cout<<"hello"<<endl;
        int x = l1->val + c;
        int d = x % 10;
        c = x / 10;
        ans->next = new ListNode(d);
        ans = ans->next;
        l1 = l1->next;
    }
    while (l2)
    {
        // cout << "hello" << endl;
        int x = l2->val + c;
        int d = x % 10;
        c = x / 10;
        ans->next = new ListNode(d);
        ans = ans->next;
        l2 = l2->next;
    }
    // while (ans)
    // {
    //     cout << ans->val << "-->";
    //     ans = ans->next;
    // }
    return temp->next;
}

int main()
{
    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);
    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    ListNode *ans = addTwoNumbers(l1, l2);
    while (ans)
    {
        cout << ans->val << "-->";
        ans = ans->next;
    }
    return 0;
}
//by ad73prem