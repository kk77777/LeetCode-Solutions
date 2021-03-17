class Solution
{
public:
    string longestPalindrome(string s)
    {

        if (s.length() == 1)
            return s;
        int n = s.length();
        string ans;
        int ml = -1;
        bool dp[n][n];
        for (int g = 0; g < n; g++)
        {
            for (int i = 0, j = g; j < n; i++, j++)
            {
                if (g == 0)
                {
                    dp[i][j] = true;
                }
                else if (g == 1)
                {
                    dp[i][j] = (s[i] == s[j]) ? true : false;
                }
                else
                {
                    dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]) ? true : false;
                }
                if (dp[i][j])
                {
                    if (ml < j - i)
                    {
                        ml = j - i;
                        ans = s.substr(i, j - i + 1);
                    }
                }
            }
        }
        return ans;
    }
};