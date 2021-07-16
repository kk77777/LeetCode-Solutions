class Solution
{
public:
    int reverse(int x)
    {
        bool flag = 0;
        int rev = 0, prev = 0;
        while (x != 0)
        {
            int cd = x % 10;
            if ((x < 0 && rev < (INT_MIN - cd) / 10) ||
                (x > 0 && rev > (INT_MAX - cd) / 10))
                return 0;
            rev = rev * 10 + cd;
            x /= 10;
        }
        return rev;
    }
};