class Solution
{
public:
    int gcd(int n)
    {
        for (int i = n - 1; i > 1; i--)
        {
            if (n % i == 0)
            {
                return i;
            }
        }
        return -1;
    }

    int minSteps(int n)
    {
        if (n == 0 || n == 1)
            return 0;
        int dp[n + 1];
        dp[0] = 0;
        dp[1] = 0;
        dp[2] = 2;
        for (int i = 3; i <= n; i++)
        {
            int x = gcd(i);
            dp[i] = x == -1 ? i : (dp[x] + (i / x));
        }
        return dp[n];
    }
};