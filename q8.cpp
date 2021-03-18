class Solution
{
public:
    int myAtoi(string s)
    {
        int cw = 0;
        int i = 0;
        long long int ans = -1;
        bool flag = 0;
        while (s[i] == ' ')
        {
            i++;
        }
        s.erase(s.begin(), s.begin() + i);
        i = 0;
        if (s[i] == '-')
        {
            flag = 1;
            i++;
        }
        else if (s[i] == '+')
        {
            i++;
        }
        for (; i < s.length(); i++)
        {
            int c = s[i] - '0';
            if (c >= 0 && c <= 9)
            {
                if (ans != -1)
                {

                    ans *= 10;
                    if (ans >= INT_MAX && flag == 0)
                        return INT_MAX;
                    if (ans >= INT_MAX && flag == 1)
                        return INT_MIN;
                    ans += c;
                }
                else
                {
                    ans = c;
                }
            }
            else
            {
                if (ans == -1)
                {
                    return 0;
                }
                break;
            }
        }

        ans = ans == -1 ? 0 : ans;
        ans = flag ? -ans : ans;
        ans = ans >= INT_MAX ? INT_MAX : ans;
        ans = ans <= INT_MIN ? INT_MIN : ans;
        return ans;
    }
};