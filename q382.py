# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:

    def __init__(self, head: Optional[ListNode]):
        self.head = head

    def getRandom(self) -> int:
        stream = self.head.val
        nxt = self.head.next
        p = 2
        while nxt:
            if random.random() < 1/p:
                stream = nxt.val
            p += 1
            nxt = nxt.next
        return stream

# Your Solution object will be instantiated and called as such:
# obj = Solution(head)
# param_1 = obj.getRandom()
