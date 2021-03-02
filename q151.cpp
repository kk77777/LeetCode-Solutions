class Solution
{
public:
    string reverseWords(string s)
    {
        stack<string> st;
        string temp = "";
        int i = 0, j = 0, n = s.length() - 1;
        while (s[i] == ' ')
        {
            i++;
        }
        while (s[n] == ' ')
        {
            n--;
        }
        for (; i <= n; i++)
        {
            if (s[i] == ' ' && s[i - 1] == ' ')
                continue;
            else if (s[i] == ' ')
            {
                j = 0;
                st.push(temp);
                temp = "";
            }
            else
            {
                temp += s[i];
                j++;
            }
        }
        st.push(temp);
        temp = "";
        while (!st.empty())
        {
            if (st.size() > 1)
            {
                temp = temp + st.top() + " ";
            }
            else
            {
                temp = temp + st.top();
            }
            st.pop();
        }
        return temp;
    }
};