# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def getAllElements(self, root1: TreeNode, root2: TreeNode) -> List[int]:

        res, list1, list2 = [], [], []

        while root1 or root2 or len(list1) or len(list2):
            while root1:
                list1.append(root1)
                root1 = root1.left

            while root2:
                list2.append(root2)
                root2 = root2.left

            if len(list2) == 0 or (len(list1) > 0 and list1[-1].val < list2[-1].val):
                root1 = list1.pop()
                res.append(root1.val)
                root1 = root1.right

            else:
                root2 = list2.pop()
                res.append(root2.val)
                root2 = root2.right

        return res
