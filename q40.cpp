class Solution
{
public:
    void solve(vector<int> &a, int sum, vector<vector<int>> &ans, vector<int> &res, int start)
    {
        if (sum < 0)
            return;
        if (sum == 0)
        {
            ans.push_back(res);
            return;
        }
        for (int i = start; i < a.size() && sum - a[i] >= 0; i++)
        {
            if (i != 0 && a[i] == a[i - 1] && i > start)
                continue;
            res.push_back(a[i]);
            solve(a, sum - a[i], ans, res, i + 1);
            res.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<int> res;
        vector<vector<int>> ans;
        if (candidates.size() == 0)
            return ans;
        sort(candidates.begin(), candidates.end());
        solve(candidates, target, ans, res, 0);
        return ans;
    }
};