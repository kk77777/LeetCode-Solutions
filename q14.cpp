class Solution
{
public:
    string findPrefix(string s1, string s2)
    {
        string pr;
        int n1 = s1.length();
        int n2 = s2.length();
        for (int i = 0; i < n1 && i < n2; i++)
        {
            if (s1[i] != s2[i])
                break;
            pr.push_back(s1[i]);
        }
        return pr;
    }

    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.size() == 0)
            return "";
        if (strs.size() == 1)
            return strs[0];
        string prefix = strs[0];
        for (int i = 1; i < strs.size(); i++)
        {
            prefix = findPrefix(prefix, strs[i]);
        }
        return prefix;
    }
};