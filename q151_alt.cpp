class Solution
{
public:
    string reverseWords(string s)
    {
        int n = s.length();
        int i = 0;
        while (s[i] == ' ')
        {
            i++;
        }
        s.erase(0, i);
        i = 0;
        reverse(s.begin(), s.end());
        while (s[i] == ' ')
        {
            i++;
        }
        s.erase(0, i);
        n = s.length();
        int cnt = 0, temp = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == ' ' && s[i - 1] == ' ')
            {
                s.erase(i, 1);
                i--;
            }
            else if (s[i] == ' ')
            {
                temp = i + 1;
                reverse(s.begin() + i - cnt, s.begin() + i);
                cnt = 0;
            }
            else
            {
                cnt++;
            }
        }
        n = s.length();
        reverse(s.begin() + temp, s.begin() + n);
        return s;
    }
};

//["---the"]