class Solution
{
public:
    int isPossible(string s, string p, vector<int> &removable, int mid, string &t)
    {
        int n = s.length();
        int m = p.length();
        for (int i = 0; i <= mid; i++)
        {
            t[removable[i]] = '#';
        }
        int j = 0;
        for (int i = 0; i < n && j < m; i++)
        {
            if (t[i] == '#')
            {
                continue;
            }
            if (s[i] == p[j])
            {

                j++;
                continue;
            }
        }
        if (j == m)
        {
            return true;
        }
        for (int i = 0; i <= mid; i++)
        {
            t[removable[i]] = s[removable[i]];
        }

        return false;
    }
    int maximumRemovals(string s, string p, vector<int> &removable)
    {

        string t = s;
        int cnt = -1;
        int l = 0, r = removable.size() - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (isPossible(s, p, removable, mid, t))
            {
                l = mid + 1;
                cnt = mid;
            }
            else
            {
                r = mid - 1;
            }
        }
        return cnt + 1;
    }
};