class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int sum = 0, mx = nums[0];
        for (int i : nums)
        {
            sum += i;
            mx = max(sum, mx);
            if (sum < 0)
            {
                sum = 0;
            }
        }
        return mx;
    }
};