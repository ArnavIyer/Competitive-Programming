# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def oddEvenList(self, head: ListNode) -> ListNode:
        if head ==None or head.next == None:
            return head
        co = head
        ce = head.next
        evenhead = head.next
        while True:
            if (ce.next == None):
                co.next=evenhead
                break
            elif ce.next.next == None:
                co.next = co.next.next
                co= co.next
                co.next = evenhead
                ce.next = None
                break
            else:
                co.next = co.next.next
                ce.next = ce.next.next
                co = co.next
                ce=ce.next
        return head