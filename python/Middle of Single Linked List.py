class Node:
    def __init__(self,val):
        self.val=val
        self.next=None
def buildLinkedList(nums):
        if not nums:
            return None
        head=Node(nums[0])
        current=head
        for val in nums[1:]:
            current.next=Node(val)
            current=current.next
        return head
def traverse(head):
        temp=head
        while temp:
            print(temp.val,end=" ")
            temp=temp.next
        print()
def middleNode(head):
        slow=head
        fast=head
        while fast!=None and fast.next !=None:
            slow=slow.next
            fast=fast.next.next
        return slow
head=buildLinkedList([1,2,3,4,5])
traverse(head)
mid=middleNode(head)
traverse(mid)
