class Solution
{
public:
    int lis(vector<int> &nums, vector<int> &v, int n)
    {
        for (int i = 1; i < n; i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (nums[j] >= nums[i])
                    continue;
                int temp = v[j] + 1;
                v[i] = max(temp, v[i]);
            }
        }
        int x;
        x = 1;
        for (auto it : v)
        {
            if (x < it)
                x = it;
        }
        return x;
    }

    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return 1;
        vector<int> v(n, 1);
        return lis(nums, v, n);
    }
};