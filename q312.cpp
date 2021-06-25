class Solution
{
public:
    int mcm(int i, int j, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (i >= j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int mx = INT_MIN;
        for (int k = i; k <= j - 1; k++)
        {
            int temp = mcm(i, k, nums, dp) + mcm(k + 1, j, nums, dp) + (nums[i - 1] * nums[k] * nums[j]);
            if (temp > mx)
            {
                mx = temp;
            }
        }
        return dp[i][j] = mx;
    }

    int maxCoins(vector<int> &nums)
    {

        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return mcm(1, n - 1, nums, dp);
    }
};