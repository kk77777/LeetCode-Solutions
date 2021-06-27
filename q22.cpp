class Solution
{
public:
    void solve(int n, vector<string> &s, int open, int close, string temp)
    {
        if (close == n)
        {
            s.push_back(temp);
            return;
        }
        if (open < n)
        {
            temp.push_back('(');
            solve(n, s, open + 1, close, temp);
            temp.pop_back();
        }
        if (close < open)
        {
            temp.push_back(')');
            solve(n, s, open, close + 1, temp);
            temp.pop_back();
        }
        return;
    }

    vector<string> generateParenthesis(int n)
    {
        string temp = "";
        vector<string> s;
        solve(n, s, 0, 0, temp);
        return s;
    }
};