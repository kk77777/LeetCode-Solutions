# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def insertionSortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy=ListNode(0)
        curr=head
        
        while curr:
            curr_next=curr.next
            prev=dummy
            nxt=dummy.next
            while nxt:
                if nxt.val>curr.val: break
                prev=nxt
                nxt=nxt.next
            curr.next=nxt
            prev.next=curr
            curr=curr_next
        
        return dummy.next
