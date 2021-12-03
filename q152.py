class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        prev_min=nums[0]
        prev_max=nums[0]
        curr_min=nums[0]
        curr_max=nums[0]
        ans=nums[0]
        
        for x in nums[1:]:
            curr_min=min(prev_min*x,prev_max*x,x)
            curr_max=max(prev_min*x,prev_max*x,x)
            ans=max(curr_max,ans)
            prev_min=curr_min
            prev_max=curr_max
            
        return ans;
