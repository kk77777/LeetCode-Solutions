class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        if (n == 1)
            return heights[0];
        stack<int> s;
        int i = 0;
        int tp;
        int ans = 0;
        int temp;
        while (i < n)
        {
            if (s.empty() || heights[i] >= heights[s.top()])
            {
                s.push(i++);
            }
            else
            {
                tp = s.top();
                s.pop();
                temp = heights[tp] * (s.empty() ? i : i - s.top() - 1);
                ans = temp > ans ? temp : ans;
            }
        }
        while (!s.empty())
        {
            tp = s.top();
            s.pop();
            temp = heights[tp] * (s.empty() ? i : i - s.top() - 1);
            ans = temp > ans ? temp : ans;
        }
        return ans;
    }
};