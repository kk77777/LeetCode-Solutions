class Solution
{
public:
    int lcs(string &s1, string &s2, int m, int n, vector<vector<int>> &t)
    {
        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (i == 0 || j == 0)
                {
                    t[i][j] = 0;
                }
            }
        }
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {

                if (s1[i - 1] == s2[j - 1])
                {
                    t[i][j] = 1 + t[i - 1][j - 1];
                }
                else
                {
                    t[i][j] = max(t[i - 1][j], t[i][j - 1]);
                }
            }
        }
        return t[m][n];
    }
    int longestCommonSubsequence(string s1, string s2)
    {
        int m = s1.length();
        int n = s2.length();
        if (m == 0 || n == 0)
            return 0;
        vector<vector<int>> t(m + 1, vector<int>(n + 1, -1));
        return lcs(s1, s2, m, n, t);
    }
};