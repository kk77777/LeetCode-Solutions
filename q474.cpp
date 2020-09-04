class Solution
{
public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (auto s : strs)
        {
            int x = count(s.begin(), s.end(), '0');
            int y = s.size() - x;
            for (int i = m; i >= x; i--)
            {
                for (int j = n; j >= y; j--)
                {
                    dp[i][j] = max(dp[i][j], 1 + dp[i - x][j - y]);
                }
            }
        }
        return dp[m][n];
    }
};