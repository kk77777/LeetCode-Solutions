class Solution
{

    bool checkInDict(string x, vector<string> &wordDict)
    {
        for (int i = 0; i < wordDict.size(); i++)
        {
            if (wordDict[i].compare(x) == 0)
            {
                return true;
            }
        }
        return false;
    }

    bool check(string s, vector<string> &wordDict)
    {
        int n = s.size();
        vector<bool> dp(n + 1, 0);
        if (n == 0)
            return true;
        for (int i = 1; i <= n; i++)
        {
            if (dp[i] == false && checkInDict(s.substr(0, i), wordDict))
            {
                dp[i] = true;
            }
            if (dp[i] == true)
            {
                if (i == n)
                    return true;
                for (int j = i + 1; j <= n; j++)
                {
                    if (dp[j] == false && checkInDict(s.substr(i, j - i), wordDict))
                    {
                        dp[j] = true;
                    }
                    if (j == n && dp[j] == true)
                        return true;
                }
            }
        }
        return false;
    }

public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        return check(s, wordDict);
    }
};