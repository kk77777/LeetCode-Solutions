class Solution
{
public:
    void solve(vector<int> &a, int sum, vector<vector<int>> &ans, vector<int> &res, int i)
    {
        if (sum < 0)
            return;
        if (sum == 0)
        {
            ans.push_back(res);
            return;
        }
        while (i < a.size() && sum - a[i] >= 0)
        {
            res.push_back(a[i]);
            solve(a, sum - a[i], ans, res, i);
            res.pop_back();
            i++;
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
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