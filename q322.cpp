class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int dp[amount + 1];
        dp[0] = 0;
        for (int i = 1; i <= amount; i++)
        {
            dp[i] = amount + 1;
            for (auto k : coins)
            {
                if (i - k >= 0)
                {
                    dp[i] = min(dp[i], dp[i - k] + 1);
                }
            }
        }
        if (dp[amount] > amount)
            return -1;
        return dp[amount];
    }
};