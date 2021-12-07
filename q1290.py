# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def getDecimalValue(self, head: ListNode) -> int:
        node=head
        res=0
        while node is not None:
            res=res*2+node.val
            node=node.next
    
        return res
