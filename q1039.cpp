class Solution
{

    int mcm(int i, int j, vector<int> &values, vector<vector<int>> &dp)
    {
        if (i >= j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int mn = INT_MAX;
        for (int k = i; k <= j - 1; k++)
        {
            int temp = mcm(i, k, values, dp) + mcm(k + 1, j, values, dp) + (values[i - 1] * values[k] * values[j]);
            if (temp < mn)
            {
                mn = temp;
            }
        }
        return dp[i][j] = mn;
    }

public:
    int minScoreTriangulation(vector<int> &values)
    {
        int n = values.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return mcm(1, n - 1, values, dp);
    }
};