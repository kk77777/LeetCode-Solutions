class Solution
{
public:
    string longestPalindrome(string s)
    {
        string ms = "";
        int ml = 0;
        int n = s.length();
        if (n == 1)
            return s;
        for (int mid = 0; mid < n; mid++)
        {
            for (int x = 0; mid - x >= 0 && mid + x < n; x++)
            {
                if (s[mid - x] != s[mid + x])
                    break;
                int l = 2 * x + 1;
                if (l > ml)
                {
                    ml = l;
                    ms = s.substr(mid - x, l);
                }
            }
        }
        for (int mid = 0; mid < n - 1; mid++)
        {
            for (int x = 1; mid - x + 1 >= 0 && mid + x < n; x++)
            {
                if (s[mid - x + 1] != s[mid + x])
                    break;
                int l = 2 * x;
                if (l > ml)
                {
                    ml = l;
                    ms = s.substr(mid - x + 1, l);
                }
            }
        }

        return ms;
    }
};