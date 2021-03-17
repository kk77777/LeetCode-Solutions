class Solution
{
public:
    int countSubstrings(string s)
    {
        if (s.length() == 1)
            return 1;
        bool dp[s.length()][s.length()];
        int cnt = 0;
        for (int g = 0; g < s.length(); g++)
        {
            for (int i = 0, j = g; j < s.length(); i++, j++)
            {
                if (g == 0)
                    dp[i][j] = true;
                else if (g == 1)
                {
                    dp[i][j] = (s[i] == s[j]) ? true : false;
                }
                else
                {
                    dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]) ? true : false;
                }
                if (dp[i][j])
                    cnt++;
            }
        }
        return cnt;
    }
};