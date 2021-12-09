class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        if arr[start]==0: return True
        if arr[start]==-1: return False
        left_side=start-arr[start]
        right_side=start+arr[start]
        arr[start]=-1
        return (left_side>=0 and self.canReach(arr,left_side)) or (right_side<len(arr) and self.canReach(arr,right_side))
