class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> s;
        int mx = 0;
        for (int i : nums)
        {
            s.insert(i);
        }
        for (int i : nums)
        {
            if (!s.count(i - 1))
            {
                int x = i;
                int cmx = 1;
                while (s.count(x + 1))
                {
                    x++;
                    cmx++;
                }
                mx = max(mx, cmx);
            }
        }
        return mx;
    }
};