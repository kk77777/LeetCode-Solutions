class Solution
{
public:
    int solve(vector<int> &nums, int targetSum, int sum, int curr, vector<int> &dp)
    {
        if (sum == (targetSum - sum))
        {
            return true;
        }
        if (curr >= nums.size())
            return (sum == (targetSum - sum));
        if (dp[sum] != -1)
        {
            return dp[sum];
        }
        bool take = solve(nums, targetSum, sum + nums[curr], curr + 1, dp);
        bool notTake = solve(nums, targetSum, sum, curr + 1, dp);

        return dp[sum] = take || notTake;
    }

    bool canPartition(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(20004, -1);
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
        }
        return solve(nums, sum, 0, 0, dp);
    }
};