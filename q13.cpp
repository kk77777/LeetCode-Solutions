class Solution
{
public:
    int val(char c)
    {
        switch (c)
        {
        case 'I':
            return 1;
            break;
        case 'V':
            return 5;
            break;
        case 'X':
            return 10;
            break;
        case 'L':
            return 50;
            break;
        case 'C':
            return 100;
            break;
        case 'D':
            return 500;
            break;
        case 'M':
            return 1000;
            break;
        default:
            return -1;
        }
    }

    int romanToInt(string s)
    {
        int res = 0;
        for (int i = 0; i < s.length(); i++)
        {
            int x1 = val(s[i]);
            if (i + 1 < s.length())
            {
                int x2 = val(s[i + 1]);
                if (x1 >= x2)
                {
                    res = res + x1;
                }
                else
                {
                    res = res + x2 - x1;
                    i++;
                }
            }
            else
            {
                res = res + x1;
            }
        }
        return res;
    }
};