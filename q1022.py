# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumRootToLeaf(self, root: Optional[TreeNode]) -> int:
        def solve(root, ans):
            if root is None:
                return 0
            ans = (ans << 1)+root.val
            if root.left is None and root.right is None:
                return ans
            return solve(root.left, ans)+solve(root.right, ans)
        return solve(root, 0)
