class Solution
{
public:
    int lcs(string &s1, string &s2, int m, int n, vector<vector<int>> &t)
    {
        if (m == 0 || n == 0)
            return 0;
        if (t[m - 1][n - 1] != -1)
            return t[m - 1][n - 1];
        if (s1[m - 1] == s2[n - 1])
            t[m - 1][n - 1] = 1 + lcs(s1, s2, m - 1, n - 1, t);
        else
        {
            t[m - 1][n - 1] = max(lcs(s1, s2, m, n - 1, t), lcs(s1, s2, m - 1, n, t));
        }
        return t[m - 1][n - 1];
    }

    int longestCommonSubsequence(string s1, string s2)
    {
        int m = s1.length();
        int n = s2.length();
        if (m == 0 || n == 0)
            return 0;
        vector<vector<int>> t(m, vector<int>(n, -1));
        return lcs(s1, s2, m, n, t);
    }
};