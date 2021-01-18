class Solution
{
public:
    double myPow(double x, int n)
    {
        long temp = n;
        double ans = 1.0;
        if (temp < 0)
            temp *= (-1);
        while (temp > 0)
        {
            if (temp % 2 != 0)
            {
                ans *= x;
                temp--;
            }
            else
            {
                temp /= 2;
                x *= x;
            }
        }
        if (n < 0)
        {
            ans = double(1.0) / double(ans);
        }
        return ans;
    }
};