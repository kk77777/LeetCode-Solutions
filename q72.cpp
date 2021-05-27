class Solution
{

    int solve(string &s1, string &s2, int n, int m, vector<vector<int>> &dp)
    {
        if (n == 0)
            return m;
        if (m == 0)
            return n;
        if (dp[n][m] != -1)
            return dp[n][m];
        if (s1[n - 1] == s2[m - 1])
            dp[n][m] = solve(s1, s2, n - 1, m - 1, dp);
        else
        {
            int ins = 1 + solve(s1, s2, n, m - 1, dp);
            int rem = 1 + solve(s1, s2, n - 1, m, dp);
            int rep = 1 + solve(s1, s2, n - 1, m - 1, dp);
            dp[n][m] = min(ins, min(rem, rep));
        }
        return dp[n][m];
    }

public:
    int minDistance(string word1, string word2)
    {
        int n = word1.length();
        int m = word2.length();
        if (n == 0)
            return m;
        if (m == 0)
            return n;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return solve(word1, word2, n, m, dp);
    }
};