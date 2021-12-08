# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findTilt(self, root: Optional[TreeNode]) -> int:
        weight,tilt=self.find_sum_tilt(root)
        return tilt
    
    def find_sum_tilt(self,node:TreeNode)->(int,int):
        if node is None:
            return 0,0
        
        left_weight,left_tilt=self.find_sum_tilt(node.left)
        right_weight,right_tilt=self.find_sum_tilt(node.right)
        
        node_weight=left_weight+right_weight+node.val
        node_tilt=left_tilt+right_tilt+abs(left_weight-right_weight)
        
        return node_weight,node_tilt
