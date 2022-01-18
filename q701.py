# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def insertIntoBST(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:

        def solve(root, val):
            if root is None:
                return TreeNode(val)
            if root.val > val:
                root.left = solve(root.left, val)
            else:
                root.right = solve(root.right, val)
            return root

        return solve(root, val)
