class Solution
{
public:
    pair<int, int> dp[50][50];
    pair<int, int> solve(vector<int> &arr, int i, int j)
    {
        if (i == j)
            return {arr[i], 0};
        if (dp[i][j].first != -1)
            return dp[i][j];
        int sum = INT_MAX;
        int mx = INT_MIN;
        for (int k = i; k < j; k++)
        {
            pair<int, int> l = solve(arr, i, k);
            pair<int, int> r = solve(arr, k + 1, j);
            sum = min(sum, l.second + r.second + (l.first * r.first));
            mx = max(l.first, r.first);
        }
        return dp[i][j] = {mx, sum};
    }

    int mctFromLeafValues(vector<int> &arr)
    {
        for (int i = 0; i < 50; i++)
        {
            for (int j = 0; j < 50; j++)
            {
                dp[i][j] = {-1, -1};
            }
        }
        pair<int, int> ans = solve(arr, 0, arr.size() - 1);
        return ans.second;
    }
};