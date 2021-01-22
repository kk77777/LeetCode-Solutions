int lengthOfLongestSubstring(string s)
{
    int mx = 0;
    unordered_map<char, int> mp;
    int l = 0, r = 0, n = s.length();
    while (r < n)
    {
        if (mp.find(s[r]) != mp.end())
        {
            l = max(l, mp[s[r]] + 1);
        }
        mp[s[r]] = r;
        mx = max(mx, r - l + 1);
        r++;
    }

    return mx;
}