class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        int t = n + m - 2;
        int r = m - 1;
        double res = 1.0;
        for (int i = 1; i <= r; i++)
        {
            res = res * (t - r + i) / i;
        }
        return (int)res;
    }
};