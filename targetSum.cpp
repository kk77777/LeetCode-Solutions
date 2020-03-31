class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int S)
    {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
        }
        if (S > sum || (sum + S) % 2 != 0)
            return 0;

        int rsum = (S + sum) / 2;
        vector<vector<int>> t(n + 5, vector<int>(rsum + 5));

        for (int j = 0; j <= rsum; j++)
        {
            t[0][j] = 0;
        }
        for (int i = 0; i <= n; i++)
        {
            t[i][0] = 1;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= rsum; j++)
            {
                if (nums[i - 1] > j)
                {
                    t[i][j] = t[i - 1][j];
                }
                else if (nums[i - 1] <= j)
                {
                    t[i][j] = t[i - 1][j] + t[i - 1][j - nums[i - 1]];
                }
            }
        }

        return t[n][rsum];
    }
};