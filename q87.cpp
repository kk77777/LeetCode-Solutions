class Solution
{
public:
    unordered_map<string, bool> mp;
    bool solve(string a, string b)
    {
        if (a.compare(b) == 0)
        {
            return true;
        }
        if (a.length() <= 1)
        {
            return false;
        }

        string key = "";
        key += a + " " + b;

        if (mp.find(key) != mp.end())
        {
            return mp[key];
        }

        bool flag = false;

        int n = a.length();

        for (int i = 1; i <= n - 1; i++)
        {
            bool cond1 = false, cond2 = false;
            if (solve(a.substr(0, i), b.substr(n - i, i)) && solve(a.substr(i, n - i), b.substr(0, n - i)))
                cond1 = true;
            if (solve(a.substr(0, i), b.substr(0, i)) && solve(a.substr(i, n - i), b.substr(i, n - i)))
                cond2 = true;
            if (cond1 || cond2)
            {
                flag = true;
                break;
            }
        }

        return mp[key] = flag;
    }

    bool isScramble(string s1, string s2)
    {
        return solve(s1, s2);
    }
};