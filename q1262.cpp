class Solution {
    
    int solve(vector<int>&nums,int x,int rem,vector<vector<int>>&dp){
        if(x>=nums.size()){
            return rem?INT_MIN:0;
        }
        if(dp[x][rem]!=-1) return dp[x][rem];
        int take=nums[x]+solve(nums,x+1,(rem+nums[x])%3,dp);
        int notTake=solve(nums,x+1,rem,dp);
        return dp[x][rem]=max(take,notTake);
    }
    
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<vector<int>>dp(nums.size()+1,vector<int>(3,-1));
        return solve(nums,0,0,dp);
    }
};
