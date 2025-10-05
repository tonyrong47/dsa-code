#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *deleteMiddle(ListNode *head)
{
    // first find the middle using tortroise hare method
    if (head == nullptr)
    {
        return nullptr;
    }
    if (head->next == nullptr)
    {
        ListNode *ln = nullptr;
        return ln;
    }
    ListNode *fast = head;
    ListNode *slow = head;
    // we can modify the hare tortoise into givinf the node just before the slow node or the middle node

    ListNode *prev = nullptr;
    while (fast && fast->next)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    // now prev->next is the node to be delete
    // cout<<slow->val<<endl;
    ListNode *nodeToBeDeleted = prev->next;
    prev->next = prev->next->next;
    delete nodeToBeDeleted;
    return head;
}

int main()
{
    ListNode *head = new ListNode(1);
    // head->next = new ListNode(2);
    // head->next->next = new ListNode(3);
    // head->next->next->next = new ListNode(4);
    // head->next->next->next->next = new ListNode(5);
    ListNode *ans = deleteMiddle(head);
    while (ans)
    {
        cout << ans->val << " ";
        ans = ans->next;
    }
    cout << endl;
    return 0;
}
// by ad73prem