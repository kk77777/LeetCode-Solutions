class Solution
{
public:
    int countPalindromicSubsequence(string s)
    {
        vector<int> f(26, INT_MAX);
        vector<int> l(26, 0);
        for (auto i = 0; i < s.length(); i++)
        {
            f[s[i] - 'a'] = min(f[s[i] - 'a'], i);
            l[s[i] - 'a'] = i;
        }
        int ans = 0;
        for (int i = 0; i < 26; i++)
        {
            if (f[i] < l[i])
            {
                ans += set<char>(begin(s) + f[i] + 1, begin(s) + l[i]).size();
            }
        }
        return ans;
    }
};