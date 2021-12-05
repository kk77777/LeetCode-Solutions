# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rob(self, root: Optional[TreeNode]) -> int:
        self.dp={}
        def rob_dp(node,state):
            if(node,state) not in self.dp:
                if not node:
                    return 0
                if state:
                    self.dp[(node,state)]=rob_dp(node.left,False)+rob_dp(node.right,False)+node.val
                else:
                    self.dp[(node,state)]=max(rob_dp(node.left,True),rob_dp(node.left,False))+max(rob_dp(node.right,True),rob_dp(node.right,False))
                    
            return self.dp[(node,state)]
        return max(rob_dp(root,True),rob_dp(root,False))
